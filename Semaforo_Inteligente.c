#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/i2c.h"
#include "hardware/pwm.h"  // Biblioteca para controle PWM do buzzer
#include "font.h"
#include "ssd1306.h"
#include "rgb.h"
#include "buzzer.h"

// Definições dos pinos para comunicação I2C e buzzer
#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define ENDERECO 0x3C
#define BUZZER_PIN 10  // Defina o pino correto do buzzer

ssd1306_t ssd;

// Inicializa o buzzer
void iniciar_buzzer() {
    gpio_set_function(BUZZER_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(BUZZER_PIN);
    pwm_set_wrap(slice_num, 12500);
    pwm_set_enabled(slice_num, true);
}

// Toca uma nota no buzzer
void tocar_buzzer(int freq, int duracao) {
    if (freq == 0) {
        pwm_set_gpio_level(BUZZER_PIN, 0);
    } else {
        uint slice_num = pwm_gpio_to_slice_num(BUZZER_PIN);
        pwm_set_clkdiv(slice_num, 4.0);
        pwm_set_wrap(slice_num, 1250000 / freq);
        pwm_set_gpio_level(BUZZER_PIN, (1250000 / freq) / 2);
    }
    sleep_ms(duracao);
    pwm_set_gpio_level(BUZZER_PIN, 0);
}

// Inicializa o I2C e o display OLED SSD1306
void display() {
    i2c_init(I2C_PORT, 400 * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    ssd1306_init(&ssd, WIDTH, HEIGHT, false, ENDERECO, I2C_PORT);
    ssd1306_config(&ssd);
    ssd1306_send_data(&ssd);

    ssd1306_fill(&ssd, false);
    ssd1306_send_data(&ssd);
}

void contador1() {
    char buffer[10];

    for (int j = 30; j >= 0; j--) {
        snprintf(buffer, sizeof(buffer), "%d", j);
        ssd1306_fill(&ssd, false);
        ssd1306_draw_string(&ssd, "Sinal vermelho", 10, 10);
        ssd1306_draw_string(&ssd, "PARE", 54, 30);
        ssd1306_draw_string(&ssd, buffer, 54, 55);
        ssd1306_send_data(&ssd);
        state(1, 0, 0);

        if (j == 30) {
            for (int q = 4; q >= 0; q--) {
                tocar_buzzer(25, 175);
                tocar_buzzer(2500, 175);
            }
        }
        sleep_ms(1000);
    }
}

void contador2() {
    char buffer[10];

    for (int j = 5; j >= 0; j--) {
        snprintf(buffer, sizeof(buffer), "%d", j);
        ssd1306_fill(&ssd, false);
        ssd1306_draw_string(&ssd, "Sinal amarelo", 10, 10);
        ssd1306_draw_string(&ssd, "ALERTA", 48, 30);
        ssd1306_draw_string(&ssd, buffer, 54, 55);
        ssd1306_send_data(&ssd);
        state(1, 1, 0);

        if (j == 5) {
            for (int q = 3; q >= 0; q--) {
                tocar_buzzer(60, 50);
                tocar_buzzer(2500, 50);
            }
        }
        sleep_ms(1000);
    }
}

void contador3() {
    char buffer[10];

    for (int j = 30; j >= 0; j--) {
        snprintf(buffer, sizeof(buffer), "%d", j);
        ssd1306_fill(&ssd, false);
        ssd1306_draw_string(&ssd, "Sinal verde", 20, 10);
        ssd1306_draw_string(&ssd, "PROSSIGA", 40, 30);
        ssd1306_draw_string(&ssd, buffer, 54, 55);
        ssd1306_send_data(&ssd);
        state(0, 1, 0);

        if (j == 30) {
            tocar_buzzer(25, 120);
            tocar_buzzer(35, 90);
            tocar_buzzer(40, 90);
            tocar_buzzer(45, 90);
            tocar_buzzer(50, 90);
            tocar_buzzer(55, 90);
            tocar_buzzer(60, 90);
            tocar_buzzer(65, 90);
            tocar_buzzer(70, 90);
            tocar_buzzer(75, 90);
            tocar_buzzer(80, 90);
            tocar_buzzer(85, 90);
            tocar_buzzer(90, 90);
        }
        sleep_ms(1000);
    }
}

volatile int estado = 0;

int main() {
    stdio_init_all();
    iniciar_rgb();
    iniciar_buzzer();
    display();

    while (true) {
        switch (estado) {
            case 0:
                contador1();
                estado = 1;
                break;
            case 1:
                contador2();
                estado = 2;
                break;
            case 2:
                contador3();
                estado = 0;
                break;
        }
    }
}
