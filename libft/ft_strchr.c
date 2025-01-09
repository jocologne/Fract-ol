/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:11:31 by jcologne          #+#    #+#             */
/*   Updated: 2024/10/18 15:45:35 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*tmp;

	tmp = s;
	while (*tmp != '\0')
	{
		if (*tmp == (char)c)
			return ((char *)tmp);
		tmp++;
	}
	if ((char)c == '\0')
		return ((char *)tmp);
	return (NULL);
}
