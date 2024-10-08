/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsukuru <tsukuru@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:14:49 by tsukuru           #+#    #+#             */
/*   Updated: 2024/10/08 16:52:14 by tsukuru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

static char	*ft_read_to_leftover(int fd, char *leftover)
{
    char *buff;
    char *temp;
    int read_bytes;

    buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buff)
        return NULL;
    read_bytes = 1;
    while((!leftover || !ft_strchr(leftover, '\n')) && read_bytes > 0){
        read_bytes = read(fd, buff, BUFFER_SIZE);
        if (read_bytes <= 0)
        {
            break;
        }
        buff[read_bytes] = '\0';
        
        temp = ft_strjoin(leftover, buff);
        if (!temp){
            free(buff);
            return NULL;
        }
        if (leftover)
            free(leftover);
        leftover = temp;
    }
    free(buff);
    return (leftover);
}

char *ft_get_line(char *leftover)
{
    int i = 0;
    char *line;

    if(!leftover)
        return NULL;

    while(leftover[i] && leftover[i] != '\n')
        i++;

    line = (char *)malloc(sizeof(char) * (i + 2));
    if(!line)
        return NULL;
    
    i = 0;
    while(leftover[i] && leftover[i] != '\n'){       
        line[i] = leftover[i];
        i++;
    }
    if(leftover[i] == '\n'){
        line[i] = leftover[i];
        i++;
    }
    line[i] = '\0';
    return line;
}

static char *ft_new_leftover(char *leftover){
    int i = 0;
    int j = 0;
    char *new_leftover = NULL;

    if (!leftover){
        // free(leftover);
        return NULL;        
    }
    while (leftover[i] && leftover[i] != '\n')
        i++;
    new_leftover = (char *)malloc(sizeof(char) * (ft_strlen(leftover) - i));
    if(!new_leftover)
        return NULL;
    i++;
    while (leftover[i])
        new_leftover[j++] = leftover[i++];
    new_leftover[j] = '\0';
    free(leftover);
    return new_leftover;
}

char *get_next_line(int fd)
{
    static char *leftover;
    char *line;

    //if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    leftover = ft_read_to_leftover(fd, leftover);
    if (!leftover || leftover[0] == '\0'){
        free(leftover);
        leftover = NULL;
        return (NULL);        
    }
    line = ft_get_line(leftover);
    leftover = ft_new_leftover(leftover);
    return (line);
}
