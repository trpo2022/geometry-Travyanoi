#include <stdio.h>
#include <stdlib.h>
#define STRLEN 50

int main()
{
    int ctd(char a[], int count, int chrlen);
    int circle_check(char a[], char b[]);
    char first[STRLEN];
    char second[STRLEN];
    char circle[STRLEN] = {"circle                                        "};
    int count;
    //char triangle[9] = {"triangle"};
    int c_ch_flag = 0;

    printf("Enter first figure:\n");
    int chrlen = 0;
    while((first[chrlen] = getchar()) != '\n'){
        if(first[chrlen] == '('){
            count = chrlen;
        }
        chrlen++;
    }
    first[chrlen] = '\0';

    if(first[chrlen - 1] != ')'){
        printf("Expected ')'!\n");
        return 1;
    }

    if((first[0] == circle[0]) || (first[0] == circle[0] - 32)){
        c_ch_flag = circle_check(first, circle);
    } else {
        printf("Unexpected figure!\n");
        return 2;
    }

    if(c_ch_flag == 10){
        return 3;
    }

    int flag;
    flag = ctd(first, count, chrlen); 
    if(flag == 10){
        return 4;
    }

    int cool = 0;
    count = 0;
    printf("Enter second figure!\n");
    while((second[cool] = getchar()) != '\n'){
        if(second[cool] == '('){
            count = cool;
        }
        cool++;
    }
    second[cool] = '\0';

    if(second[cool - 1] != ')'){
        printf("Expected ')'!\n");
        return 5;
    }

    if((second[0] == circle[0]) || (second[0] == circle[0] - 32)){
        c_ch_flag = circle_check(second, circle);
    } else {
        printf("Unexpected figure!\n");
        return 6;
    }

    if(c_ch_flag == 10){
        return 7;
    }

    flag = ctd(second, count, cool); 
    if(flag == 10){
        return 8;
    }
     
    return 0;
}

int circle_check(char a[], char b[])
{
    int flag = 0;
    int i;
    for(i = 1; a[i] != '('; i++){
        if((a[i] == b[i]) || (a[i] == b[i] - 32)){
            flag = 1;
        } else {
            flag = 0;
            printf("Unexpected figure!\n");
            return 10;
        }
    }

    return flag;
}

int ctd(char a[], int count, int chrlen)
{

    for(int k = count + 1; k < chrlen - 1; k++){
        if(a[k] == ' ' || a[k] == ',' || a[k] == '.' || ('0' <= a[k] && a[k] <= '9')){  // проверка, что при вводе координат нет никакаих букв и т.д
            continue;
        } else {
            printf("Incorret input!\n");
            return 10;
        }
    }

    double otvet[3];
    char converter[STRLEN] = {'0'};

    for(int i = 0; i < 3; i++){
        int k = 0;
        for(count += 1; count < chrlen; count++){
            if(a[count] == ' ' || a[count] == ')' || a[count] == ','){
                continue;
            } else {
                if(a[count + 1] == ' ' || a[count + 1] == ',' || a[count + 1] == ')'){
                    converter[k] = a[count];
                    converter[k + 1] = '\0';
                    count += 1;
                    break;
                }
                converter[k] = a[count];
                k++;
            }
        }
        otvet[i] = atof(converter);
        printf("%lf\n", otvet[i]);
    }
    
    return 0;
}