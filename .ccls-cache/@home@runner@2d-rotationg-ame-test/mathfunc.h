#pragma once
#include "mathfunc.c"

class coordinate{

    public:
        coordinate(float xb,float yb);
        bool compare(coordinate cord);
        bool compare_ByVal(float xb,float yb);
        float x;
        float y;

    
};