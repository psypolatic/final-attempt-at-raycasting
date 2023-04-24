valgr#include <math.h>
#include <stdio.h>
#define DEG_TO_RAD(degrees) ((degrees) * (M_PI / 180.0))

void rotate(double *x, double *y, double theta) {
    double cos_theta = cos(theta);
    double sin_theta = sin(theta);

    double x_new = (*x * cos_theta) - (*y * sin_theta);
    double y_new = (*x * sin_theta) + (*y * cos_theta);

    *x = x_new;
    *y = y_new;
}


int main() {
    double x = 10;
    double y = 0;
    double theta = DEG_TO_RAD(90); // 30 degrees in radians

    rotate(&x, &y, theta);

    printf("New coordinates: (%f, %f)\n", x, y);

    return 0;
}