/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 13:05:31 by larlena           #+#    #+#             */
/*   Updated: 2020/11/17 14:04:10 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (0);
}


size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src, '\0'));
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src, '\0'));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	start;
	size_t	i;

	i = 0;
	start = 0;
	while (dst[start] != '\0' && start < dstsize)
		start++;
	while (start + i + 1 < dstsize && src[i])
	{
		dst[start + i] = src[i];
		i++;
	}
	if (start != dstsize)
		dst[start + i] = '\0';
	return (start + ft_strlen(src, '\0'));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	len1;
	size_t	len2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1, '\0');
	len2 = ft_strlen(s2, '\0');
	if ((dst = malloc(sizeof(char) * (len1 + len2 + 1))) == NULL)
		return (NULL);
	ft_strlcpy(dst, s1, len1 + 1);
	ft_strlcat(dst, s2, len1 + len2 + 1);
	return (dst);
}


size_t	ft_strlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c)
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*dst;

	if ((dst = malloc(count * size)) == NULL)
		return (NULL);
	ft_memset(dst, '\0', count * size);
	return (dst);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*buf;

	i = 0;
	buf = (unsigned char *)b;
	while (i < len)
	{
		buf[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

// size_t	ft_strlen(char *s)
// {
// 	return (*s ? (1 + ft_strlen(++s)) : 0);
// }