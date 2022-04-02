#include <LibGeometry/libgeometry.h>
#define STRLEN 50

int main()
{
    char mas[STRLEN];
    int flag;

    for(int i = 1; i <= 3; i++){
        flag = init(i, mas);
        if(flag == 10){
            return 10;
        }
    }
    

    return 0;
}