#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#define Green_LED 11
#define Blue_LED 12
#define Red_LED 13
volatile int estado = 0;

bool semafaro(struct repeating_timer *t);
int main()
{
    stdio_init_all();
    gpio_init(Green_LED);
    gpio_set_dir(Green_LED, GPIO_OUT);
    gpio_init(Red_LED);
    gpio_set_dir(Red_LED, GPIO_OUT);
    gpio_init(Blue_LED);
    gpio_set_dir(Blue_LED, GPIO_OUT);

    struct repeating_timer timer;
    add_repeating_timer_ms(3000, semafaro, NULL, &timer);

    while (true) {
        printf("Temporizador periódico.\n");
        sleep_ms(1000);
    }
}

bool semafaro(struct repeating_timer *t) {
    //Desligar todos os LEDs
    gpio_put(Red_LED, 0);
    gpio_put(Green_LED, 0);
    gpio_put(Blue_LED, 0);
    // ligar dependendo da condição
    if (estado == 0) {
        gpio_put(Red_LED, 1);
    } else if (estado == 1) {
        gpio_put(Blue_LED, 1);
    } else if (estado == 2) {
        gpio_put(Green_LED, 1);
    }
    //atualizar estadp dp semafaro
    estado = (estado + 1) % 3;
    return true;
}
