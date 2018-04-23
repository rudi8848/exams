/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   	rpn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvynogra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:24:32 by gvynogra          #+#    #+#             */
/*   Updated: 2018/01/29 16:46:40 by gvynogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef		struct	s_list
{
	long long int				value;
	struct s_list	*next;
} t_list;

void	push(t_list **head, long long int data)
{
	t_list *tmp;

	tmp = (t_list*)malloc(sizeof(t_list));
	tmp->value = data;
	tmp->next  = (*head);
	(*head) = tmp;
}

int		pop(t_list **head)
{
	t_list	*prev;
	long long int		val;

	prev = (*head);
	val = prev->value;
	(*head) = (*head)->next;
	free (prev);
	return (val);
}

int		ft_is_digit(int c)
{
	return (c >= '0' && c <= '9' ? 1 : 0);
}

int		ft_rpn_calc(char *str)
{
	long long int i;
	t_list *head;
	int tmp;

	head = NULL;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == '-' && ft_is_digit(str[i + 1])) || ft_is_digit(str[i]))
		{
			push(&head, atoi(str + i));
			i++;
			while (str[i] && ft_is_digit(str[i]))
				i++;
		}
		else if (head != NULL && head->next != NULL && str[i] == '+')
			push(&head, pop(&head) + pop(&head));
		else if (head != NULL && head->next != NULL  && str[i] == '-')
			push(&head, -pop(&head) + pop(&head));
		else if (head != NULL && head->next != NULL && str[i] == '*')
			push(&head, pop(&head) * pop(&head));
		else if (head != NULL && head->next != NULL && str[i] == '/')
		{
			tmp = pop(&head);
			if (tmp == 0)
				return 0;
			push(&head, pop(&head) / tmp);
		}
		else if (head != NULL && str[i] == '%')
		{
			tmp = pop(&head);
			if (tmp == 0)
				return 0;
			push(&head, pop(&head) % tmp);
		}
		else if (str[i] != ' ')
			return 0; 
		i++;
	}
	if (head->next != NULL)
		return (0);
	printf("%lld\n", head->value);
	return (1);
}

int		main(int argc, char **argv)
{
	int i = 0;

	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == ' ' || ft_is_digit(argv[1][i])
					|| argv[1][i] == '+' || argv[1][i] == '-'
					|| argv[1][i] == '*' || argv[1][i] == '/'
					|| argv[1][i] == '%')
				i++;
			else
			{
				printf("Error\n");
				return (0);
			}
		}
		if (!ft_rpn_calc(argv[1]))
		{
			printf("Error\n");
			return (0);
		}
	}
	else
		printf("Error\n");
	return (0);
}
