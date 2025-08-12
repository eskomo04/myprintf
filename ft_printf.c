/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 00:31:32 by eskomo            #+#    #+#             */
/*   Updated: 2025/08/12 02:46:10 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_dedecor(char spcif, va_list arg)
{
	if (spcif == '%')
		return (ft_putchar_fd('%', 1));
	else if (spcif == 'c')
		return (ft_putchar_fd((char)va_arg(arg, int), 1));
	else if (spcif == 's')
		return (ft_putstr_fd(va_arg(arg, char *), 1));
	else if (spcif == 'p')
		return (ft_ptrptr(va_arg(arg, void *)));
	else if (spcif == 'd')
		return (ft_putnbr_fd(va_arg(arg, int), 1));
	else if (spcif == 'i')
		return (ft_putnbr_fd((va_arg(arg, int)), 1));
	else if (spcif == 'u')
		return (ft_print_unsignd_fd((va_arg(arg, unsigned int)), 1));
	else if (spcif == 'x')
		return (ft_print_hex((unsigned long long)(va_arg(arg, unsigned int))
			, 16, 'L'));
	else if (spcif == 'X')
		return (ft_print_hex((unsigned long long)(va_arg(arg, unsigned int))
			, 16, 'U'));
	return (0);
}

int	ft_printf(const char *formstr, ...)
{
	va_list	arg;
	int		counter;
	int		p;

	counter = 0;
	va_start(arg, formstr);
	while (*formstr)
	{
		if (*formstr == '%')
		{
			formstr++;
			p = ft_dedecor(*formstr, arg);
		}
		else
			p = write(1, formstr, 1);
		if (p == -1)
			return (-1);
		counter += p;
		formstr++;
	}
	va_end(arg);
	return (counter);
}
