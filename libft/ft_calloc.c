/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 02:19:03 by jcologne          #+#    #+#             */
/*   Updated: 2024/10/29 02:42:39 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb > (size_t)-1 / size)
		return (NULL);
	ptr = (void *)malloc(nmemb * size);
	if (ptr == 0)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
