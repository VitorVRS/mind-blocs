#include "DiamondView.h"

void Tiles::DiamondView::tileWalking(int c, int r, int direction) const {
    // @todo
}

void Tiles::DiamondView::mouseMap(int mx, int my, int tw, int th, int &c, int &r) const {
    // @todo
}

void Tiles::DiamondView::calcTilePosition(int c, int r, int tw, int th, int &x0, int &y0) const {
    x0 = c * tw/2 - r * tw/2;
    y0 = c * th/2 + r * th/2;
}
