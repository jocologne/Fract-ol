/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:51:07 by jcologne          #+#    #+#             */
/*   Updated: 2024/10/16 18:53:16 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;

	len = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)(s + len));
	while (len > 0)
	{
		if (s[len - 1] == (char)c)
			return ((char *)(s + len - 1));
		len--;
	}
	return (NULL);
}
