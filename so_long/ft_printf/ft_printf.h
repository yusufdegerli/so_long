/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:30:58 by ydegerli          #+#    #+#             */
/*   Updated: 2022/12/25 17:36:57 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_putchar(int c);

int		hexa_dec_up(unsigned int c);

int		hexa_dec_lwr(unsigned int c);

int		ctl(va_list lst, char c);

int		int_print(int s);

size_t	ft_putnbr(int n);

int		str_print(char *str);

int		ft_putstr(char *s);

int		ft_printf(const char *start, ...);

int		ptr_print(unsigned long ptr);

int		ptr_len(unsigned long num);

int		uns_print(unsigned int num);

#endif
