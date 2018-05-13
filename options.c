/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 10:04:43 by exam              #+#    #+#             */
/*   Updated: 2018/05/08 11:31:39 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define ERROR "Invalid Option\n"
#define USAGE "options: abcdefghijklmnopqrstuvwxyz\n"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_putstr(char *str)
{
	return (write(1, str, ft_strlen(str)));
}

void	ft_print_res(int *arr)
{
	int		i;
	char	c;
	int		j;

	i = 31;
	j = 31;
	while (i >= 0)
	{
		if ((31 - i) % 8 == 0 && (31 - i))
			write(1, " ", 1);
		if (j < 26 && j >= 0)
		{
			c = arr[j] + '0';
			write(1, &c, 1);
		}
		else
			write(1, "0", 1);
		j--;
		i--;
	}
	write(1, "\n", 1);
}

int		arg_validator(char *str, int *arr)
{
	int i;

	i = 0;
	if (str[0] == '-' && str[1] != '\0')
		i = 1;
	else
	{
		ft_putstr(ERROR);
		return (0);
	}
	while (str[i])
	{
		if (str[i] < 'a' || str[i] > 'z')
			return (ft_putstr(ERROR));
		else if (str[i] == 'h')
			return (ft_putstr(USAGE));
		else
			arr[str[i] - 'a'] = 1;
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int i;
	int	arr[26];

	i = 0;
	while (i < 26)
	{
		arr[i] = 0;
		i++;
	}
	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			if (arg_validator(argv[i], arr) != 1)
				return (0);
			i++;
		}
		ft_print_res(arr);
	}
	else
		ft_putstr(USAGE);
	return (0);
}
