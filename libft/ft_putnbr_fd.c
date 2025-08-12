/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 22:32:17 by eskomo            #+#    #+#             */
/*   Updated: 2025/08/12 03:12:17 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(long n, int fd)
{
	char	c;
	int		counter;
	int		p;

	counter = 0;
	if (n < 0)
	{
		if (write(fd, "-", 1) == -1)
			return (-1);
		counter++;
		n = -n;
	}
	if (n >= 10)
	{
		p = ft_putnbr_fd(n / 10, fd);
		if (p == -1)
			return (-1);
		counter += p;
	}
	c = '0' + (n % 10);
	p = write(fd, &c, 1);
	if (p == -1)
		return (-1);
	counter += p;
	return (counter);
}
