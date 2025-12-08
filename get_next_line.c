/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 20:54:50 by marvin            #+#    #+#             */
/*   Updated: 2025/12/08 20:54:50 by marvin           ###   ########.fr       */
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *str)
{
	char	*new;
	int		i;

	if (!str)
		return (NULL);
	new = malloc(ft_strlen(str) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strcpy(s2));
	if (!s2)
		return (ft_strcpy(s1));
	new = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	j = -1;
	while(s2[++j])
		new[i + j] = s2[j];
	new[i + j] = '\0';
	free(s1);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*temp;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (find_newline(buffer) == -1)
	{
		temp = malloc(BUFFER_SIZE + 1);
		if (!temp)
			return NULL;
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(temp);
			break;
		}
		temp[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, temp);
		free(temp);
	}
	if (!buffer)
		return (NULL);
	if (find_newline(buffer == -1))
	{
		
	}
	
}