/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:26:12 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/07 15:46:35 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (ft_strlen((char *)needle) == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[j + i] == needle[j] && needle[j] && j + i < len)
			j++;
		if (!needle[j])
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char	haystack[] = "holqa que tal ";
	char	needle[] = "que";
	int		len;

	len = 10;
	printf("%s", ft_strnstr(haystack, needle, len));
	printf("\n%s", strnstr(haystack, needle, len));
	return (0);
}*/
