/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:25:27 by pthiruma          #+#    #+#             */
/*   Updated: 2023/02/21 13:40:07 by pthiruma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include <stdio.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);

t_list	*ft_get_last_lst(t_list *stash);

void	read_and_stash(int fd, t_list **stash, int *readed_ptr);
void	add_to_stash(t_list **stash, char *buff, int readed_ptr);
void	extract_line(t_list *stash, char **line);
void	cleaned_stash(t_list **stash);
void	free_stash(t_list *stash);
void	generate_line(t_list *stash, char **line);

int		ft_strlen(const char *str);
int		found_newline(t_list *stash);

#endif
