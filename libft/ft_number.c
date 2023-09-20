/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 12:13:30 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/18 16:53:44 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_number(long n)
{
	int		nbr;

	nbr = 0;
	if (n < 0)
	{
		nbr += write(1, "-", 1);
		n *= -1;
	}
	if (n > 9)
		nbr += ft_number(n / 10);
	if (n || (n == 0 && nbr == 0))
		nbr++;
	ft_putchar((n % 10) + 48);
	return (nbr);
}
