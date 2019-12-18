/*!
 * \file      rtc-board.c
 *
 * \brief     Target board RTC timer and low power modes management
 *
 * \copyright Revised BSD License, see section \ref LICENSE.
 *
 * \code
 *                ______                              _
 *               / _____)             _              | |
 *              ( (____  _____ ____ _| |_ _____  ____| |__
 *               \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 *               _____) ) ____| | | || |_| ____( (___| | | |
 *              (______/|_____)_|_|_| \__)_____)\____)_| |_|
 *              (C)2013-2017 Semtech
 *
 * \endcode
 *
 * \author    Miguel Luis ( Semtech )
 *
 * \author    Gregory Cristian ( Semtech )
 *
 * \author    Marten Lootsma(TWTG) on behalf of Microchip/Atmel (c)2017
 */

#include "board-config.h"
#include "board.h"
#include "system/timer.h"
#include "system/systime.h"
#include "system/gpio.h"
#include <math.h>
#include<stdio.h>
#include "rtc-board.h"
#include "fsl_pit.h"
#include <stdio.h>
#include "fsl_common.h"
#include "board_46.h"

/*
*En esta placa se utilizo un PIT que incrementa un contador cada 1ms
*Se utiliza la alarma por polling
*Se podria vlver a probar el RTC
*Calibrar el PIT ante de utilizar
*/
#define PIT_SOURCE_CLOCK CLOCK_GetFreq(kCLOCK_BusClk)

#define NUMERO_DECIMALES 3

#define RTC_DEBUG_ENABLE                            1
#define RTC_DEBUG_DISABLE                           0

#define RTC_DEBUG_GPIO_STATE                        RTC_DEBUG_DISABLE //RTC_DEBUG_DISABLE
#define RTC_DEBUG_PRINTF_STATE                      RTC_DEBUG_DISABLE // RTC_DEBUG_DISABLE Habilito el debug por pantalla

#define MIN_ALARM_DELAY                             3 // in ticks

pit_config_t pitConfig; //PIT
uint32_t second=0U;
uint32_t COUNT=0U;

/*!
 * \brief Indicates if the RTC is already Initialized or not
 */
static bool RtcInitialized = false;
static volatile bool RtcTimeoutPendingInterrupt = false;
static volatile bool RtcTimeoutPendingPolling = false;

typedef enum AlarmStates_e
{
    ALARM_STOPPED = 0,
    ALARM_RUNNING = !ALARM_STOPPED
} AlarmStates_t;

/*!
 * RTC timer context 
 */
typedef struct
{
    uint32_t Time;  // Reference time
    uint32_t Delay; // Reference Timeout duration
    uint32_t AlarmState;
}RtcTimerContext_t;

/*!
 * Keep the value of the RTC timer when the RTC alarm is set
 * Set with the \ref RtcSetTimerContext function
 * Value is kept as a Reference to calculate alarm
 */
static RtcTimerContext_t RtcTimerContext;

#if( RTC_DEBUG_GPIO_STATE == RTC_DEBUG_ENABLE )
Gpio_t DbgRtcPin0;
Gpio_t DbgRtcPin1;
#endif

/*!
 * Used to store the Seconds and SubSeconds.
 * 
 * WARNING: Temporary fix fix. Should use MCU NVM internal
 *          registers
 */
uint32_t RtcBkupRegisters[] = { 0, 0 };

/*!
 * \brief Callback for the hw_timer when counter overflows
 */
//static void RtcOverflowIrq( void );

void PIT_IRQHandler(void)
{
    /* Clear interrupt flag.*/
    PIT_ClearStatusFlags(PIT, kPIT_Chnl_0, kPIT_TimerFlag);
    COUNT++;

    /*
     * Habilitar estas lineas para calibrar el PIT
     * Usar un cronometro e iniciarlo cuando se inicia el debug
     * luego cuando salta el printf debieron haber transcurrido 60 segudos
     * de lo contrario ir modificando el periodo del PIT
     *
    second=COUNT>>10;
    if(second == 60U){
    	printf(":) alarma segundo  %d \n",second);
    }
*/
}

void RtcInit( void )
{
    if( RtcInitialized == false )
    {
#if( RTC_DEBUG_GPIO_STATE == RTC_DEBUG_ENABLE )
        GpioInit( &DbgRtcPin0, RTC_DBG_PIN_0, PIN_OUTPUT, PIN_PUSH_PULL, PIN_NO_PULL, 0 );
        GpioInit( &DbgRtcPin1, RTC_DBG_PIN_1, PIN_OUTPUT, PIN_PUSH_PULL, PIN_NO_PULL, 0 );
#endif

	   //pitConfig.enableRunInDebug = false;
	   PIT_GetDefaultConfig(&pitConfig);
	   // Init pit module
	   PIT_Init(PIT, &pitConfig);
	   //Set timer period for channel 0
	   PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, USEC_TO_COUNT(1000U, PIT_SOURCE_CLOCK)); //875U para ABP *** 939U para OTAA
	   //Set priority
	   NVIC_SetPriority (PIT_IRQn, 2);
	   // Enable timer interrupts for channel 0
	   PIT_EnableInterrupts(PIT, kPIT_Chnl_0, kPIT_TimerInterruptEnable);
	   // Enable at the NVIC
	   EnableIRQ(PIT_IRQn);
	   // Start channel 0
	   PIT_StartTimer(PIT, kPIT_Chnl_0);

       RtcTimerContext.AlarmState = ALARM_STOPPED;
	   RtcSetTimerContext( );
	   RtcInitialized = true;
    }
}

