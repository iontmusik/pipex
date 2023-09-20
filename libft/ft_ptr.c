/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:12:45 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/12 16:35:52 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr(unsigned long n, char *hexa)
{
	int		nbr;

	nbr = 0;
	if (n >= 16)
		nbr += ft_ptr((n / 16), hexa);
	nbr += ft_putchar(hexa[n % 16]);
	return (nbr);
}
