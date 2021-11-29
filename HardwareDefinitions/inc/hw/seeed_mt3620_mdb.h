/* Copyright (c) Microsoft Corporation. All rights reserved.
   Licensed under the MIT License. */

// This header contains the peripheral pinout definitions for the
// Seeed MT3620 Mini Development Board (MDB)

// This file is autogenerated from ../../seeed_mt3620_mdb.json.  Do not edit it directly.

#pragma once
#include "hw/ailink_wfm620rsc1.h"

// User LED uses GPIO7.
#define SEEED_MT3620_MDB_USER_LED AILINK_WFM620RSC1_PIN4_GPIO7

// GPIO4 is exposed on J1 pin 1.
#define SEEED_MT3620_MDB_J1_PIN1_GPIO4 AILINK_WFM620RSC1_PIN1_GPIO4

// GPIO41 is exposed on J1 pin 1.
#define SEEED_MT3620_MDB_J1_PIN1_GPIO41 AILINK_WFM620RSC1_PIN1_GPIO41

// GPIO5 is exposed on J1 pin 2.
#define SEEED_MT3620_MDB_J1_PIN2_GPIO5 AILINK_WFM620RSC1_PIN2_GPIO5

// GPIO42 is exposed on J1 pin 2.
#define SEEED_MT3620_MDB_J1_PIN2_GPIO42 AILINK_WFM620RSC1_PIN2_GPIO42

// GPIO6 is exposed on J1 pin 3.
#define SEEED_MT3620_MDB_J1_PIN3_GPIO6 AILINK_WFM620RSC1_PIN3_GPIO6

// GPIO43 is exposed on J1 pin 3.
#define SEEED_MT3620_MDB_J1_PIN3_GPIO43 AILINK_WFM620RSC1_PIN3_GPIO43

// GPIO8 is exposed on J1 pin 5.
#define SEEED_MT3620_MDB_J1_PIN5_GPIO8 AILINK_WFM620RSC1_PIN5_GPIO8

// GPIO26 is exposed on J1 pin 5.
#define SEEED_MT3620_MDB_J1_PIN5_GPIO26 AILINK_WFM620RSC1_PIN5_GPIO26

// GPIO9 is exposed on J1 pin 6.
#define SEEED_MT3620_MDB_J1_PIN6_GPIO9 AILINK_WFM620RSC1_PIN6_GPIO9

// GPIO27 is exposed on J1 pin 6.
#define SEEED_MT3620_MDB_J1_PIN6_GPIO27 AILINK_WFM620RSC1_PIN6_GPIO27

// GPIO10 is exposed on J1 pin 7.
#define SEEED_MT3620_MDB_J1_PIN7_GPIO10 AILINK_WFM620RSC1_PIN7_GPIO10

// GPIO28 is exposed on J1 pin 7.
#define SEEED_MT3620_MDB_J1_PIN7_GPIO28 AILINK_WFM620RSC1_PIN7_GPIO28

// GPIO11 is exposed on J1 pin 8.
#define SEEED_MT3620_MDB_J1_PIN8_GPIO11 AILINK_WFM620RSC1_PIN8_GPIO11

// GPIO29 is exposed on J1 pin 8.
#define SEEED_MT3620_MDB_J1_PIN8_GPIO29 AILINK_WFM620RSC1_PIN8_GPIO29

// GPIO30 is exposed on J1 pin 9.
#define SEEED_MT3620_MDB_J1_PIN9_GPIO30 AILINK_WFM620RSC1_PIN9_GPIO30

// GPIO32 is exposed on J1 pin 10.
#define SEEED_MT3620_MDB_J1_PIN10_GPIO32 AILINK_WFM620RSC1_PIN10_GPIO32

// GPIO34 is exposed on J1 pin 11.
#define SEEED_MT3620_MDB_J1_PIN11_GPIO34 AILINK_WFM620RSC1_PIN11_GPIO34

// GPIO31 is exposed on J2 pin 13.
#define SEEED_MT3620_MDB_J2_PIN13_GPIO31 AILINK_WFM620RSC1_PIN14_GPIO31

