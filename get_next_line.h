/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:59:21 by yguaye            #+#    #+#             */
/*   Updated: 2017/11/29 14:37:16 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 42

typedef struct		s_buff
{
	char			val[BUFF_SIZE];
	int				i;
	int				fd;
	struct s_buff	*next;
}					t_buff;

int					get_next_line(const int fd, char **line);

#endif
