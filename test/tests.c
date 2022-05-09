#include <LibGeometry/libgeometry.h>
#include <ctest.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define SQR(x) x* x

CTEST(geometry_suite, intesection_circles)
{
    const int exp = 0;
    struct Figure circle[2];
    circle[0].name = "Circle1";
    circle[0].first.x = 0;
    circle[0].first.y = 0;
    circle[0].radius = 5;
    circle[1].name = "Circle2";
    circle[1].first.x = 1;
    circle[1].first.y = 1;
    circle[1].radius = 3;
    int res = intersection_circle_circle(circle[0], circle[1]);
    ASSERT_EQUAL(exp, res);
}

CTEST(geometry_suite, Check_volume_of_circle)
{
    double test[4];
    test[0] = 2;
    test[1] = 3;
    test[2] = 5;
    const double exp = M_PI * SQR(test[2]);
    double res = volume(test, 3);
    ASSERT_EQUAL(exp, res);
}

CTEST(geometry_suite, Check_perimeter_of_circle)
{
    double test[4];
    test[0] = 2;
    test[1] = 3;
    test[2] = 5;
    const double exp = 2 * M_PI * test[2];
    double res = perimeter(test, 3);
    ASSERT_EQUAL(exp, res);
}

CTEST(geometry_suite, Check_perimeter_of_triangle)
{
    double test[8];
    test[0] = 0;
    test[1] = 0;
    test[2] = 5;
    test[3] = 5;
    test[4] = 10;
    test[5] = 0;
    test[6] = 0;
    test[7] = 0;
    double first_side
            = sqrt(SQR((test[3] - test[1])) + SQR((test[2] - test[0])));
    double second_side
            = sqrt(SQR((test[5] - test[3])) + SQR((test[4] - test[2])));
    double third_side
            = sqrt(SQR((test[5] - test[1])) + SQR((test[4] - test[0])));
    const double exp = first_side + second_side + third_side;
    double res = perimeter(test, 4);
    ASSERT_EQUAL(exp, res);
}

CTEST(geometry_suite, Check_volume_of_triangle)
{
    double test[8];
    test[0] = 0;
    test[1] = 0;
    test[2] = 5;
    test[3] = 5;
    test[4] = 10;
    test[5] = 0;
    test[6] = 0;
    test[7] = 0;
    double first_side
            = sqrt(SQR((test[3] - test[1])) + SQR((test[2] - test[0])));
    double second_side
            = sqrt(SQR((test[5] - test[3])) + SQR((test[4] - test[2])));
    double third_side
            = sqrt(SQR((test[5] - test[1])) + SQR((test[4] - test[0])));
    double half_perim = (first_side + second_side + third_side) / 2;
    const double exp
            = sqrt(half_perim * (half_perim - first_side)
                   * (half_perim - second_side) * (half_perim - third_side));
    double res = volume(test, 4);
    ASSERT_EQUAL(exp, res);
}