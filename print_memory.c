/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:34:24 by exam              #+#    #+#             */
/*   Updated: 2018/05/01 12:58:46 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(int nbr, int rem)
{
	char *base = "0123456789abcdef";

	if (rem > 1)
		print_hex(nbr / 16, 1);
	write(1, base + (nbr % 16), 1);
}

void	print_val(const unsigned char *ptr)
{
	if (*ptr >= ' ' && *ptr <= '~')
		write(1, ptr, 1);
	else
		write(1, ".", 1);
}

void	print_memory(const void *addr, size_t size)
{
	size_t i;
	size_t a;
	unsigned char const *ptr;

	ptr = addr;
	i = 0;
	while (i < size)
	{
		a = 0;
		while (a < 16 && a + i < size)
		{
			print_hex(*(ptr + i + a), 2);
			if (a % 2)
				write(1, " ", 1);
			a++;
		}
		while (a < 16)
		{
			write(1, "  ", 2);
			if (a % 2)
				write(1, " ", 1);
			a++;
		}
		a = 0;
		while (a < 16 && a + i < size)
		{
			print_val(ptr + i + a);
			a++;
		}
		write(1, "\n", 1);
		i += 16;
	}
}
