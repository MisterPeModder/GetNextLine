/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 23:29:42 by yguaye            #+#    #+#             */
/*   Updated: 2017/11/17 21:44:30 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	*ft_lst_create_tab(t_list *lst)
{
	size_t	size;

	size = 0;
	while (lst)
	{
		size += lst->content_size;
		lst = lst->next;
	}
	if (!size)
		return (NULL);
	return (malloc(size));
}

void		*ft_lst_to_array(t_list *lst)
{
	void	*tab;
	size_t	i;

	if (!lst || !(tab = ft_lst_create_tab(lst)))
		return ((void *)NULL);
	i = 0;
	while (lst)
	{
		ft_memcpy(tab + i, lst->content, lst->content_size);
		lst = lst->next;
		if (lst)
			i += lst->content_size;
	}
	return (tab);
}
