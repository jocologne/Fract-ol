/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:24:48 by jcologne          #+#    #+#             */
/*   Updated: 2024/10/16 16:53:56 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmps1;
	unsigned char	*tmps2;
	size_t			i;

	if (n == 0)
		return (0);
	tmps1 = (unsigned char *) s1;
	tmps2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char) tmps1[i] != (unsigned char) tmps2[i])
			return ((unsigned char) tmps1[i] - (unsigned char) tmps2[i]);
		i++;
	}
	return (0);
}
