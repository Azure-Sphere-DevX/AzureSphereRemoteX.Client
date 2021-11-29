/* Copyright (c) Microsoft Corporation. All rights reserved.
   Licensed under the MIT License. */

// This header contains the peripheral pinout definitions for the
// Avnet MT3620 Starter Kit (SK)

// This file is autogenerated from ../../avnet_mt3620_sk.json.  Do not edit it directly.

#pragma once
#include "avnet_aesms_mt3620.h"

// Application status LED uses GPIO4.
#define AVNET_MT3620_SK_APP_STATUS_LED_YELLOW AVNET_AESMS_PIN8_GPIO4

// WLAN status LED uses GPIO5.
#define AVNET_MT3620_SK_WLAN_STATUS_LED_YELLOW AVNET_AESMS_PIN9_GPIO5

// User LED Red channel uses GPIO8.
#define AVNET_MT3620_SK_USER_LED_RED AVNET_AESMS_PIN11_GPIO8

// User LED Green channel uses GPIO9.
#define AVNET_MT3620_SK_USER_LED_GREEN AVNET_AESMS_PIN12_GPIO9

// User LED Blue channel uses GPIO10.
#define AVNET_MT3620_SK_USER_LED_BLUE AVNET_AESMS_PIN13_GPIO10

// User BUTTON A uses GPIO12.
#define AVNET_MT3620_SK_USER_BUTTON_A AVNET_AESMS_PIN14_GPIO12

// User BUTTON B uses GPIO13.
#define AVNET_MT3620_SK_USER_BUTTON_B AVNET_AESMS_PIN15_GPIO13

// GPIO42 is exposed on SOCKET1.
#define AVNET_MT3620_SK_GPIO42 AVNET_AESMS_PIN30_GPIO42

// GPIO43 is exposed on SOCKET2.
#define AVNET_MT3620_SK_GPIO43 AVNET_AESMS_PIN31_GPIO43

// GPIO16 is exposed on SOCKET1.
#define AVNET_MT3620_SK_GPIO16 AVNET_AESMS_PIN16_GPIO16

// GPIO17 is exposed on SOCKET2 and UART/BLE Connector.
#define AVNET_MT3620_SK_GPIO17 AVNET_AESMS_PIN17_GPIO17

// GPIO34 is exposed on SOCKET1.
#define AVNET_MT3620_SK_GPIO34 AVNET_AESMS_PIN25_GPIO34

// GPIO35 is exposed on SOCKET2.
#define AVNET_MT3620_SK_GPIO35 AVNET_AESMS_PIN26_GPIO35

// GPIO31 is exposed on SOCKET1 and SOCKET2.
#define AVNET_MT3620_SK_GPIO31 AVNET_AESMS_PIN22_GPIO31

// GPIO33 is exposed on SOCKET1 and SOCKET2.
#define AVNET_MT3620_SK_GPIO33 AVNET_AESMS_PIN24_GPIO33

// GPIO32 is exposed on SOCKET1 and SOCKET2.
#define AVNET_MT3620_SK_GPIO32 AVNET_AESMS_PIN23_GPIO32

// GPIO0 is exposed on SOCKET1.
#define AVNET_MT3620_SK_GPIO0 AVNET_AESMS_PIN5_GPIO0

// GPIO1 is exposed on SOCKET2 and UART/BLE Connector.
#define AVNET_MT3620_SK_GPIO1 AVNET_AESMS_PIN6_GPIO1

// GPIO2 is exposed on SOCKET1, SOCKET2, and UART/BLE Connector.
#define AVNET_MT3620_SK_GPIO2 AVNET_AESMS_PIN7_GPIO2

// GPIO28 is exposed on SOCKET1, SOCKET2, and UART/BLE Connector.
#define AVNET_MT3620_SK_GPIO28 AVNET_AESMS_PIN20_GPIO28

// GPIO26 is exposed on SOCKET1, SOCKET2, and UART/BLE Connector.
#define AVNET_MT3620_SK_GPIO26 AVNET_AESMS_PIN18_GPIO26

// GPIO37 is exposed on SOCKET1, SOCKET2, GROVE Connector, and OLED Display Connector.
#define AVNET_MT3620_SK_GPIO37 AVNET_AESMS_PIN27_GPIO37

// GPIO38 is exposed on SOCKET1, SOCKET2, GROVE Connector, and OLED Display Connector.
#define AVNET_MT3620_SK_GPIO38 AVNET_AESMS_PIN28_GPIO38

// GPIO29 is exposed on UART/BLE Connector.
#define AVNET_MT3620_SK_GPIO29 AVNET_AESMS_PIN21_GPIO29

