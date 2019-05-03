#include <stdio.h>

void printComb(char list[], int i, int n);

void change(char *elem);

int main(){
    char table[4] = { 'T', 'F', 'T', 'F' };
    printComb(table, 0, 4);
}

void printComb(char list[], int i, int n){
    if (i == n){
        for (int i=0; i<n; i++){
            printf("%c ", list[i]);
        }
        printf("\n");
    }
    else {
        printComb(list, i+1, n);
        change(&list[i]);
        printComb(list, i+1, n);
        change(&list[i]);
    }
}

void change(char *elem){
    if (*elem == 'T'){
        *elem = 'F'; 
    }
    else {
        *elem = 'T';
    }
}