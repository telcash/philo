/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:45:10 by csalazar          #+#    #+#             */
/*   Updated: 2024/09/18 08:48:35 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (i < len && big[i])
	{
		if (ft_strncmp(big + i, little, ft_strlen(little)) == 0 && (i
				+ ft_strlen(little) - 1) < len)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
