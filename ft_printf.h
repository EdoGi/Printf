#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *toprint, ...);
void	ft_display_args(char c, char flag, va_list arg, int *ret);
int		ft_is_flag(char c);
void	ft_putflag_hexa(char c, char flag, int *ret);
void	ft_putflag_nbr(char flag, int nbr, int *ret);
int		ft_is_arg(char c);
void	ft_putstr(char *str, int *ret);
void	ft_putnbr(int nbr, int *ret, char flag);
void	ft_putnbr_u(unsigned int nbr, int *ret, char flag);
void	ft_putchar(char c, int *ret);
void	ft_puthexa(char c, unsigned long nbr, int *ret, char flag);
int		ft_strchr(char c, char *str);
void	ft_putadress(char c, unsigned long long arg, int *ret);
int		ft_strlen(const char *str);
int		ft_protec(const char *toprint);

#endif
