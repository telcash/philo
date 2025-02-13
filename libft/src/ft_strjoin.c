/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:38:33 by csalazar          #+#    #+#             */
/*   Updated: 2024/09/18 14:01:10 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sj;
	size_t	i;

	sj = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!sj)
		return (NULL);
	i = 0;
	while (*s1)
	{
		sj[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		sj[i] = *s2;
		i++;
		s2++;
	}
	sj[i] = '\0';
	return (sj);
}
