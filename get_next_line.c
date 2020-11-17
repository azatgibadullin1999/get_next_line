/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 12:02:19 by larlena           #+#    #+#             */
/*   Updated: 2020/11/17 14:23:49 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	size_t		i;
	size_t		j;
	static char *str;
	char		*buf;
	char		fl_buf[BUFFER_SIZE + 1];

	i = 0;
	if (str == NULL)
		str = ft_calloc(sizeof(char), 1);
	while ((j = read(fd, fl_buf, BUFFER_SIZE)))
	{
		if (j == -1)
			return (-1);
		fl_buf[j] = '\0';
		str = ft_strjoin(str, fl_buf);
		if (ft_strchr(fl_buf, '\n'))
		{
			i = ft_strlen(str, '\n');
			str[i] = '\0';
			*line = ft_strdup(str);
			buf = ft_strdup(&str[i + 1]);
			free(str);
			str = buf;
			return (1);
		}
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	end;
	size_t	i;

	i = 0;
	end = ft_strlen(s1, '\0') + 1;
	if ((dst = malloc(sizeof(char) * end)) == NULL)
		return (NULL);
	ft_strlcpy(dst, s1, end + 1);
	return (dst);
}
