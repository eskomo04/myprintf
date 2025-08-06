/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 00:31:32 by eskomo            #+#    #+#             */
/*   Updated: 2025/08/06 03:20:21 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

static	void	ft_print_str(char *str)
{
	while (*str)
	{
		write (1, str, 1);
		str++;
	}
}

int	ft_printf(const char *formstr, ...)
{
	va_list	arg;
	char	c;
	char	*s;
	void	*p;
	int		d;
	char	percent;

	va_list(arg, formstr);
	while (*formstr)
	{
		if (*formstr == '%')
		{
			formstr + 1;
			if (*formstr == 'c')
			{
				c = va_arg(arg, char);
				write (1, &c, 1);
			}
			else if (*formstr == 's')
			{
				s = va_arg(arg, char *);
				ft_print_str(s);
			}
			else if (*formstr == 'p')
			{
				p = va_arg(arg, void *);
				ft_print_hex((unsigned long)p);
			}
			else if (*formstr == 'd')
			{
				d = va_arg(arg, int);
				
			}
			else if (*formstr == 'i')
			{
				i = va_arg(arg, int);
				//print
			}
			else if (*formstr == 'u')
			{
				u = va_arg(arg, unsigned int);
				//print
			}
			else if (*formstr == 'x')
			{
				x = va_arg(arg, /**/);
				//print hexa in Lowercase
			}
			else if (*formstr == 'X')
			{
				X = va_arg(arg, /**/);
				//print hexa in Uppercase
			}
			else if (*formstr == '%')
			{
				percent = va_arg(arg, char);
				write(1, &percent, 1);
			}
		}
		else
			write (1, *formstr, 1);
		formstr + 1;
	}
	va_end(arg);
}
