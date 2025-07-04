#include "stdint.h"
#include "screen.h"

void main();

#define VGA_MEMORY 0xB8000
#define BLACK 0
#define GREEN 2
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25 

void _start() {
    main();
    
    while(1) {
        asm("hlt");
    }
}

void main() {
    const uint16_t color = (GREEN << 8) | (BLACK << 12); // first 4 bytes: background, then foreground, then character
    volatile uint16_t* vga = (uint16_t*) VGA_MEMORY;

    print_logo(color, vga);


    // uint16_t num = 123;
    // uint16_t out = number_of_digits(num);

    // print_int(out, 1, color, vga);

}
