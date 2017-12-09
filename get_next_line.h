/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 11:53:20 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/09 11:53:21 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"

# define BUFF_SIZE 42

typedef struct		s_buff
{
	int				fd;
	char			*pstr;
	char			*str;
	struct s_buff	*next;
}					t_buff;

int					get_next_line(const int fd, char **line);

#endif
