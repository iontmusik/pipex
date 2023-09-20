/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:55:12 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/18 17:01:08 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_string(char *s)
{
	int	nbr;
	int	i;

	nbr = 0;
	i = 0;
	if (s == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		nbr += write(1, &s[i], 1);
		i++;
	}
	return (nbr);
}
