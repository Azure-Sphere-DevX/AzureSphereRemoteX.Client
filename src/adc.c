#include "../applibs/adc.h"

int BEGIN_API(ctx_block, ADC_Open, ADC_ControllerId id)
{
    ctx_block.id = id;
    SEND_MSG(ADC_Open_c, sizeof(ADC_Open_t), sizeof(ADC_Open_t), true);
}
END_API(ADC_Open)

int BEGIN_API(ctx_block, ADC_GetSampleBitCount, int fd, ADC_ChannelId channel)
{
    ctx_block.fd = fd;
    ctx_block.channel = channel;
    SEND_MSG(ADC_GetSampleBitCount_c, sizeof(ADC_GetSampleBitCount_t), sizeof(ADC_GetSampleBitCount_t), true);
}
END_API(ADC_GetSampleBitCount)

int BEGIN_API(ctx_block, ADC_SetReferenceVoltage, int fd, ADC_ChannelId channel, float referenceVoltage)
{
    ctx_block.fd = fd;
    ctx_block.channel = channel;
    ctx_block.referenceVoltage = referenceVoltage;
    SEND_MSG(ADC_SetReferenceVoltage_c, sizeof(ADC_SetReferenceVoltage_t), sizeof(ADC_SetReferenceVoltage_t), true);
}
END_API(ADC_SetReferenceVoltage)

int BEGIN_API(ctx_block, ADC_Poll, int fd, ADC_ChannelId channel, uint32_t *outSampleValue)
{
    ctx_block.fd = fd;
    ctx_block.channel = channel;
    SEND_MSG(ADC_Poll_c, sizeof(ADC_Poll_t), sizeof(ADC_Poll_t), true);

    *outSampleValue = ctx_block.outSampleValue;
}
END_API(ADC_Poll)