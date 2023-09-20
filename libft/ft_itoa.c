/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:38:06 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/10 14:25:05 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_digits(unsigned long int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		len ++;
		nbr /= 10;
	}
	return (len);
}

static char	*ft_ul_itoa(unsigned long int nbr, size_t sign)
{
	int		len;
	char	*str;

	len = ft_digits(nbr);
	if (sign)
		len += 1;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str)
	{
		str[0] = '0';
		str[len] = 0;
		if (sign)
			str[0] = '-';
		while (nbr && len > 0)
		{
			len--;
			str[len] = (nbr % 10) + '0';
			nbr /= 10;
		}
	}
	return (str);
}

char	*ft_itoa(int nbr)
{
	int	sign;

	sign = 0;
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nbr < 0)
	{
		sign = 1;
		nbr *= -1;
	}
	return (ft_ul_itoa(nbr, sign));
}

// int	main(void)
// {
// 	int	n;

// 	n = -2147483648;
// 	printf("%s", ft_itoa(n));
// 	return (0);
// }