// GPIO33 is exposed on J2 pin 14.
#define SEEED_MT3620_MDB_J2_PIN14_GPIO33 AILINK_WFM620RSC1_PIN15_GPIO33

// GPIO35 is exposed on J2 pin 15.
#define SEEED_MT3620_MDB_J2_PIN15_GPIO35 AILINK_WFM620RSC1_PIN16_GPIO35

// PWM CONTROLLER 1 channel 0 is exposed on J1 pin 4, channel 1 is exposed on J1 pin 2, channel 2 is exposed on J1 pin 3, and channel 3 is used by User LED. Pins for this controller are shared with SEEED_MT3620_MDB_USER_LED, SEEED_MT3620_MDB_J1_PIN2_GPIO5/GPIO42, SEEED_MT3620_MDB_J1_PIN3_GPIO6/GPIO43. If this PWM Controller is requested, none of these GPIOs can be used.
#define SEEED_MT3620_MDB_PWM_CONTROLLER1 AILINK_WFM620RSC1_PWM_CONTROLLER1

// PWM CONTROLLER 2 channel 0 is exposed on J1 pin 5, channel 1 is exposed on J1 pin 6, channel 2 is exposed on J1 pin 7, and channel 3 is exposed on J1 pin 8. Pins for this controller are shared with SEEED_MT3620_MDB_J1_PIN5_GPIO8/GPIO26, SEEED_MT3620_MDB_J1_PIN6_GPIO9/GPIO27, SEEED_MT3620_MDB_J1_PIN7_GPIO10/28, SEEED_MT3620_MDB_J1_PIN8_GPIO11/29. If this PWM Controller is requested, none of these GPIOs can be used.
#define SEEED_MT3620_MDB_PWM_CONTROLLER2 AILINK_WFM620RSC1_PWM_CONTROLLER2

// ADC CONTROLLER 0 channel 0 is exposed on pin 1, channel 1 is exposed on pin 2, and channel 2 is exposed on pin 3. Pins for this controller are shared with SEEED_MT3620_MDB_J1_PIN1_GPIO4/GPIO41, SEEED_MT3620_MDB_J1_PIN2_GPIO5/GPIO42, and SEEED_MT3620_MDB_J1_PIN3_GPIO6/GPIO43. If this ADC controller is requested, none of these GPIOs can be used.
#define SEEED_MT3620_MDB_ADC_CONTROLLER0 AILINK_WFM620RSC1_ADC_CONTROLLER0

// ISU0 I2C is exposed on J1, pin 7 (SDA) and pin 6 (SCL).
#define SEEED_MT3620_MDB_J1_ISU0_I2C AILINK_WFM620RSC1_ISU0_I2C

// ISU0 SPI is exposed on J1, pin 7 (MISO), pin 5 (SCLK), pin 8 (CSA), pin 6 (MOSI) and pin 9 (CSB).
#define SEEED_MT3620_MDB_J1_ISU0_SPI AILINK_WFM620RSC1_ISU0_SPI

// ISU0 UART is exposed on J1, pin 7 (RX), pin 5 (TX), pin 8 (CTS), and pin 6 (RTS).
#define SEEED_MT3620_MDB_J1_ISU0_UART AILINK_WFM620RSC1_ISU0_UART

// ISU1 I2C is exposed on J1 and J2, pin 14 (SDA) and pin 10 (SCL).
#define SEEED_MT3620_MDB_J1J2_ISU1_I2C AILINK_WFM620RSC1_ISU1_I2C

// ISU1 SPI is exposed on J1 and J2, pin 14 (MISO), pin 13 (SCLK), pin 11 (CSA), pin 10 (MOSI) and pin 16 (CSB).
#define SEEED_MT3620_MDB_J1J2_ISU1_SPI AILINK_WFM620RSC1_ISU1_SPI

// ISU1 UART is exposed on J1 and J2, pin 14 (RX), pin 13 (TX), pin 11 (CTS), and pin 10 (RTS).
#define SEEED_MT3620_MDB_J1J2_ISU1_UART AILINK_WFM620RSC1_ISU1_UART

