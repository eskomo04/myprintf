/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Loeschen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 00:53:47 by eskomo            #+#    #+#             */
/*   Updated: 2025/08/10 06:25:10 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int	main(void)
{
	char c = 'A';
    char *str = "Hello, printf!";
    void *ptr = (void *)0xdeadbeef;
    int d = -12345;
    unsigned int u = 4294967295;
    unsigned int x = 3735928559;  // 0xdeadbeef
	int		counter = 0;
	printf("=== Standard printf ===\n");
	printf("Char: %c\n", c);
	printf("String: %s\n", str);
	printf("Pointer: %p\n", ptr);
	printf("Decimal: %d\n", d);
	printf("Integer: %i\n", d);
	printf("Unsigned: %u\n", u);
	printf("Hex lower: %x\n", x);
	printf("Hex upper: %X\n", x);
	printf("Percent sign: %%\n");
	printf("\n=== ft_printftest output ===\n");
	ft_printf("Char: %c", c);
	write(1, "\n", 1);
	ft_printf("String: %s", str);
	write(1, "\n", 1);
	ft_printf("Pointer: %p", ptr);
	write(1, "\n", 1);
	ft_printf("Decimal: %d", d);
	write(1, "\n", 1);
	ft_printf("Integer: %i", d);
	write(1, "\n", 1);
	ft_printf("Unsigned: %u", u);
	write(1, "\n", 1);
	ft_printf("Hex lower: %x", x);
	write(1, "\n", 1);
	ft_printf("Hex upper: %X", x);
	write(1, "\n", 1);
	ft_printf("Percent sign: %%");
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "Print the counter (Retrun of ft_printf)\n", 40);
	counter = ft_printf("Test to count and retrun how many %u char has been printed:68", u);
	write(1, "\n", 1);
	printf("%i\n", counter);

	return (0);
}
