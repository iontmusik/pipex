/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:08:16 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/07 15:41:28 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	if (n != 0)
	{
		ft_memset(s, '\0', n);
	}
}

/*int	main(void)
{
    char	str1[] = "holas";
    char	str2[] = "holas";
	
    ft_bzero(str1, 8);
    printf("%s\n", str1);
    bzero(str2, 8);
    printf("%s\n", str2);
    return (0);
}*/
