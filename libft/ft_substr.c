/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:28:07 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/07 15:46:50 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;
	size_t		lencom;

	i = 0;
	if (!s)
		return (NULL);
	lencom = ft_strlen(s);
	if (len > lencom)
		len = lencom;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	if (start < lencom)
	{
		while (i < len)
			str[i++] = s[start++];
	}
	str[i] = '\0';
	return (str);
}

/*int	main(void)
{
	char const		s[] = "hola que tal";
	size_t			len;
	unsigned int	start;

	len = 2;
	start = 5;
	printf("%s\n", ft_substr(s, start, len));
	return (0);
}
*/