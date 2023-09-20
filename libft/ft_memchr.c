/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:29:20 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/07 15:43:21 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*d;

	i = 0;
	d = (unsigned char *)s;
	while ((unsigned long)i < n)
	{
		if (d[i] == (unsigned char)c)
			return (&d[i]);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char	s[] = "hola que qtal";
	char	c;
	size_t	n;	

	c = 'e';
	n = 8;
	printf("%s", ft_memchr(s, c, n));
	printf("\n%s", memchr(s, c, n));
	return (0);
}*/
