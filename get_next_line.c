/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theomart <theomart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:35:01 by theomart          #+#    #+#             */
/*   Updated: 2025/12/06 18:04:54 by theomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];
	int			rd_bytes;

	line = NULL;
	rd_bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		// printf("1 NULL\n");
		return (NULL);
	}
	if (buffer[0] != 0)
	{
		line = ft_strjoin(line, buffer);
		if (!line)
		{
			// printf("2 NULL\n");
			return (NULL);
		}
	}
	while (rd_bytes > 0 && ft_strchr(buffer) == -1)
	{
		rd_bytes = read(fd, buffer, BUFFER_SIZE);
		if (rd_bytes == 0 && line && line[0])
		{
			buffer[0] = 0;
			break ;
		}
		if (rd_bytes == -1)
		{
			free(line);
			buffer[0] = 0;
			// printf("3 NULL\n");
			return (NULL);
		}
		buffer[rd_bytes] = 0;
		line = ft_strjoin(line, buffer);
		if (!line)
		{
			// printf("4 NULL\n");
			return (NULL);
		}
	}
	if (ft_strchr(line) != -1)
		ft_move(buffer);
	if (rd_bytes == 0 && ft_strchr(buffer) == -1)
		buffer[0] = '\0';
	if (line && ft_strchr(line) != -1)
		line[ft_strchr(line) + 1] = 0;
	if (!line || line[0] == '\0')
	{
		free(line);
		// printf("5 NULL\n");
		return (NULL);
	}
	// printf("'%s'", line);
	return (line);
}
