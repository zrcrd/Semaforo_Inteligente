#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/i2c.h"
#include "font.h"
#include "ssd1306.h"
#include "rgb.h"

// Definições dos pinos para comunicação I2C
#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define ENDERECO 0x3C

ssd1306_t ssd;

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
        printf("%d\n", j);
        
        ssd1306_fill(&ssd, false);
        snprintf(buffer, sizeof(buffer), "%d", j);
        ssd1306_draw_string(&ssd, buffer, 54, 55);

        state(1, 0, 0);
        printf("LED Vermelho ON - PARE\n");
        
        ssd1306_draw_string(&ssd, "Sinal vermelho", 10, 10);
        ssd1306_draw_string(&ssd, "PARE", 54, 30);
        
        ssd1306_send_data(&ssd);
        
        sleep_ms(1000);
    }
}

void contador2() {
    char buffer[10];

    for (int j = 5; j >= 0; j--) {  
        printf("%d\n", j);
        
        ssd1306_fill(&ssd, false);
        snprintf(buffer, sizeof(buffer), "%d", j);
        ssd1306_draw_string(&ssd, buffer, 54, 55);

        state(1, 1, 0);
        printf("LED Amarelo ON - ALERTA\n");
        
        ssd1306_draw_string(&ssd, "Sinal amarelo", 10, 10);
        ssd1306_draw_string(&ssd, "ALERTA", 48, 30);
        
        ssd1306_send_data(&ssd);
        
        sleep_ms(1000);
    }
}

void contador3() {
    char buffer[10];

    for (int j = 30; j >= 0; j--) {
        printf("%d\n", j);
        
        ssd1306_fill(&ssd, false);
        snprintf(buffer, sizeof(buffer), "%d", j);
        ssd1306_draw_string(&ssd, buffer, 54, 55);

        state(0, 1, 0);
        printf("LED Verde ON - PROSSIGA\n");
        
        ssd1306_draw_string(&ssd, "Sinal verde", 20, 10);
        ssd1306_draw_string(&ssd, "PROSSIGA", 40, 30);
        
        ssd1306_send_data(&ssd);
        
        sleep_ms(1000);
    }
}

volatile int estado = 0;

int main() {
    stdio_init_all();
    iniciar_rgb();
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
