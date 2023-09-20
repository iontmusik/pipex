/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variables.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:14:48 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/18 16:45:09 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_variables(char let, va_list lst)
{
	if (let == 'c')
		return (ft_putchar(va_arg(lst, int)));
	else if (let == 's')
		return (ft_string(va_arg(lst, char *)));
	else if (let == 'd' || let == 'i')
		return (ft_number(va_arg(lst, int)));
	else if (let == 'p')
	{
		write(1, "0x", 2);
		return (ft_ptr(va_arg(lst, unsigned long), "0123456789abcdef") + 2);
	}
	else if (let == 'u')
		return (ft_number_un(va_arg(lst, unsigned int)));
	else if (let == 'x')
		return (ft_hexa(va_arg(lst, unsigned int), "0123456789abcdef"));
	else if (let == 'X')
		return (ft_hexa(va_arg(lst, unsigned int), "0123456789ABCDEF"));
	else if (let == '%')
		return (ft_putchar('%'));
	return (0);
}
