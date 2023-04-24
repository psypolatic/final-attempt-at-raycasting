#include "mathfunc.hpp"
#include <cmath>

#include <memory>
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

std::unique_ptr<int[]> findIntersection(int s, int square_x, int square_y, double m) {
    int* intersection = new int[2];
    double b = square_y - m * square_x; // Calculate y-intercept of line

    // Calculate x and y coordinates of intersection points with square sides
    double x1 = -s/2.0;
    double y1 = m * x1 + b;
    double x2 = s/2.0;
    double y2 = m * x2 + b;
    double x3 = (square_y + s/2.0 - b) / m;
    double y3 = -s/2.0;
    double x4 = (square_y - s/2.0 - b) / m;
    double y4 = s/2.0;

    // Find intersection points that lie inside the square
    double x_intersect = NAN, y_intersect = NAN;
    if (x1 >= -s/2.0 && x1 <= s/2.0 && y1 >= -s/2.0 && y1 <= s/2.0) {
        x_intersect = x1;
        y_intersect = y1;
    } else if (x2 >= -s/2.0 && x2 <= s/2.0 && y2 >= -s/2.0 && y2 <= s/2.0) {
        x_intersect = x2;
        y_intersect = y2;
    } else if (x3 >= -s/2.0 && x3 <= s/2.0 && y3 >= -s/2.0 && y3 <= s/2.0) {
        x_intersect = x3;
        y_intersect = y3;
    } else if (x4 >= -s/2.0 && x4 <= s/2.0 && y4 >= -s/2.0 && y4 <= s/2.0) {
        x_intersect = x4;
        y_intersect = y4;
    }

    // Set intersection point coordinates in result array
    intersection[0] = round(x_intersect + square_x);
    intersection[1] = round(y_intersect + square_y);
    
    return std::unique_ptr<int[]>(intersection);
}

coordinate::coordinate(double xb ,double yb){
    x = xb;
    y = yb; 
}

void coordinate::xy(double xb, double yb){
    //double tabs is weird im not fixing it :D
        x = xb;
        y = yb;
}

//math functions go under here

//I think i finished it im not gonna touch this ever again even if it breaks everything im going to work around it instead of fixing it later

//im probably never gonna use this stupid ass fucking code i have to make a new rotate function stupid fucking bull shit inssuferbalkstupid r
/* me going *(*#&%(*&)) mode on this stupid ass bullshit 4/16/23
                ────────▄▄▄▄▄▄▄▄▄
                ────────▌▐░▀░▀░▀▐
                ────────▌░▌░░░░░▐
                ────────▌░░░░░░░▐
                ────────▄▄▄▄▄▄▄▄▄
                ──▄▀▀▀▀▀▌▄█▄░▄█▄▐▀▀▀▀▀▄
                ─█▒▒▒▒▒▐░░░░▄░░░░▌▒▒▒▒▒█
                ▐▒▒▒▒▒▒▒▌░░░░░░░▐▒▒▒▒▒▒▒▌
                ▐▒▒▒▒▒▒▒█░▀▀▀▀▀░█▒▒▒▒▒▒▒▌
                ▐▒▒▒▒▒▒▒▒█▄▄▄▄▄█▒▒▒▒▒▒▒▒▌
                ▐▒▒▒▒▐▒▒▒▒▒▒▒▒▒▒▒▒▐▒▒▒▒▒▌
                ▐▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▌
                ▐▒▒▒▒▒▐▒▒▒▒▒▒▒▒▒▒▒▌▒▒▒▒▒▌
                ▐▒▒▒▒▒▒▌▒▒▒▒▒▒▒▒▒▐▒▒▒▒▒▒▌
                ▐▒▒▒▒▒▒▌▄▄▄▄▄▄▄▄▄▐▒▒▒▒▒▒▌
                ▐▄▄▄▄▄▄▌▌███████▌▐▄▄▄▄▄▄▌
                ─█▀▀▀▀█─▌███▌███▌─█▀▀▀▀█
                ─▐░░░░▌─▌███▌███▌─▐░░░░▌
                ──▀▀▀▀──▌███▌███▌──▀▀▀▀
                ────────▌███▌███▌
                ────────▌███▌███▌
                ──────▐▀▀▀██▌█▀▀▀▌
                ▒▒▒▒▒▒▐▄▄▄▄▄▄▄▄▄▄▌▒▒▒▒▒▒▒
    */
void rotate_pair(double *x, double *y, double theta, coordinate center ){
    
    double cos_theta = cos(theta);
    double sin_theta = sin(theta);
    
    if (center.x == 0 && center.y == 0){  
        
        double x_new = (*x * cos_theta) - (*y * sin_theta);
        double y_new = (*x * sin_theta) + (*y * cos_theta);
        *x = x_new;
        *y = y_new;
    
    }
    else{
        //we subtract and re add the values because its not directly in the center
        // either way its weird cuz 0,0 is not the center since 0,0 is in a corner
        double x_new = ((*x - center.x) * cos_theta) - ((*y - center.y) * sin_theta) + center.x;
        double y_new = ((*x - center.x) * sin_theta) + ((*y - center.y) * cos_theta) + center.y;
        *x = x_new;
        *y = y_new;
        
    }

}

//yummy match
double rotate_x(double x,double y,double theta,int center_x,int center_y){
    double cos_theta = cos(theta);
    double sin_theta = sin(theta);
    //silly one line im so quirky lol
    if (center_x == 0 && center_y == 0){return (x * cos_theta) - (y * sin_theta); } 
    return ((x - center_x) * cos_theta) - ((y - center_y) * sin_theta) + center_x;
}

double rotate_y(double x,double y,double theta,int center_x, int center_y){
    double cos_theta = cos(theta);
    double sin_theta = sin(theta);
    if (center_x == 0 && center_y == 0){return (x * sin_theta) + (y * cos_theta); } 
    return ((x - center_x) * sin_theta) + ((y - center_y) * cos_theta) + center_y;
    
    
}


//true false comparison functions go under here

bool coordinate::compare(coordinate cord){
    if ((x == cord.x) && (y == cord.y)){
        return true;        
    }
    return false;
}

// Il fix this later probably
// I fixed it 20 days later :p
bool coordinate::compare_ByVal(double xb,double yb){
    if((x == xb) && (y==yb)){
        return true;        
    }
    return false;
}