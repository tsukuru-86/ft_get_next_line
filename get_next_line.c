/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsukuru <tsukuru@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:14:49 by tsukuru           #+#    #+#             */
/*   Updated: 2024/08/21 08:20:41 by tsukuru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_to_leftover(int fd, char *leftover)
{
    char *buff;
    int read_bytes;

    buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buff)
        return NULL;
    read_bytes = 1;
    while(!ft_strchr(leftover, '\n') && read_bytes != 0)
    {
        read_bytes = read(fd, buff, BUFFER_SIZE);
        if (read_bytes = -1)
        {
            free (buff);
            return NULL;
        }
        buff[read_bytes] = '\0';
        leftover = ft_strjoin(leftover, buff);
    }
    free(buff);
    return (leftover);
}

char *get_next_line(int fd)
{
    static char *leftover;
    char *line;

    if (fd < 0)
        return (NULL);

    leftover = ft_read_to_leftover(int fd, char *leftover);
    if (!leftover)
        return (NULL);

    line = 1行を確保する関数
    leftover = leftoverの更新
    return (line);
}

