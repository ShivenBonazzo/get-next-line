/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvinbobw.co <marvinbobw.co@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:14:44 by rarriola          #+#    #+#             */
/*   Updated: 2025/12/11 15:50:07 by marvinbobw.      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	j = -1;
	while (s2[++j])
		new[i + j] = s2[j];
	new[i + j] = '\0';
	free(s1);
	return (new);
}
