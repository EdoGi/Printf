/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 00:29:25 by egiacomi          #+#    #+#             */
/*   Updated: 2021/10/06 14:51:40 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf.h"

void	ft_putstr(char *str, int *ret)
{
	int	i;

	i = 0;
	if (!str)
		ft_putstr("(null)", ret);
	else
	{
		while (str[i])
		{
			ft_putchar(str[i++], ret);
		}
	}
}

void	ft_putnbr(int nbr, int *ret, char flag)
{
	if (flag != 0)
		ft_putflag_nbr(flag, nbr, ret);
	flag = 0;
	if (nbr == INT_MIN)
		return (ft_putstr("-2147483648", ret));
	if (nbr < 0)
	{
		ft_putchar('-', ret);
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr((nbr / 10), ret, flag);
	ft_putchar(((nbr % 10) + 48), ret);
}

void	ft_putnbr_u(unsigned int nbr, int *ret, char flag)
{
	if (flag != 0)
		ft_putflag_nbr(flag, nbr, ret);
	flag = 0;
	if (nbr >= 10)
		ft_putnbr((nbr / 10), ret, flag);
	ft_putchar(((nbr % 10) + 48), ret);
}

void	ft_puthexa(char c, unsigned long nbr, int *ret, char flag)
{
	char			*base;
	unsigned long	n;

	if (flag != 0)
	{
		if (nbr != 0)
			ft_putflag_hexa(c, flag, ret);
		flag = 0;
	}
	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	n = nbr;
	if (n >= 16)
		ft_puthexa(c, (n /= 16), ret, flag);
	ft_putchar(base[nbr % 16], ret);
}

void	ft_putadress(char c, unsigned long long arg, int *ret)
{
	char				*base;
	unsigned long long	n;

	base = "0123456789abcdef";
	n = arg;
	if (n >= 16)
		ft_putadress(c, (n /= 16), ret);
	ft_putchar(base[arg % 16], ret);
}
