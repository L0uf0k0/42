Attention:
.main.c:

#include "ft_printf.h"
int main() {
	ft_printf("Hello %s! Your score is %d%%.\n", "Alice", 95);
	printf("Hello %s! Your score is %d%%.\n", "Alice", 95);
	ft_printf("Hex: %x, Pointer: %p\n", 255, (void *)0x7ffeed);
	printf("Hex: %x, Pointer: %p\n", 255, (void *)0x7ffeed);

	ft_printf("Hello %s! Your score is %d%%.\n", (char *)NULL, 0x0);
	printf("Hello %s! Your score is %d%%.\n", (char *)NULL, 0x0);
	ft_printf("Hex: %x, Pointer: %p\n", 0x0, (void *)0x0);
	printf("Hex: %x, Pointer: %p\n", 0x0, (void *)0x0);
	return 0;

}
