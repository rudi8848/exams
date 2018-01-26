#include <stdio.h>
#include <stdlib.h>

int     ft_len(int  nbr)
{
    int i = 0;
    unsigned nb;
    if (nbr < 0)
        nb = -nbr;
    else if (nbr == 0)
        return 1;
    else nb = nbr;
    while (nb > 0)
    {
        nb /=10;
        i++;
    }
return i;
}

char    *ft_itoa(int value)
{
    char  	 *nbr;
    int     neg;
    int 	len;
    unsigned	res;

    len = ft_len(value);
    neg = 0;
    if (value < 0)
    {
        neg = 1;
        res = -value;
    }
    else
    	res = value;
    nbr = (char*)malloc(sizeof(char) * len + neg + 1);
    nbr[len + neg] = '\0';
    while (len-- > 0)
    {
        nbr[len + neg] = (res % 10) +  '0';
        res = res / 10;
    }
    if (neg)
        nbr[0] = '-';
    return (nbr);
}

int     main(void)
{
    printf("%s\n", ft_itoa(0));
    printf("%s\n", ft_itoa(245));
    printf("%s\n", ft_itoa(-245));
    printf("%s\n", ft_itoa(1<<31));
    printf("%s\n", ft_itoa(~(1<<31)));
   // printf("%s\n", ft_itoa());
    return 0;
}