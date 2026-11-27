#ifndef COMMON_H
#define COMMON_H

#include <sstream>

#define SCREEN_WIDTH 360
#define SCREEN_HEIGHT 1080


#define BLOCK_SIZE 20


struct PixelPosition {
    int x ;
    int y ;
    friend std::ostream & operator<<(std::ostream &out, PixelPosition p) {
        return out <<'(' << p.x << ',' << p.y << ')' ;
    }
};


#endif // COMMON_H
