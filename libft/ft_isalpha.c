/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:12:32 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/07 15:49:00 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int a)
{
	if (a >= 'a' && a <= 'z')
		return (1);
	else if (a >= 'A' && a <= 'Z')
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	int	a;

	a = 'b';
	printf("%c", ft_isalpha(a));
	printf("%c", isalpha(a));
	return (0);
}*/
