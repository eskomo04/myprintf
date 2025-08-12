/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 23:58:32 by eskomo            #+#    #+#             */
/*   Updated: 2025/08/11 01:19:14 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long long n, int base, char cse)
{
	char	*digit_table;
	int		counter;
	int		p;

	counter = 0;
	if (cse == 'L')
		digit_table = "0123456789abcdef";
	else
		digit_table = "0123456789ABCDEF";
	if (n >= (unsigned long long )base)
	{
		p = ft_print_hex(n / base, base, cse);
		if (p == -1)
			return (-1);
		counter += p;
	}
	p = ft_putchar_fd(digit_table[n % base], 1);
	if (p == -1)
		return (-1);
	return (counter + p);
}

// int	main(void)
// {
// 	// Decimal
// 	write(1, "255 in Decimal: ", 16);
// 	ft_print_hex(255, 10, 'L');
// 	write(1, "\n", 1);

// 	// Hex lowercase
// 	write(1, "255 in Hex lowercase: ", 22);
// 	ft_print_hex(255, 16, 'L');
// 	write(1, "\n", 1);

// 	// Hex uppercase
// 	write(1, "255 in Hex uppercase: ", 22);
// 	ft_print_hex(255, 16, 'U');
// 	write(1, "\n", 1);

// 	// Binary
// 	write(1, "255 in Binary: ", 15);
// 	ft_print_hex(255, 2, 'L');
// 	write(1, "\n", 1);

// 	// Negative number in decimal
// 	write(1, "-12345 in Negative decimal: ", 28);
// 	ft_print_hex(INT32_MAX, 10, 'L');
// 	write(1, "\n", 1);

// 	// Large hex uppercase
// 	write(1, "48879 in hex uppercase: ", 24);
// 	ft_print_hex(48879, 16, 'U'); // BEEF
// 	write(1, "\n", 1);

// 	return (0);
// }