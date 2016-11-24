#ifndef REGULAR_VIEW_HEADER
#define REGULAR_VIEW_HEADER

#include "TileMapView.h"

namespace Tiles {

class RegularView: public Tiles::TileMapView {
public:
    void tileWalking();
    void mouseMap();
    void calcTilePosition();
};

};

#endif
