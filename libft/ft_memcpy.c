/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:05:13 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/07 15:43:39 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	a;

	a = 0;
	if (!src && !dst)
		return (NULL);
	while (a < n)
	{
		((unsigned char *)dst)[a] = ((unsigned char *)src)[a];
		a++;
	}
	return (dst);
}

// int	main(void)
// {
// 	char	src[] = "hola que tal";
// 	char	dst[] = "perico";
// 	size_t	n;

// 	n = 2;
// 	printf("%s", ft_memcpy(dst, src, n));
//  	printf("\n%s", memcpy(dst, src, n));
// 	return (0);
// }
