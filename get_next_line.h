/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theomart <theomart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:26:01 by theomart          #+#    #+#             */
/*   Updated: 2025/12/03 20:15:12 by theomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(const char *s, char c);
int		ft_strlen(const char *str);
void	*ft_memmove(void *dest, const void *src, int n);
void	*ft_calloc(int nmemb, int size);
int		ft_endline(char *str);
char	*ft_substr(char const *s, int start, int len);

#endif
