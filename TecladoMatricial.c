#define BUZZER_PIN 22

// Inicialização do buzzer
void init_buzzer() {
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);
    gpio_put(BUZZER_PIN, 0); // Inicialmente desligado
}

void control_devices(char key) {
    // Desliga todos os LEDs e o buzzer
    gpio_put(RED_LED, 0);
    gpio_put(GREEN_LED, 0);
    gpio_put(BLUE_LED, 0);
    gpio_put(BUZZER_PIN, 0);

int main() {
    init_buzzer();    // Inicializa o buzzer
}
