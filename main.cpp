#include <iostream>
#include "funcs.h"

int main()
{
  Coord3D pt, pt2;
  std::cout << "=============TASK A===========\n";
  pt.x = 10; pt.y = 20; pt.z = 30; std::cout << "length function where {x,y,z} = {10,20,30} returns: " << length(&pt) << "\n";
  pt.x = -64; pt.y = 111; pt.z = 14; std::cout << "length function where {x,y,z} = {-64,111,14} returns: " << length(&pt) << "\n";
  pt.x = 0; pt.y = -33; pt.z = -91; std::cout << "length function where {x,y,z} = {0,-33,91} returns: " << length(&pt) << "\n";
  pt.x = 28; pt.y = 53; pt.z = 2048; std::cout << "length function where {x,y,z} = {28,53,2048} returns: " << length(&pt) << "\n";
  std::cout << "=============TASK B===========\n";
  pt = {10,20,30}; pt2 = {-20,21,-22};
  std::cout << "fartherFromOrigin function where p1 and p2 are\np1 (" << &pt << ") = {10,20,30}\np2 (" << &pt2 << ") = {-20,21,-22}\nreturns: " << fartherFromOrigin(&pt, &pt2) << "\n\n";

  pt = {-4,8,-12}; pt2 = {-13,66,-77};
  std::cout << "fartherFromOrigin function where p1 and p2 are\np1 (" << &pt << ") = {-4,8,-12}\np2 (" << &pt2 << ") = {-13,-66,77}\nreturns: " << fartherFromOrigin(&pt, &pt2) << "\n\n";

  pt = {8,8,8}; pt2 = {-8,-8,-8};
  std::cout << "fartherFromOrigin function where p1 and p2 are\np1 (" << &pt << ") = {8,8,8}\np2 (" << &pt2 << ") = {-8,-8,-8}\nreturns: " << fartherFromOrigin(&pt, &pt2) << "\n\n";

  pt = {90,-41,144}; pt2 = {102,5,-151};
  std::cout << "fartherFromOrigin function where p1 and p2 are\np1 (" << &pt << ") = {90,-41,144}\np2 (" << &pt2 << ") = {102,5,-151}\nreturns: " << fartherFromOrigin(&pt, &pt2) << "\n";
  std::cout << "=============TASK C===========\n";
  Coord3D vel; double dt;
  pt = {0,0,100}; vel = {1,-5,.2}; dt = 2.0; move(&pt, &vel, dt);
  std::cout << "move function with the parameters\npoint = {0,0,100}\nvelocity = {1,-5,.2}\ndeltaTime = 2.0\nchanges the point to: {" << pt.x << "," << pt.y << "," << pt.z << "}\n\n";
  pt = {-42,643,54}; vel = {612,34,-444}; dt = 3.141592653; move(&pt, &vel, dt);
  std::cout << "move function with the parameters\npoint = {-42,643,54}\nvelocity = {612,34,-444}\ndeltaTime = 3.141592653\nchanges the point to: {" << pt.x << "," << pt.y << "," << pt.z << "}\n\n";
  pt = {6.1134515432,2.153412,-.0123512}; vel = {.00124,.4112,.88765}; dt = 21.324512; move(&pt, &vel, dt);
  std::cout << "move function with the parameters\npoint = {6.1134515432,2.153412,-.0123512}\nvelocity = {.00124,.4112,.88765}\ndeltaTime = 21.324512\nchanges the point to: {" << pt.x << "," << pt.y << "," << pt.z << "}\n\n";
  pt = {-2419,21620,343212}; vel = {420,666,888}; dt = .01532; move(&pt, &vel, dt);
  std::cout << "move function with the parameters\npoint = {-2419,21620,343212}\nvelocity = {420,666,888}\ndeltaTime = .01532\nchanges the point to: {" << pt.x << "," << pt.y << "," << pt.z << "}\n\n";
  std::cout << "=============TASK E===========\n";
  double x,y,z,vx,vy,vz;
  x = 2; y = 4; z = 6; vx = 0; vy = 0; vz = 3; dt = 4;
  Coord3D *pt3 = createCoord3D(x,y,z), *vel2 = createCoord3D(vx,vy,vz); move(pt3, vel2, dt);
  std::cout << "Created dynamic coordinate {2,4,6}.\nCoordinate position after calling move with velocity = {0,0,3} and deltaTime = 4: {" << pt3->x << "," << pt3->y << "," << pt3->z << "}\n"; deleteCoord3D(pt3); deleteCoord3D(vel2); std::cout << "Memory released after use.\n\n";
  x = -41; y = 61.2; z = 99.99; vx = -42; vy = -52; vz = 5; dt = 30;
  pt3 = createCoord3D(x,y,z); vel2 = createCoord3D(vx,vy,vz); move(pt3, vel2, dt);
  std::cout << "Created dynamic coordinate {-41,61.2,99.99}.\nCoordinate position after calling move with velocity = {-42,-52,5} and deltaTime = 30: {" << pt3->x << "," << pt3->y << "," << pt3->z << "}\n"; deleteCoord3D(pt3); deleteCoord3D(vel2); std::cout << "Memory released after use.\n\n";
  x = -12; y = 1441; z = -683; vx = 0; vy = 18; vz = -76; dt = 6;
  pt3 = createCoord3D(x,y,z); vel2 = createCoord3D(vx,vy,vz); move(pt3, vel2, dt);
  std::cout << "Created dynamic coordinate {-12,1441,-683}.\nCoordinate position after calling move with velocity = {0,18,-76} and deltaTime = 6: {" << pt3->x << "," << pt3->y << "," << pt3->z << "}\n"; deleteCoord3D(pt3); deleteCoord3D(vel2); std::cout << "Memory released after use.\n\n";
  return 0;
}
