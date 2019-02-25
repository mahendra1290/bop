#include<stdio.h>
#include<string.h>
#include"expression.c"
#include<time.h>

int main(){
    srand(time(0));
    int i;
    int inflen, ans, postlen;
    char str[MAX], post[MAX];
    char val;
    for(i=0; i<10; i++){
        char *mine = makeInfix();
	    printf("%s\n", mine);
    }
    inflen = getInfix(str);
    if(validateInfix(str, inflen)){
        convertInfixToPostfix   (str, post, inflen);
        postlen = strlen(post);
        ans = solvePostfix(post, postlen);
        printf("%s\n", post);
        printf("solu : %d", ans);
    }
    else{
        printf("sorry input is not correct...\n");
    }
    printf("ansss = %d", ((((7+9)-7)*7)*7+4));
    return 0;
}

