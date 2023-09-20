/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:20:56 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/07 15:46:14 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*str;

	i = 0 ;
	if (!s || !f)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	while (s[i])
	{
		if (!str)
			return (NULL);
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// int	main(void)
// {
// 	const char	s[] = "Awesome Tompedra";

// 	printf("%s", ft_strmapi(i, (*f)s));
// 	return (0);
// }
