#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once
#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>


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
class infixToPostfix
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

class MainWindow : public QWidget{

  Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);

  private slots:
    void On_0();
    void On_1();
    void On_2();
    void On_3();
    void On_4();
    void On_5();
    void On_6();
    void On_7();
    void On_8();
    void On_9();
    void On_add();
    void On_minus();
    void On_divide();
    void On_multi();
    void On_clear();
    void On_allclear();
    void On_ans();
  private:
    QLabel *disp;
};

#endif // MAINWINDOW_H
