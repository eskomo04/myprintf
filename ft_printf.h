/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 03:47:40 by eskomo            #+#    #+#             */
/*   Updated: 2025/08/10 05:29:51 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
#define PRINT_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "./libft/libft.h"

int	ft_print_digit(long num, int base, char cse);
int	ft_printf(const char *formstr, ...);
int	ft_print_unsignd_fd(unsigned int n, int fd);

#endif
