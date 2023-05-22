/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*  jtorre-s <jtorre-s@student.42madrid.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:56:39 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/22 11:56:39 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stdlib.h>
#include <sys/types.h>

char	*ft_strnstr( char *haystack, char *needle, size_t len);
char	**ft_split_pipex(char const *s, char c);
char    **parsing(char **env);

# endif