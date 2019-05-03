/**********************************
 * Author      : Mahendra Suthar
 * Date        : 22/04/2019
 * Description : Modular program to find all occurrences of a substring in the
 *               second string. Strings can be overlapping also Indices of all
 *               occurrences will be returned by the function and main will
 *               print those.
 * *******************************/

#include <stdio.h>
#include <stdlib.h>

int *isSubstring(char *subStr, char *str);

int main(){
    int *arr;
    char *str = "dra";
    char *sub = "draa";
    arr = isSubstring(sub, str);
    for(int i=1; i<=arr[0]; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
/*
 * Funtion: isSubstring
 * --------------------
 * checks for substring in given string
 * arguments : substring and main string
 * returns : the array of indices of all occurenes
 *           first element is lenght of array
 * 
 */
int *isSubstring(char *subStr, char *str){
    int i, j, k, l;
    int *arr;
    i = 0;
    j = 0;
    k = 0;
    l = 0;
    while (str[i] != '\0'){
        i++;
    }
    arr = malloc(sizeof(int)*i);
    i = 0;
    while (str[i] != '\0'){
        if (subStr[j] == str[i]){
            k = i;
            while (str[k] != '\0' && subStr[j] != '\0' && (subStr[j] == str[k])){
                k++;
                j++;
            }
            if (subStr[j] == '\0'){
                arr[1+l] = i;
                l++;
            }
            j = 0;
        }
        i++;
    }
    arr[0] = l;   //first value is length of array
    return arr;
}
