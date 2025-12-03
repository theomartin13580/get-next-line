/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theomart <theomart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:23:46 by theomart          #+#    #+#             */
/*   Updated: 2025/12/03 20:35:04 by theomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	test(char *s, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		s[i] = '\0';
		i++;
	}
}

char	*fill_line(char *f_line, int fd, char *buffer)
{
	int	rd_bytes;

	rd_bytes = 1;
	while (rd_bytes > 0 && !ft_endline(f_line))
	{
		if (!buffer[0])
			rd_bytes = read(fd, buffer, BUFFER_SIZE);
		if (rd_bytes == 0)
			return (f_line);
		if (rd_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		f_line = ft_strjoin(f_line, buffer);
		if (ft_strlen(f_line) >= ft_strlen(buffer) && !ft_endline(buffer))
			test(buffer, BUFFER_SIZE);
	}
	return (f_line);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*f_line;
	char		*tmp;

	f_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = (char *)ft_calloc((BUFFER_SIZE + 1), 1);
	if (!buffer)
		return (NULL);
	f_line = fill_line(f_line, fd, buffer);
	if (!f_line)
	{
		free(buffer);
		return (f_line);
	}
	tmp = ft_substr(f_line, 0, ft_strchr(f_line, '\n') + 1);
	ft_memmove(buffer, buffer + ft_strchr(buffer, '\n') + 1, ft_strlen(buffer)
		- ft_strchr(buffer, '\n'));
	if (f_line)
		free(f_line);
	return (tmp);
}

void	*ft_calloc(int nmemb, int size)
{
	unsigned char	*ptr;
	int				i;

	i = 0;
	if (!size || !nmemb)
	{
		ptr = malloc(0);
		if (!ptr)
			return (0);
		return (ptr);
	}
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (0);
	while (i < nmemb * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

int	ft_endline(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
