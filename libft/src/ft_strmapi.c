/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:06:08 by csalazar          #+#    #+#             */
/*   Updated: 2024/09/18 19:15:34 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*smap;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	smap = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!smap)
		return (NULL);
	i = 0;
	while (s[i])
	{
		smap[i] = f(i, s[i]);
		i++;
	}
	smap[i] = '\0';
	return (smap);
}
