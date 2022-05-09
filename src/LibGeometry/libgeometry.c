#include <LibGeometry/libgeometry.h>
#include <malloc.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define SQR(x) x* x

int init(int num, char a[])
{
    static struct Figure fig[3];
    char triangle[9] = {"triangle"};
    char circle[7] = {"circle"};
    int figure_flag = 0;
    int chrlen = 0;
    int count = 0;
    int flag = 0;

    printf("Enter figure %d\n(example: circle(x y, radius), triangle(x1 y1, x2 "
           "y2, x3 y3, x4 y4)):\n",
           num + 1);
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
            flag = ctd(a, count, chrlen, 3, num, fig);
            if (flag == 10) {
                return 10;
            }
        }

    } else if ((a[0] == triangle[0]) || (a[0] == triangle[0] - ' ')) {
        if ((figure_flag = triangle_check(a, triangle)) == 10) {
            return 10;
        } else {
            flag = ctd(a, count, chrlen, 4, num, fig);
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

int ctd(char a[],
        int count,
        int chrlen,
        int exp_num,
        int num,
        struct Figure* fig)
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
    struct Figure* circle2 = (struct Figure*)malloc(sizeof(struct Figure));
    if (exp_num == 3) {
        if (num == 0) {
            fig[num].name = "First circle";
            circle2 = fill_circle(otvet, exp_num, circle2);
            fig[num].first = circle2->first;
            fig[num].radius = circle2->radius;
        } else if (num == 1) {
            fig[num].name = "Second circle";
            circle2 = fill_circle(otvet, exp_num, circle2);
            fig[num].first = circle2->first;
            fig[num].radius = circle2->radius;
        } else if (num == 2) {
            fig[num].name = "Thirst circle";
            circle2 = fill_circle(otvet, exp_num, circle2);
            fig[num].first = circle2->first;
            fig[num].radius = circle2->radius;
        }
    }
    free(circle2);

    struct Figure* triangle2 = (struct Figure*)malloc(sizeof(struct Figure));
    if (exp_num == 4) {
        if ((otvet[0] != otvet[6]) && (otvet[1] != otvet[7])) {
            printf("First and last coordinate can't be different!\n");
            return 10;
        }

        if (num == 0) {
            fig[num].name = "First triangle";
            triangle2 = fill_triangle(otvet, exp_num, triangle2);
            fig[num].first = triangle2->first;
            fig[num].second = triangle2->second;
            fig[num].third = triangle2->third;
            fig[num].fourth = triangle2->fourth;
        } else if (num == 1) {
            fig[num].name = "Second triangle";
            triangle2 = fill_triangle(otvet, exp_num, triangle2);
            fig[num].first = triangle2->first;
            fig[num].second = triangle2->second;
            fig[num].third = triangle2->third;
            fig[num].fourth = triangle2->fourth;
        } else if (num == 2) {
            fig[num].name = "Thirst triangle";
            triangle2 = fill_triangle(otvet, exp_num, triangle2);
            fig[num].first = triangle2->first;
            fig[num].second = triangle2->second;
            fig[num].third = triangle2->third;
            fig[num].fourth = triangle2->fourth;
        }
    }
    free(triangle2);
    if (num == 2) {
        intersection_figures(fig);
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

struct Figure* fill_circle(double otvet[], int exp_num, struct Figure* circle2)
{
    circle2->flag_of_figure = 0;
    circle2->first.x = otvet[0];
    circle2->first.y = otvet[1];
    circle2->radius = otvet[2];
    printf("Circle's x = %.2lf, y = %.2lf\n",
           circle2->first.x,
           circle2->first.y);
    printf("Circle's radius = %.2lf\n", circle2->radius);
    printf("Perimeter of circle = %lf\n", perimeter(otvet, exp_num));
    printf("Volume of circle = %lf\n", volume(otvet, exp_num));
    return circle2;
}

struct Figure*
fill_triangle(double otvet[], int exp_num, struct Figure* triangle2)
{
    triangle2->flag_of_figure = 1;
    triangle2->first.x = otvet[0];
    triangle2->first.y = otvet[1];
    triangle2->second.x = otvet[2];
    triangle2->second.y = otvet[3];
    triangle2->third.x = otvet[4];
    triangle2->third.y = otvet[5];
    triangle2->fourth.x = otvet[6];
    triangle2->fourth.y = otvet[7];
    printf("Triangle's coordinates:\nx1 - %.2lf, y1 - %.2lf\nx2 - %.2lf, y2 - "
           "%.2lf\nx3 - %.2lf, y3 - %.2lf\nx4 - %.2lf, y4 - %.2lf\n",
           triangle2->first.x,
           triangle2->first.y,
           triangle2->second.x,
           triangle2->second.y,
           triangle2->third.x,
           triangle2->third.y,
           triangle2->fourth.x,
           triangle2->fourth.y);
    printf("Perimeter of triangle = %.2lf\n", perimeter(otvet, exp_num));
    printf("Volume of triangle = %.2lf\n", volume(otvet, exp_num));

    return triangle2;
}

struct Figure* intersection_figures(struct Figure* fig)
{
    if (fig[0].flag_of_figure == 0) {
        if (fig[1].flag_of_figure == 0) {
            intersection_circle_circle(fig[0], fig[1]);
        }
        if (fig[2].flag_of_figure == 0) {
            intersection_circle_circle(fig[0], fig[2]);
        }
    }

    if (fig[1].flag_of_figure == 0) {
        if (fig[2].flag_of_figure == 0) {
            intersection_circle_circle(fig[1], fig[2]);
        }
    }
    return 0;
}

int intersection_circle_circle(struct Figure circle1, struct Figure circle2)
{
    float gip;
    float sum_radius = circle1.radius + circle2.radius;
    gip
            = sqrt(SQR(fabs(circle1.first.x - circle2.first.x))
                   + SQR(fabs(circle1.first.y - circle2.first.y)));
    if (sum_radius >= gip) {
        printf("%s intersects with %s\n", circle1.name, circle2.name);
        return 0;
    } else {
        printf("%s not intersects with %s\n", circle1.name, circle2.name);
    }
    return -1;
}
