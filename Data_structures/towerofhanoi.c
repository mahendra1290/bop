//to show all steps to solve tower of hanoi problem
#include <stdio.h>

void solveTowerOfHanoi(int disks, int curr, int dest);
int getExtraTower(int curr, int dest);

int main(){
    solveTowerOfHanoi(5 , 0, 2);
}

void solveTowerOfHanoi(int disks, int curr, int dest){
    if(disks == 1){
        printf("put disk %d from %d to %d\n\n", disks, curr+1, dest+1);
        return;
    }
    int extra = getExtraTower(curr, dest);
    solveTowerOfHanoi(disks-1, curr, extra);
    printf("put disk %d from %d to %d\n\n", disks, curr+1, dest+1);
    solveTowerOfHanoi(disks-1, extra, dest);
}

int getExtraTower(int curr, int dest){
    int extra;
    if(curr == 0){
        if(dest == 1){
            extra = 2;
        }
        else{
            extra = 1;
        }
    }
    else if(curr == 1){
        if(dest == 0){
            extra = 2;
        }
        else{
            extra = 0;
        }
    }
    else{
        if(dest == 1){
            extra = 0;
        }
        else{
            extra = 1;
        }
    }
    return extra;
}