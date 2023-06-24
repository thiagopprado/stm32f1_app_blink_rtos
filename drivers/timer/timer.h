/**
 * Author: thiagopereiraprado@gmail.com
 * 
 * @file
 * @defgroup timer STM32F1 timer driver
 * @brief STM32F1 timer driver
 * 
 */
#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

#include "stm32f1xx.h"

typedef void (*timer_callback_t)(void);

typedef enum {
    TIMER_1 = 0,
    TIMER_2,
    TIMER_3,
    TIMER_4,
    TIMER_NR,
} timer_idx_t;

typedef enum {
    TIMER_PWM_CH_1 = 0,
    TIMER_PWM_CH_2,
    TIMER_PWM_CH_3,
    TIMER_PWM_CH_4,
    TIMER_PWM_CH_NR,
} timer_pwm_ch_t;

void timer_setup(timer_idx_t timer, uint32_t psc, uint32_t arr);
void timer_update_psc(timer_idx_t timer, uint32_t psc, uint32_t arr);
void timer_attach_callback(timer_idx_t timer, timer_callback_t callback);
void timer_pwm_setup(timer_idx_t timer, timer_pwm_ch_t pwm_ch);
void timer_pwm_set_duty(timer_idx_t timer, timer_pwm_ch_t pwm_ch, uint32_t ccr);

TIM_TypeDef* timer_get_ptr(timer_idx_t timer);

#endif /* TIMER_H */
