/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:59:25 by wsl               #+#    #+#             */
/*   Updated: 2024/10/18 14:46:59 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *n)
{
	int	sign;
	int	num;
	int	i;

	i = 0;
	sign = 1;
	num = 0;
	if (n[i] == '\0')
		return (0);
	while ((n[i] >= 9 && n[i] <= 13) || n[i] == 32)
		i++;
	if (n[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (n[i] == '+')
		i++;
	while (n[i] >= '0' && n[i] <= '9')
	{
		num = (num * 10) + (n[i]) - 48;
		i++;
	}
	return (num * sign);
}
