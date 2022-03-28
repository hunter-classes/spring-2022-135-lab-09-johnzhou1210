#include <iostream>
#include <cmath>
#include "funcs.h"

double square(int n)
{
  return pow(n,2);
}

double dist(Coord3D *p1, Coord3D *p2)
{
  return sqrt(square((p2->x) - (p1->x)) + square((p2->y) - (p1->y)) + square((p2->z) - (p1->z)));
}

double length(Coord3D *p)
{
  double len = sqrt(square(p->x) + square(p->y) + square(p->z));
  return len;
}

Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2)
{
  Coord3D originObj = {0,0,0};
  Coord3D* originPtr = (Coord3D*)&originObj;
  if (dist(originPtr,p1) >= dist(originPtr,p2))
  {
    std::cout << "p1 is further at " << dist(originPtr,p1) << " while p2 is only " << dist(originPtr,p2) << "\n";
    return p1;
  }
  std::cout << "p2 is further at " << dist(originPtr,p2) << " while p1 is only " << dist(originPtr,p1) <<"\n";
  return p2;
}

void move(Coord3D *ppos, Coord3D *pvel, double dt)
{
  ppos->x = ppos->x + pvel->x * dt;
  ppos->y = ppos->y + pvel->y * dt;
  ppos->z = ppos->z + pvel->z * dt;
}
