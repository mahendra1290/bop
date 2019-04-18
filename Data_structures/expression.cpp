/************************
 * author:mahendra suthar
 * Proagram to solve general maths equation
 * like (87-9.788)/89
 * if converts infix to postfix and
 * than solve it
 * ************************/

#include<iostream>
#define MAX 100
#include<string.h>
using namespace std;

class doubStack;
class charStack;
class expression;
class doubStack{
private:
    int top;
    double arr[MAX];
public:
    doubStack();
    void push(double elem);
    double  pop();
    double showLast();
    bool isEmpty();
    bool isFull();
};

doubStack::doubStack(){
    top = -1;
}

void doubStack::push(double elem){
    if(!isFull()){
        arr[++top] = elem;
    }
    else{
        printf("stack is full\n");
    }
}

double doubStack::pop(){
    if(!isEmpty()){
        return arr[top--];
    }
    else{
        printf("stack is empty\n");
        return -1390;
    }
}

double doubStack::showLast(){
    if(!isEmpty()){
        return arr[top];
    }
    else{
        printf("stack is empty\n");
        return -1390;
    }
}

bool doubStack::isEmpty(){
    if(top == -1)
        return true;
    return false;
}

bool doubStack::isFull(){
    if(top == MAX-1)
        return true;
    return false;
}


class charStack{
private:
    int top;
    char arr[MAX];
public:
    charStack();
    void push(char elem);
    char  pop();
    char showLast();
    bool isEmpty();
    bool isFull();
};

charStack::charStack(){
    top = -1;
}

void charStack::push(char elem){
    if(!isFull()){
        arr[++top] = elem;
    }
    else{
        printf("stack is full\n");
    }
}

char charStack::pop(){
    if(!isEmpty()){
        return arr[top--];
    }
    else{
        printf("stack is empty\n");
        return '^';
    }
}

char charStack::showLast(){
    if(!isEmpty()){
        return arr[top];
    }
    else{
        printf("stack is empty\n");
        return '^';
    }
}

bool charStack::isEmpty(){
    if(top == -1)
        return true;
    return false;
}

bool charStack::isFull(){
    if(top == MAX-1)
        return true;
    return false;
}

class expression{
private:
    char *infix   = new char[MAX];
    char *postfix = new char[MAX];
    char *result  = new char[MAX];
    char *error   = new char[MAX];
public:
    void operator=(const char str[]);
    friend ostream &operator<<(ostream &output, const expression &infi);
    int getPrecedence(char oper);
    int setPostfix();
    bool validateInfix();
    bool validatePostfix();
    void infixToPostfix();
    double solvePostfix();
    double toDouble(const char str[]);
    double evalInfix();
};

void expression::operator=(const char str[]){
    int i=0;
    int len = strlen(str);
    for(i=0; i<len; i++){
         infix[i] = str[i];   
    }
    infix[i] = '\0';
}

ostream &operator<<(ostream &output, const expression &infi){
    output <<"infix: "<<infi.infix<<endl<<"postfix :"<<infi.postfix<<endl <<"errors :"<<infi.error;
    return output;
}

int expression::getPrecedence(char oper){
    switch(oper){
        case '+': 
        case '-':
            return 3;
        case '*':
        case '/':
            return 4;
        case '(':
            return 1;
        case ')':
            return 2;
        case '$':
            return 0;
        default:
            error = "invalid character entered";
            throw "invalid character entered";
            return -1;
    }
}

bool expression::validateInfix(){
    int i, leftPran=0, rightPran=0, numbers=0, opers=0;
    int leftPranPosi=-1, rightPranPosi=-1, opersPosi=-2;
    int len = strlen(infix);
    if(len == 0){
        error = "expression not entered";
        throw "expression not entered";
        return false;
    }
    for(i=0; i<len; i++){
        if(infix[i] >= '0' && infix[i] <= '9'){
            numbers++;
            i++;
            while((i < len) && ((infix[i] >= '0' && infix[i] <= '9') || 
                infix[i] == '.')){
                    i++;
            }
            i--;
        }
        else{
            switch(infix[i]){
            case '(':
                leftPranPosi = i;
                leftPran++;
                break;
            case ')':
                rightPranPosi = i;
                rightPran++;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                opersPosi = i;
                opers++;
                break;
            default:
                error = "invalid character entered";
                throw "invalid character entered";
                return false;
            }
        }
        if((leftPranPosi != -1 && infix[leftPranPosi+1] != '(') 
            && (infix[leftPranPosi+1] < '0' 
            || infix[leftPranPosi+1] > '9')){
            error = "parenthesis not placed correctly\n";
            throw "parenthesis not placed correctly\n";
        }
        if((rightPranPosi != -1 && infix[rightPranPosi-1] != ')')
            && (infix[rightPranPosi-1] < '0' 
            || infix[rightPranPosi-1] > '9')){
            error = "parenthesis not placed correctly\n";
            throw "parenthesis not placed correctly\n";
        }
        if(rightPran > leftPran){
            error = "parenthesis doesn't match";
            throw "parenthesis doesn't match";
            return false;
        }
    }
    if(opers >= numbers || opers < (numbers-1)){
        error = "invalid expression";
        throw "invalid expression";
        return false;
    }
    if(rightPran != leftPran){
        error =  "parenthesis doesn't match";
        throw "parenthesis doesn't match";
        return false;
    }
    return true;
}

