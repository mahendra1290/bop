/********************************
 * Author : Mahendra Suthar
 * Data   : 22/04/19
 * *****************************/
#define MAX 100

#include <stdio.h>

void parseExpression(char *str);

int getPrecedence(char oper);

int main()
{
    int a = 9;
    int b = 10;
    char str[MAX];
    fgets(str, MAX, stdin);
    //printf("%s", str);
    parseExpression(str);
    printf("%s", str);
    printf("%d", -4);
}
//removes space from expression
void parseExpression(char *str)
{
    int i, j;
    i = 0;
    j = 0;
    int count = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            while (str[j] != '\0' && str[j] == ' ')
            {
                j++;
                count++;
            }
            str[i] = str[j];
            str[j] = ' ';
            if (str[i] == '\0')
            {
                break;
            }
        }
        count++;
        i++;
        j++;
    }
    printf("count %d\n", count);
}

int getPrecedence(char oper)
{
    switch (oper)
    {
    case 'p':
    case 'm':
        return 5;
    case '$':
        return 0;
    case '+':
    case '-':
        return 3;
    case '*':
    case '/':
    case '%':
        return 4;
    }
}