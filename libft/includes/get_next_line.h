/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:40:45 by nofanizz          #+#    #+#             */
/*   Updated: 2025/02/25 13:35:35 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 18
# endif

char	*get_next_line(int fd);
char	*ft_strdup_gnl(const char *s);
size_t	ft_strlen_gnl(const char *str);
void	ft_bzero_gnl(void *s, size_t n);
void	*ft_calloc_gnl(size_t elementCount, size_t elementSize);
int		ft_strchr_gnl(char *str, char c);

#endif