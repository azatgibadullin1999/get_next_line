/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 12:02:19 by larlena           #+#    #+#             */
/*   Updated: 2020/11/18 15:30:09 by larlena          ###   ########.fr       */
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
	while ((read(fd, fl_buf, BUFFER_SIZE)) )
	*line = ft_strdup(str);
	return (0);
}
