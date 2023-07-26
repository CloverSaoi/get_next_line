/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddutta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:55:21 by ddutta            #+#    #+#             */
/*   Updated: 2023/07/26 17:42:28 by ddutta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const	char	*c)
{
	int 	i;

	i = 0;
	while(c[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*s1_dup;

	len = ft_strlen(s1) + 1;
	i = 0;
	s1_dup = malloc(len * sizeof(char));
	while (i < len)
	{
		s1_dup[i] = s1[i];
		i++;
	}
	s1_dup[i] = '\0';
	return (s1_dup);


}

char	*strchr(const char *s, int c)
{
	int i;

	i = 0;
	j = ft_strlen(s);
	if (c == 0)
		return ((char *)(s + j);
	while (i < j)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);	
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*join;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = (char *)malloc(len * sizeof(char));
	if (join == 0)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s1);
	while (i < len && join)
	{
		join[i] = s1[i];
		i++;
	}
	len = ft_strlen(s2);
	while (j < len && join)
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	return (join);

}


