/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:03:28 by exam              #+#    #+#             */
/*   Updated: 2018/01/26 14:36:25 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_len(int value, int base)
{
	int			len;
	unsigned	nbr;

	len = 0;
	if (value == 0)
		return (1);
	else if (value < 0)
	{
		if (base == 10)
			len++;
		nbr = -value;
	}
	else
		nbr = value;
	while (nbr)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(int value, int base)
{
	int				len;
	unsigned int	res;
	char			*nbr;

	len = ft_len(value, base);
	if (value < 0)
		res = -value;
	else
		res = value;
	if (!(nbr = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	nbr[len] = '\0';
	while (len-- > 0)
	{
		nbr[len] = (res % base) + (res % base > 9 ? 'A' - 10 : '0');
		res /= base;
	}
	if (value < 0 && base == 10)
		nbr[0] = '-';
	return (nbr);
}
