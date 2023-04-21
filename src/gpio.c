#include "gpio.h"
#include <stddef.h>
#ifndef USE_STATIC_MEMORY
#include <stdlib.h>
#endif

#ifndef GPIO_COUNT
#define GPIO_COUNT 7
#endif

struct gpio_s
{
    uint8_t port;
    uint8_t pin;
    bool output;
    bool allocated;
};

gpio_t gpioAllocate(void)
{
    static struct gpio_s instances[GPIO_COUNT] = {0};
    gpio_t result = NULL;

    for (int indice=0; indice<GPIO_COUNT; ++indice)
    {
        if (instances[indice].allocated == false)
        {
            result = &instances[indice];
            result->allocated = true;
        }
    }
}


gpio_t gpioCreate(uint8_t port, uint8_t pin, bool output)
{
#ifdef USE_STATIC_MEMORY
    gpio_t result = gpioAllocate();
#else
    gpio_t result = malloc(sizeof(struct gpio_s));
#endif
    result->port = port;
    result->pin = pin;
    result->output = output;

    return result;
}

bool gpioGetValue(gpio_t output)
{
    /*Leer el valor actual*/
    return false;
}

void gpioSetValue(gpio_t output, bool value)
{
    if (output->output == true)
    {
        /*Setear el valor de la salida*/
    }
}