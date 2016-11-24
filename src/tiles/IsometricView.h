#ifndef ISOMETRIC_VIEW_HEADER
#define ISOMETRIC_VIEW_HEADER

#include "TileMapView.h"

namespace Tiles {

class IsometricView: public Tiles::TileMapView {
public:
    void tileWalking();
    void mouseMap();
    void calcTilePosition();
};

};

#endif
