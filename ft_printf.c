/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsenii <arsenii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:12:41 by arsenii           #+#    #+#             */
/*   Updated: 2023/11/02 18:53:36 by arsenii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

// typedef struct s_print
// {
// 	va_list	args;
// 	int		width;
// 	int		prc;
// 	int		zero;
// 	int		pnt;
// 	int		dash;
// 	int		tl;
// 	int		sign;
// 	int		is_zero;
// 	int		perc;
// 	int		sp;
// }			t_print;

// t_print	*ft_initialize_tab(t_print *tab)
// {
// 	tab->width = 0;
// 	tab->prc = 0;
// 	tab->zero = 0;
// 	tab->pnt = 0;
// 	tab->sign = 0;
// 	tab->tl = 0;
// 	tab->zero = 0;
// 	tab->dash = 0;
// 	tab->perc = 0;
// 	tab->sp = 0;
// 	return (tab);
// }

static void	ft_printf_checker(char specifier, va_list *args, int *len, int *i)
{
	if (specifier == 's')
		ft_string(va_arg(*args, char *), len);
	else if (specifier == 'd' || specifier == 'i')
		ft_number(va_arg(*args, int), len);
	else if (specifier == 'u')
		ft_unsigned_int(va_arg(*args, unsigned int), len);
	else if (specifier == 'x')
		ft_hexadecimal(va_arg(*args, unsigned int), len, 'x');
	else if (specifier == 'X')
		ft_hexedecimal(va_arg(*args, unsigned int), len, 'X');
	else if (specifier == 'p')
		ft_pointer(va_arg(*args, size_t), len);
	else if (specifier == 'c')
		ft_putchar_len(va_arg(*args, int), len);
	else if (specifier == '%')
		ft_putchar_len('%', len);
	else
		(*i)--;
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		length;
	va_list	args;

	i = 0;
	length = 0;
	va_start(args, format);
	while (format[i] != '/0')
	{
		if (format[i] == '%')
		{
			i++;
			ft_printf_checker(format[i], &args, &length, &i);
			i++;
		}
		else
		{
			ft_putchar_len((char)format[i], &length);
			i++;
		}
	}
	va_end(args);
	return (length);
}
