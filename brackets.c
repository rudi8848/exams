/*
Assignment name  : brackets 
Expected files   : *.c *.h
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes an undefined number of strings in arguments. For each
argument, the program prints on the standard output "OK" followed by a newline 
if the expression is correctly bracketed, otherwise it prints "Error" followed by
a newline.

Symbols considered as 'brackets' are brackets '(' and ')', square brackets '[' 
and ']'and braces '{' and '}'. Every other symbols are simply ignored.

An opening bracket must always be closed by the good closing bracket in the 
correct order. A string which not contains any bracket is considered as a 
correctly bracketed string.

If there is no arguments, the program must print only a newline.

Examples :

$> ./brackets '(johndoe)' | cat -e
OK$
$> ./brackets '([)]' | cat -e
Error$
$> ./brackets '' '{[(0 + 0)(1 + 1)](3*(-1)){()}}' | cat -e
OK$
OK$
$> ./brackets | cat -e
$
$>
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack
{
	int val;
	struct s_stack *next;
} t_stack;

void 	push(t_stack **head, int val)
{
	t_stack *tmp;

	tmp = (t_stack*)malloc(sizeof(t_stack));
	tmp->val = val;
	tmp->next = (*head);
	(*head) = tmp;

}

int 	pop(t_stack **head)
{
	t_stack *prev;
	int val;

	if (!head)
	{
		write(1, "Error", 5);
		exit(0);
	}
	prev = (*head);
	val = prev->val;
	(*head) = (*head)->next;
	free (prev);
	return val;
}

int 	ft_is_match(int a, int b)
{
	if (a == '(' && b == ')')
		return 1;
	else if (a == '{' && b == '}')
		return 1;
	else if (a == '[' && b == ']')
		return 1;
	else
		return 0;
}

int	 		ft_check_brackets(char *str)
{
	int i = 0;
	t_stack *head;

	head = NULL;
	while (str[i])
	{
		if (str[i] == '{' || str[i] == '(' || str[i] == '[')
			push(&head, str[i]);
		else if (str[i] == '}' || str[i] == ')' || str[i] == ']')
		{
			if (head == NULL || !ft_is_match(pop(&head), str[i]))
				return 0;
		}
		i++;
	}
	if (head != NULL)
		return (0);
	return (1);
}

int 		main(int argc, char **argv)
{
//printf("---> %s\n", __FUNCTION__);
	int i = 1;
	int res = 0;

	while (i < argc)
	{
		res = ft_check_brackets(argv[i]);
		if (res)
			write(1, "OK", 2);
		else
			write(1, "Error", 5);
		i++;
	}

	write(1, "\n", 1);
	return 0;
}