#include "ft_printf.h"

int main() {
    ft_printf("Hello %s! Your score is %d%%.\n", "Alice", 95);
    ft_printf("Hex: %x, Pointer: %p\n", 255, (void *)0x7ffeed);
    printf("Hello %s! Your score is %d%%.\n", "Alice", 95);
    printf("Hex: %x, Pointer: %p\n", 255, (void *)0x7ffeed);
    return 0;

}
