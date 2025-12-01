/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theom <theom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:29:38 by theomart          #+#    #+#             */
/*   Updated: 2025/12/01 18:23:40 by theom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = ft_strlen(s1);
	k = ft_strlen(s2);
	ptr = malloc(sizeof(char) * (j + k) + 1);
	if (!ptr)
		return (0);
	while (i < j)
	{
		ptr[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < k)
	{
		ptr[j] = s2[i];
		i++;
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

int		ft_strchr(const char *s, char c)
{
	int	i;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			write(1, "found\n", 6);
			return (1);
		}
		i++;
		write(1, "char checked\n", 14);
		__builtin_printf("s[%d] = %c\n", i - 1, s[i]);
	}
	write(1, "not found\n", 11);
	return (0);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i;
	char *str;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (0);
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	i = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}