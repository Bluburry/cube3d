#include "cube.h"

void    print_errors(char *str)
{
    printf("Error\n");
    if (str)
        printf("%s", str);
    if (!str)
        return ;
    auto int i = 0;
    while (str[i])
        i++;
    if (str[i - 1] != '\n')
        printf("\n");
}