/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:08:03 by jcologne          #+#    #+#             */
/*   Updated: 2024/10/22 18:17:19 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	begin;
	unsigned int	end;
	unsigned int	len;
	char			*result;

	if (!s1 || !set)
		return (NULL);
	begin = 0;
	while (s1[begin] && ft_strchr(set, s1[begin]))
		begin++;
	end = ft_strlen(s1);
	while (end > begin && ft_strchr(set, s1[end - 1]))
		end--;
	len = end - begin;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1 + begin, len + 1);
	return (result);
}
