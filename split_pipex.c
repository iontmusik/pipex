static int	ft_cont_lines(char const *s, char c)
{
	int		i;
	int		lines;

	i = 0;
	lines = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			if (i == 0 || s[i - 1] == c)
				lines++;
			i++;
		}
	}
	return (lines);
}

void	ft_free(char **wtf, int point)
{
	int	i;

	i = 0;
	while (i < point)
	{
		free(wtf[i]);
		i++;
	}
}

static int	ft_array(const char *s, int lines, char c, char **wtf)
{
	int	i;
	int	j;
	int	point;

	i = 0;
	point = 0;
	lines = ft_cont_lines(s, c);
	while (s[i] && point < lines)
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		wtf[point++] = ft_substr(s, j, i - j);
		if (wtf[point - 1] == NULL)
		{
			ft_free(wtf, point);
			return (-1);
		}
	}
	return (point);
}

char	**ft_split_pipex(char const *s, char c)
{
	char	**wtf;
	int		lines;
	int		point;

	if (!s)
		return (NULL);
	lines = ft_cont_lines(s, c);
	wtf = malloc(sizeof(char *) * (lines + 1));
	if (wtf == NULL)
		return (NULL);
	point = ft_array(s, lines, c, wtf);
	if (point == -1)
		return (NULL);
	wtf[point] = NULL;
	return (wtf);
}