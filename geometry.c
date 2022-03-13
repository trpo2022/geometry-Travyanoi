#include <stdio.h>
#include <stdlib.h>
#define STRLEN 50

typedef struct{
    int x;
    int y;
} point;

typedef struct{
    point first;
    int radius;
} Circle;

typedef struct{
    point first;
    point second;
    point third;
    point fourth;
} Triangle;

int main()
{
    int init(int num, char a[]);
    int ctd(char a[], int count, int chrlen, int exp_num);
    int circle_check(char a[], char b[]);
    int triangle_check(char a[], char b[]);
    char first[STRLEN];
    char second[STRLEN];
    char third[STRLEN];

    init(1, first);
    init(2, second);
    init(3, third);

    return 0;
}

int init(int num, char a[])
{
    int ctd(char a[], int count, int chrlen, int exp_num);
    int circle_check(char a[], char b[]);
    int triangle_check(char a[], char b[]);
    char triangle[9] = {"triangle"};
    char circle[7] = {"circle"};
    int figure_flag = 0;
    int chrlen = 0;
    int count = 0;
    int flag = 0;

    printf("Enter figure %d:\n", num);
    while((a[chrlen] = getchar()) != '\n'){
        if(a[chrlen] == '('){
            count = chrlen;
        }
        chrlen++;
    }
    a[chrlen] = '\0';

    if((a[0] == circle[0]) || (a[0] == circle[0] - ' ')){
        if((figure_flag = circle_check(a, circle)) == 10){
            return 1;
        } else {
            flag = ctd(a, count, chrlen, 3); 
            if(flag == 10){
                return 1;
            }
        }

    } else if ((a[0] == triangle[0]) || (a[0] == triangle[0] - ' ')){
        if((figure_flag = triangle_check(a, triangle)) == 10){
            return 1;
        } else {
            flag = ctd(a, count, chrlen, 4); 
            if(flag == 10){
                return 1;
            }
        }

    } else {
        printf("Unexpected figure!\n");
        return 1;
    }

    return 0;

}

int circle_check(char a[], char b[])
{
    for(int i = 1; a[i] != '('; i++){
        if((a[i] == b[i]) || (a[i] == b[i] - ' ')){
            continue;
        } else {
            printf("Unexpected figure. Maybe you put something between 'circle' and '(', check it.\n");
            return 10;
        }
    }

    return 0;

}

int triangle_check(char a[], char b[])
{
    for(int i = 1; a[i] != '('; i++){
        if((a[i] == b[i]) || (a[i] == b[i] - ' ')){
        } else {
            printf("Unexpected figure or you put something between 'triangle' and '('\n");
            return 10;
        }
    }

    return 0;
}

int ctd(char a[], int count, int chrlen, int exp_num)
{

    for(int k = count + 1; k < chrlen - 1; k++){
        if(a[k] == ' ' || a[k] == ',' || a[k] == '.' || ('0' <= a[k] && a[k] <= '9')){  // проверка, что при вводе координат нет никакаих букв и т.д
            continue;
        } else {
            printf("Incorret input!\n");
            return 10;
        }
    }

    double otvet[8] = {0};
    char converter[20] = {'0'};

    for(int i = 0; i <= 7; i++){
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
    }
    if(exp_num == 3){
        printf("Circle's x = %.2lf, y = %.2lf\n", otvet[0], otvet[1]);
        printf("Circle's radius = %.2lf\n", otvet[2]);
    }

    if(exp_num == 4){

        if((otvet[0] != otvet[6]) && (otvet[1] != otvet[7])){
            printf("First and last coordinate can't be different!\n");
            return 10;
        }
        
        for(int k = 0; k < exp_num; k++){
            printf("Triangle's x%d = %.2lf, y%d = %.2lf\n", k+1, otvet[k*2], k+1, otvet[k*2 + 1]);
        }
    }
    
    return 0;
}