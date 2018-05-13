#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_mult(char *a, char *b)
{

	int alen = ft_strlen(a);
	int blen = ft_strlen(b);
	int clen = alen + blen;
	
	char *c = (char*)malloc(sizeof(char) *clen + 1);
	

	int i;
	int carry;
	int index;
	int j;


	i = 0;

	//забиваємо все с 0-ми
	while (i <= clen)
	{
		c[i] = 0;
		i++;
	}

	i = alen - 1;
//ідемо з кінця а до початку а
	while (i >= 0 && a[i] != '-')
	{
		index = clen + i - alen;
		//ідемо з кінця б до початку б
		j = blen - 1;
		while (j >= 0 && b[j] != '-')
		{
			c[index] += (b[j] - '0') * (a[i] - '0');
			//проходимо з кінця с до початку с і робимо переноси
			carry = clen - 1;
			while (carry >= 0)
			{
				if (c[carry] > 9)
				{
					c[carry - 1] += c[carry] / 10;
					c[carry] %= 10;
				}
				carry--;
			}
			index--;
			j--;
		}
		i--;
	}
	
	index = 0;
	while (index < clen)
	{
		c[index] += '0';
		index++;
	}

	char *ptr = c;
	while (*ptr == '0')
		ptr++;
	if ((a[0] == '-' && b[0] != '-') || (a[0] != '-' && b[0] == '-') )
		write(1, "-", 1);
	
	ft_putstr(ptr);

}

int		main(void)
{
	char *a = "2145954369456789";
	char *b = "-2";

	if (strlen(a) > strlen(b))
		ft_mult(a, b);
	else
		ft_mult(b, a);
	write(1, "\n", 1);
	return 0;
}