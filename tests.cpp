#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <cmath>
#include "doctest.h"
#include "funcs.h"
#include <iostream>

double absDiff(double a, double b)
{
  // std::cout << "a and b before abs respectively are " << a << ", " << b << "\n";
  return abs(a-b);
}

bool closeEnough(double a, double b)
{
  return absDiff(a,b) <= .001;
}

bool vectorCloseEnough(Coord3D *a, Coord3D *b)
{
  if (!(closeEnough(a->x,b->x) && closeEnough(a->y,b->y) && closeEnough(a->z,b->z)))
  {
    // std::cout << " " << absDiff(a->x,b->x) << ", " << absDiff(a->y,b->y) << ", " << absDiff(a->z,b->z) << "\n";
  }
  return closeEnough(a->x,b->x) && closeEnough(a->y,b->y) && closeEnough(a->z,b->z);
}


TEST_CASE("TASK A: length function")
{
  Coord3D pt;
  pt = {10,20,30}; CHECK(closeEnough(length(&pt), 37.4166));
  pt = {-64,111,14}; CHECK(closeEnough(length(&pt), 128.891));
  pt = {0,-33,91}; CHECK(closeEnough(length(&pt), 96.7988));
  pt = {28,53,2048}; CHECK(closeEnough(length(&pt), 2048.88));
}

TEST_CASE("TASK B: fartherFromOrigin function")
{
  Coord3D pt, pt2;
  pt = {10,20,30}; pt2 = {-20,21,-22}; CHECK(fartherFromOrigin(&pt, &pt2) == &pt);
  pt = {-4,8,-12}; pt2 = {-13,66,-77}; CHECK(fartherFromOrigin(&pt, &pt2) == &pt2);
  pt = {8,8,8}; pt2 = {-8,-8,-8}; CHECK(fartherFromOrigin(&pt, &pt2) == &pt);
  pt = {90,-41,144}; pt2 = {102,5,-151}; CHECK(fartherFromOrigin(&pt, &pt2) == &pt2);
}

TEST_CASE("TASK C: move function")
{
  Coord3D pt, vel, expectedVector; double dt;
  pt = {0,0,100}; vel = {1,-5,.2}; expectedVector = {2,-10,100.4}; dt = 2.0; move(&pt, &vel, dt); CHECK(vectorCloseEnough(&pt, &expectedVector));
  pt = {-42,643,54}; vel = {612,34,-444}; expectedVector = {1880.65,749.814,-1340.87};  dt = 3.141592653; move(&pt, &vel, dt); CHECK(vectorCloseEnough(&pt, &expectedVector));
  pt = {6.1134515432,2.153412,-.0123512}; vel = {.00124,.4112,.88765}; expectedVector = {6.13989,10.9221,18.9164}; dt = 21.324512; move(&pt, &vel, dt); CHECK(vectorCloseEnough(&pt, &expectedVector));
  pt = {-2419,21620,343212}; vel = {420,666,888}; expectedVector = {-2412.57,21630.2,343226}; dt = .01532; move(&pt, &vel, dt); CHECK(vectorCloseEnough(&pt, &expectedVector));
}

TEST_CASE("TASK E: createCoord3D and deleteCoord3D functions")
{
  double x,y,z,vx,vy,vz,dt; Coord3D *expectedVector = createCoord3D(2,4,18);
  x = 2; y = 4; z = 6; vx = 0; vy = 0; vz = 3; dt = 4;
  Coord3D *pt3 = createCoord3D(x,y,z), *vel2 = createCoord3D(vx,vy,vz); move(pt3, vel2, dt);
  CHECK(vectorCloseEnough(pt3,expectedVector));
  deleteCoord3D(pt3); deleteCoord3D(vel2); deleteCoord3D(expectedVector);
  x = -41; y = 61.2; z = 99.99; vx = -42; vy = -52; vz = 5; dt = 30; expectedVector = createCoord3D(-1301,-1498.8,249.99);
  pt3 = createCoord3D(x,y,z), vel2 = createCoord3D(vx,vy,vz); move(pt3, vel2, dt);
  CHECK(vectorCloseEnough(pt3,expectedVector));
  deleteCoord3D(pt3); deleteCoord3D(vel2); deleteCoord3D(expectedVector);
  x = -12; y = 1441; z = -683; vx = 0; vy = 18; vz = -76; dt = 6; expectedVector = createCoord3D(-12,1549,-1139);
  pt3 = createCoord3D(x,y,z), vel2 = createCoord3D(vx,vy,vz); move(pt3, vel2, dt);
  CHECK(vectorCloseEnough(pt3,expectedVector));
  deleteCoord3D(pt3); deleteCoord3D(vel2); deleteCoord3D(expectedVector);
}
