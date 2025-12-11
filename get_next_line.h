/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvinbobw.co <marvinbobw.co@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 20:50:12 by marvin            #+#    #+#             */
/*   Updated: 2025/12/11 15:50:01 by marvinbobw.      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strcpy(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		find_newline(char *str);
char	*get_line(char *str, int pos_newline);
char	*get_rest(char *str, int pos_newline);

#endif