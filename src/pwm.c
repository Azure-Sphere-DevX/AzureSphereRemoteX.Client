#include "applibs/pwm.h"

int BEGIN_API(ctx_block, PWM_Open, PWM_ControllerId pwm)
{
    ctx_block.pwm = pwm;
    SEND_MSG_WITH_DEFAULTS(PWM_Open, true);
}
END_API(PWM_Open)

int BEGIN_API(ctx_block, PWM_Apply, int pwmFd, PWM_ChannelId pwmChannel, const PwmState *newState)
{
    ctx_block.pwmFd = pwmFd;
    ctx_block.pwmChannel = pwmChannel;
    ctx_block.period_nsec = newState->period_nsec;
    ctx_block.dutyCycle_nsec = newState->dutyCycle_nsec;
    ctx_block.polarity = newState->polarity;
    ctx_block.enabled = newState->enabled;

    SEND_MSG_WITH_DEFAULTS(PWM_Apply, false);
}
END_API(PWM_Apply)