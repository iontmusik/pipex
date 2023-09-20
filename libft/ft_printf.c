/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:53:24 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/16 13:49:21 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	lst;
	int		i;
	int		j;

	j = 0;
	i = 0;
	va_start (lst, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == '%')
				j += write(1, "%%", 1);
			else
				j += ft_variables(s[i], lst);
		}
		else
			j += write(1, &s[i], 1);
		i++;
	}
	va_end(lst);
	return (j);
}

/* int	main(void)
 {
 	int		a;
 	int		b;
 	char	*c;
 	char 	z;
	
	c = "hola";
 	z = 'r';
 	b = printf("numero: %c, %p\n", z, c);
 	a = ft_printf("numero: %c, %p\n", z, c);
 	printf("mio: %d\nsuyo: %d", b, a);
 } */
