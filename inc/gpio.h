#include <stdint.h>
#include <stdbool.h>

typedef struct gpio_s * gpio_t;

gpio_t gpioCreate(uint8_t port, uint8_t pin, bool output);
bool gpioGetValue(gpio_t output);
void gpioSetValue(gpio_t output, bool value);
