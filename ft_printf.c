/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 19:19:10 by egiacomi          #+#    #+#             */
/*   Updated: 2021/10/16 21:01:37 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	ft_display_args(char c, char flag, va_list arg, int *ret)
{
	if (c == 'c')
		ft_putchar(va_arg(arg, int), ret);
	else if (c == 's')
		ft_putstr(va_arg(arg, char *), ret);
	else if (c == 'p')
	{
		ft_putstr("0x", ret);
		ft_putadress(c, va_arg(arg, unsigned long long), ret);
	}
	else if (c == 'u')
		ft_putnbr_u(va_arg(arg, unsigned int), ret, flag);
	else if ((c == 'd') || (c == 'i'))
		ft_putnbr(va_arg(arg, int), ret, flag);
	else if (c == 'x' || (c == 'X'))
		ft_puthexa(c, va_arg(arg, unsigned int), ret, flag);
	else if (c == '%')
		ft_putchar('%', ret);
	else
		ft_putnbr(-1, ret, flag);
}

int	ft_is_arg(char c)
{
	if (ft_strchr(c, "cspdiu%xX"))
		return (1);
	return (0);
}

int	ft_is_flag(char c)
{
	if ((c == '#') || (c == ' ') || (c == '+'))
		return (1);
	return (0);
}

int	ft_protec(const char *toprint)
{
	if (!toprint)
		return (-1);
	return (0);
}

int	ft_printf(const char *toprint, ...)
{
	int		i;
	int		ret;
	char	flag;
	va_list	args_type;

	va_start (args_type, toprint);
	i = 0;
	ret = ft_protec(toprint);
	while (toprint && toprint[i] && (i < ft_strlen(toprint)))
	{
		flag = 0;
		while (toprint[i] != '%' && toprint[i])
			ret += write(1, &toprint[i++], 1);
		if (toprint[i] == '%')
		{
			i++;
			while (ft_is_flag(toprint[i]))
				flag = toprint[i++];
			if (ft_is_arg(toprint[i]))
				ft_display_args(toprint[i++], flag, args_type, &ret);
		}
	}
	va_end (args_type);
	return (ret);
}
