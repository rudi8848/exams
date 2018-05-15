#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

unsigned char   *ft_memalloc(void)
{
    int i;
    int n;

    n = 4096;
    i = 0;
    unsigned char *ptr;
    ptr = (unsigned char*)malloc(sizeof(char) * n);
    while (i < n)
    {
        ptr[i] = 0;
        i++;
    }
    return (ptr);
}

void            ft_brainfuck(char *str)
{
    unsigned char *ptr;
    int i = 0;
    int loop;

    ptr = ft_memalloc();
    while (str[i])
    {
        if (str[i] == '>')
            ptr++;
        else if (str[i] == '<')
            ptr--;
        else if (str[i] == '+')
            (*ptr)++;
        else if (str[i] == '-')
            (*ptr)--;
        else if (str[i] == '.')
            write(1, ptr, 1);
        if (str[i] == '[')
        {
            if (*ptr == 0)
            {
                loop = 0;
                while (str[i])
                {
                    if (str[i] == '[')
                        loop++;
                    else if (str[i] == ']')
                    {
                        if (loop)
                             loop--;
                        if (loop == 0)
                            break;
                    }
                    i++;
                }
            }
        }
        else if (str[i] == ']')
        {
            if (*ptr != 0)
            {
                loop = 0;
                while (i >= 0)
                {
                    if (str[i] == ']')
                        loop++;
                    else if (str[i] == '[')
                    {
                        if (loop)
                            loop--;
                        if (loop == 0)
                            break;
                    }
                    i--;
                }
            }
        }
        i++;
    }
}

int        main(void)
{
    ft_brainfuck("++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.");
    write(1, "\n", 1);
    ft_brainfuck("++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.");
    write(1, "\n", 1);
    ft_brainfuck("+++++[>++sefs++[>++sef+dht+>+++++sfsfefijdgj<<-]>>>++efn<<<<-]>>esf-----sf---.>+++++.>.");
    write(1, "\n", 1);
    ft_brainfuck("+>+++++++[>>>++++++++<<<<++++++++>-]+++++++++>>>+>>++++++++++[>++++++++++<-]>[>>+>+>+>+>+>+>+>>+>+>>+>+>+>+>>+>+>>+>+>+>>+>+>+>+>>>>>+>+>+>+>>+>+>+>>+>+>+>+>>+>+>+>>+>+>+>+>>+>+>>+>+>+>+>+>+>>>>+>+>>+>+>+>+<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<-]<++++[>++++++++<-]>[>+>>>>>>>>+>>>+>>>>>+>>>+>>>>+>>>>>+>+>>+>>>>>+>>>>+>>>>>+>>>>+>>>>>+>>>+>>>>>>>+>+>+>>>+>>>>>+<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<-]+++++[>>>++>+++>+++>++>>+++>>++>>>>>>+++>>++>++>>+++>+>>>++++>->++>++>++>+++>++>>--->->+>>>++>++>>>>++>++++>++>>->++>>>++>->+++>+++>>+>+++>>>+++>++>+++>++>>>++>>++>++>>++>++>+++<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<-]>>-->+>+>+>-->+>>>+>++>>-->+>+>->>+>>>+>->+>>->++>-->-->++>->>>->++>++>+>>+>>+>>>+>->>>++>>>>++>++>>>>>+>>++>->+>++>>>>+++>>>+>>->+>->+<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<[>>>>++++++++++[->[-]+>[-]<<[<<<<<.>>>>.>>>>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>>>.<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<.>>>>.>>>>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>>>>>>>>>>>>>>.>.>>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<.>>>>-.>>>>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>>.>..<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<-]>[<<<<<->[-]+>[-]<<[<.>>>>.>>>>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>>>.<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<.>>>>.>>>>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>>>>>>>>>>>>>>.>.>>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<-.>>>>+++++++++.>>>>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>>.>..<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<-]>[<<.>>>>.>>>>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>>>.<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<.>>>>.>>>>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>>>>>>>>>>>>>>.>.>>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<+++++++++.>>>>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>>.>..<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<->]<<+>>>>>->]<<]<<<<-]>>>>++++++++[->[-]+>[-]<<[<.>>>>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>>>.<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<.>>>>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>>>>>>>>>>>>>>.>.>>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<-.>>>>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>>.>..<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<-]>[<<.>>>>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>>>.<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<.>>>>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>>>>>>>>>>>>>>.>.>>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<-.>>>>.>.>.>.>.>.>.>>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>>.>..<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<->]<<]<.>>>>.>.>.>.>.>.>.>>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>>>.<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<.>>>>.>.>.>.>.>.>.>>.>.>.>.>.>.>.>.>>>>>>>>>>>>>>.>.>>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>>.>");
    return (0);
}
