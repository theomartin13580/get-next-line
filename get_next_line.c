/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theomart <theomart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:23:46 by theomart          #+#    #+#             */
/*   Updated: 2025/12/01 12:45:25 by theomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer;
	char		*line;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
}

char	*fill_line(char *f_line, int fd, char *buffer)
{
	size_t	fread;
	char	*tmp;

	fread = read(fd, buffer, BUFFER_SIZE);
	while (fread > 0)
	{
	}
	return (f_line)
}
