/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theomart <theomart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:31:54 by theomart          #+#    #+#             */
/*   Updated: 2025/12/06 17:32:06 by theomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*s;
	int		i;

	i = 0;
	fd = open("read_error.txt", O_RDONLY);
	s = "";
	// while (s)
	// {
	// 	s = get_next_line(fd);
	// 	printf("'%s'", s);
	// 	free(s);
	// }
	s = get_next_line(fd);
	// printf("'%s'", s);
	free(s);
	close(fd);
	s = get_next_line(fd);
	printf("'%s'", s);
}
