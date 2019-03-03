#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

class charStack
{
    private:
        int top=-1;
        char Stack[300];
    public:
        void push(char elem);
        char pop();
        char showLast();
};
class intStack
{
    private:
        int top = -1;
        double Stack[300];
    public:
        void push(double );
        double pop();
};
class infinxToPostfix
{
    private:
        charStack charObject;
        intStack intObject;
    public:
        int pres(char ope);
        char * infix_postfix(char str[]);
        double solve_postfix(char str[]);
        double getResult( char str[]);

};
int infinxToPostfix:: pres(char ope)
{
    if(ope=='&')
        return 0;
    else if(ope=='(')
        return 1;
    else if(ope==')')
        return 2;
    else if(ope=='+' || ope=='-')
        return 3;
    else
        return 4;
}
char* infinxToPostfix:: infix_postfix(char str[])
{
    int k=0;
    int check =0;
    char ope;
    charObject.push('&');
    int len = strlen(str);
    char *t_str = (char *)malloc(sizeof(char)*((len/2)+len+1));
    for(int i=0;i<len;i++)
    {
        printf("string = %c",str[i]);
        if(str[i]>=48 && str[i]<=57)
        {
            t_str[k++]=str[i];
            check=1;
            printf("yes");
        }
        else if(pres(charObject.showLast()) < pres(str[i]) || str[i]=='(')
        {
            if(check==1)
            {
                t_str[k++]= '|';
                check=0;
            }
            charObject.push(str[i]);
        }
        else
        {
            if(check==1)
            {
                t_str[k++] = '|';
                check= 0;
            }
            while((pres(charObject.showLast()) >= pres(str[i])) && charObject.showLast()!='&')
                t_str[k++] = charObject.pop();
            if(str[i]==')')
                ope = charObject.pop();
            else
                charObject.push(str[i]);
        }
        for(int store= 0;store<k;store++)
        {
            printf("%c",t_str[store]);
        }
        printf("\n");

    }
    if(check==1)
        t_str[k++]= '|';
    while(charObject.showLast()!='&')
    {
        t_str[k++]=charObject.pop();
    }
    t_str[k]='\0';
    for(int i=0;i<k;i++)
    {
        printf("%c",t_str[i]);
    }
    return t_str;
}
void charStack:: push(char elem)
{
    if(top<299)
    {
        Stack[++top] = elem;
    }
    else
        printf("stack is full\n");
}
char charStack::pop()
{
    if(top>-1)
    {
        return Stack[top--];
    }
    else
    {
        printf("\nstack is empty");
        return '&';
    }
}
double intStack::pop()
{
    if(top>-1)
    {
        return Stack[top--];
    }
    else
    {
        printf("\nstack is empty");
        return '99999';
    }
}
void intStack:: push(double elem)
{
    if(top<299)
    {
        //printf("\nelement = %d\n",elem);
        Stack[++top] = elem;
    }
    else
        printf("stack is full\n");
}
double infinxToPostfix::solve_postfix(char str[])
{
    int i=0, len=0;
    double  res;
    double number,val1,val2;
    while(str[i]!='\0')
    {
        len++;
        i++;
    }
    i=0;
    for(int i=0;i<len;i++)
    {
        printf("string value = %d\n", str[i]);
        if(str[i]>=48 && str[i]<=57)
        {
            number = 0;
            while(str[i]!='|' && i<len)
            {
                number = (number*10)+str[i]-48;
                //printf("NUmber = %d\n",number);
                i++;

            }
            intObject.push(number);

        }
        else
        {
            val2 = intObject.pop();
        //   printf("\nval 2 = %d\n", val2);
            val1 = intObject.pop();
        //  printf("\nval1 = %d\n", val1);
            switch(str[i])
            {
                case '+':
                    res = val2+val1;
                    break;
                case '-':
                    res = val1 - val2;
                    break;
                case '*':
                    res = val1*val2;
                    break;
                case '/':
                    res = val1/val2;
                    break;
                }
        //      printf("\nresult = %f\n", res);
                intObject.push(res);
        }
    }
    return intObject.pop();
}
double infinxToPostfix::getResult( char str[])
{
    char *ptr = infix_postfix(str);
    return solve_postfix(ptr);
}
char charStack::showLast()
{
    return Stack[top];
}
int main()
{
    cout<<"enter the string";
    char str[50];
    cin>>str;
    infinxToPostfix a;
    double ans  = a.getResult(str);
    cout<<endl<<ans<<endl;
}
