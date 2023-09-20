/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:25:05 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/07 15:46:29 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char			*str;
	unsigned char			*str2;
	size_t					i;

	str = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if ((!s1 || !s2) && !n)
		return (0);
	while ((s1[i] || s2[i]) && (i < n))
	{
		if (str[i] != str2[i])
			return (str[i] - str2[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	const char	s1[] = "hola que qtal";
	const char	s2[] = "holaw";
	int			n;

	n = 5;
	printf("%d", ft_strncmp(s1, s2, n));
	printf("\n%d", strncmp(s1, s2, n));
	return (0);
}*/
