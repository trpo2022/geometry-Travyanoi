#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define SQR(x) x*x

typedef struct{
    double x;
    double y;
    double radius;
} Circle;

double char_to_double()
{
    double number;
    char last_symb;
    int integer;
    char intch;
    int dec_length;
    while ((last_symb = getchar()) == ' ') continue;

        integer = (last_symb - '0') * 10;
        while ((intch = getchar()) != '.'){
            integer = (intch - '0' + integer) * 10;
        }

        integer /= 10;
        float dec = 0;
        char decch;
        dec_length = 0;

        while ( ((decch = getchar()) != ' ') && (decch != ',') ){
            
            dec = (decch - '0' + dec) * 10;
            dec_length += 1;
        }

        dec /= 10;
        dec /= pow(10, dec_length);
        number = integer + dec;

        return number;

}

double char_to_double_last()
{
    double number;
    char last_symb;
    int integer;
    char intch;
    int dec_length;
    while ((last_symb = getchar()) == ' ') continue;

        integer = (last_symb - '0') * 10;
        while ((intch = getchar()) != '.'){
            integer = (intch - '0' + integer) * 10;
        }

        integer /= 10;
        float dec = 0;
        char decch;
        dec_length = 0;

        while (((decch = getchar()) != ')') && (decch != ' ')){
            dec = (decch - '0' + dec) * 10;
            dec_length += 1;
        }

        dec /= 10;

        if (decch != ')'){
            while ((last_symb = getchar()) == ' ') continue;
            if (last_symb != ')'){
                printf("Expected ')'\n");
                return 0;
            }
        }

        dec /= pow(10, dec_length);
        number = integer + dec;

        return number;

}

void output(Circle universal)
{
    double perimeter; 
    double area;
    perimeter = 2 * M_PI * universal.radius;
    area = M_PI * SQR(universal.radius);
    printf("Perimeter = %lf\nArea = %lf\n", perimeter, area);
}

int main()
{
    int intersection_circles(Circle a, Circle b);
    int i, is_circle1 = 0, is_circle2 = 0;
    Circle first;
    Circle second;
    char figure1[50];
    char figure2[50];
    char circle[7] = {"circle"};
    
    printf("Enter first figure\n");

    i = 0;
    while ((figure1[i] = getchar()) != '('){
        i++;
    }
    
    if ((figure1[0] == circle[0]) || (figure1[0] == circle[0] - 32)){
        for (i = 1; figure1[i] != '('; i++) {
            if ((figure1[i] == circle[i]) || (figure1[i] == circle[i] - 32)){
                is_circle1 = 1;
            } else {
                is_circle1 = 0;
                break;
            }
        }
    }

    
    if (is_circle1 == 1){
        
        first.x = char_to_double();
        first.y = char_to_double();
        first.radius = char_to_double_last();
        if (first.radius == 0){
            printf("Radius of second circle can't be zero, type another digit\n");
            return 0;
        }

        output(first);

    } else {
        printf("Unexpected figure\n");
    } 

    printf("Enter second figure\n");
    getchar();
    
    i = 0;
    while ((figure2[i] = getchar()) != '('){
        i++;
    }
    
    if ((figure2[0] == circle[0]) || (figure2[0] == circle[0] - 32)) {
        for (i = 1; figure2[i] != '('; i++) {
            if ((figure2[i] == circle[i]) || (figure2[i] == circle[i] - 32)) {
                is_circle2 = 1;
            } else {
                is_circle2 = 0;
                break;
            }
        }
    }
    
    if (is_circle2 == 1){
        
        second.x = char_to_double();
        second.y = char_to_double();
        second.radius = char_to_double_last();
        if (second.radius == 0){
            printf("Radius of second circle can't be zero, type another digit\n");
            return 0;
        }

        output(second);

    } else {
        printf("Unexpected figure\n");
    } 

    int flag;
    flag = intersection_circles(first, second);

    if (flag == 1){
        printf("Пересекаются\n");
    } else {
        printf("Не пересекаются\n");
    }

    return 0;
}

int intersection_circles(Circle first, Circle second)
{
    int flag = 0;
    double x_difference;
    double y_difference;
    double r_vec;
    double r_summ;

    x_difference = abs(first.x - second.x);
    y_difference = abs(first.y - second.y);

    r_vec = sqrt(SQR(x_difference) + SQR(y_difference));
    r_summ = first.radius + second.radius;

    if (r_vec <= r_summ){
        flag = 1;
    } else {
        flag = 0;
    }

    return flag;
}