/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 12:02:19 by larlena           #+#    #+#             */
/*   Updated: 2020/11/20 20:56:53 by larlena          ###   ########.fr       */
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
	if (!str)
		str = ft_strdup("");
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
