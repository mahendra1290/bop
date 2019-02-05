#include<stdio.h>
#include<string.h>
#include<expression.h>

int main(){
    char str[MAX], post[MAX];
    char val;
    int len, ans;
    len = getInfix(str);
    if(len > 0){
		toPostfix(str, post, len);
        len = strlen(post);
        ans = evaluate(post, len);
        printf("ans %d\n", ans);
        printf("%s\n", post);
        to
    }
}

