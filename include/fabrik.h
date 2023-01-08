#ifndef _FABRIK_H
#define _FABRIK_H

#include <points.h>

void solve_fabrik_b(Point2D* links, Point2D goal);
void solve_fabrik_b3d(Point3D* links, Point3D goal);

void solve_fabrik_f(Point2D* links);
void solve_fabrik_f3d(Point3D* links);

void solve_fabrik(Point2D* links, Point2D goal, double precision);
void solve_fabrik3d(Point3D* links, Point3D goal, double precision);

double generate_mycobot280pi(double x, double y, double z);

#endif // _FABRIK_H