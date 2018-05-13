#include <stdio.h>
#include <stdlib.h>

/*
принимает строку или массив строк и выводит максимальную подстроку ("" тоже считается подстрокой)
если есть несколько одинаково длинных подстрок - выводим ту, которая идет первая в первом аргументе


Assignment name  : str_maxlenoc
Expected files   : str_maxlenoc.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes one or more strings and displays, followed by a
newline, the longest string that appears in every parameter. If more that one
string qualifies, it will display the one that appears first in the first
parameter. Note that the empty string technically appears in any string.

If there are no parameters, the program displays \n.

Examples:

$>./str_maxlenoc ab bac abacabccabcb
a
$>./str_maxlenoc bonjour salut bonjour bonjour
u
$>./str_maxlenoc xoxAoxo xoxAox  oxAox oxo  A ooxAoxx oxooxo Axo | cat -e
$
$>./str_maxlenoc bosdsdfnjodur atehhellosd afkuonjosurafg headfgllosf fghellosag afdfbosnjourafg
os
$>./str_maxlenoc | cat -e
$
*/



char *cmp(char *s1, char *s2)
{

}


int		main(int argc, char **argv)
{
	int i = 2;
	char *substr;

	if (argc > 1)
	{
		substr = argv[1];
		
		while (i < argc)
		{
			substr = cmp(substr, argv[i]);
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}