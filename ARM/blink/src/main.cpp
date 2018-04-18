#include "mbed.h"

DigitalOut ld1(LED1);
DigitalOut ld2(LED2);

int main() {
    while(1) {
        ld1 = 1;
        ld2 = 0;
        wait(1);
        ld1 = 0;
        ld2 = 1;
        wait(1);
    }
}
