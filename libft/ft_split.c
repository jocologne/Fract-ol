/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:07:38 by jcologne          #+#    #+#             */
/*   Updated: 2024/10/29 02:05:17 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	malloc_free(char **token_v, int position, size_t buffer)
{
	int		i;

	i = 0;
	token_v[position] = malloc(buffer);
	if (NULL == token_v[position])
	{
		while (i < position)
			free(token_v[i++]);
		free(token_v);
		return (1);
	}
	return (0);
}

static int	fill_words(char **token_v, char const *s, char delimeter)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == delimeter && *s)
			++s;
		while (*s != delimeter && *s)
		{
			++len;
			++s;
		}
		if (len)
		{
			if (malloc_free(token_v, i, len + 1))
				return (1);
			ft_strlcpy(token_v[i], s - len, len + 1);
		}
		++i;
	}
	return (0);
}

static size_t	count_words(char const *s, char delimeter)
{
	size_t	n;
	int		inside_token;

	n = 0;
	while (*s)
	{
		inside_token = 0;
		while (*s == delimeter && *s)
			++s;
		while (*s != delimeter && *s)
		{
			if (!inside_token)
			{
				++n;
				inside_token = 42;
			}
			++s;
		}
	}
	return (n);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**result;

	if (NULL == s)
		return (NULL);
	words = 0;
	words = count_words(s, c);
	result = malloc((words + 1) * sizeof(char *));
	if (NULL == result)
		return (NULL);
	result[words] = NULL;
	if (fill_words(result, s, c))
		return (NULL);
	return (result);
}
