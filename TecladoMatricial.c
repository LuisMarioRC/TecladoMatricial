#include <stdio.h>
#include "pico/stdlib.h"

// Pinos para o primeiro LED RGB

const uint led_pin_rgb1_red   = 2;
const uint led_pin_rgb1_green = 3;
const uint led_pin_rgb1_blue  = 4;

// Pinos para o segundo LED RGB
const uint led_pin_rgb2_red   = 6;
const uint led_pin_rgb2_green = 7;
const uint led_pin_rgb2_blue  = 8;

// Pinos para o terceiro LED RGB
const uint led_pin_green = 11;
const uint led_pin_blue  = 12;
const uint led_pin_red   = 13;

int main()
{
    // Inicializando os pinos para os LEDs comuns
    gpio_init(led_pin_green);
    gpio_set_dir(led_pin_green, GPIO_OUT);
    gpio_init(led_pin_blue);
    gpio_set_dir(led_pin_blue, GPIO_OUT);
    gpio_init(led_pin_red);
    gpio_set_dir(led_pin_red, GPIO_OUT);

    // Inicializando os pinos para o primeiro LED RGB
    gpio_init(led_pin_rgb1_red);
    gpio_set_dir(led_pin_rgb1_red, GPIO_OUT);
    gpio_init(led_pin_rgb1_green);
    gpio_set_dir(led_pin_rgb1_green, GPIO_OUT);
    gpio_init(led_pin_rgb1_blue);
    gpio_set_dir(led_pin_rgb1_blue, GPIO_OUT);

    // Inicializando os pinos para o segundo LED RGB
    gpio_init(led_pin_rgb2_red);
    gpio_set_dir(led_pin_rgb2_red, GPIO_OUT);
    gpio_init(led_pin_rgb2_green);
    gpio_set_dir(led_pin_rgb2_green, GPIO_OUT);
    gpio_init(led_pin_rgb2_blue);
    gpio_set_dir(led_pin_rgb2_blue, GPIO_OUT);

    while (true) {
        // Pisca o LED verde
        gpio_put(led_pin_green, true);
        sleep_ms(900);
        gpio_put(led_pin_green, false);
        sleep_ms(900);

        // Pisca o LED azul
        gpio_put(led_pin_blue, true);
        sleep_ms(600);
        gpio_put(led_pin_blue, false);
        sleep_ms(600);

        // Pisca o LED vermelho
        gpio_put(led_pin_red, true);
        sleep_ms(300);
        gpio_put(led_pin_red, false);
        sleep_ms(300);

        // Pisca o primeiro LED RGB (vermelho)
        gpio_put(led_pin_rgb1_red, true);
        gpio_put(led_pin_rgb1_green, false);
        gpio_put(led_pin_rgb1_blue, false);
        sleep_ms(500);
        gpio_put(led_pin_rgb1_red, false);

        // Pisca o primeiro LED RGB (verde)
        gpio_put(led_pin_rgb1_green, true);
        gpio_put(led_pin_rgb1_red, false);
        gpio_put(led_pin_rgb1_blue, false);
        sleep_ms(500);
        gpio_put(led_pin_rgb1_green, false);

        // Pisca o primeiro LED RGB (azul)
        gpio_put(led_pin_rgb1_blue, true);
        gpio_put(led_pin_rgb1_red, false);
        gpio_put(led_pin_rgb1_green, false);
        sleep_ms(500);
        gpio_put(led_pin_rgb1_blue, false);

        // Pisca o segundo LED RGB (vermelho)
        gpio_put(led_pin_rgb2_red, true);
        gpio_put(led_pin_rgb2_green, false);
        gpio_put(led_pin_rgb2_blue, false);
        sleep_ms(500);
        gpio_put(led_pin_rgb2_red, false);

        // Pisca o segundo LED RGB (verde)
        gpio_put(led_pin_rgb2_green, true);
        gpio_put(led_pin_rgb2_red, false);
        gpio_put(led_pin_rgb2_blue, false);
        sleep_ms(500);
        gpio_put(led_pin_rgb2_green, false);

        // Pisca o segundo LED RGB (azul)
        gpio_put(led_pin_rgb2_blue, true);
        gpio_put(led_pin_rgb2_red, false);
        gpio_put(led_pin_rgb2_green, false);
        sleep_ms(500);
        gpio_put(led_pin_rgb2_blue, false);
    }

    return 0;
}
