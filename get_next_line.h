/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddutta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:55:12 by ddutta            #+#    #+#             */
/*   Updated: 2023/09/08 21:05:15 by ddutta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

size_t	ft_strlen(const char	*c);
char	*ft_strdup(const char	*s1);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize);
// char	*get_next_line(int	fd);
#endif
