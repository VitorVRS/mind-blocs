#ifndef TILE_MAP_VIEW_HEADER
#define TILE_MAP_VIEW_HEADER

#include "TileMap.h"

namespace Tiles {

class TileMapView {
private:
    int width;
    int height;
    int x;
    int y;

public:
    virtual void tileWalking(int c, int r, int direction) const = 0;
    virtual void mouseMap(int mx, int my, int tw, int th, int &c, int &r) const = 0;
    virtual void calcTilePosition(int c, int r, int tw, int th, int &x0, int &y0) const = 0;

};

};

#endif
