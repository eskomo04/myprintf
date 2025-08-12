/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 23:02:55 by eskomo            #+#    #+#             */
/*   Updated: 2025/08/11 01:19:42 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrptr(void *ptr)
{
	int	counter;
	int	p;

	counter = 0;
	if ((void *)ptr == NULL)
		return (ft_putstr_fd(PTRNULL, 1));
	p = write(1, "0x", 2);
	if (p == -1)
		return (-1);
	counter += p;
	p = ft_print_hex((unsigned long long) ptr, 16, 'L');
	if (p == -1)
		return (-1);
	return (counter + p);
}
