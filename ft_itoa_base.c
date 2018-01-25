/*
Assignment name  : ft_itoa_base
Expected files   : ft_itoa_base.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that converts an integer value to a null-terminated string
using the specified base and stores the result in a char array that you must
allocate.

The base is expressed as an integer, from 2 to 16. The characters comprising
the base are the digits from 0 to 9, followed by uppercase letter from A to F.

For example, base 4 would be "0123" and base 16 "0123456789ABCDEF".

If base is 10 and value is negative, the resulting string is preceded with a
minus sign (-). With any other base, value is always considered unsigned.

Your function must be declared as follows:

char	*ft_itoa_base(int value, int base);
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int        ft_len(int nb, int base)
{
    int i = 0;
    unsigned nbr;

    if(nb < 0)
    	nbr = -nb;
    else if (nb == 0)
    	return 1;
    else
    	nbr = nb;
    while(nbr > 0)
    {
      nbr /= base;
      i++;
      }
        return i;
}

char    *ft_itoa_base(int value, int base)
{
    char  	 *nbr;
    int     neg;
    int 	len;
    unsigned	res;

    len = ft_len(value, base);
    neg = 0;
    if (value < 0)
    {
        if (base == 10)
            neg = 1;
        res = -value;
    }
    else
    	res = value;
    nbr = (char*)malloc(sizeof(char) * len + neg + 1);
    nbr[len + neg] = '\0';
    while (len-- > 0)
    {
        nbr[len + neg] = (res % base) + (res % base > 9 ? 'A' - 10 : '0');
        res = res / base;
    }
    if (neg)
        nbr[0] = '-';
    return (nbr);
}


int 	main(int argc, char **argv)
{
	if (argc == 3)
	{
		int nbr = atoi(argv[1]);
		int base = atoi(argv[2]);
		printf("%s\n", ft_itoa_base(nbr, base));
	}
	else
		printf("usage: %s <number> <base>\n", argv[0]);
	return 0;
}