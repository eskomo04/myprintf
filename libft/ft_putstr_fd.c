/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 22:18:34 by eskomo            #+#    #+#             */
/*   Updated: 2025/08/11 01:20:00 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	counter;

	if (s == NULL)
		return (write(1, "(null)", 6));
	counter = write(fd, s, ft_strlen(s));
	if (counter == -1)
		return (-1);
	return (counter);
}
