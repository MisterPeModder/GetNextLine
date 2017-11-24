/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_to_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 23:22:07 by yguaye            #+#    #+#             */
/*   Updated: 2017/11/15 15:36:13 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_array_to_lst(void *array, size_t len, size_t (*get_size)(void *))
{
	t_list	*lst;
	void	*val;
	t_list	*tmp;
	size_t	size;

	lst = (t_list *)NULL;
	size = sizeof(void *);
	while (len--)
	{
		size = (*get_size)(array + len);
		if (!(val = malloc(size)))
			return ((t_list *)NULL);
		if (!(tmp = ft_lstnew(ft_memcpy(val, array + len, size), size)))
			return ((t_list *)NULL);
		tmp->next = lst;
		lst = tmp;
	}
	return (lst);
}
