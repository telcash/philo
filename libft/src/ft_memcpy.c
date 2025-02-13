/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:43:08 by csalazar          #+#    #+#             */
/*   Updated: 2024/09/26 19:59:20 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*csrc;
	unsigned char	*cdest;

	if (!dest || !src)
		return (NULL);
	csrc = (unsigned char *)src;
	cdest = (unsigned char *)dest;
	while (n-- > 0)
		*cdest++ = *csrc++;
	return (dest);
}
