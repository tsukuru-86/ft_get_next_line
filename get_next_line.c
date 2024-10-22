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

// #include "get_next_line.h"

// char	*ft_connect(int fd, char *buff, char *temp, char **leftover)
// {
// 	int	read_bytes;

// 	read_bytes = 1;
// 	while ((!(*leftover) || !ft_strchr(*leftover, '\n')) && read_bytes > 0)
// 	{
// 		read_bytes = read(fd, buff, BUFFER_SIZE);
// 		if (read_bytes == -1)
// 		{
// 			free(buff);
// 			if (*leftover)
// 			{
// 				free(*leftover);
// 				*leftover = NULL;
// 			}
// 			return (NULL);
// 		}
// 		if (read_bytes == 0)
// 			break ;
// 		buff[read_bytes] = '\0';
// 		if (*leftover == NULL)
// 			temp = ft_strdup(buff);
// 		else
// 			temp = ft_strjoin(*leftover, buff);
// 		if (!temp)
// 		{
// 			free(buff);
// 			return (NULL);
// 		}
// 		if (*leftover)
// 			free(*leftover);
// 		*leftover = temp;
// 	}
// 	free(buff);
// 	return (*leftover);
// }

// char	*ft_get_line(char *leftover)
// {
// 	int		i;
// 	char	*line;

// 	i = 0;
// 	if (!leftover)
// 		return (NULL);
// 	while (leftover[i] && leftover[i] != '\n')
// 		i++;
// 	line = (char *)malloc(sizeof(char) * (i + 2));
// 	if (!line)
// 		return (NULL);
// 	i = 0;
// 	while (leftover[i] && leftover[i] != '\n')
// 	{
// 		line[i] = leftover[i];
// 		i++;
// 	}
// 	if (leftover[i] == '\n')
// 	{
// 		line[i] = leftover[i];
// 		i++;
// 	}
// 	line[i] = '\0';
// 	return (line);
// }

// static char	*ft_new_leftover(char *leftover)
// {
// 	int		i;
// 	char	*new_leftover;

// 	i = 0;
// 	if (!leftover)
// 		return (NULL);
// 	while (leftover[i] && leftover[i] != '\n')
// 		i++;
// 	if (leftover[i] == '\0')
// 	{
// 		free(leftover);
// 		return (NULL);
// 	}
// 	i++;
// 	new_leftover = ft_strdup(leftover + i);
// 	if (!new_leftover)
// 	{
// 		free(leftover);
// 		return (NULL);
// 	}
// 	free(leftover);
// 	return (new_leftover);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*leftover;
// 	char		*line;
// 	char		*buff;
// 	char		*temp;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 	{
// 		if (leftover)
// 		{
// 			free(leftover);
// 			leftover = NULL;
// 		}
// 		return (NULL);
// 	}
// 	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (!buff)
// 		return (NULL);
// 	temp = NULL;
// 	if (!(ft_connect(fd, buff, temp, &leftover)))
// 		return (NULL);
// 	if (leftover[0] == '\0')
// 	{
// 		free(leftover);
// 		leftover = NULL;
// 		return (NULL);
// 	}
// 	line = ft_get_line(leftover);
// 	leftover = ft_new_leftover(leftover);
// 	return (line);
// }

#include "get_next_line.h"

char	*ft_read_error(char *buff, char **leftover)
{
	free(buff);
	if (*leftover)
	{
		free(*leftover);
		*leftover = NULL;
	}
	return (NULL);
}

char	*ft_connect(int fd, char *buff, char *temp, char **leftover)
{
	int	read_bytes;

	read_bytes = 1;
	while ((!(*leftover) || !ft_strchr(*leftover, '\n')) && read_bytes > 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
			return (ft_read_error(buff, leftover));
		if (read_bytes == 0)
			break ;
		buff[read_bytes] = '\0';
		if (*leftover == NULL)
			temp = ft_strdup(buff);
		else
			temp = ft_strjoin(*leftover, buff);
		if (!temp)
			return (ft_read_error(buff, leftover));
		free(*leftover);
		*leftover = temp;
	}
	free(buff);
	return (*leftover);
}

char	*ft_get_line(char *leftover)
{
	int		i;
	char	*line;

	i = 0;
	if (!leftover)
		return (NULL);
	while (leftover[i] && leftover[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (leftover[i] && leftover[i] != '\n')
	{
		line[i] = leftover[i];
		i++;
	}
	if (leftover[i] == '\n')
	{
		line[i] = leftover[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_new_leftover(char *leftover)
{
	int		i;
	char	*new_leftover;

	i = 0;
	if (!leftover)
		return (NULL);
	while (leftover[i] && leftover[i] != '\n')
		i++;
	if (leftover[i] == '\0')
	{
		free(leftover);
		return (NULL);
	}
	i++;
	new_leftover = ft_strdup(leftover + i);
	if (!new_leftover)
	{
		free(leftover);
		return (NULL);
	}
	free(leftover);
	return (new_leftover);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*buff;
	char	*temp;
	static char	*leftover;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_read_error(NULL, &leftover));
	// {
	// 	if (leftover)
	// 	{
	// 		free(leftover);
	// 		leftover = NULL;
	// 	}
	// 	return (NULL);
	// }
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	temp = NULL;
	if (!(ft_connect(fd, buff, temp, &leftover)))
		return (NULL);
	if (leftover[0] == '\0')
		return (ft_read_error(NULL, &leftover));
	// {
	// 	free(leftover);
	// 	leftover = NULL;
	// 	return (NULL);
	// }
	line = ft_get_line(leftover);
	leftover = ft_new_leftover(leftover);
	return (line);
}
