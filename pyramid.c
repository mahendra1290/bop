#include<stdio.h>
#include<math.h>
void main(){
	char arr[7] = {'G','F','E','D','C','B','A'};
	int i=0;
	int j=0;
	for(i=0; i<7; i++){
		for(j=0; j<13; j++){
			if(j>(6-i) && j<(6+i)){
				printf("  ");
			}
			else{
				printf("%c ",arr[abs(6-j)]);
			}
		}
		printf("\n");
	}
}
