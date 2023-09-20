/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:27:00 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/07 15:46:39 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		size_s;

	size_s = 0;
	size_s = ft_strlen(s);
	while (size_s >= 0)
	{
		if (s[size_s] == (char) c)
			return ((char *) &s[size_s]);
		size_s--;
	}
	return (NULL);
}

/*int	main(void)
{
	char	s[] = "hola que qtal";
	int		c;

	c = 'q';
	printf("%s", ft_strrchr(s, c));
	printf("\n%s", strrchr(s, c));
	return (0);
}*/
