/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:59:21 by yguaye            #+#    #+#             */
/*   Updated: 2017/11/30 11:59:06 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 465
# define REACHED_END(buff) (buff->i == buff->lsiz && buff->i < BUFF_SIZE)

typedef struct		s_buff
{
	char			val[BUFF_SIZE];
	int				i;
	int				fd;
	int				lsiz;
	struct s_buff	*next;
}					t_buff;

int					get_next_line(const int fd, char **line);

#endif
