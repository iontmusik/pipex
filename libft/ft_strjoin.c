/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:22:31 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/07 15:45:56 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strconcat(char const *s1, char const *s2)
{
	char	*str;
	int		s1len;
	int		s2len;

	s1len = 0;
	s2len = 0;
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[s1len])
	{
		str[s1len] = s1[s1len];
		s1len++;
	}
	while (s2[s2len])
	{
		str[s1len] = s2[s2len];
		s1len++;
		s2len++;
	}
	str[s1len] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	return (ft_strconcat(s1, s2));
}

/*int	main(void)
{
	const char	s1[] = "hola ";
	const char	s2[] = "que tal";

	printf("%s", ft_strjoin(s1, s2));
	return (0);
}*/
