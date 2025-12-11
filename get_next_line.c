/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvinbobw.co <marvinbobw.co@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 20:54:50 by marvin            #+#    #+#             */
/*   Updated: 2025/12/11 15:50:04 by marvinbobw.      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*buffer;
	char		*temp;
	char		*line;
	int			pos;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	if (find_newline(buffer) == -1)
	{
		temp = buffer;
		buffer = NULL;
		return (temp);
	}
	pos = find_newline(buffer);
	line = get_line(buffer, pos);
	temp = get_rest(buffer, pos);
	free(buffer);
	buffer = temp;
	return (line);
}
/* int main()
{
	int	fd;
	fd = open("gnlrd.txt", O_RDONLY);
	for (size_t i = 0; i < 5; i++)
	{
		char *str = get_next_line(fd);
		printf("%s\n",str);
		free(str);
	}
	close(fd);
} */