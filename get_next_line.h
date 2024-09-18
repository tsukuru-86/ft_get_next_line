/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsukuru <tsukuru@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:30:09 by tsukuru           #+#    #+#             */
/*   Updated: 2024/09/18 23:47:18 by tsukuru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE
#endif

size_t ft_strlen(const char *s);
char *ft_strdup(const char *s1);
char *ft_strchr(const char *s, int c);
char *ft_substr(char const *s, unsigned int start, size_t len);




#endif
