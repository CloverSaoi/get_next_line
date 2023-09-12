/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddutta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:55:03 by ddutta            #+#    #+#             */
/*   Updated: 2023/09/12 21:07:27 by ddutta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*gnl_clean(char **fbuffer)
{
	free(*fbuffer);
	*fbuffer = NULL;
	return (NULL);
}

char	*gnl_read(int fd, char *fbuffer)
{
	char	lbuffer[BUFFER_SIZE + 1];
	char	*temp;
	ssize_t	size;

	while (ft_strchr(fbuffer, '\n') == NULL)
	{
		size = read(fd, lbuffer, BUFFER_SIZE);
		if (size == 0)
			break ;
		if (size == -1)
			return (gnl_clean(&fbuffer));
		lbuffer[size] = '\0';
		temp = ft_strjoin(fbuffer, lbuffer);
		free(fbuffer);
		fbuffer = temp;
	}
	return (fbuffer);
}

char	*gnl_extract(char **buffer)
{
	ssize_t	size;
	char	*temp;
	char	*fbuffer;
	char	*rbuffer;

	fbuffer = *buffer;
	size = ft_strlen(fbuffer) + 1;
	if (ft_strchr(fbuffer, '\n') != NULL)
		size = (ft_strchr(fbuffer, '\n') - fbuffer) + 2;
	rbuffer = malloc(size);
	ft_strlcpy(rbuffer, fbuffer, size);
	if (ft_strchr(fbuffer, '\n') != NULL)
	{
		temp = ft_strdup(ft_strchr(fbuffer, '\n') + 1);
		free(fbuffer);
		fbuffer = temp;
	}
	else
	{
		free(fbuffer);
		fbuffer = NULL;
	}
	*buffer = fbuffer;
	return (rbuffer);
}

char	*get_next_line(int fd)
{
	static char	*fbuffer = NULL;

	if (fbuffer == NULL)
		fbuffer = ft_strdup("");
	fbuffer = gnl_read(fd, fbuffer);
	if (fbuffer == NULL)
		return (NULL);
	if (ft_strlen(fbuffer) == 0)
		return (gnl_clean(&fbuffer));
	return (gnl_extract(&fbuffer));
}
