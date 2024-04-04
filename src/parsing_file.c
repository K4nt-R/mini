#include "minishell.h"

char *get_clean_line(char **line);

void	parse (char *line)
{
	char **line_pipe;
	char ***line_split;
	int	i;
	int	 size;

	size = 0;
	line = get_clean_line(&line);
	line_pipe = ft_split(line, '|'); //il faut le free
	while (line_pipe[size] != NULL)
		size++;
	line_split = malloc(sizeof(char **) * size); //a proteger

	i = -1;
	while (line_pipe[++i] != NULL)
		line_split[i] = ft_split(line_pipe[i], ' ');
	printf("%s, %s ,%s, %s\n",line_split[0][0], line_split[0][1], line_split[0][2], line_split[0][3]);
}

char *get_clean_line(char **line) {
	int i;

	i = 0;
	while ((*line)[i]) {
		if (((*line)[i] == '>' && ((*line)[i + 1] != ' ' && (*line)[i + 1] != '>' && (*line)[i + 1] != '\0'))
			|| ((*line)[i] == '<' && ((*line)[i + 1] != ' ' && (*line)[i + 1] != '<' && (*line)[i + 1] != '\0')))
		{
			ft_addspace(line, i);
			i++;
		}
		i++;
	}
	while (i > 0) {
		if (((*line)[i] == '>' && ((*line)[i - 1] != ' ' && (*line)[i - 1] != '>'))
			|| ((*line)[i] == '<' && ((*line)[i - 1] != ' ' && (*line)[i - 1] != '<')))
		{
			ft_addspace_rev(line, i);
			i--;
		}
		i--;
	}
	return (*line);
}

void ft_addspace(char **line, int i)
{
	char *new_line;
	char *temp_line;

	temp_line = ft_calloc(i + 3, sizeof(char));
	ft_memcpy(temp_line, *line, i + 1);
	temp_line[i + 1] = ' ';
	new_line = ft_strjoin(temp_line, *(line) + i + 1);
	free(*line);
	free(temp_line);
	*line = ft_strdup(new_line);
}

void ft_addspace_rev(char **line, int i)
{
	char *new_line;
	char *temp_line;

	temp_line = ft_calloc(i + 2, sizeof(char));
	ft_memcpy(temp_line, *line, i);
	temp_line[i] = ' ';
	new_line = ft_strjoin(temp_line, *(line) + i);
	free(*line);
	free(temp_line);
	*line = ft_strdup(new_line);
}