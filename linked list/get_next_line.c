/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:30:03 by pthiruma          #+#    #+#             */
/*   Updated: 2023/03/22 14:40:03 by pthiruma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*stash;
	char			*line;
	int				readed_ptr;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
	{
		free_stash(stash);
		stash = NULL;
		return (NULL);
	}
	readed_ptr = 1;
	read_and_stash (fd, &stash, &readed_ptr);
	if (stash == NULL && readed_ptr == 0)
		return (NULL);
	extract_line (stash, &line);
	cleaned_stash (&stash);
	if (line[0] == '\0')
	{
		free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

void	read_and_stash(int fd, t_list **stash, int *readed_ptr)
{
	char	*buff;

	while (!found_newline(*stash) && *readed_ptr != 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return ;
		*readed_ptr = (int)read(fd, buff, BUFFER_SIZE);		
		if (*readed_ptr == -1 || (*stash == NULL && readed_ptr == 0))
		{
			free(buff);
			return ;
		}
		buff[*readed_ptr] = '\0';
		add_to_stash(stash, buff, *readed_ptr);
		free(buff);
	}
}

void	add_to_stash(t_list **stash, char *buff, int readed_ptr)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(t_list) * (readed_ptr + 1));
	if (new_node->content == NULL)
		return ;
	i = 0;
	while (buff[i] && i < readed_ptr)
	{
		new_node->content[i] = buff[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*stash == NULL)
	{
		*stash = new_node;
		return ;
	}
	last = ft_get_last_lst(*stash);
	last->next = new_node;
}

void	extract_line(t_list *stash, char **line)
{
	int	i;
	int	j;

	if (stash == NULL)
		return ;
	generate_line(stash, line);
	if (!line)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

void	cleaned_stash(t_list **stash)
{
	t_list	*last;
	t_list	*cn;
	int		i;
	int		j;

	cn = malloc(sizeof(t_list));
	if (!stash || !cn)
		return ;
	cn->next = NULL;
	last = ft_get_last_lst(*stash);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content[i] == '\n')
		i++;
	cn->content = malloc(sizeof(char) * (ft_strlen(last->content) - i + 1));
	if (!cn->content)
		return ;
	j = 0;
	while (last->content[i])
		cn->content[j++] = last->content[i++];
	cn->content[j] = '\0';
	free_stash(*stash);
	*stash = cn;
}
