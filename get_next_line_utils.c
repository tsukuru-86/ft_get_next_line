/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsukuru <tsukuru@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:43:25 by tsukuru           #+#    #+#             */
/*   Updated: 2024/09/18 23:49:03 by tsukuru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    size_t i;
    i = 0;

    while (s[i])
        i++;
    return i;
}

char	*ft_strchr(const char *s, int c)
{
    while(*s)
    {
        if (*s == c)
            return (char *)s;
        s++;
    }
    if ((char)c == '\0')
        return (char *)s;
    return NULL;
}

char *ft_strdup(const char *s1)
{
    char *str;
    size_t i;

    i = 0;
    str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));

    if (!str)
        return NULL;

    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    str[i] = '\n';
    return str;
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t i;
    char *substr;

    i = 0;

    if(!s || start >= ft_strlen(s))
        return NULL;
        
    if (ft_strlen(s + start) < len)
        len = ft_strlen(s + start);
    
    substr = (char *)malloc(sizeof(char) * (len +1));
    if (!substr)
        return NULL;
    
    while (i < len)
    {
        substr[i] = s[start +i];
        i++;
    }
    substr[i] = '\0';
    return substr;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
    size_t all_len;
    char *space;
    char *temp;

    all_len = ft_strlen(s1) + ft_strlen(s2) + 1;
    space = (char *)malloc(all_len);
    
    temp = space;
    if (!space)
        return NULL;
    while(*s1)
        *temp++ = *s1++;
    while(*s2)
        *temp++ = *s2++;
    *temp = '\0';
    return (space);
}