#pragma once

#include "coord3d.h"

double length(Coord3D *p);
Coord3D * fartherFromOrigin(Coord3D *pl, Coord3D *p2);
void move(Coord3D *ppos, Coord3D *pvel, double dt);
