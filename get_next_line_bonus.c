/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarriola <rarriola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:47:58 by rarriola          #+#    #+#             */
/*   Updated: 2025/12/09 12:05:44 by rarriola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	find_newline(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_line(char *str, int pos_newline)
{
	char	*line;
	int		i;

	line = malloc(pos_newline + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (i <= pos_newline)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_rest(char *str, int pos_newline)
{
	if (!str[pos_newline + 1])
		return (NULL);
	return (ft_strcpy(str + pos_newline + 1));
}

static char	*read_buffer(int fd, char *buffer)
{
	char	*temp;
	int		bytes_read;

	while (find_newline(buffer) == -1)
	{
		temp = malloc(BUFFER_SIZE + 1);
		if (!temp)
			return (NULL);
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(temp);
			break ;
		}
		temp[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, temp);
		free(temp);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FILES];
	char		*temp;
	char		*line;
	int			pos;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FILES)
		return (NULL);
	buffer[fd] = read_buffer(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	if (find_newline(buffer[fd]) == -1)
	{
		temp = buffer[fd];
		buffer[fd] = NULL;
		return (temp);
	}
	pos = find_newline(buffer[fd]);
	line = get_line(buffer[fd], pos);
	temp = get_rest(buffer[fd], pos);
	free(buffer[fd]);
	buffer[fd] = temp;
	return (line);
}
