/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 14:46:00 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/09 12:03:58 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static t_buff		*gnl_buff(t_buff **beg, int fd)
{
	t_buff			*tmp;

	tmp = *beg;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = (t_buff *)malloc(sizeof(t_buff))))
		return (NULL);
	tmp->fd = fd;
	tmp->pstr = ft_strnew(0);
	tmp->str = tmp->pstr;
	tmp->next = NULL;
	if (!*beg)
		*beg = tmp;
	else
		tmp->next = *beg;
	return (tmp);
}

static int			gnl_copy_until_nl(char **dst, char *src)
{
	int				i;
	int				pos;

	i = 0;
	while (src[i] && src[i] != '\n')
		++i;
	if (!(*dst = ft_strnew(i)))
		return (0);
	pos = -1;
	while (++pos < i)
		(*dst)[pos] = src[pos];
	return (pos);
}

static int			gnl_free_buff(t_buff **beg, t_buff *buff)
{
	t_buff			*b;

	if (*beg == buff)
	{
		ft_memdel((void **)&(*beg)->pstr);
		(*beg)->str = NULL;
		ft_memdel((void **)beg);
	}
	else
	{
		b = *beg;
		while (b->next && b->next != buff)
			b = b->next;
		if (b->next == buff)
		{
			b->next = buff->next;
			ft_memdel((void **)&buff->pstr);
			buff->str = NULL;
			ft_memdel((void **)buff);
		}
	}
	return (0);
}

static char			*gnl_join(t_buff *curr, char *buf)
{
	char			*tmp;

	if (!ft_strlen(curr->str))
	{
		ft_memdel((void **)&curr->pstr);
		curr->pstr = ft_strdup(buf);
		curr->str = curr->pstr;
	}
	else
	{
		tmp = ft_strjoin(curr->str, buf);
		ft_memdel((void **)&curr->pstr);
		curr->pstr = tmp;
		curr->str = curr->pstr;
	}
	return (curr->str);
}

int					get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_buff	*beg;
	int				i;
	int				ret;
	t_buff			*curr;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	curr = gnl_buff(&beg, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (!gnl_join(curr, buf))
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < BUFF_SIZE && !ft_strlen(curr->str))
		return (gnl_free_buff(&beg, curr));
	i = gnl_copy_until_nl(line, curr->str);
	(i < (int)ft_strlen(curr->str))
		? curr->str += (i + 1)
		: ft_strclr(curr->str);
	return (1);
}
