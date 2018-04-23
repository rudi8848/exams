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
#include <stdio.h>
#include <unistd.h>

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
	int arr[256];

	int curr;
	int n;

	curr = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == '{' || str[i] == '(' || str[i] == '[')
		{
			curr++;
			arr[curr] = str[i];
			n++;
		}
		else if (str[i] == '}' || str[i] == ')' || str[i] == ']')
		{
			if (ft_is_match(arr[curr], str[i]) && n > 0)
			{
				curr--;
				n--;
			}
			else
				return 0;
		}
		i++;
	}
	if (n != 0)
		return (0);
	return (1);
}

int 		main(int argc, char **argv)
{
	int i = 1;
	int res = 0;
	while (i < argc)
	{
		if (ft_check_brackets(argv[i]))
			res++;
		i++;
	}
	if (res == argc - 1)
			write(1, "OK", 2);
		else
			write(1, "Error", 5);
	write(1, "\n", 1);
	return 0;
}