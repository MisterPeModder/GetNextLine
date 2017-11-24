/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:50:25 by yguaye            #+#    #+#             */
/*   Updated: 2017/11/12 19:47:26 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int ch, size_t n)
{
	unsigned char	*str;
	unsigned char	c;
	size_t			i;

	str = (unsigned char *)s;
	c = (unsigned char)ch;
	i = 0;
	while (i < n)
		if (str[i++] == c)
			return ((void *)(s + i - 1));
	return (NULL);
}
