void scrollString(char str[], int speedd);
void displayString(char str[], int showFor);
void displayAlpha(char toPrint, int showFor);
void displayPattern(int showFor);

const byte rows[] = {1, 2, 3, 4, 5};
const byte cols[] = {6, 7, 8, 9, 10};                
byte bitSelect = 16;
unsigned long tame;
const char piyu[] = "hello world ! ";

byte pattern[50][5] = {{0, 0, 0, 0, 16},
                        {0, 0, 0, 16, 16},
                        {0, 0, 16, 16, 16},
                        {0, 16, 16, 16, 16},
                        {16, 16, 16, 16, 16},
                        {24, 16, 16, 16, 16},
                        {28, 16, 16, 16, 16},
                        {30, 16, 16, 16, 16},
                        {31, 16, 16, 16, 16},
                        {31, 17, 16, 16, 16},
                        {31, 17, 17, 16, 16},
                        {31, 17, 17, 17, 16},
                        {31, 17, 17, 17, 17},
                        {31, 17, 17, 17, 19},
                        {31, 17, 17, 17, 23},
                        {31, 17, 17, 17, 31},
                        {31, 17, 17, 17, 15},
                        {31, 17, 17, 1, 15},
                        {31, 17, 1, 1, 15},
                        {31, 1, 1, 1, 15},
                        {15, 1, 1, 1, 15},
                        {7, 1, 1, 1, 15},
                        {3, 1, 1, 1, 15},
                        {1, 1, 1, 1, 15},
                        {0, 1, 1, 1, 15},
                        {0, 0, 1, 1, 15},
                        {0, 0, 0, 1, 15},
                        {0, 0, 0, 0, 15},
                        {0, 0, 0, 0, 14},
                        {0, 0, 0, 0, 12},
                        {0, 0, 0, 0, 8},
                        {0, 0, 0, 0, 0},
                        {16, 0, 0, 0, 0},
                        {24, 16, 0, 0, 0},
                        {28, 24, 16, 0, 0},
                        {30, 28, 24, 16, 0},
                        {31, 30, 28, 24, 16},
                        {31, 31, 30, 28, 24},
                        {31, 31, 31, 30, 28},
                        {31, 31, 31, 31, 30},
                        {31, 31, 31, 31, 31},
                        {15, 31, 31, 31, 31},
                        {7, 15, 31, 31, 31},
                        {3, 7, 15, 31, 31},
                        {1, 3, 7, 15, 31},
                        {0, 1, 3, 7, 15},
                        {0, 0, 1, 3, 7},
                        {0, 0, 0, 1, 3},
                        {0, 0, 0, 0, 1},
                        {0, 0, 0, 0, 0}
                        };
byte alphabets[39][5] = {{14, 10, 14, 10, 10}, //a
                         {14, 10, 14, 10, 14}, //b
                         {14, 8, 8, 8, 14},    //c
                         {14, 9, 9, 9, 14},    //d
                         {14, 8, 14, 8, 14},   //e
                         {14, 8, 14, 8, 8},    //f
                         {7, 8, 11, 9, 7},     //g
                         {10, 10, 14, 10, 10}, //h
                         {14, 4, 4, 4, 14},    //i
                         {14, 4, 4, 12, 4},    //j
                         {9, 10, 12, 10, 9},   //k
                         {8, 8, 8, 8, 14},     //l
                         {17, 27, 21, 17, 17}, //m
                         {17, 25, 21, 19, 17}, //n
                         {14, 17, 17, 17, 14}, //o
                         {14, 9, 14, 8, 8},    //p
                         {30, 18, 22, 30, 1},  //q
                         {14, 9, 14, 12, 10},  //r
                         {6, 8, 12, 2, 12},    //s
                         {14, 4, 4, 4, 4},     //t
                         {9, 9, 9, 9, 15},     //u
                         {17, 17, 17, 10, 4},  //v
                         {17, 17, 21, 27, 17}, //w
                         {17, 10, 4, 10, 17},  //x
                         {10, 10, 4, 4, 4},    //y
                         {31, 2, 4, 8, 31},    //z
                         {0, 0, 0, 0, 0},      //whitespace
                         {4, 4, 4, 0, 4},      //exclamation
                         {10, 21, 17 ,10 ,4},//heart
                         {14, 10, 10, 10, 14},  //0
                         {4, 4, 4, 4, 4}, //1
                         {14, 2, 14, 8, 14}, //2
                         {14, 2, 14, 2, 14}, //3
                         {10, 10, 14, 2, 2},//4
                         {14, 8, 14, 2, 14},//5
                         {14, 8, 14, 10, 14},//6
                         {14, 2, 2, 2, 2},//7
                         {14, 10, 14, 10, 14},//8
                         {14, 10, 14, 2, 14}//9
                        };
