/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:48:41 by nofanizz          #+#    #+#             */
/*   Updated: 2025/02/25 13:56:56 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin_free(char *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*merged;

	if (!s1)
		return (ft_strdup_gnl(s2));
	merged = ft_calloc_gnl(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1,
			sizeof(char));
	if (!merged)
		return (free(s1), NULL);
	i = -1;
	while (s1[++i])
		merged[i] = s1[i];
	j = -1;
	while (s2[++j])
	{
		merged[i] = s2[j];
		i++;
	}
	return (free(s1), merged);
}

static char	*ft_parse(char *buffer, int fd)
{
	int		length;
	char	*line;

	line = NULL;
	if (ft_strlen_gnl(buffer) > 0)
	{
		line = ft_strdup_gnl(buffer);
		if (!line)
			return (NULL);
	}
	while (!ft_strchr_gnl(buffer, '\n'))
	{
		length = read(fd, buffer, BUFFER_SIZE);
		if (length < 0)
		{
			if (line)
				free(line);
			return (NULL);
		}
		if (length == 0)
			return (line);
		buffer[length] = 0;
		line = ft_strjoin_free(line, buffer);
	}
	return (line);
}

static void	ft_get_remainders(char *remainders)
{
	size_t	i;
	size_t	j;

	j = (size_t)ft_strchr_gnl(remainders, '\n');
	if (!j)
	{
		remainders[0] = 0;
		return ;
	}
	i = 0;
	while (remainders[j + i])
	{
		remainders[i] = remainders[i + j];
		i++;
	}
	remainders[i] = 0;
}

static char	*ft_get_line(char *line)
{
	size_t	i;
	size_t	len;
	char	*res;

	len = (size_t)ft_strchr_gnl(line, '\n');
	if (!len)
		return (line);
	res = ft_calloc_gnl(len + 1, sizeof(char));
	if (!res)
		return (free(line), NULL);
	i = 0;
	while (i < len)
	{
		res[i] = line[i];
		i++;
	}
	return (free(line), res);
}

char	*get_next_line(int fd)
{
	static char	remainders[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_parse(remainders, fd);
	ft_get_remainders(remainders);
	line = ft_get_line(line);
	return (line);
}
