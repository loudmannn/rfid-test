#pragma once

#define FW_MAIN
//#define FW_MAIN_LITE
#define FW_MAIN_FULL
//#define FW_READ_SENSOR_SN
// #define FW_STRESS_TEST
//#define FW_STRESS_TEST_LITE

#ifdef FW_STRESS_TEST // Sensor, Buzzer, Servo
constexpr bool STRESS_TEST = true;
#else
constexpr bool STRESS_TEST = false;
#endif


#ifdef FW_STRESS_TEST_LITE // Servo only
constexpr bool STRESS_TEST_LITE = true;
#else
constexpr bool STRESS_TEST_LITE = false;
#endif


#define BATTERY
#define BUZZER
#define SLEEP
#define SENSOR
#define BUTTON
#define SERVO
#define TEST_PROTOCOL

#ifdef NDEBUG
#define MONITOR_DEBUG
#endif
