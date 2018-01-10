/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 10:39:49 by exam              #+#    #+#             */
/*   Updated: 2017/12/26 11:32:47 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_atoi(char *s)
{
	int nbr;
	int i;
	int neg;

	nbr = 0;
	i = 0;
	neg = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (s[i] == '-')
		neg = 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		nbr *= 10;
		nbr += s[i] - '0';
		i++;
	}
	if (neg)
		nbr = -nbr;
	return (nbr);
}

void	print_hex(int n)
{
	if (n >= 16)
	{
		print_hex(n / 16);
		print_hex(n % 16);
	}
	else if (n >= 10 && n <= 15)
		ft_putchar(n - 10 + 'a');
	else
		ft_putchar(n + '0');
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_atoi(argv[1]) >= 0)
			print_hex(ft_atoi(argv[1]));
	}
	ft_putchar('\n');
	return (0);
}
