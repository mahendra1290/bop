#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QGridLayout>
#include <QLCDNumber>
#include <QDebug>
#include <iostream>
#include <stdlib.h>
#include <string>

int infixToPostfix:: pres(char ope)
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
char* infixToPostfix:: infix_postfix(char str[])
{
    int k=0;
    int check =0;
    char ope;
    charObject.push('&');
    unsigned int len = strlen(str);
    char *t_str = new char[(len/2)+len+1];
    for( unsigned long  i=0;i<len;i++)
    {
        if(str[i]>=48 && str[i]<=57)
        {
            t_str[k++]=str[i];
            check=1;
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

    }
    if(check==1)
        t_str[k++]= '|';
    while(charObject.showLast()!='&')
    {
        t_str[k++]=charObject.pop();
    }
    t_str[k]='\0';
    return t_str;
}
void charStack:: push(char elem)
{
    if(top<299)
    {
        Stack[++top] = elem;
    }
}
char charStack::pop()
{
    if(top>-1)
    {
        return Stack[top--];
    }
    else
    {
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
        return 99999;
    }
}
void intStack:: push(double elem)
{
    if(top<299)
    {
        Stack[++top] = elem;
    }
}
double infixToPostfix::solve_postfix(char str[])
{
    int i=0, len=0;
    double res;
    double number,val1,val2;
    while(str[i]!='\0')
    {
        len++;
        i++;
    }
    i=0;
    for(int i=0;i<len;i++)
    {
        if(str[i]>=48 && str[i]<=57)
        {
            number = 0;
            while(str[i]!='|' && i<len)
            {
                number = (number*10)+str[i]-48;

                i++;

            }
            intObject.push(number);

        }
        else
        {
            val2 = intObject.pop();
            val1 = intObject.pop();
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
                intObject.push(res);
        }
    }
    return intObject.pop();
}
double infixToPostfix::getResult( char str[])
{
    char *ptr = infix_postfix(str);
    return solve_postfix(ptr);
}
char charStack::showLast()
{
    return Stack[top];
}

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent){
    QPushButton *zero  = new QPushButton("0", this);
    QPushButton *one   = new QPushButton("1", this);
    QPushButton *two   = new QPushButton("2", this);
    QPushButton *three = new QPushButton("3", this);
    QPushButton *four  = new QPushButton("4", this);
    QPushButton *five  = new QPushButton("5", this);
    QPushButton *six   = new QPushButton("6", this);
    QPushButton *seven = new QPushButton("7", this);
    QPushButton *eight = new QPushButton("8", this);
    QPushButton *nine  = new QPushButton("9", this);
    QPushButton *add   = new QPushButton("+", this);
    QPushButton *minus = new QPushButton("-", this);
    QPushButton *multi = new QPushButton("*", this);
    QPushButton *divide = new QPushButton("/", this);
    QPushButton *clear = new QPushButton("C", this);
    QPushButton *allClear = new QPushButton("AC", this);
    QPushButton *ans = new QPushButton("ans", this);
    disp = new QLabel(this);
    QGridLayout *panel = new QGridLayout(this);
    panel->addWidget(allClear, 1, 0);
    panel->addWidget(clear, 1, 1);
    panel->addWidget(ans, 1, 2);
    panel->addWidget(divide, 1, 3);
    panel->addWidget(nine, 2, 0);
    panel->addWidget(eight, 2, 1);
    panel->addWidget(seven, 2, 2);
    panel->addWidget(multi, 2, 3);
    panel->addWidget(four, 3, 0);
    panel->addWidget(five, 3, 1);
    panel->addWidget(six, 3, 2);
    panel->addWidget(minus, 3, 3);
    panel->addWidget(one, 4, 0);
    panel->addWidget(two, 4, 1);
    panel->addWidget(three, 4, 2);
    panel->addWidget(add, 4, 3);
    panel->addWidget(zero, 5, 1);
    panel->addWidget(disp, 0, 0, 1, 4);
    panel->setRowMinimumHeight(0, 40);
    setLayout(panel);
    connect(one, &QPushButton::clicked, this, &MainWindow::On_1);
    connect(two, &QPushButton::clicked, this, &MainWindow::On_2);
    connect(three, &QPushButton::clicked, this, &MainWindow::On_3);
    connect(four, &QPushButton::clicked, this, &MainWindow::On_4);
    connect(five, &QPushButton::clicked, this, &MainWindow::On_5);
    connect(six, &QPushButton::clicked, this, &MainWindow::On_6);
    connect(seven, &QPushButton::clicked, this, &MainWindow::On_7);
    connect(eight, &QPushButton::clicked, this, &MainWindow::On_8);
    connect(nine, &QPushButton::clicked, this, &MainWindow::On_9);
    connect(zero, &QPushButton::clicked, this, &MainWindow::On_0);
    connect(add, &QPushButton::clicked, this, &MainWindow::On_add);
    connect(multi, &QPushButton::clicked, this, &MainWindow::On_multi);
    connect(divide, &QPushButton::clicked, this, &MainWindow::On_divide);
    connect(minus, &QPushButton::clicked, this, &MainWindow::On_minus);
    connect(clear, &QPushButton::clicked, this, &MainWindow::On_clear);
    connect(allClear, &QPushButton::clicked, this, &MainWindow::On_allclear);
    connect(ans, &QPushButton::clicked, this, &MainWindow::On_ans);
}

void MainWindow::On_0(){
    QString str = disp->text();
    str.append('0');
    disp->setText(str);
}

void MainWindow::On_1(){
    QString str = disp->text();
    str.append('1');
    disp->setText(str);
}

void MainWindow::On_2(){
    QString str = disp->text();
    str.append('2');
    disp->setText(str);
}

void MainWindow::On_3(){
    QString str = disp->text();
    str.append('3');
    disp->setText(str);
}

void MainWindow::On_4(){
    QString str = disp->text();
    str.append('4');
    disp->setText(str);
}

void MainWindow::On_5(){
    QString str = disp->text();
    str.append('5');
    disp->setText(str);
}

void MainWindow::On_6(){
    QString str = disp->text();
    str.append('6');
    disp->setText(str);
}

void MainWindow::On_7(){
    QString str = disp->text();
    str.append('7');
    disp->setText(str);
}

void MainWindow::On_8(){
    QString str = disp->text();
    str.append('8');
    disp->setText(str);
}

void MainWindow::On_9(){
    QString str = disp->text();
    str.append('9');
    disp->setText(str);
}

void MainWindow::On_add(){
    QString str = disp->text();
    str.append('+');
    disp->setText(str);
}
void MainWindow::On_minus(){
    QString str = disp->text();
    str.append('-');
    disp->setText(str);
}
void MainWindow::On_multi(){
    QString str = disp->text();
    str.append('*');
    disp->setText(str);
}
void MainWindow::On_divide(){
    QString str = disp->text();
    str.append('/');
    disp->setText(str);
    qDebug()<<str;
}
void MainWindow::On_clear(){
    QString str = disp->text();
    int len = str.length();
    str.remove(len-1, 1);
    disp->setText(str);
}
void MainWindow::On_allclear(){
    QString str = disp->text();
    int len = str.length();
    str.remove(0, len);
    disp->setText(str);

}
void MainWindow::On_ans()
{
    infixToPostfix expres;
    //double result = object->getResult(str);
    qDebug()<<disp->text();
    QString str1 = disp->text();
    QByteArray ba = str1.toLatin1();
    char *c_str2 = ba.data();
    double result = expres.getResult(c_str2);
    disp->setNum(result);
}






