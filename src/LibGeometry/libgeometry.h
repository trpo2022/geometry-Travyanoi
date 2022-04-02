#ifndef LIBINTVECTOR_H
#define LIBINTVECTOR_H

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

int init(int num, char a[]);
int ctd(char a[], int count, int chrlen, int exp_num);
int circle_check(char a[], char b[]);
int triangle_check(char a[], char b[]);
double perimeter(double a[], int exp_num);
double volume(double a[], int exp_num);


#endif
