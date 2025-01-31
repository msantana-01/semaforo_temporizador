#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definição dos GPIOs para os LEDs
#define LED_VERDE 11
#define LED_AMARELO 12
#define LED_VERMELHO 13

// Variável global para controlar o estado do semáforo
typedef enum {
    VERMELHO,
    AMARELO,
    VERDE
} Luzes_Semaforo;

Luzes_Semaforo led_atual = VERMELHO;

// Função para desligar todos os LEDs
void desligar_leds() {
    gpio_put(LED_VERMELHO, 0);
    gpio_put(LED_AMARELO, 0);
    gpio_put(LED_VERDE, 0);
}

// Função de callback para o temporizador
bool timer_callback(struct repeating_timer *t) {
    // Desliga todos os LEDs antes de mudar o estado
    desligar_leds();

    // Altera o estado do semáforo
    switch (led_atual) {
        case VERMELHO:
            gpio_put(LED_AMARELO, 1); // Liga o LED amarelo
            led_atual = AMARELO;
            break;
        case AMARELO:
            gpio_put(LED_VERDE, 1); // Liga o LED verde
            led_atual = VERDE;
            break;
        case VERDE:
            gpio_put(LED_VERMELHO, 1); // Liga o LED vermelho
            led_atual = VERMELHO;
            break;
    }

    return true; // Mantém o temporizador ativo
}

int main() {
    // Inicializa a comunicação serial (para imprimir informações)
    stdio_init_all();

    // Configura os GPIOs dos LEDs como saída
    gpio_init(LED_VERMELHO);
    gpio_init(LED_AMARELO);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    // Desliga todos os LEDs no início
    desligar_leds();

    // Liga o LED vermelho inicialmente
    gpio_put(LED_VERMELHO, 1);

    // Configura o temporizador para chamar a função de callback a cada 3000ms
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, timer_callback, NULL, &timer);

    // Loop principal
    while (true) {
        // Imprime o estado atual dos LEDs a cada 1000ms
        switch (led_atual) {
            case VERMELHO:
                printf("LEDs desligados: Amarelo, Verde | LED ligado: Vermelho\n");
                break;
            case AMARELO:
                printf("LEDs desligados: Vermelho, Verde | LED ligado: Amarelo\n");
                break;
            case VERDE:
                printf("LEDs desligados: Vermelho, Amarelo | LED ligado: Verde\n");
                break;
        }

        sleep_ms(1000); // Aguarda 1 segundo
    }

    return 0;
}