/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddutta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:55:03 by ddutta            #+#    #+#             */
/*   Updated: 2023/09/08 22:14:18 by ddutta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd)
{
	static char	*fbuffer;
	char 		lbuffer[BUFFER_SIZE + 1];
	char 		*rbuffer;
	ssize_t		size;
	char 		*temp;

	if (fbuffer == NULL)
		fbuffer = ft_strdup("");
	while (ft_strchr(fbuffer, '\n') == NULL)
	{
		size = read(fd, lbuffer, BUFFER_SIZE);
		if (size == 0)
				break;
		if (size == -1)
				return (NULL);
		lbuffer[size] = '\0';
		temp = fbuffer;
		fbuffer = ft_strjoin(fbuffer, lbuffer);
		free(temp);
	}
	size = 0;
	if (ft_strchr(fbuffer, '\n') != NULL)
		size = (ft_strchr(fbuffer, '\n') - fbuffer) + 2;
	if (size == 0 || size == 1)
		size = ft_strlen(fbuffer) + 1;
	rbuffer = malloc(size);
	ft_strlcpy(rbuffer, fbuffer, size);
	temp = fbuffer;
	if (ft_strchr(fbuffer, '\n') != NULL)
		fbuffer = ft_strdup(ft_strchr(fbuffer, '\n') + 1);
	else
		fbuffer = NULL;
	return (rbuffer);
	// We're guaranteed to either have at least a one line in the buffer or end of file.
	//extract
	//	copy first line from fbuffer
	//	remove first line from fbuffer
	
	// return copied first line
}

#include <stdio.h>
#include <fcntl.h>
int main(void)
{
		int chicken;

		chicken = open("hello.txt", O_RDONLY);

		char *achicken;
		achicken = get_next_line(chicken);
		while (achicken)
		{
			printf("%s", achicken);
			free(achicken);
			achicken = get_next_line(chicken);
		}
}
