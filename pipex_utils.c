#include "pipex.h"

static char	*ft_strconcat(char const *s1, char const *s2)
{
	char	*str;
	int		s1len;
	int		s2len;

	s1len = 0;
	s2len = 0;
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[s1len])
	{
		str[s1len] = s1[s1len];
		s1len++;
	}
	while (s2[s2len])
	{
		str[s1len] = s2[s2len];
		s1len++;
		s2len++;
	}
	str[s1len] = '\0';
	return (str);
}

char	*ft_strjoin_pipex(char const *s1, char const *s2)
{
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	return (ft_strconcat(s1, s2));
}

char	*ft_strnstr( char *haystack, char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (ft_strlen((char *)needle) == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[j + i] == needle[j] && needle[j] && j + i < len)
			j++;
		if (!needle[j])
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}

char    **parsing(char **env)
{
    int     i;
    char    *tmp;
    char    **split;
    char    *path;

    i = 0;
    path = NULL;
    while (env[i] && path == NULL)
    {
        path = ft_strnstr(env[i], "PATH=", 5);
        i++;
    }
    if (path == NULL)
        return (NULL);
    split = ft_split_pipex(path + 5, ':');
    i = 0;
    while (split[i])
    {
        tmp = ft_strjoin_pipex(split[i], "/");
        free(split[i]);
        split[i] = tmp;
        i++;
    }
    return (split);
}