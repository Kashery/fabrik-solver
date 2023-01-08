#ifndef _POINT_H
#define _POINT_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <float.h>

typedef struct point2D
{
    double x;
    double z;
    struct point2D* _next;
    struct point2D* _prev;
}Point2D;

typedef struct point3D
{
    double x;
    double y;
    double z;
    struct point3D* _next;
    struct point3D* _prev;
    bool _x;
    bool _y;
    bool _z;
}Point3D;

void print_all(Point2D* _);
void print_all3d(Point3D* _);

double find_dist(Point2D* A, Point2D* B);
double find_dist3d(Point3D* A, Point3D* B);

Point2D* find_last(Point2D* first);
Point3D* find_last3d(Point3D* first);

Point2D* find_bet(Point2D* A, Point2D* B, double dist);
Point3D* find_bet3d(Point3D* A, Point3D* B, double dist);

Point3D* normal_3d(Point3D* A, Point3D* B, double dist);

#endif // _POINT_H