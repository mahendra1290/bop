#include<stdio.h>
#include<stdlib.h>

typedef struct polyTerm{
    int expo;
	int val;
	struct polyTerm *nextTermPtr;
}polyTerm;

polyTerm *getPolynomial();
polyTerm *addPolynomials(polyTerm *poly_1, polyTerm *poly_2);
polyTerm *multiplyPolynomials(polyTerm *poly_1, polyTerm *poly_2);
void printPolynomial(polyTerm *poly);

int main(){
    polyTerm *poly_1;
    polyTerm *poly_2;
    polyTerm *poly_3;
    poly_1 = getPolynomial();
    printPolynomial(poly_1);
    poly_2 = getPolynomial();
    printPolynomial(poly_2);
    poly_3 = multiplyPolynomials(poly_1, poly_2);
    printPolynomial(poly_3);
    return 0;
}

polyTerm *getPolynomial(){
    char conti = 'y';
    polyTerm *startTerm = NULL;
    polyTerm *prevTerm = NULL;
    polyTerm *term;
    startTerm = (polyTerm *)malloc(sizeof(polyTerm));
    if(startTerm == NULL){
        printf("System error: memory can't be allocated\n");
        return NULL;
    }
    prevTerm = startTerm;
    printf("Enter the exponent and value of polynomial terms\n");
    printf("warning: enter exponent in only decreasing order\n");
    printf("<---------------------------------------------->\n");
    printf("enter value and exponent: ");
    scanf("%d %d", &startTerm->val, &startTerm->expo);
    printf("want to add more term? [y\\n] ");
    scanf(" %c", &conti);
    while(conti == 'y' || conti == 'Y'){
        term = (polyTerm *)malloc(sizeof(polyTerm));
        if(term == NULL){
            printf("System error: memory can't be allocated\n");
            return NULL;
        }
        printf("enter value and exponent: ");
        scanf("%d %d", &term->val, &term->expo);
        prevTerm->nextTermPtr = term;
        prevTerm = term;
        printf("want to add more term? [y\\n] ");
        scanf(" %c", &conti);
    }
    prevTerm->nextTermPtr = NULL;
    return startTerm;
}

polyTerm *addPolynomial(polyTerm *poly_1, polyTerm *poly_2){
    int exponOfA, exponOfB, exponOfC;
    int valOfA, valOfB, valOfC;
    polyTerm *tempA = NULL;
    polyTerm *tempB = NULL;
    polyTerm *startTerm = NULL;
    polyTerm *newTerm   = NULL;
    polyTerm *prevTerm  = NULL;
    tempA = poly_1;
    tempB = poly_2;
    while(tempA != NULL && tempB != NULL){
        if(tempA->expo == tempB->expo){
            valOfC   = tempA->val + tempB->val;
            tempA = tempA->nextTermPtr;
            tempB = tempB->nextTermPtr;
            if(valOfC != 0)
                exponOfC = tempA->expo;
        }
        else if(tempA->expo > tempB->expo){
            valOfC = tempA->val;
            exponOfC = tempA->expo;
            tempA = tempA->nextTermPtr;
        }
        else if(tempA->expo < tempB->expo){
            valOfC = tempB->val;
            exponOfC = tempB->expo;
            tempB = tempB->nextTermPtr;
        }
        newTerm = (polyTerm *)malloc(sizeof(polyTerm));
        newTerm->expo = exponOfC;
        newTerm->val  = valOfC;
        if(prevTerm != NULL){
            prevTerm->nextTermPtr = newTerm;
        }
        if(startTerm == NULL){
            startTerm = newTerm;
        }
        prevTerm = newTerm;
    }
    while(tempA != NULL || tempB){
        newTerm = (polyTerm *)malloc(sizeof(polyTerm));
        if(startTerm == NULL){
            startTerm = newTerm;
        }
        if(tempA != NULL){
            newTerm->expo = tempA->expo;
            newTerm->val  = tempA->val;
            tempA = tempA->nextTermPtr;
        }
        else{
            newTerm->expo = tempB->expo;
            newTerm->val  = tempB->val;
            tempB = tempB->nextTermPtr;
        }
        if(prevTerm != NULL)
            prevTerm->nextTermPtr = newTerm;
        prevTerm  = newTerm;
    }
    return startTerm;
}

void printPolynomial(polyTerm *poly){
    polyTerm *tempPoly = NULL;
    int first = 1;
    tempPoly = poly;
    if(poly == NULL){
        printf("no polynomial to print\n");
    }
    else{
        while(tempPoly != NULL){
            if(tempPoly->val > 0 && first != 1)
                printf("+ %dx^%d ", tempPoly->val, tempPoly->expo);
            else
                printf("%dx^%d ", tempPoly->val, tempPoly->expo);
            tempPoly = tempPoly->nextTermPtr;
            first++;
        }
    }
    printf("\n");
}

polyTerm *multiplyPolynomials(polyTerm *poly_1, polyTerm *poly_2){
    polyTerm *tempPolyA = NULL;
    polyTerm *tempPolyB = NULL;
    polyTerm *tempTerm = NULL;
    polyTerm *startTerm = NULL;
    tempPolyA = poly_1;
    tempPolyB = poly_2;
    if(tempPolyA == NULL || tempPolyB == NULL){
        printf("can,t multiply single polynomial\n");
        return startTerm;
    }
    while(tempPolyA != NULL){
        while(tempPolyB != NULL){
            tempTerm = (polyTerm *)malloc(sizeof(polyTerm));
            tempTerm->expo = tempPolyA->expo + tempPolyB->expo;
            tempTerm->val  = tempPolyA->val * tempPolyB->val;
            startTerm = addPolynomial(startTerm, tempTerm);
            tempPolyB = tempPolyB->nextTermPtr;
            free(tempTerm);
        }
        tempPolyB = poly_2;
        tempPolyA = tempPolyA->nextTermPtr;
    }
    return startTerm;
}
