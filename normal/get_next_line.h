/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:25:27 by pthiruma          #+#    #+#             */
/*   Updated: 2023/03/08 12:28:30 by pthiruma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#include <stdio.h>

char	*get_next_line(int fd);
char	*ft_new_line(char *static_buffer);
char	*ft_line(char *static_buffer);
char	*read_text(int fd, char *static_buffer);
int     ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif
