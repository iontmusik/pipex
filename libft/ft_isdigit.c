/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:13:57 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/01 17:08:10 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "libft.h"
#include<ctype.h>

int	ft_isdigit(int a)
{
	if (a >= 48 && a <= 57)
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	int	a;

	a = 'g';
	printf("%d", ft_isdigit(a));
	printf("\n%d", isdigit(a));
}*/
