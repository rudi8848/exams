/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvynogra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:24:32 by gvynogra          #+#    #+#             */
/*   Updated: 2018/01/29 16:46:40 by gvynogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** segmentation fault in case of invalid str. for example 
** if operator goes first in str " * 22 66 -"
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define ERROR -1103

typedef		struct	s_list
{
	int				value;
	struct s_list	*next;
} t_list;

void	push(t_list **head, int data)
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
	int		val;

	prev = NULL;
	if (head == NULL)
		exit (-1);
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

int		ft_rpn_calc(t_list **stack, char *str)
{
	int i = 0;
	t_list *head;
	int tmp;

	head = *stack;
	while (str[i] != '\0')
	{
		if (str[i] == '+')
			push(&head, pop(&head) + pop(&head));
		else if (str[i] == '-')
			push(&head, -pop(&head) + pop(&head));
		else if (str[i] == '*')
			push(&head, pop(&head) * pop(&head));
		else if (str[i] == '/')
		{
			tmp = pop(&head);
			push(&head, pop(&head) / tmp);
		}
		else if (str[i] == '%')
		{
			tmp = pop(&head);
			push(&head, pop(&head) % tmp);
		}
		if (ft_is_digit(str[i]))
		{
			push(&head, atoi(str + i));
			while (str[i] && ft_is_digit(str[i]))
				i++;
		}
		i++;
	}
	if (head->next != NULL)
	{
		printf("Error\n");
		return ERROR;
	}
	return (head->value);
}

int		main(int argc, char **argv)
{
	t_list *stack;
	int i = 0;
	int res;

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
				return (ERROR);
			}
		}
		if ((res = ft_rpn_calc(&stack, argv[1])) != ERROR)
		{
			printf("%d\n", res);
			return (0);
		}
	}
	else
		printf("Error2\n");
	return (ERROR);
}
