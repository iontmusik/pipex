/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:50:47 by jtorre-s            #+#    #+#             */
/*   Updated: 2023/05/22 10:50:47 by jtorre-s           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

voiod   free_array(char **array)
{
    int i;

    i = 0;
    if (array == NULL)
        return;
    while (i)
}

child_process(int fd, char *cmd1, char *cmd2, int *pip)
{
    char    **cmds;

    cmds = ft_split_pipex(cmd1, ' ');
    /*Esta línea redirige el descriptor de archivo fd al descriptor de 
    archivo estándar de entrada (STDIN_FILENO). Esto significa que la 
    entrada estándar (stdin) del programa se redirige al descriptor 
    de archivo fd. En otras palabras, cualquier lectura desde stdin se
    realizará desde el descriptor de archivo fd en lugar de la entrada
    estándar predeterminada. STDIN_FILENO es una constante que representa
    el descriptor de archivo estándar de entrada, que generalmente tiene 
    el valor de 0.*/ 
    dup2(fd, STDIN_FILENO);
    /*Esta línea redirige el descriptor de archivo pip[1] al descriptor de 
    archivo estándar de salida (STDOUT_FILENO). Esto significa que la salida 
    estándar (stdout) del programa se redirige al descriptor de archivo pip[1]. 
    En otras palabras, cualquier escritura en stdout se enviará al descriptor de 
    archivo pip[1] en lugar de la salida estándar predeterminada. STDOUT_FILENO 
    es una constante que representa el descriptor de archivo estándar de salida, 
    que generalmente tiene el valor de 1.*/
    dup2(pip[1], STDOUT_FILENO);
    close(pip[0]);
    close(fd);
    if (fd == -1)
    {
        free_array(cmds);
        exit(EXIT_FAILURE);
    }
    else if ()
}

void    pipex(int *fd, char *cmd1, char *cmd2, char **path)
{
    pid_t   pid;
    int     pip[2];

    if (pipe(pip) == -1)
    {
        perror("pipe failed");
        exit(EXIT_FAILURE);
    }
    pid = fork();
    if (pid == 0)
        child_process(fd[0], cmd1, path, pip);
    if (pid != 0)
    {
        wait(NULL);
        parent_process(fd[1], cmd2, path, pip);
        free_array(path);
        exit(EXIT_FAILURE);
    }
}

int main(int ac, char **av, char **env)
{
    int     fd[2];
    char    **path;

    if (ac != 5)
        return (ft_printf("error 4 arguments are requiered"));
    fd[0] = open(av[1], O_RDNLY);
    /*O_WRONLY: Esta constante es una bandera utilizada con la función open() y 
    especifica que el archivo se abrirá en modo de escritura solamente (write-only).

    O_TRUNC: Esta constante es otra bandera utilizada con open() y especifica que, 
    si el archivo ya existe, se truncará (se eliminará su contenido) antes de abrirlo.

    O_CREAT: Esta constante es otra bandera utilizada con open() y especifica que,
    si el archivo no existe, se creará.

    0644: Este número representa los permisos de acceso que se asignarán al archivo 
    en caso de que sea creado. En este caso, 0644 indica que el archivo tendrá permisos 
    de lectura y escritura para el propietario, y solo permisos de lectura para otros usuarios.*/
    fd[1] = open(av[4], O_WRONLY | O_TRUNK | O_CREAT, 0644);
    /*La constante F_OK es otra bandera que se puede utilizar con la función access() en C para 
    verificar la existencia de un archivo o directorio. La función access() se utiliza para 
    verificar si un archivo o directorio tiene permisos de lectura, escritura o ejecución.*/
    if (access(av[1], F_OK) == -1)
        ft_printf("no such file or directory : %s\n", av[1]);
    else if (access(av[1], R_OK) == -1)
    /*La constante R_OK es una bandera utilizada con la función access() en C para verificar 
    los permisos de lectura de un archivo o directorio. Se utiliza para comprobar si un archivo 
    o directorio tiene permisos de lectura para el usuario actual.*/
        ft_printf("permission denied : %s\n", av[1]);
    if (access(av[4], W_OK | R_OK) == -1)
        return (ft_printf("permission denied : %s\n", av[1]));
    path = parsing(env);
    if (path == NULL)
        return (ft_printf("environment not found"));
    pipex(fd; av[2], av[3], path);
}