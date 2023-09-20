/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:14:01 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/09/18 14:48:49 by jtorre-s         ###   ########.fr       */
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
# include <sys/types.h>
# include <errno.h>
# include "../libft/libft.h"

typedef struct s_pipe
{
	char	**path;
	char	*tmp;
	int		i;
	int		j;
	int		fd_pipe[2];
	int		pid1;
	int		pid2;
	int		status;
}	t_pipe;

void	child_process(char **path, char **av, int *fd_pipe, char **env);
void	child2_process(char **path, char **av, int *fd_pipe, char **env);
char	*search_cmd(char **path, char **cmd, char *av);
void	free_array(char **array);
void	checkpath(char **envp, char **argv, t_pipe *pipex);
void	exit_error(int error, char *msg, int errnum);
void	init_struct(t_pipe *pipex);
char	*check_cmd(char **path, char *command);
int		possible_path(char **envp);

#endif