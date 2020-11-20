/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 12:02:19 by larlena           #+#    #+#             */
/*   Updated: 2020/11/20 23:42:00 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_check_str(char **str, char **line)
{
	char	*p_n;
	char	*buf;

	if ((p_n = ft_strchr(*str, '\n')))
	{
		*p_n = '\0';
		if (!(*line = ft_strdup(*str)))
			return (-1);
		if (!(buf = ft_strdup(++p_n)))
		{
			free(*line);
			return (-1);
		}
		free(*str);
		*str = buf;
		return (1);
	}
	else
	{
		if (!(*line = ft_strdup(*str)))
			return (-1);
		free(*str);
		*str = ft_strdup("");
		return (0);
	}
}

int		get_next_line(int fd, char **line)
{
	size_t		i;
	static char	*str;
	char		buf[BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	if (!str && !(str = ft_strdup("")))
		return (-1);
	if (ft_strchr(str, '\n'))
		return (ft_check_str(&str, line));
	else
	{
		while ((i = read(fd, buf, BUFFER_SIZE)))
		{
			buf[i] = '\0';
			if (!(str = ft_strjoin(&str, buf)))
				return (-1);
			if (ft_strchr(str, '\n'))
				break ;
		}
		return (ft_check_str(&str, line));
	}
}

char	*ft_strjoin(char **s1, char *s2)
{
	char	*dst;
	size_t	len1;
	size_t	len2;

	if (*s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(*s1);
	len2 = ft_strlen(s2);
	if ((dst = malloc(sizeof(char) * (len1 + len2 + 1))) == NULL)
		return (NULL);
	ft_strlcpy(dst, *s1, len1 + 1);
	ft_strlcpy(&dst[len1], s2, len2 + 1);
	free(*s1);
	return (dst);
}
