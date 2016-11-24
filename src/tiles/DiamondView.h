
#ifndef DIAMOND_VIEW_HEADER
#define DIAMOND_VIEW_HEADER

#include "TileMapView.h"

namespace Tiles {

class DiamondView: public Tiles::TileMapView {
public:
    void tileWalking(int c, int r, int direction) const;
    void mouseMap(int mx, int my, int tw, int th, int &c, int &r) const;
    void calcTilePosition(int c, int r, int tw, int th, int &x0, int &y0) const;
};

};

#endif
