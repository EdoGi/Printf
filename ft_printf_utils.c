/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 01:29:41 by egiacomi          #+#    #+#             */
/*   Updated: 2021/10/06 15:26:44 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *ret)
{
	*ret += write(1, &c, 1);
}

void	ft_putflag_hexa(char c, char flag, int *ret)
{
	if (flag == '#')
	{
		if (c == 'x')
			ft_putstr("0x", ret);
		if (c == 'X')
			ft_putstr("0X", ret);
	}
}

void	ft_putflag_nbr(char flag, int nbr, int *ret)
{
	if (nbr >= 0)
	{
		if (flag == ' ')
			ft_putchar(' ', ret);
		else if (flag == '+')
			ft_putchar('+', ret);
	}
}

int	ft_strchr(char c, char *str)
{
	while (*str)
	{
		if (c == (char)*str)
			return (1);
		str++;
	}
	return (0);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
