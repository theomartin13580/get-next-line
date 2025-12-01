/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theom <theom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:23:46 by theomart          #+#    #+#             */
/*   Updated: 2025/12/01 18:24:26 by theom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "get_next_line.h"

char *ft_strdup(const char *s);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strchr(const char *s, int c);

char	*fill_line(char *f_line, int fd, char *buffer)
{
	int rd_bytes;
	int i;
	char *temp;

	i = 0;
	rd_bytes = 1;
	while (rd_bytes > 0)
	{
		rd_bytes = read(fd, buffer, BUFFER_SIZE);
		if (rd_bytes == -1)
			return (NULL);
		buffer[rd_bytes] = '\0';
		if (!f_line)
			f_line = ft_strdup("");
		temp = f_line;
		__builtin_printf("BUFFER READ: %s", buffer);
		f_line = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;		
	}
	return (f_line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*f_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	f_line = fill_line(f_line, fd, buffer);
	free(buffer);
	return (f_line);
}
