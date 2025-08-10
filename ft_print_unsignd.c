/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsignd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 23:29:00 by eskomo            #+#    #+#             */
/*   Updated: 2025/08/10 05:24:04 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsignd_fd(unsigned int n, int fd)
{
	char			c;
	unsigned long	num;
	int				counter;

	counter = 0;
	num = n;
	if (num >= 10)
	{
		ft_print_unsignd_fd(num / 10, fd);
	}
	c = '0' + (num % 10);
	counter += write(fd, &c, 1);
	return (counter);
}
