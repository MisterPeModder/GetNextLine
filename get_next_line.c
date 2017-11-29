/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye44@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 13:35:48 by yguaye            #+#    #+#             */
/*   Updated: 2017/11/29 16:05:49 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

static t_buff	*gnl_buff(t_buff **beg, int fd)
{
	t_buff	*buff;

	if (beg && *beg)
	{
		buff = *beg;
		while (buff)
		{
			if (buff->fd == fd)
				return (buff);
			buff = buff->next;
		}
	}
	if (!(buff = (t_buff *)malloc(sizeof(t_buff))))
		return (NULL);
	buff->fd = fd;
	buff->i = -1;
	buff->next = NULL;
	if (beg && *beg)
	{
		buff->next = *beg;
		*beg = buff;
	}
	else
		*beg = buff;
	return (buff);
}

static void		gnl_reset_buff(t_buff *buff)
{
	while (buff->i > 0 && --buff->i >= 0)
		buff->val[buff->i] = 0;
	buff->i = -1;
}

static int		gnl_free_buff(int ret, t_buff **beg, t_buff *buff)
{
	t_buff	*b;

	if (*beg == buff)
		ft_memdel((void **)beg);
	else
	{
		b = *beg;
		while (b->next && b->next != buff)
			b = b->next;
		if (b->next == buff)
		{
			b->next = buff->next;
			free(buff);
		}
	}
	return (ret);
}

static void		gnl_join(t_buff *buff, char **line, int j)
{
	char	*nstr;
	char	*tmp;

	nstr = ft_strsub(buff->val, j, buff->i - j);
	if (*line)
	{
		tmp = ft_strjoin(*line, nstr);
		free(*line);
		*line = tmp;
		free(nstr);
	}
	else
		*line = nstr;
}

int				get_next_line(const int fd, char **line)
{
	static t_buff	*beg;
	t_buff			*buff;
	int				ret;
	int				j;

	if (!(buff = gnl_buff(&beg, fd)))
		return (-1);
	ret = 1;
	*line = NULL;
	while (buff->i != BUFF_SIZE)
	{
		if (buff->i == -1 || buff->i == 0)
			if ((ret = read(fd, buff->val, BUFF_SIZE)) <= 0)
				break ;
		j = ++buff->i;
		while (buff->i < BUFF_SIZE && buff->val[buff->i] != '\n')
			++buff->i;
		gnl_join(buff, line, j);
		printf("i: %d, j: %d", buff->i, j);
		if (buff->i != BUFF_SIZE)
			return (1);
		else if (ret != 0)
			gnl_reset_buff(buff);
	}
	return (gnl_free_buff(ret, &beg, buff));
}
