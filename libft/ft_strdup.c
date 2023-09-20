/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:21:49 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/07 15:45:49 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*d;
	int		i;

	i = 0;
	d = malloc(ft_strlen(s1) + 1);
	if (d == NULL)
		return (NULL);
	while (s1[i])
	{
		d[i] = s1[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

/*int	main(void)
{
	const char	s1[] = "hola";

	printf("%s\n", ft_strdup(s1));
	printf("%s", strdup(s1));
	return (0);
}

	if (s1 == NULL)
		return (NULL);
*/