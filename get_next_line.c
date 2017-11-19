/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye44@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 13:35:48 by yguaye            #+#    #+#             */
/*   Updated: 2017/11/19 14:18:00 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

static ssize_t	my_get_buffer(t_buffer *buffer)
{

}

int				get_next_line(const int fd, char **line)
{
	static t_buffer	*buffer;
	int				i;

	if (!buff && ((t_buffer *)malloc(sizeof(t_buffer))))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		i = 0;
		while (i < ret)
		{
			
			++i;
		}
	}
	return (ret);
}
