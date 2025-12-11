/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvinbobw.co <marvinbobw.co@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:48:04 by rarriola          #+#    #+#             */
/*   Updated: 2025/12/11 15:50:10 by marvinbobw.      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define MAX_FILES 10000

char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strcpy(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		find_newline(char *str);
char	*get_line(char *str, int pos_newline);
char	*get_rest(char *str, int pos_newline);

#endif