/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:54:30 by ydegerli          #+#    #+#             */
/*   Updated: 2023/01/21 18:58:41 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//Harita ögelerinin kontrolü.
//Control of map elements.
void	ft_fe_count_check(t_arg *arg)
{
	if (arg->coin_count == 0 && arg->exit_count == 0 && arg->player_count == 0)
	{
		ft_printf("Hata! Haritada istenilenlerden\
				(P, C, E) en az bir tane olmalı!\n");
		exit(1);
	}
	if (arg->coin_count < 1 || arg->exit_count != 1
		|| arg->player_count != 1)
	{
		ft_printf("Hata! Haritada istenilenlerden (P, C, E) en az \
				bir tane olmalı!\n Error! There must be at least one \
				of the needed ones on the map");
		exit(1);
	}
}

static int	digit_counter(long int n)
{
	long int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n == 0)
	{
		return (1);
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			l;
	long int	tmp;

	tmp = n;
	l = digit_counter(tmp);
	str = (char *)malloc(l + 1);
	if (!str)
		return (NULL);
		str[l] = '\0';
	if (tmp < 0)
	{
		str[0] = '-';
		tmp = tmp * -1;
	}
	if (tmp == 0)
		str[0] = '0';
	while (tmp > 0)
	{
		str[--l] = (tmp % 10) + 48;
		tmp /= 10;
	}
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (s1[size])
		++size;
	new = malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
