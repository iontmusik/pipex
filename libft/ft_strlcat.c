/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:23:07 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/07 15:46:00 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len2;
	size_t	len1;
	size_t	cut;
	size_t	res;

	cut = 0;
	len1 = ft_strlen(src);
	if (!dst && !size)
		return (len1);
	len2 = ft_strlen(dst);
	if (size > len2)
	{
		cut = size - len2 - 1;
		res = len2 + len1;
	}
	else
		res = len1 + size;
	i = 0;
	while (i < cut && src[i])
		dst[len2++] = src[i++];
	if (cut)
		dst[len2] = '\0';
	return (res);
}
/*int	main(void)
{
	char	dst[] = "hoftdfc";
	char	src[] = "nasdadadas";
	size_t	dstsize;

	dstsize = 3;
//	printf("%zu\n", ft_strlcat(dst, src, dstsize));
	strlcat(dst, src, dstsize);
	printf("%s\n", dst);
}*/
