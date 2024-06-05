/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:14:38 by fmacau            #+#    #+#             */
/*   Updated: 2024/06/05 14:14:42 by fmacau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putunbr(unsigned int u)
{
	int	len;

	len = 0;
	if (u <= 9)
	{
		ft_putstr_char(u + '0');
		len++;
	}
	if (u >= 10)
	{
		len += ft_putnbr(u / 10);
		len += ft_putnbr(u % 10);
	}
	return (len);
}