uint32_t RtcMs2Tick( TimerTime_t milliseconds )
{
	return ( uint32_t )(milliseconds);
}

TimerTime_t RtcTick2Ms( uint32_t tick )
{
	uint32_t seconds = tick >> 10;
    tick = tick & 0x3FF;
//    return ( ( seconds * 1000 ) + ( ( tick*1000) >> 10 ));
    return ( ( seconds * 1000 ) + (tick));
}

uint32_t RtcGetCalendarTime( uint16_t *milliseconds )
{
	 uint32_t ticks = 0;
	 uint32_t calendarValue = COUNT;
	 uint32_t seconds = ( uint32_t )calendarValue >> 10;
	 ticks =  ( uint32_t )calendarValue & 0x3FF;
	 *milliseconds = ( ticks ); //RtcTick2Ms()
	 return seconds;
}

uint32_t RtcSetTimerContext( void )
{

    RtcTimerContext.Time =( COUNT );
    return ( uint32_t )RtcTimerContext.Time;  //Lo guarda en ticks
}

uint32_t RtcGetTimerContext( void )
{
    return RtcTimerContext.Time;
}

uint32_t RtcGetMinimumTimeout( void )
{
    return( MIN_ALARM_DELAY );
}

void RtcDelayMs( TimerTime_t milliseconds )
{
    uint32_t delayTicks = 0;
    uint32_t refTicks = RtcGetTimerValue(); //Esta funcion devuelve los ticks actuales

    delayTicks = RtcMs2Tick( milliseconds );

    // Wait delay ms
    while( ( ( RtcGetTimerValue() - refTicks ) ) < delayTicks )
    {
        __NOP( );
    }
}

void RtcSetAlarm( uint32_t timeout )
{
    RtcStartAlarm( timeout );
}

void RtcStopAlarm( void )
{
    RtcTimerContext.AlarmState = ALARM_STOPPED;
}

void RtcStartAlarm( uint32_t timeout ) //timeout [ticks]
{
    CRITICAL_SECTION_BEGIN( );

    RtcStopAlarm( );

    RtcTimerContext.Delay = timeout;

#if( RTC_DEBUG_PRINTF_STATE == RTC_DEBUG_ENABLE )
    printf( "TIMEOUT \t%010ld\t%010ld\r\n", RtcTimerContext.Time, RtcTimerContext.Delay );
#endif
#if( RTC_DEBUG_GPIO_STATE == RTC_DEBUG_ENABLE )
    GpioWrite( &DbgRtcPin0, 0 );
    GpioWrite( &DbgRtcPin1, 0 );
#endif

	RtcTimeoutPendingInterrupt =false;
	RtcTimeoutPendingPolling =true;

	RtcTimerContext.AlarmState = ALARM_RUNNING;

    CRITICAL_SECTION_END( );
}

uint32_t RtcGetTimerValue( void )
{
    return (COUNT);
}

uint32_t RtcGetTimerElapsedTime( void )
{
    return ( uint32_t)( (COUNT) - RtcTimerContext.Time );
}

void RtcBkupWrite( uint32_t data0, uint32_t data1 )
{
    CRITICAL_SECTION_BEGIN( );
    RtcBkupRegisters[0] = data0;
    RtcBkupRegisters[1] = data1;
    CRITICAL_SECTION_END( );
}

void RtcBkupRead( uint32_t* data0, uint32_t* data1 )
{
    CRITICAL_SECTION_BEGIN( );
    *data0 = RtcBkupRegisters[0];
    *data1 = RtcBkupRegisters[1];
    CRITICAL_SECTION_END( );
}

void RtcProcess( void )
{
    CRITICAL_SECTION_BEGIN( );
    if( (  RtcTimerContext.AlarmState == ALARM_RUNNING ) && ( RtcTimeoutPendingPolling == true ) )
    {
        if( RtcGetTimerElapsedTime( ) >= RtcTimerContext.Delay )
        {
            RtcTimerContext.AlarmState = ALARM_STOPPED;
            // Because of one shot the task will be removed after the callback
            RtcTimeoutPendingPolling = false;
#if( RTC_DEBUG_GPIO_STATE == RTC_DEBUG_ENABLE )
            GpioWrite( &DbgRtcPin0, 0 );
            GpioWrite( &DbgRtcPin1, 1 );
#endif
            // NOTE: The handler should take less then 1 ms otherwise the clock shifts
            TimerIrqHandler( );
#if( RTC_DEBUG_GPIO_STATE == RTC_DEBUG_ENABLE )
            GpioWrite( &DbgRtcPin1, 0 );
#endif
        }
    }
    CRITICAL_SECTION_END( );
}

TimerTime_t RtcTempCompensation( TimerTime_t period, float temperature )
{
    return period;
}

void RtcAlarmIrq( void )
{
    RtcTimerContext.AlarmState = ALARM_STOPPED;
    // Because of one shot the task will be removed after the callback
    RtcTimeoutPendingInterrupt = false;
#if( RTC_DEBUG_GPIO_STATE == RTC_DEBUG_ENABLE )
    GpioWrite( &DbgRtcPin1, 1 );
#endif
    // NOTE: The handler should take less then 1 ms otherwise the clock shifts
    TimerIrqHandler( );
#if( RTC_DEBUG_GPIO_STATE == RTC_DEBUG_ENABLE )
    GpioWrite( &DbgRtcPin1, 0 );
#endif
}

static void RtcOverflowIrq( void )
{
    //RtcTimerContext.Time += ( uint64_t )( 1 << 32 );
}


