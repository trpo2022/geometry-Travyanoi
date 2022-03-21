#include <LibGeometry/libgeometry.h>
#define STRLEN 50

int main()
{
    char first[STRLEN];
    char second[STRLEN];
    char third[STRLEN];
    int flag;

    flag = init(1, first);
    if(flag == 10){
        return 10;
    }
    flag = init(2, second);
    if(flag == 10){
        return 10;
    }
    flag = init(3, third);
    if(flag == 10){
        return 10;
    }

    return 0;
}