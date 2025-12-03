/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theomart <theomart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:31:54 by theomart          #+#    #+#             */
/*   Updated: 2025/12/03 20:33:23 by theomart         ###   ########.fr       */
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

	i = 1;
	fd = open("multiple_line_with_nl", O_RDONLY);
	s = get_next_line(fd);
	while (s != NULL)
	{
		__builtin_printf("TEST %d : %s", i, s);
		if (s)
			free(s);
		s = get_next_line(fd);
		i++;
	}
	__builtin_printf("TEST %d : %s", i, s);
	if (s)
		free(s);
	close(fd);
}
