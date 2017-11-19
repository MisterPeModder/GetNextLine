/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye44@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 13:35:48 by yguaye            #+#    #+#             */
/*   Updated: 2017/11/19 15:50:39 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

static int	gnl_append_buff(char **line, t_buffer *buff, int to_append)
{
	int		c;

	c = 0;
	while (c < to_append && buff->i + c < BUFF_SIZE)
		if (buff->val[c++] == '\n')
}

int			get_next_line(const int fd, char **line)
{
	static t_buffer	*buff;
	int				ret;
	int				i;

	if (!buff)
	{
		if ((buff = (t_buffer *)malloc(sizeof(t_buffer))))
			return (-1);
		buff->i = 0;
	}
	ret = 1;
	while (ret > 0)
	{
		if (buff->i == 0 && (ret = read(fd, buff->val)))
	}

	while (BUFF_SIZE - buff->i)
	{
		if ((ret = read(fd, buff->val + buff->i, size)) < 0)
			return (-1);
		
	}
	free(*buff);
	return (ret);
}
