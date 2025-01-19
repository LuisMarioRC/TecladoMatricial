#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"

// Definindo os pinos para as linhas do teclado matricial
#define LINE1 14
#define LINE2 15
#define LINE3 16
#define LINE4 17

// Definindo os pinos para as colunas do teclado matricial
#define COL1 18
#define COL2 19
#define COL3 20
#define COL4 21

// Definindo os pinos para os LEDs RGB
#define RED_LED 2
#define GREEN_LED 3
#define BLUE_LED 10

// Definindo o pino para o buzzer
#define BUZZER_PIN 22

// Mapeamento das teclas para cada posição no teclado 4x4
const char key_mapping[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

// Função para configurar os pinos do teclado matricial
void setup_keypad() {
    // Configura as linhas como saídas
    gpio_init(LINE1); gpio_set_dir(LINE1, GPIO_OUT);
    gpio_init(LINE2); gpio_set_dir(LINE2, GPIO_OUT);
    gpio_init(LINE3); gpio_set_dir(LINE3, GPIO_OUT);
    gpio_init(LINE4); gpio_set_dir(LINE4, GPIO_OUT);

    // Configura as colunas como entradas com resistência pull-down
    gpio_init(COL1); gpio_set_dir(COL1, GPIO_IN); gpio_pull_down(COL1);
    gpio_init(COL2); gpio_set_dir(COL2, GPIO_IN); gpio_pull_down(COL2);
    gpio_init(COL3); gpio_set_dir(COL3, GPIO_IN); gpio_pull_down(COL3);
    gpio_init(COL4); gpio_set_dir(COL4, GPIO_IN); gpio_pull_down(COL4);
}

// Função para detectar a tecla pressionada no teclado matricial
char read_keypad() {
    // Testa cada linha e coluna para verificar a tecla pressionada
    for (int row = 0; row < 4; row++) {
        gpio_put(LINE1, row == 0);
        gpio_put(LINE2, row == 1);
        gpio_put(LINE3, row == 2);
        gpio_put(LINE4, row == 3);

        for (int col = 0; col < 4; col++) {
            // Se uma coluna for lida como alta, significa que a tecla foi pressionada
            if (gpio_get(COL1 + col)) {
                return key_mapping[row][col];
            }
        }
    }
    return '\0'; // Retorna '\0' se nenhuma tecla foi pressionada
}

// Função para configurar os LEDs
void setup_leds() {
    // Configura os pinos dos LEDs como saídas
    gpio_init(RED_LED); gpio_set_dir(RED_LED, GPIO_OUT);
    gpio_init(GREEN_LED); gpio_set_dir(GREEN_LED, GPIO_OUT);
    gpio_init(BLUE_LED); gpio_set_dir(BLUE_LED, GPIO_OUT);

    // Desliga todos os LEDs ao iniciar
    gpio_put(RED_LED, 0);
    gpio_put(GREEN_LED, 0);
    gpio_put(BLUE_LED, 0);
}

// Função para configurar o buzzer
void setup_buzzer() {
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);
    gpio_put(BUZZER_PIN, 0); // Inicialmente desligado
}

// Função para acionar os LEDs conforme a tecla pressionada
void update_leds_and_buzzer(char pressed_key) {
    // Desliga todos os LEDs antes de acionar o novo
    gpio_put(RED_LED, 0);
    gpio_put(GREEN_LED, 0);
    gpio_put(BLUE_LED, 0);

    // Acende o LED correspondente à tecla pressionada
    if (pressed_key == '1') {
        gpio_put(RED_LED, 1);  // Acende o LED vermelho
    } else if (pressed_key == '2') {
        gpio_put(GREEN_LED, 1);  // Acende o LED verde
    } else if (pressed_key == '3') {
        gpio_put(BLUE_LED, 1);  // Acende o LED azul
    } else if (pressed_key == '4') {
        // Ativa o buzzer quando a tecla '4' é pressionada
        gpio_put(BUZZER_PIN, 1);
        sleep_ms(500);  // Buzzer ligado por 500ms
        gpio_put(BUZZER_PIN, 0);
    }
}

int main() {
    stdio_init_all();  // Inicializa a comunicação serial para depuração

    // Configura o teclado, os LEDs e o buzzer
    setup_keypad();
    setup_leds();
    setup_buzzer();

    char current_key = '\0'; // Variável para armazenar a última tecla pressionada

    while (true) {
        // Lê o teclado para verificar se uma tecla foi pressionada
        char key = read_keypad();

        // Atualiza os LEDs e o buzzer apenas se a tecla for diferente da anterior
        if (key != current_key) {
            current_key = key; // Atualiza a tecla pressionada

            // Se uma tecla foi pressionada, atualiza os LEDs e o buzzer
            if (current_key != '\0') {
                update_leds_and_buzzer(current_key);  // Controla os LEDs e o buzzer com base na tecla
            }
        }

        sleep_ms(150);  // Pequeno atraso para evitar múltiplas leituras de uma só tecla
    }

    return 0;
}