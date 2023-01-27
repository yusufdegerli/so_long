/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:46:03 by ydegerli          #+#    #+#             */
/*   Updated: 2023/01/21 18:52:08 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//Haritanın sütun uzuluğu kontrolü
//Checking the column length of the map
void	ft_line_len(t_arg *arg, char *str)
{
	int		fd;
	int		len;
	char	c;

	fd = open(str, O_RDONLY);
	len = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			len++;
	}
	len++;
	close(fd);
	arg->map = malloc(sizeof(char *) * (len + 1));
	arg->tmp_map = malloc(sizeof(char *) * (len + 1));
	arg->map[len] = NULL;
	arg->tmp_map[len] = NULL;
	arg->line_count = len;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (s1 && !s2)
		return ((char *)s1);
	if (!s1 && s2)
		return ((char *)s2);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	new = (char *)malloc((i + j) + 1);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		new[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new[j++] = s2[i++];
	new[j] = '\0';
	return (new);
}
//Haritayı okuma işlemi.
//The process of reading the map.
void	ft_read_map(t_arg *arg, char *str)
{
	int		fd;
	int		i;
	char	*tmp;

	ft_line_len(arg, str);
	i = 0;
	fd = open(str, O_RDONLY);
	while (i < arg->line_count)
	{
		arg->map[i] = get_next_line(fd);
		arg->tmp_map[i] = ft_strdup(arg->map[i]);
		i++;
	}
	tmp = arg->map[arg->line_count - 1];
	arg->map[arg->line_count - 1] = ft_strjoin(arg->map[arg->line_count - 1],
			"\n");
	free(tmp);
	tmp = arg->tmp_map[arg->line_count - 1];
	arg->tmp_map[arg->line_count - 1] = ft_strjoin
		(arg->tmp_map[arg->line_count - 1], "\n");
	free(tmp);
	close(fd);
}
