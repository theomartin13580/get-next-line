/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theomart <theomart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:36:44 by theomart          #+#    #+#             */
/*   Updated: 2025/12/06 18:06:33 by theomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s2)
	{
		free(s1);
		return (NULL);
	}
	j = ft_strlen(s1);
	ptr = malloc(sizeof(char) * (j + ft_strlen(s2)) + 1);
	if (!ptr)
	{
		free(s1);
		return (0);
	}
	while (i < j)
	{
		ptr[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
		ptr[j++] = s2[i++];
	ptr[j] = '\0';
	free(s1);
	return (ptr);
}

void	ft_move(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strchr(buffer) + 1;
	while (buffer[i])
	{
		buffer[i] = buffer[i + j];
		i++;
	}
	buffer[i] = '\0';
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!dup)
		return (0);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}