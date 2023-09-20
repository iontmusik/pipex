/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:56:42 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/16 14:20:04 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_string(char *s);
int		ft_number(long n);
int		ft_number_un(unsigned long n);
int		ft_variables(char let, va_list lst);
int		ft_hexa(unsigned long n, char *hexa);
int		ft_ptr(unsigned long n, char *hexa);
int		ft_printf(const char *s, ...);

#endif