//#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	interpret(char *msg)
{
	char arr[30000] = {0};
	char *p = arr;
	int i = 0;
	int loop = 0;
	int j = 0;

	while (i < strlen(msg))
	{
		if (msg[i] == '>')
			p++;
		else if (msg[i] == '<')
			p--;
		else if (msg[i] == '+')
			(*p)++;
		else if (msg[i] == '-')
			(*p)--;
		else if (msg[i] == '.')
			ft_putchar(*p);
		else if (msg[i] == '[')
				loop = i-1;
		else if (msg[i] == ']')
		{
			while (msg[loop])
			{
				msg[loop]--;
				i = loop;
				continue;
			}
		}
		
		i++;
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		interpret(argv[1]);
	else
		printf("usage: %s <message>\n", argv[0]);
	return 0;
}