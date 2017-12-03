/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 14:46:00 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/03 10:43:41 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

static t_buff    *gnl_buff(t_buff **beg, int fd)
{
	t_buff    *buff;

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
	buff->lsiz=0;
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

static int        gnl_reset_or_read(t_buff *buff, int *ret, int fd, int sread)
{
	if (sread)
	{
		if(buff->i == -1 || buff->i == 0)
		{
			if ((*ret = read(fd, buff->val, BUFF_SIZE)) <= 0)
				return (1);
			buff->lsiz = *ret;
		}
	}
	else if (!REACHED_END(buff))
	{
		while (buff->i > 0 && --buff->i >= 0)
			buff->val[buff->i] = 0;
		buff->i = -1;
	}
	return (REACHED_END(buff));
}

static int        gnl_free_buff(int ret, t_buff **beg, t_buff *buff)
{
	t_buff    *b;

	ret = REACHED_END(buff) ? 1 : ret;
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

static void        gnl_join(t_buff *buff, char **line, int j)
{
	char    *nstr;
	char    *tmp;

	if (!(buff->lsiz == 1 && buff->val[0] == '\n'))
	{
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
	else
	{
		if (!*line)
			*line = (char *)ft_memalloc(1);
		gnl_reset_or_read(buff, 0, 0, 0);
		//++buff->i;
	}
}

int                get_next_line(const int fd, char **line)
{
	static t_buff    *beg;
	t_buff            *buff;
	int                ret;
	int                j;

	if (!line || !(buff = gnl_buff(&beg, fd)))
		return (-1);
	ret = 1;
	*line = NULL;
	while (buff->i != BUFF_SIZE)
	{
		if (gnl_reset_or_read(buff, &ret, fd, 1))
			break ;
		j = ++buff->i;
		while (buff->i < buff->lsiz && buff->val[buff->i] != '\n')
			++buff->i;
		gnl_join(buff, line, j);
		if ((buff->lsiz == 1 && buff->val[0] == '\n') || buff->i != buff->lsiz)
			return (1);
		else if (ret != 0)
			gnl_reset_or_read(buff, 0, 0, 0);
	}
	return (gnl_free_buff(ret, &beg, buff));
}
