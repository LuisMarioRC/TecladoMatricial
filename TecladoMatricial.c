#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"

// Definições dos pinos do teclado matricial
#define LINE1 14
#define LINE2 15
#define LINE3 16
#define LINE4 17
#define COL1 18
#define COL2 19
#define COL3 20
#define COL4 21

// Definições dos pinos dos LEDs RGB
#define RED_LED 2
#define GREEN_LED 3
#define BLUE_LED 10

// Definição do pino do buzzer
#define BUZZER_PIN 22

// Mapeamento do teclado matricial
const char key_map[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

// Inicialização do teclado matricial
void init_keypad() {
    // Configurar linhas como saída
    gpio_init(LINE1); gpio_set_dir(LINE1, GPIO_OUT);
    gpio_init(LINE2); gpio_set_dir(LINE2, GPIO_OUT);
    gpio_init(LINE3); gpio_set_dir(LINE3, GPIO_OUT);
    gpio_init(LINE4); gpio_set_dir(LINE4, GPIO_OUT);

    // Configurar colunas como entrada com pull-down
    gpio_init(COL1); gpio_set_dir(COL1, GPIO_IN); gpio_pull_down(COL1);
    gpio_init(COL2); gpio_set_dir(COL2, GPIO_IN); gpio_pull_down(COL2);
    gpio_init(COL3); gpio_set_dir(COL3, GPIO_IN); gpio_pull_down(COL3);
    gpio_init(COL4); gpio_set_dir(COL4, GPIO_IN); gpio_pull_down(COL4);
}

// Leitura da tecla pressionada no teclado matricial
char read_keypad() {
    for (int row = 0; row < 4; row++) {
        gpio_put(LINE1, row == 0);
        gpio_put(LINE2, row == 1);
        gpio_put(LINE3, row == 2);
        gpio_put(LINE4, row == 3);

        for (int col = 0; col < 4; col++) {
            if (gpio_get(COL1 + col)) {
                return key_map[row][col];
            }
        }
    }
    return '\0'; // Nenhuma tecla pressionada
}

// Inicialização dos LEDs
void init_leds() {
    gpio_init(RED_LED); gpio_set_dir(RED_LED, GPIO_OUT);
    gpio_init(GREEN_LED); gpio_set_dir(GREEN_LED, GPIO_OUT);
    gpio_init(BLUE_LED); gpio_set_dir(BLUE_LED, GPIO_OUT);

    // Apagar todos os LEDs no início
    gpio_put(RED_LED, 0);
    gpio_put(GREEN_LED, 0);
    gpio_put(BLUE_LED, 0);
}

// Inicialização do buzzer
void init_buzzer() {
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);
    gpio_put(BUZZER_PIN, 0); // Inicialmente desligado
}

// Controle de LEDs e buzzer com base na tecla pressionada
void control_devices(char key) {
    // Desliga todos os LEDs e o buzzer
    gpio_put(RED_LED, 0);
    gpio_put(GREEN_LED, 0);
    gpio_put(BLUE_LED, 0);
    gpio_put(BUZZER_PIN, 0);

    switch (key) {
        case '1':
            gpio_put(RED_LED, 1);  // Acende o LED vermelho
            break;
        case '2':
            gpio_put(GREEN_LED, 1);  // Acende o LED verde
            break;
        case '3':
            gpio_put(BLUE_LED, 1);  // Acende o LED azul
            break;
        case '4':
            gpio_put(BUZZER_PIN, 1); // Ativa o buzzer
            sleep_ms(500);
            gpio_put(BUZZER_PIN, 0);
            break;
        default:
            break;
    }
}

// Função principal
int main() {
    stdio_init_all(); // Inicializa entrada/saída padrão
    init_keypad();    // Inicializa o teclado matricial
    init_leds();      // Inicializa os LEDs
    init_buzzer();    // Inicializa o buzzer

    char last_key = '\0'; // Armazena a última tecla pressionada

    while (true) {
        char key = read_keypad(); // Lê a tecla pressionada
        if (key != '\0' && key != last_key) { // Se tecla diferente foi pressionada
            last_key = key;
            printf("Tecla pressionada: %c\n", key);
            control_devices(key); // Controla LEDs e buzzer
        }
        sleep_ms(150); // Delay para evitar múltiplas leituras
    }

    return 0;
}
