void scrollString(char str[]);
void displayString(char str[], int showFor);
void displayAlpha(char toPrint, int showFor);
const byte rows[] = {1, 2, 3, 4, 5};
const byte cols[] = {6, 7, 8, 9, 10};                
byte bitSelect = 16;
unsigned long tame;
const char piyu[] = "mn";
byte alphabets[27][5] = {{14, 10, 14, 10, 10}, //a
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
                         {0, 0, 0, 0, 0},      //whitespace;
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
    scrollString(piyu);
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
    if(toPrint == 32){
        alpha = 26;
    }
    else{
        alpha = (toPrint-97);
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


void displayMat(byte mat[]){
    tame = millis();
        while(millis()-tame < 1000){
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

void scrollString(char str[]){
    byte current[5];
    byte next[5];
    byte tomap = B00100000;
    int i=0;
    int k=0;
    while(str[k+1] != NULL){
        tomap = B00100000;
        for(i=0; i<5; i++){
            current[i] = alphabets[str[k]-97][i];
            next[i]    = alphabets[str[k+1]-97][i];
        }
        for(int j=0; j<6; j++){
            for(i=0; i<5; i++){
                if(tomap & next[i]){
                    current[i] = (current[i] | 1);
                }
            }
            displayMat(current);
            tomap >>= 1;
            for(i=0; i<5; i++){
                current[i] <<= 1;
            }
        }
        k++;
    }
}
