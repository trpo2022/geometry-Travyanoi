#ifndef LIBINTVECTOR_H
#define LIBINTVECTOR_H

typedef struct {
    double x;
    double y;
} point;

struct Figure {
    point first;
    point second;
    point third;
    point fourth;
    double radius;
    char* name;
    int flag_of_figure; // 0 - circle; 1 - triangle
};

int init(int num, char a[]);
int ctd(char a[],
        int count,
        int chrlen,
        int exp_num,
        int num,
        struct Figure* fig);
int circle_check(char a[], char b[]);
int triangle_check(char a[], char b[]);
double perimeter(double a[], int exp_num);
double volume(double a[], int exp_num);
struct Figure* fill_circle(double otvet[], int exp_num, struct Figure* circle2);
struct Figure*
fill_triangle(double otvet[], int exp_num, struct Figure* triangle2);
struct Figure* intersection_figures(struct Figure* fig);
int intersection_circle_circle(struct Figure circle1, struct Figure circle2);

#endif