void clearScreen(){
    for(int i=0; i<5; i++){
        digitalWrite(rows[i], HIGH);
        for(int j=0; j<5; j++){
            digitalWrite(cols[j], LOW);
        }
    }
}
void setup() {
    for(int i=0; i<5; i++){
        pinMode(rows[i], OUTPUT);
        digitalWrite(rows[i], HIGH);
        pinMode(cols[i], OUTPUT);
        digitalWrite(cols[i],LOW);
    }
    //Serial.begin(9600);
}
  
void loop() {
    scrollString(piyu, 200);
}

void displayString(char str[], int showFor){
    int i=0;
    while(i < str[i] != '\0'){
        displayAlpha(str[i], showFor);
        i++;
    }
}

void displayAlpha(char toPrint, int showFor){
    int alpha;
     if(toPrint >= 48 && toPrint <= 57){
            alpha = 29+(toPrint-48);
        }
        else if(toPrint == 32 || toPrint == 33 || toPrint == 34){
            alpha = 26+(toPrint-32);
        }
        else{
            alpha = toPrint-97;
        }
    tame = millis();
    while(millis()-tame < showFor){
        for(int i=0; i<5; i++){
            digitalWrite(rows[i], LOW);
            bitSelect = 16;
            for(int j=0; j<5; j++){
                if(bitSelect & alphabets[alpha][i]){
                    digitalWrite(cols[j], HIGH);
                }
                bitSelect >>= 1;
            }
            for(int k=0; k<5; k++){
                digitalWrite(cols[k], LOW);
            }
            digitalWrite(rows[i], HIGH);
        }
    }
}


void displayMat(byte mat[], int showFor){
    tame = millis();
        while(millis()-tame < showFor){
        for(int i=0; i<5; i++){
        digitalWrite(rows[i], LOW);
        bitSelect = 16;
        for(int j=0; j<5; j++){
            if(bitSelect & mat[i]){
                digitalWrite(cols[j], HIGH);
            }
            bitSelect >>= 1;
        }
        for(int k=0; k<5; k++){
            digitalWrite(cols[k], LOW);
        }
        digitalWrite(rows[i], HIGH);
        }
    }
}

void scrollString(char str[], int speedd){
    byte current[5];
    byte next[5];
    byte tomap = B00100000;
    int i=0;
    int k=0;
    int curr, nxt;
    while(str[k+1] != NULL){
        if(str[k] >= 48 && str[k] <= 57){
            curr = 29+(str[k]-48);
        }
        else if(str[k] == 32 || str[k] == 33|| str[k] == 34){
            curr = 26+(str[k]-32);
        }
        else{
            curr = str[k]-97;
        }
        if(str[k+1] >= 48 && str[k+1] <= 57){
            nxt = 29+(str[k+1]-48);
        }
        else if(str[k+1] == 32 || str[k+1] == 33 || str[k+1] == 34){
            nxt = 26+(str[k+1]-32);
        }
        else{
            nxt = str[k+1]-97;
        }
        tomap = B00100000;
        for(i=0; i<5; i++){
            current[i] = alphabets[curr][i];
            next[i]    = alphabets[nxt][i];
        }
        for(int j=0; j<5; j++){
            for(i=0; i<5; i++){
                if(tomap & next[i]){
                    current[i] = (current[i] | 1);
                }
            }
            displayMat(current, speedd);
            tomap >>= 1;
            for(i=0; i<5; i++){
                current[i] <<= 1;
            }
        }
        k++;
    }
}

void displayPattern(int showFor){
    for(int i=0; i<50; i++){
        displayMat(pattern[i], showFor);
    }
}
