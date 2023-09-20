/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:53:54 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/09/19 10:48:25 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	init_struct(t_pipe *pipex)
{
	pipex->path = NULL;
	pipex->tmp = NULL;
	pipex->i = -1;
	pipex->j = -1;
}

void	checkpath(char **envp, char **argv, t_pipe *pipex)
{
	if (access(argv[2], X_OK) == 0)
	{
		pipex->tmp = ft_strdup(argv[2]);
		pipex->j = 0;
	}
	if (!*envp && pipex->j != 0)
		exit_error(4, *envp, errno);
	while (!pipex->tmp && envp[++pipex->i])
	{
		if (envp[pipex->i][0] == 'P' && envp[pipex->i][1] == 'A'
		&& envp[pipex->i][2] == 'T' && envp[pipex->i][3] == 'H')
			break ;
	}
	if (!pipex->tmp)
		pipex->tmp = ft_strtrim(envp[pipex->i], "PATH=");
	pipex->path = ft_split(pipex->tmp, ':');
	if (pipex->tmp)
		free(pipex->tmp);
	pipex->i = 0;
	while (pipex->path[pipex->i])
	{
		free(pipex->path[pipex->i]);
		pipex->path[pipex->i] = ft_strjoin(pipex->path[pipex->i], "/");
		pipex->i++;
	}
}

void	child_process(char **path, char **av, int *fd_pipe, char **env)
{
	char	*path_cmd;
	char	**cmd;
	int		fd_input;

	close(fd_pipe[0]);
	fd_input = open(av[1], O_RDONLY);
	if (fd_input == -1)
	{
		free_array(path);
		exit_error(4, av[1], errno);
	}
	dup2(fd_input, STDIN_FILENO);
	close(fd_input);
	dup2(fd_pipe[1], STDOUT_FILENO);
	close(fd_pipe[1]);
	close(fd_pipe[0]);
	cmd = ft_split(av[2], ' ');
	path_cmd = search_cmd(path, cmd, av[2]);
	if (execve(path_cmd, cmd, env) == -1)
	{
		free(path_cmd);
		free_array(cmd);
		exit (errno);
	}
}

void	child2_process(char **path, char **av, int *fd_pipe, char **env)
{
	char	*new_cmd;
	char	**cmd;
	int		fd_output;

	fd_output = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_output == -1)
	{
		free_array(path);
		exit_error(5, av[4], errno);
	}
	dup2(fd_output, STDOUT_FILENO);
	dup2(fd_pipe[0], STDIN_FILENO);
	close(fd_output);
	close(fd_pipe[1]);
	close(fd_pipe[0]);
	cmd = ft_split(av[3], ' ');
	new_cmd = search_cmd(path, cmd, av[3]);
	if (execve(new_cmd, cmd, env) == -1)
	{
		free(new_cmd);
		free_array(cmd);
		exit (errno);
	}
}

static void leaks(void)
{
    system("leaks -q pipex");
}

int	main(int ac, char **av, char **env)
{
	t_pipe	pipex;

	atexit(leaks);
	init_struct(&pipex);
	if (ac != 5)
		exit_error(1, NULL, 1);
	checkpath(env, av, &pipex);
	if (pipe(pipex.fd_pipe) == -1)
		exit_error(2, NULL, errno);
	pipex.pid1 = fork();
	if (pipex.pid1 == -1)
		exit_error(3, NULL, errno);
	if (pipex.pid1 == 0)
		child_process(pipex.path, av, pipex.fd_pipe, env);
	pipex.pid2 = fork();
	if (pipex.pid2 == -1)
		exit_error(3, NULL, errno);
	if (pipex.pid2 == 0)
		child2_process(pipex.path, av, pipex.fd_pipe, env);
	close(pipex.fd_pipe[0]);
	close(pipex.fd_pipe[1]);
	free_array(pipex.path);
	waitpid(pipex.pid1, &pipex.status, 0);
	waitpid(pipex.pid2, &pipex.status, 0);
	return (WEXITSTATUS(pipex.status));
}