// GPIO27 is exposed on UART/BLE Connector.
#define AVNET_MT3620_SK_GPIO27 AVNET_AESMS_PIN19_GPIO27

// PWM CONTROLLER 0: channel 0 is exposed on SOCKET1 pin PWM, channel 1 is exposed on: SOCKET2 pin PWM and UART/BLE Connector pin 9, channel 2 is exposed on: SOCKET1 pin INT, SOCKET2 pin INT and UART/BLE Connector pin 7. Pins for this controller are shared with AVNET_MT3620_SK_GPIO0, AVNET_MT3620_SK_GPIO1 and AVNET_MT3620_SK_GPIO2. If this PWM controller is requested, none of these GPIOs can be used.
#define AVNET_MT3620_SK_PWM_CONTROLLER0 AVNET_AESMS_PWM_CONTROLLER0

// PWM CONTROLLER 1: channel 0 is used by Application Status LED, and channel 1 is used by WLAN status LED. Pins for this controller are shared with AVNET_MT3620_SK_APP_STATUS_LED_YELLOW and AVNET_MT3620_SK_WLAN_STATUS_LED_YELLOW. If this PWM controller is requested, none of these GPIOs can be used.
#define AVNET_MT3620_SK_PWM_CONTROLLER1 AVNET_AESMS_PWM_CONTROLLER1

// PWM CONTROLLER 2: channel 0 is used by User LED Red, channel 1 is used by User LED Green, channel 2 is used by User LED Blue. Pins for this controller are shared with AVNET_MT3620_SK_USER_LED_RED, AVNET_MT3620_SK_USER_LED_GREEN, and AVNET_MT3620_SK_USER_LED_BLUE. If this PWM controller is requested, none of these GPIOs can be used.
#define AVNET_MT3620_SK_PWM_CONTROLLER2 AVNET_AESMS_PWM_CONTROLLER2

// ADC CONTROLLER 0: channel 0 is used by Ambient Light Sensor, channel 1 is exposed on SOCKET1 AN, channel 2 is exposed on SOCKET2 AN. Pins for this controller are shared with AVNET_MT3620_SK_GPIO42 and AVNET_MT3620_SK_GPIO43. If this ADC controller is requested, none of these GPIOs can be used.
#define AVNET_MT3620_SK_ADC_CONTROLLER0 AVNET_AESMS_ADC_CONTROLLER0

// ISU0 UART is exposed on SOCKET1, SOCKET2, and UART/BLE Connector. On SOCKET1/2: TX (TX), RX (RX) since RTS/CTS are not exposed, UART0 must be used with software flow control. On UART/BLE Connector: pin1 (CTS), pin2 (TX), pin3 (RX), pin4 (RTS).
#define AVNET_MT3620_SK_ISU0_UART AVNET_AESMS_ISU0_UART

// ISU0 SPI is exposed on UART/BLE Connector: pin 3 (MISO), pin 2 (SCLK), pin 1 (CSA), pin 4 (MOSI).
#define AVNET_MT3620_SK_ISU0_SPI AVNET_AESMS_ISU0_SPI

// ISU0 I2C is exposed on UART/BLE Connector: pin 15 (SDA) and pin 10 (SCL).
#define AVNET_MT3620_SK_ISU0_I2C AVNET_AESMS_ISU0_I2C

// ISU1 UART is exposed on SOCKET1: "MISO" (RX), "SCK" (TX), "CS" (CTS), and "MOSI" (RTS).
#define AVNET_MT3620_SK_ISU1_UART AVNET_AESMS_ISU1_UART

// ISU1 SPI is shared between SOCKET1 and SOCKET2: MISO (MISO), SCK (SCLK), CS (CSA on SOCKET1 and CSB on SOCKET2), and MOSI (MOSI).
#define AVNET_MT3620_SK_ISU1_SPI AVNET_AESMS_ISU1_SPI

// ISU2 I2C is shared between GROVE Connector, OLED DISPLAY Connector, SOCKET1, and SOCKET2. On GROVE Connector: pin 15 (SDA) and pin 10 (SCL). On OLED Display connector: pin 4 (SDA) and pin 3 (SCL). On SOCKET1/2: "MISO" (SDA) and "MOSI" (SCL)
#define AVNET_MT3620_SK_ISU1_I2C AVNET_AESMS_ISU1_I2C

// ISU2 I2C is shared between on-device sensors, GROVE Connector, OLED DISPLAY Connector, SOCKET1, and SOCKET2. On GROVE Connector: pin 15 (SDA) and pin 10 (SCL). On OLED Display connector: pin 4 (SDA) and pin 3 (SCL). On SOCKET1/2: SDA (SDA) and SCL (SCL)
#define AVNET_MT3620_SK_ISU2_I2C AVNET_AESMS_ISU2_I2C

