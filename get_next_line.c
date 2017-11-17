/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:03:15 by yguaye            #+#    #+#             */
/*   Updated: 2017/11/17 17:48:42 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

static int	fill_buff(const int fd, char *buff, size_t *len)
{
	int		ret;
	char	b;

	*len = 0;
	while (*len < BUFF_SIZE && (ret = read(fd, &b, 1)) == 1)
	{
		if (b == '\n')
			return (1);
		buff[(*len)++] = b;
	}
	if (*len == BUFF_SIZE)
		return (2);
	return (ret);
}

static int	append_buffer(char **line, char *buff, size_t len)
{
	char	*newstr;
	size_t	llen;

	llen = *line ? ft_strlen(*line) : 0;
	if (!(newstr = ft_strnew(llen + len)))
		return (0);
	if (*line)
	{
		ft_strcpy(newstr, *line);
		free(*line);
	}
	ft_memcpy(newstr + llen, buff, len);
	*line = newstr;
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE];
	int			ret;
	size_t		len;

	if (!line)
		return (-1);
	*line = NULL;
	while ((ret = fill_buff(fd, buff, &len)) >= 0)
	{
		if (!append_buffer(line, buff, len))
			return (-1);
		if (ret <= 1)
			break ;
	}
	return (ret);
}