double expression::evalInfix(){
    try{
        double ans = 0;
        validateInfix();
        infixToPostfix();
        ans = solvePostfix();
        return ans;
    }
    catch(const char *msg){
        cout<<msg<<endl;
        return 0.39;
    }
}

void expression::infixToPostfix(){
    charStack cstack;
    cstack.push('$');
    int i, k, len;
    len = strlen(infix);
    i = 0;
    k = 0;
    for(i=0; i<len; i++){
        if((infix[i] >= '0' && infix[i] <= '9') || infix[i] == '.'){
            if(i==0 || (infix[i-1] != '.' && (
               infix[i-1] < '0' || infix [i-1] > '9'))){
                postfix[k++] = '|';
            }
            postfix[k++] = infix[i];
        }
        else{
            if(getPrecedence(infix[i]) > getPrecedence(cstack.showLast()) || infix[i] == '('){
                cstack.push(infix[i]);
            }
            else{
                while(cstack.showLast() != '$' 
                      && (getPrecedence(cstack.showLast()) >= getPrecedence(infix[i]))){
                    if(postfix[k-1] >= '0' && postfix[k-1] <= '9'){
                        postfix[k++] = '|';
                    }
                    postfix[k++] = cstack.pop();
                }
                if(infix[i] == ')'){
                    cstack.pop();
                }
                else{
                    cstack.push(infix[i]);
                }
            }
        }
    }
    if(cstack.showLast() != '$'){
        while(cstack.showLast() != '$'){
            if(postfix[k-1] >= '0' && postfix[k-1] <= '9'){
                postfix[k++] = '|';
            }
            postfix[k++] = cstack.pop();
        }
    }
    postfix[k] = '\0';
}

double expression::toDouble(const char str[]){
    int len, i;
    int increDeci = 0;
    double result=0;
    int countDeci = 0;
    len = strlen(str);
    for(i=0; i<len; i++){
        if(str[i] >= '0' && str[i] <= '9'){
            result = result*10 + (str[i]-48);
            if(increDeci)
                ++countDeci;
        }
        else{
            increDeci = 1;
        }
    }
    for(i=0; i<countDeci; i++){
        result /= 10;
    }
    return result;
}

double expression::solvePostfix(){
    doubStack dstack;
    double elem;
    double ans = 0.39;
    int i, len, k;
    len = strlen(postfix);
    k = 0;
    for(i=0; i<len; i++){
        if(postfix[i] == '|'){
            i++;
            char str[100];
            while(postfix[i] != '|' && i<len){
                str[k++] = postfix[i];
                i++;
            }
            str[k] = '\0';
            elem = toDouble(str);
            dstack.push(elem);
            if(i < len && (postfix[i+1] >= '0' && postfix[i+1] <= '9')){
                i--;
            }
        }
        else{
            double elem_2 = dstack.pop();
            double elem_1 = dstack.pop();
            switch(postfix[i]){
                case '+':
                    elem_1 += elem_2;
                    break;
                case '-':
                    elem_1 -= elem_2;
                    break;
                case '*':
                    elem_1 *= elem_2;
                    break;
                case '/':
                    elem_1 /= elem_2;
                    break;
            }
            dstack.push(elem_1);
        }
        k = 0;
    }
    if(!dstack.isEmpty())
        ans = dstack.pop();
    return ans;
}

int main(){
    double ans;
    expression infix;
    infix = "(1+9.66)*(3*4*(8/45)*634-78)";
    ans = infix.evalInfix();
    cout << infix <<endl;
    cout << "ans "<<ans<<endl;
}
