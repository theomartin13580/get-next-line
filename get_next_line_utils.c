/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theomart <theomart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:29:38 by theomart          #+#    #+#             */
/*   Updated: 2025/12/03 20:26:43 by theomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	if (!s1 && (!s2 || !s2[0]))
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	ptr = malloc(sizeof(char) * (j + ft_strlen(s2)) + 1);
	if (!ptr)
		return (0);
	while (i < j)
	{
		ptr[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2) && s2[i] != '\n')
		ptr[j++] = s2[i++];
	if (s2[i] == '\n')
		ptr[j++] = '\n';
	ptr[j] = '\0';
	if (s1)
		free(s1);
	return (ptr);
}

int	ft_strchr(const char *s, char c)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, int start, int len)
{
	int		i;
	char	*str;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_calloc(1, 1));
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

void	*ft_memmove(void *dest, const void *src, int n)
{
	int	i;
	int	len;

	len = n;
	i = 0;
	if (!dest && !src)
		return (0);
	while (i < len)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	while (i < ft_strlen(dest))
	{
		((unsigned char *)dest)[i] = '\0';
		i++;
	}
	return (dest);
}
