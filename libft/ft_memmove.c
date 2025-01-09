/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:17:18 by jcologne          #+#    #+#             */
/*   Updated: 2024/10/16 19:11:43 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmpdst;
	char	*tmpsrc;

	tmpdst = (char *) dest;
	tmpsrc = (char *) src;
	if (!dest && !src)
		return (NULL);
	if (tmpdst > tmpsrc)
	{
		while (n > 0)
		{
			tmpdst[n - 1] = tmpsrc[n - 1];
			n--;
		}
	}
	else
	{
		while (n > 0)
		{
			*tmpdst++ = *tmpsrc++;
			n--;
		}
	}
	return (dest);
}
