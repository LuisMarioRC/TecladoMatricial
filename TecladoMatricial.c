#define BUZZER 13

void init_leds_and_buzzer() {
    gpio_init(LED_R); gpio_set_dir(LED_R, GPIO_OUT);
    gpio_init(LED_G); gpio_set_dir(LED_G, GPIO_OUT);
    gpio_init(LED_B); gpio_set_dir(LED_B, GPIO_OUT);
    gpio_init(BUZZER); gpio_set_dir(BUZZER, GPIO_OUT);

    gpio_put(LED_R, 0);
    gpio_put(LED_G, 0);
    gpio_put(LED_B, 0);
    gpio_put(BUZZER, 0);
}

void control_leds_and_buzzer(char key) {
    gpio_put(LED_R, 0);
    gpio_put(LED_G, 0);
    gpio_put(LED_B, 0);
    gpio_put(BUZZER, 0);

    switch (key) {
        case 'A':
            gpio_put(LED_R, 1);
            break;
        case 'B':
            gpio_put(LED_G, 1);
            break;
        case 'C':
            gpio_put(LED_B, 1);
            break;
        case '#':
            gpio_put(BUZZER, 1);
            break;
        default:
            break;
    }
}

init_leds_and_buzzer();
