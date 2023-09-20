/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:16:59 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/07 15:44:33 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while ((unsigned long)i < n)
	{
		if (str1[i] != str2[i])
		{	
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char	s1[] = "hola que tal";
	char	s2[] = "holq que tal";
	size_t	n;

	n = 6;
	printf("%d\n", ft_memcmp(s1, s2, n));
	printf("%d\n", memcmp(s1, s2, n));
	return (0);
}*/
