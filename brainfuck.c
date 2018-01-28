#include <unistd.h>
#include <stdlib.h>

void    ft_brainfuck(char *str)
{
    int        i;
    char    *ptr;

    i = 0;
    ptr = (char*)malloc(sizeof(char*) * 2048);
    while (str[i] != 0)
    {
        *ptr += str[i] == '+' ? 1 : 0;
        *ptr -= str[i] == '-' ? 1 : 0;
        ptr += str[i] == '>' ? 1 : 0;
        ptr -= str[i] == '<' ? 1 : 0;
        if (str[i] == '[' && *ptr == 0)
            while (str[i] != ']')
                i++;
        if (str[i] == ']' && *ptr != 0)
            while (str[i] != '[')
                i--;
        if (str[i] == '.')
            write(1, ptr, 1);
        i++;
    }
}

int        main()
{
    ft_brainfuck("++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.");  
}
