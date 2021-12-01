#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>

#define REMOTEX_CONTRACT_VERSION 6

typedef enum __attribute__((packed))
{
    GPIO_OpenAsOutput_c,
    GPIO_OpenAsInput_c,
    GPIO_SetValue_c,
    GPIO_GetValue_c,

    I2CMaster_Open_c,
    I2CMaster_SetBusSpeed_c,
    I2CMaster_SetTimeout_c,
    I2CMaster_Write_c,
    I2CMaster_WriteThenRead_c,
    I2CMaster_Read_c,
    I2CMaster_SetDefaultTargetAddress_c,

    SPIMaster_Open_c,
    SPIMaster_InitConfig_c,
    SPIMaster_SetBusSpeed_c,
    SPIMaster_SetMode_c,
    SPIMaster_SetBitOrder_c,
    SPIMaster_WriteThenRead_c,
    SPIMaster_TransferSequential_c,

    PWM_Open_c,
    PWM_Apply_c,

    ADC_Open_c,
    ADC_GetSampleBitCount_c,
    ADC_SetReferenceVoltage_c,
    ADC_Poll_c,

    Storage_OpenMutableFile_c,
    Storage_DeleteMutableFile_c,

    RemoteX_Write_c,
    RemoteX_Read_c,
    RemoteX_Lseek_c,
    RemoteX_Close_c,
    RemoteX_PlatformInformation_c,

    UART_InitConfig_c,
    UART_Open_c

} SOCKET_CMD;

typedef struct __attribute__((packed))
{
    uint16_t block_length;
    uint16_t response_length;
    SOCKET_CMD cmd;
    bool respond;
    uint8_t contract_version;
} CTX_HEADER;

typedef struct __attribute__((packed))
{
    uint8_t flags;
    uint16_t length;
} SPI_TransferConfig;

// Note the data block sent is variable length but not greater that 4096 and must be the last field in control block
typedef struct __attribute__((packed))
{
    uint8_t data[4096];
} DATA_BLOCK;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    int32_t gpioId;
    uint8_t outputMode;
    uint8_t initialValue;
    int32_t returns;
    int32_t err_no;
} GPIO_OpenAsOutput_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    int32_t gpioId;
    int32_t returns;
    int32_t err_no;
} GPIO_OpenAsInput_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    int32_t gpioFd;
    uint8_t value;
    int32_t returns;
    int32_t err_no;
} GPIO_SetValue_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    int32_t gpioFd;
    uint8_t outValue;
    int32_t returns;
    int32_t err_no;
} GPIO_GetValue_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    int32_t I2C_InterfaceId;
    int32_t returns;
    int32_t err_no;
} I2CMaster_Open_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    int32_t fd;
    uint32_t speedInHz;
    int32_t returns;
    int32_t err_no;
} I2CMaster_SetBusSpeed_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    int32_t fd;
    uint32_t timeoutInMs;
    int32_t returns;
    int32_t err_no;
} I2CMaster_SetTimeout_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    int32_t fd;
    uint8_t address;
    int32_t length;
    int32_t returns;
    int32_t err_no;
    DATA_BLOCK data_block; // Must be the last element in the struct
} I2CMaster_Write_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    int32_t fd;
    uint8_t address;
    uint32_t lenWriteData;
    uint32_t lenReadData;
    int32_t returns;
    int32_t err_no;
    DATA_BLOCK data_block; // Must be the last element in the struct
} I2CMaster_WriteThenRead_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    int32_t fd;
    uint8_t address;
    uint32_t maxLength;
    int32_t returns;
    int32_t err_no;
    DATA_BLOCK data_block; // Must be the last element in the struct
} I2CMaster_Read_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    int32_t fd;
    uint8_t address;
    int32_t returns;
    int32_t err_no;
} I2CMaster_SetDefaultTargetAddress_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    uint32_t pwm;
    int32_t returns;
    int32_t err_no;
} PWM_Open_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    int32_t pwmFd;
    uint32_t pwmChannel;
    uint32_t period_nsec;
    uint32_t dutyCycle_nsec;
    uint32_t polarity;
    bool enabled;
    int32_t returns;
    int32_t err_no;
} PWM_Apply_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    uint32_t id;
    int32_t returns;
    int32_t err_no;
} ADC_Open_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    int32_t fd;
    uint32_t channel;
    int32_t returns;
    int32_t err_no;
} ADC_GetSampleBitCount_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    int32_t fd;
    uint32_t channel;
    float referenceVoltage;
    int32_t returns;
    int32_t err_no;
} ADC_SetReferenceVoltage_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    int32_t fd;
    uint32_t channel;
    uint32_t outSampleValue;
    int32_t returns;
    int32_t err_no;
} ADC_Poll_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    int32_t interfaceId;
    int32_t chipSelectId;
    uint8_t csPolarity;
    uint32_t z__magicAndVersion;
    int32_t returns;
    int32_t err_no;
} SPIMaster_Open_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    uint8_t csPolarity;
    uint32_t z__magicAndVersion;
    int32_t returns;
    int32_t err_no;
} SPIMaster_InitConfig_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    int32_t fd;
    uint32_t speedInHz;
    int32_t returns;
    int32_t err_no;
} SPIMaster_SetBusSpeed_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    int32_t fd;
    uint32_t mode;
    int32_t returns;
    int32_t err_no;
} SPIMaster_SetMode_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    int32_t fd;
    uint32_t order;
    int32_t returns;
    int32_t err_no;
} SPIMaster_SetBitOrder_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    int32_t fd;
    uint32_t lenWriteData;
    uint32_t lenReadData;
    uint32_t order;
    int32_t returns;
    int32_t err_no;
    DATA_BLOCK data_block; // Must be the last element in the struct
} SPIMaster_WriteThenRead_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    uint32_t transferCount;
    uint32_t z__magicAndVersion;
    int32_t returns;
    int32_t err_no;
} SPIMaster_InitTransfers_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    int32_t fd;
    uint32_t transferCount;
    int32_t length;
    int32_t returns;
    int32_t err_no;
    DATA_BLOCK data_block; // Must be the last element in the struct
} SPIMaster_TransferSequential_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    int32_t returns;
    int32_t err_no;
} Storage_OpenMutableFile_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    int32_t returns;
    int32_t err_no;
} Storage_DeleteMutableFile_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    int32_t fd;
    int32_t length;
    int32_t returns;
    int32_t err_no;
    DATA_BLOCK data_block; // Must be the last element in the struct
} RemoteX_Write_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    int32_t fd;
    int32_t length;
    int32_t returns;
    int32_t err_no;
    DATA_BLOCK data_block; // Must be the last element in the struct
} RemoteX_Read_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    int32_t fd;
    off_t offset;
    int32_t whence;
    int32_t returns;
    int32_t err_no;
} RemoteX_Lseek_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    int32_t fd;
    int32_t returns;
    int32_t err_no;
} RemoteX_Close_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    int32_t length;
    int32_t returns;
    int32_t err_no;
    DATA_BLOCK data_block; // Must be the last element in the struct
} RemoteX_PlatformInformation_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    int32_t returns;
    int32_t err_no;
    DATA_BLOCK data_block; // Must be the last element in the struct
} UART_InitConfig_t;

typedef struct __attribute__((packed))
{
    CTX_HEADER header;
    int32_t uartId;
    int32_t returns;
    int32_t err_no;
    DATA_BLOCK data_block; // Must be the last element in the struct
} UART_Open_t;
