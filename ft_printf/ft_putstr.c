/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 06:59:16 by jcologne          #+#    #+#             */
/*   Updated: 2024/11/08 08:56:36 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_str(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (put_str("(null)"));
	while (*str)
	{
		len += put_char(*str);
		str++;
	}
	return (len);
}
