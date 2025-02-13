/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:22:03 by csalazar          #+#    #+#             */
/*   Updated: 2024/09/19 18:11:42 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*inttochar(char *s, int n)
{
	int	i;

	i = numlen(n);
	s[i] = '\0';
	if (n < 0)
	{
		*s = '-';
		n *= -1;
	}
	while (n > 0)
	{
		s[--i] = (n % 10) + 48;
		n /= 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	s = (char *)malloc((numlen(n) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	return (inttochar(s, n));
}
