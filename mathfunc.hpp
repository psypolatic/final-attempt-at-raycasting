#pragma once
#include <math.h>
#include <memory>

#define DEG_TO_RAD(degrees) ((degrees) * (M_PI / 180.0))

class coordinate{

    public:
        //yb == youngboy??!?!?!?  😲 😲 😲 😲 😲 😲 😲 😲 😲
        coordinate(double xb = 0,double yb=0);
        bool compare(coordinate cord);
        bool compare_ByVal(double xb,double yb);
        double x;
        double y;
        //just replaces the x and y values
        void xy(double xb,double yb);

    
};
double distance(double x1, double y1, double x2, double y2);
std::unique_ptr<int[]> findIntersection(int s, int square_x, int square_y, double m);

void rotate_pair(double *x, double *y, double theta,coordinate center);

double rotate_x(double x,double y,double theta,int center_x,int center_y);
//so disgusting ew
double rotate_y(double x,double y,double theta,int center_x,int center_y);
