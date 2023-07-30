/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:22:57 by pthiruma          #+#    #+#             */
/*   Updated: 2023/03/22 13:33:35 by pthiruma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main()
{
    int     fd;
    char    *line;

    fd = open("empty.txt", O_RDONLY);
    
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
                break;
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}