/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 23:58:32 by eskomo            #+#    #+#             */
/*   Updated: 2025/08/10 05:08:38 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digit(long num, int base, char cse)
{
	long	n;
	char	*digit_table;
	int		counter;

	n = num;
	counter = 0;
	digit_table = "0123456789abcdef";
	if (n < 0)
	{
		counter += write(1, "-", 1);
		n = -n;
	}
	if (n >= base)
	{
		ft_print_digit(n / base, base, cse);
	}
	if (cse == 'U' && digit_table[n % base] >= 97
		&& digit_table[n % base] <= 102)
	{
		counter += ft_putchar_fd(digit_table[n % base] - 32, 1);
	}
	else
		counter += ft_putchar_fd(digit_table[n % base], 1);
	return (counter);
}

// int	main(void)
// {
// 	// Decimal
// 	write(1, "255 in Decimal: ", 16);
// 	ft_print_digit(255, 10, 'L');
// 	write(1, "\n", 1);

// 	// Hex lowercase
// 	write(1, "255 in Hex lowercase: ", 22);
// 	ft_print_digit(255, 16, 'L');
// 	write(1, "\n", 1);

// 	// Hex uppercase
// 	write(1, "255 in Hex uppercase: ", 22);
// 	ft_print_digit(255, 16, 'U');
// 	write(1, "\n", 1);

// 	// Binary
// 	write(1, "255 in Binary: ", 15);
// 	ft_print_digit(255, 2, 'L');
// 	write(1, "\n", 1);

// 	// Negative number in decimal
// 	write(1, "-12345 in Negative decimal: ", 28);
// 	ft_print_digit(INT32_MAX, 10, 'L');
// 	write(1, "\n", 1);

// 	// Large hex uppercase
// 	write(1, "48879 in hex uppercase: ", 24);
// 	ft_print_digit(48879, 16, 'U'); // BEEF
// 	write(1, "\n", 1);

// 	return (0);
// }