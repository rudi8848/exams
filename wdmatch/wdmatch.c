/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 10:03:29 by exam              #+#    #+#             */
/*   Updated: 2017/12/26 10:35:57 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		wdmatch(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s2[i])
	{
		if (s2[i] == s1[j])
			j++;
		if (j == ft_strlen(s1))
			return (1);
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (wdmatch(argv[1], argv[2]))
			ft_putstr(argv[1]);
	}
	ft_putchar('\n');
	return (0);
}
