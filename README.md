# Semáforo com Raspberry Pi Pico

Este projeto implementa um semáforo simples utilizando um Raspberry Pi Pico. O semáforo alterna entre as luzes vermelha, amarela e verde em intervalos regulares, simulando o comportamento de um semáforo real.

## Componentes Necessários

- Raspberry Pi Pico
- 3 LEDs (vermelho, amarelo, verde)
- Resistores (220Ω para cada LED)

## Conexões

| LED       | GPIO no Raspberry Pi Pico |
|-----------|---------------------------|
| Vermelho  | GPIO 11                   |
| Amarelo   | GPIO 12                   |
| Verde     | GPIO 13                   |

## Como Funciona

O código utiliza um temporizador para alternar entre as luzes do semáforo a cada 3 segundos. O estado atual do semáforo é impresso no console a cada segundo.

### Estados do Semáforo

1. **Vermelho**: LED vermelho ligado, LEDs amarelo e verde desligados.
2. **Amarelo**: LED amarelo ligado, LEDs vermelho e verde desligados.
3. **Verde**: LED verde ligado, LEDs vermelho e amarelo desligados.

## Uso do add_repeating_timer_ms() e repeating_timer_callback()

O código utiliza duas funções importantes da SDK do Raspberry Pi Pico para criar um temporizador repetitivo: add_repeating_timer_ms() e repeating_timer_callback(). Essas funções são essenciais para controlar a alternância entre os estados do semáforo em intervalos regulares.
add_repeating_timer_ms()

A função add_repeating_timer_ms() é usada para configurar um temporizador que dispara repetidamente em um intervalo de tempo especificado. No código, ela é configurada para chamar a função de callback a cada 3000 milissegundos (3 segundos).
Parâmetros:

**Intervalo de tempo:** O tempo em milissegundos entre cada chamada da função de callback (no caso, 3000 ms).

**Função de callback:** A função que será executada sempre que o temporizador disparar (timer_callback no código).

**Dados adicionais:** Um ponteiro para dados adicionais que podem ser passados para a função de callback (neste caso, NULL, pois não são necessários).

**Estrutura do temporizador:** Uma estrutura do tipo repeating_timer que armazena o estado do temporizador.

## Demonstração no Wokwi

<https://wokwi.com/projects/421622468191194113>
