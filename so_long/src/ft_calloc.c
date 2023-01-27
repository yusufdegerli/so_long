/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:13:08 by ydegerli          #+#    #+#             */
/*   Updated: 2023/01/21 17:17:16 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*((unsigned char *)s + i) = c;
		i++;
	}
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = malloc(count * size);
	if (!str)
	{
		exit(EXIT_FAILURE);
		return (NULL);
	}
	ft_bzero(str, size * count);
	return (str);
}
