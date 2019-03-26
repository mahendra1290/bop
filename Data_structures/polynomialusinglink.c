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
    return startTerm;
}

polyTerm *addPolynomial(polyTerm *poly_1, polyTerm *poly_2){
    int exponOfA, exponOfB, exponOfC;
    int valOfA, valOfB, valOfC;
    polyTerm *tempPolyA = NULL;
    polyTerm *tempPolyB = NULL;
    polyTerm *startTerm = NULL;
    polyTerm *newTerm   = NULL;
    polyTerm *prevTerm  = NULL;
    tempPolyA = poly_1;
    tempPolyB = poly_2;
    while(tempPolyA != NULL && tempPolyB != NULL){
        exponOfA = tempPolyA->expo;
        exponOfB = tempPolyB->expo;
        valOfA   = tempPolyA->val;
        valOfB   = tempPolyB->val;
        if(exponOfA == exponOfB){
            valOfC   = valOfA+valOfB;
            tempPolyA = tempPolyA->nextTermPtr;
            tempPolyB = tempPolyB->nextTermPtr;
            if(valOfC != 0)
                exponOfC = exponOfA;
            else
                continue;
        }
        else if(exponOfA > exponOfB){
            valOfC = valOfA;
            exponOfC = exponOfA;
            tempPolyA = tempPolyA->nextTermPtr;
        }
        else if(exponOfA < exponOfB){
            valOfC = valOfB;
            exponOfC = exponOfB;
            tempPolyB = tempPolyB->nextTermPtr;
        }
        newTerm = (polyTerm *)malloc(sizeof(polyTerm));
        if(prevTerm != NULL){
            prevTerm->nextTermPtr = newTerm;
        }
        if(startTerm == NULL){
            startTerm = newTerm;
        }
        newTerm->expo = exponOfC;
        newTerm->val  = valOfC;
        prevTerm = newTerm;
    }
    while(tempPolyA != NULL){
        newTerm = (polyTerm *)malloc(sizeof(polyTerm));
        if(startTerm == NULL){
            startTerm = newTerm;
        }
        newTerm->expo = tempPolyA->expo;
        newTerm->val  = tempPolyA->val;
        if(prevTerm != NULL)
            prevTerm->nextTermPtr = newTerm;
        prevTerm  = newTerm;
        tempPolyA = tempPolyA->nextTermPtr;
    }
    while(tempPolyB != NULL){
        newTerm = (polyTerm *)malloc(sizeof(polyTerm));
        if(startTerm == NULL){
            startTerm = newTerm;
        }
        newTerm->expo = tempPolyB->expo;
        newTerm->val  = tempPolyB->val;
        if(prevTerm != NULL)
            prevTerm->nextTermPtr = newTerm;
        prevTerm  = newTerm;
        tempPolyB = tempPolyB->nextTermPtr;
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



