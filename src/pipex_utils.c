/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:22:25 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/09/18 18:02:02 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	exit_error(int error, char *msg, int errnum)
{
	if (error == 1)
		ft_putstr_fd("Error: 4 arguments are requiered ", 2);
	else if (error == 2)
		perror("Pipe error:");
	else if (error == 3)
		perror("Fork error:");
	else if (error == 4)
		perror("no such file or directory :");
	else if (error == 5)
		msg = ft_strjoin(msg, "no such file or directory:");
	else if (error == 6)
		perror("command not found :");
	else if (error == 7)
		ft_putstr_fd("Command not found:\n", 2);
	exit (errnum);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	*search_cmd(char **path, char **cmd, char *av)
{
	char	*fcmd;

	if (access(cmd[0], X_OK) == 0)
	{
		free_array(path);
		fcmd = ft_strjoin("", cmd[0]);
		return (fcmd);
	}
	if (ft_strchr(cmd[0], '/') && access(cmd[0], X_OK) != 0)
	{
		free_array(cmd);
		free_array(path);
		exit_error(4, av, 127);
	}
	fcmd = check_cmd(path, cmd[0]);
	if (fcmd != NULL)
		return (fcmd);
	free_array(cmd);
	free_array(path);
	exit_error(6, av, 127);
	return (NULL);
}

char	*check_cmd(char **path, char *command)
{
	char	*fcmd;
	int		i;

	i = 0;
	while (path[i])
	{
		fcmd = ft_strjoin(path[i], command);
		if (access(fcmd, X_OK) == 0)
		{
			free_array(path);
			return (fcmd);
		}
		free(fcmd);
		i++;
	}
	return (NULL);
}
