#include "mathfunc.hpp"

coordinate::coordinate(float xb,float yb){
    x = xb;
    y = yb; 
}






//true false comparison functions go under here

bool coordinate::compare(coordinate cord){
    if ((x == cord.x) && (y == cord.y)){
        return true;        
    }
    return false;
}
bool coordinate::compare_ByVal(float xb,float yb){
    if((x == xb) && (y==yb)){
        return true;        
    }
    return false;
}