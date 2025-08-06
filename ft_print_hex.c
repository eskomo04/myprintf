/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 23:58:32 by eskomo            #+#    #+#             */
/*   Updated: 2025/08/06 02:51:45 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_hex(unsigned long hex_num)
{
	int		i;
	char	*hex_table;
	char	*num;

	hex_table = "0123456789abcdef";
	if (hex_num == 0)
	{
		write(1, "0", 1);
		return ;
	}
	i = 0;
	while (hex_num > 0)
	{
		num[i] = hex_table[hex_num % 16];
		hex_num /= 16;
		i++;
	}
	while (i != 0)
	{
		write(1, &num[i], 1);
	}
}
