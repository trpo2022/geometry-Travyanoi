#include <LibGeometry/libgeometry.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define SQR(x) x* x

int init(int num, char a[])
{
    char triangle[9] = {"triangle"};
    char circle[7] = {"circle"};
    int figure_flag = 0;
    int chrlen = 0;
    int count = 0;
    int flag = 0;

    printf("Enter figure %d\n(example: circle(x y, radius), triangle(x1 y1, x2 "
           "y2, x3 y3, x4 y4)):\n",
           num);
    while ((a[chrlen] = getchar()) != '\n') {
        if (a[chrlen] == '(') {
            count = chrlen;
        }
        chrlen++;
    }
    a[chrlen] = '\0';

    if ((a[0] == circle[0]) || (a[0] == circle[0] - ' ')) {
        if ((figure_flag = circle_check(a, circle)) == 10) {
            return 10;
        } else {
            flag = ctd(a, count, chrlen, 3);
            if (flag == 10) {
                return 10;
            }
        }

    } else if ((a[0] == triangle[0]) || (a[0] == triangle[0] - ' ')) {
        if ((figure_flag = triangle_check(a, triangle)) == 10) {
            return 10;
        } else {
            flag = ctd(a, count, chrlen, 4);
            if (flag == 10) {
                return 10;
            }
        }

    } else {
        printf("Unexpected figure! You must enter 'circle' or 'triangle'.\n");
        return 10;
    }

    return 0;
}

int circle_check(char a[], char b[])
{
    for (int i = 1; a[i] != '('; i++) {
        if ((a[i] == b[i]) || (a[i] == b[i] - ' ')) {
            continue;
        } else {
            printf("Unexpected figure. Maybe you put something between "
                   "'circle' and '(', check it.\n");
            return 10;
        }
    }

    return 0;
}

int triangle_check(char a[], char b[])
{
    for (int i = 1; a[i] != '('; i++) {
        if ((a[i] == b[i]) || (a[i] == b[i] - ' ')) {
        } else {
            printf("Unexpected figure or you put something between 'triangle' "
                   "and '('\n");
            return 10;
        }
    }

    return 0;
}

int ctd(char a[], int count, int chrlen, int exp_num)
{
    for (int k = count + 1; k < chrlen - 1; k++) {
        if (a[k] == ' ' || a[k] == ',' || a[k] == '.'
            || ('0' <= a[k]
                && a[k] <= '9')) { // проверка, что при вводе координат нет
                                   // никакаих букв и т.д
            continue;
        } else {
            printf("Incorret input!\n");
            return 10;
        }
    }

    if (a[chrlen - 1] != ')') {
        printf("Expected ')'\n");
        return 10;
    }

    double otvet[8] = {0};
    char converter[20] = {'0'};

    for (int i = 0; i <= 7; i++) {
        int k = 0;
        for (count += 1; count < chrlen; count++) {
            if (a[count] == ' ' || a[count] == ')' || a[count] == ',') {
                continue;
            } else {
                if (a[count + 1] == ' ' || a[count + 1] == ','
                    || a[count + 1] == ')') {
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
    if (exp_num == 3) {
        printf("Circle's x = %.2lf, y = %.2lf\n", otvet[0], otvet[1]);
        printf("Circle's radius = %.2lf\n", otvet[2]);
        printf("Perimeter of circle = %lf\n", perimeter(otvet, exp_num));
        printf("Volume of circle = %lf\n", volume(otvet, exp_num));
    }

    if (exp_num == 4) {
        if ((otvet[0] != otvet[6]) && (otvet[1] != otvet[7])) {
            printf("First and last coordinate can't be different!\n");
            return 10;
        }

        for (int k = 0; k < exp_num; k++) {
            printf("Triangle's x%d = %.2lf, y%d = %.2lf\n",
                   k + 1,
                   otvet[k * 2],
                   k + 1,
                   otvet[k * 2 + 1]);
        }
        printf("Perimeter of triangle = %.2lf\n", perimeter(otvet, exp_num));
        printf("Volume of triangle = %.2lf\n", volume(otvet, exp_num));
    }

    return 0;
}

double perimeter(double a[], int exp_num)
{
    double answer;
    if (exp_num == 3) {
        answer = 2 * M_PI * a[2];
    } else {
        double first_side = sqrt(SQR((a[3] - a[1])) + SQR((a[2] - a[0])));
        double second_side = sqrt(SQR((a[5] - a[3])) + SQR((a[4] - a[2])));
        double third_side = sqrt(SQR((a[5] - a[1])) + SQR((a[4] - a[0])));
        answer = first_side + second_side + third_side;
    }

    return answer;
}

double volume(double a[], int exp_num)
{
    double answer;
    if (exp_num == 3) {
        answer = M_PI * SQR(a[2]);
    } else {
        double first_side = sqrt(SQR((a[3] - a[1])) + SQR((a[2] - a[0])));
        double second_side = sqrt(SQR((a[5] - a[3])) + SQR((a[4] - a[2])));
        double third_side = sqrt(SQR((a[5] - a[1])) + SQR((a[4] - a[0])));
        double half_perim = (first_side + second_side + third_side) / 2;
        answer = sqrt(
                half_perim * (half_perim - first_side)
                * (half_perim - second_side) * (half_perim - third_side));
    }

    return answer;
}
