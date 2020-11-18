/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 12:02:19 by larlena           #+#    #+#             */
/*   Updated: 2020/11/18 16:29:37 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	size_t		i;
	char		*buf;
	static char *str;
	char		fl_buf[BUFFER_SIZE + 1];

	i = 0;
	if (str == NULL)
		str = ft_strdup("");
	while (!ft_strchr(str, '\n') && (i = read(fd, fl_buf, BUFFER_SIZE)))
	{
		if (i == (size_t)-1)
			return (i);
		fl_buf[i] = '\0';
		str = ft_strjoin(str, fl_buf);
	}
	if (ft_strchr(str, '\n'))
	{
		i = ft_strlen(str, '\n');
		str[i] = '\0';
		*line = ft_strdup(str);
		buf = ft_strdup(&str[i + 1]);
		free(str);
		str = buf;
		return (1);
	}
	*line = ft_strdup(str);
	return (0);
}
