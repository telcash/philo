/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:45:29 by csalazar          #+#    #+#             */
/*   Updated: 2024/10/26 19:57:43 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	numwords(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (!s[i + 1] || s[i + 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*getword(char const *s, char c)
{
	size_t	i;
	char	*word;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	word = (char *)malloc((i + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, i + 1);
	return (word);
}

static void	freematrix(char **m)
{
	size_t	i;

	i = 0;
	while (m[i])
	{
		free(m[i]);
		i++;
	}
	free(m);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	split = (char **)ft_calloc((numwords(s, c) + 1), sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && j < numwords(s, c))
	{
		while (s[i] == c)
			i++;
		split[j] = getword(s + i, c);
		if (!split[j])
		{
			freematrix(split);
			return (NULL);
		}
		i += ft_strlen(split[j]);
		j++;
	}
	return (split);
}
