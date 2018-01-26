#include <unistd.h>


typedef    struct s_list
{
    void     *next;
    int     data;
} t_list;


int     (*cmp)(int, int);

int        ascending(int a, int b)
{
    return a >= b;
}

int        descending(int a, int b)
{
    return a < b;
}
t_list    *sort_list(t_list* lst, int (*cmp)(int, int))
{
    int        overflow;
    t_list    *tmp;

    tmp = lst;
    while (lst->next != NULL)
    {
        if (((*cmp)(lst->data, lst->next->data)) == 0)
        {
            overflow = lst->data;
            lst->data = lst->next->data;
            lst->next->data = overflow;
            lst = tmp;
        }
        else
            lst = lst->next;
    }
    lst = tmp;
    return (lst);
}

int main(void)
{
  t_list *lst;
  lst->data = 98;
  t_list lst->next;
  lst->next->data = 87;
  t_list lst->next->next;
  lst->next->next->data = 90;
  sort_list(lst, *ascending);
  reurn 0;
  }