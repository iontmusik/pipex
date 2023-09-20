/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:27:30 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/07 15:46:43 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;
	int		ind;

	s1 = (char *)s1;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	j = (ft_strlen((char *)s1) - 1);
	while (s1[i] && (ft_strchr(set, s1[i])))
		i++;
	while (s1[j] && ft_strchr(set, s1[j]) && j >= i)
		j--;
	ind = 0;
	str = (char *)ft_calloc(j - i + 2, sizeof(char));
	if (!str)
		return (NULL);
	while (i <= j)
		str[ind++] = s1[i++];
	return (str);
}

/*int	main(void)
{
	char	s1[] = "jota quetal jota";
	char	set[] = "jota";

	printf("%s", ft_strtrim(s1, set));
}*/
