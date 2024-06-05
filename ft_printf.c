/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:56:32 by fmacau            #+#    #+#             */
/*   Updated: 2024/06/05 14:02:36 by fmacau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_redirect(const char **format, va_list args, int *len)
{
	if (**format == 'c')
		*len += ft_putstr_char(va_arg(args, int));
	else if (**format == 's')
		*len += ft_putstr(va_arg(args, char *));
	else if (**format == 'p')
		*len += ft_putptr(va_arg(args, void *));
	else if (**format == 'd' || **format == 'i')
		*len += ft_putnbr(va_arg(args, int));
	else if (**format == 'u')
		*len += ft_putunbr(va_arg(args, unsigned int));
	else if (**format == 'x')
		*len += ft_puthex(va_arg(args, unsigned int));
	else if (**format == 'X')
		*len += ft_puthe_m(va_arg(args, unsigned int));
	else if (**format == '%')
		*len += write(1, "%", 1);
	else
		*len += write(1, *format, 1);
}

int	ft_vprintf(const char *format, va_list args)
{
	int	len;

	len = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			ft_redirect(&format, args, &len);
		}
		else
		{
			write(1, format, 1);
			len++;
		}
		format++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = ft_vprintf(format, args);
	va_end(args);
	return (len);
}
