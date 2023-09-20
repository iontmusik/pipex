/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:06:49 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/07 15:41:17 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	long long	num;
	int			j;

	i = 0;
	j = 1;
	num = 0;
	while (str[i] >= 9 & str[i] <= 13 || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - 48;
		if (num > 2147483647 && j == 1)
			return (-1);
		if (num > 2147483648 && j == -1)
			return (0);
		i++;
	}
	return (num = num * j);
}

/*int	main(void)
{
	const char	str[] = "2147445745783649";

	printf("%d", ft_atoi(str));
	printf("\n%d", atoi(str));
	return (0);
}*/
