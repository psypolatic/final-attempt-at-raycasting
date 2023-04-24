#pragma once
class Map{

    public:
    char map[200][200] = 0;
    Map(int level);

    private:
        void generate_border();
}