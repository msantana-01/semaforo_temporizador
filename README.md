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

## Demonstração no Wokwi

<https://wokwi.com/projects/421622468191194113>
