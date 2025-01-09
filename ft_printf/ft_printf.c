/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:46:02 by jcologne          #+#    #+#             */
/*   Updated: 2025/01/09 14:51:50 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	type(char c, va_list list)
{
	int	len;

	len = 0;
	if (c == '%')
		len += put_char('%');
	if (c == 'c')
		len += put_char(va_arg(list, int));
	if (c == 's')
		len += put_str(va_arg(list, char *));
	if (c == 'i' || c == 'd')
		len += put_int(va_arg(list, int));
	if (c == 'x' || c == 'X')
		len += put_hexa(va_arg(list, unsigned int), c);
	if (c == 'p')
		len += put_pnt(va_arg(list, unsigned long));
	if (c == 'u')
		len += put_uns(va_arg(list, unsigned int));
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		len;
	int		i;
	va_list	args_list;

	i = 0;
	len = 0;
	va_start(args_list, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += type(s[i + 1], args_list);
			i++;
		}
		else
			len += put_char(s[i]);
		i++;
	}
	va_end(args_list);
	return (len);
}
