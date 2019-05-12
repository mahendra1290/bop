#include <assert.h>
#include <stdio.h>
#include <time.h>

/******************************
 * Author      : Mahendra Suthar
 * Date        : 19/04/2019
 * Description : program to implement two stack in single array
 * ****************************/
int main(int argc, char** argv){
    char *day = ["Mon", "Tue", "Wed", "Thr", "Fri", "Sat", "Sun"];
    char *month = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "Octomber", "November", "December"];
    char *author = "Mahendra Suthar\n";
    char *filename = "";
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char s[64];
    printf("%d", tm->tm_mon);
    assert(strftime(s, sizeof(s), "%c", tm));
    if (argc > 1){
        printf("hello\n");
        filename = argv[1];
        FILE *file = fopen(filename, "r+");
        if (file != NULL){
            fprintf(file, "/******************************\n");
            fprintf(file, "* Author      : ");
            fprintf(file, author);
            fprintf(file, "* Date        : ");
            fprintf(file, "%s\n", s);
            fprintf(file, "* ****************************/\n");
            fclose(file);
        }
        else{

        }
    }
    return 0;
}