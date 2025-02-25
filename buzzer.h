#ifndef BUZZER_H
#define BUZZER_H

#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define BUZZER_PIN 10 // Defina o pino correto para o buzzer

// Frequências de notas para cada sinal
#define SOM_VERMELHO 300 // Som mais grave e forte
#define SOM_AMARELO 800  // Som de alerta
#define SOM_VERDE 1000   // Som mais leve e encorajador

// Inicializa o buzzer configurando o PWM
void buzzer_init() {
    gpio_set_function(BUZZER_PIN, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(BUZZER_PIN);
    pwm_set_enabled(slice, true);
}

// Função para tocar um som no buzzer
void buzzer_tocar(int freq, int duracao_ms) {
    if (freq == 0) {
        pwm_set_gpio_level(BUZZER_PIN, 0);
    } else {
        uint slice = pwm_gpio_to_slice_num(BUZZER_PIN);
        uint clock_div = 4; // Ajuste para obter frequências audíveis
        uint wrap = 125000000 / (clock_div * freq);
        pwm_set_wrap(slice, wrap);
        pwm_set_clkdiv(slice, clock_div);
        pwm_set_gpio_level(BUZZER_PIN, wrap / 2);
    }
    sleep_ms(duracao_ms);
    pwm_set_gpio_level(BUZZER_PIN, 0); // Desliga o som após a duração
}

#endif
