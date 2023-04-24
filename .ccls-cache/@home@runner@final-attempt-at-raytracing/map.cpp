#include "map.hpp"
#include "levels.hpp"




void Map::generate_border(){
    //row 1
    for (int i =0;i<200;i++){
        map[i][0] = '#';
        map[i][199] = '#';
        map[0][i] = '#';
        map[199][i] = '#';
    }
        
}



Map::Map(int level){
    if (level == 1){
        
    }
}

