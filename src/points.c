#include <points.h>

void print_all(Point2D* _)
{
    Point2D* t = _;
    while(1)
    {
        printf(" -- (%f,%f)",t->x,t->y);
        if(t->_next == NULL){
            printf("\n");
            return;
        }else{
            printf(" -- %f", find_dist(t, t->_next));
            t = t->_next;
        }
    }
}

void print_all3d(Point3D* _)
{
    Point3D* t = _;
    while(1)
    {
        printf(" -- (%.05f,%.05f,%.05f)",t->x,t->y,t->z);
        if(t->_next == NULL){
            printf("\n");
            return;
        }else{
            printf(" -- %.05f", find_dist3d(t, t->_next));
            t = t->_next;
        }
    }
}

double find_dist(Point2D* A, Point2D* B)
{
    return sqrt(((A->x - B->x)*(A->x - B->x)+(A->y - B->y)*(A->y - B->y)));
}
double find_dist3d(Point3D* A, Point3D* B)
{
    return sqrt(((A->x - B->x)*(A->x - B->x)+(A->y - B->y)*(A->y - B->y)+(A->z - B->z)*(A->z - B->z)));
}

Point2D* find_last(Point2D* first)
{
    Point2D* _  = first;
    while (1){
        _ = _->_next;
        if (_->_next == NULL){
            return _;
        }
    }
}

Point3D* find_last3d(Point3D* first)
{
    Point3D* _  = first;
    while (1){
        _ = _->_next;
        if (_->_next == NULL){
            return _;
        }
    }
}

Point2D* find_bet(Point2D* A, Point2D* B, double dist)
{   
    Point2D* _t = (Point2D*)malloc(sizeof(Point2D));
    double nd = find_dist(A,B);
    _t->x = A->x + (dist)*(B->x - A->x)/nd;
    _t->y = A->y + (dist)*(B->y - A->y)/nd;   
}

Point3D* find_bet3d(Point3D* A, Point3D* B, double dist)
{   
    Point3D* _t = (Point3D*)malloc(sizeof(Point3D));
    double nd = find_dist3d(A,B);
    _t->x = A->x + (dist)*(B->x - A->x)/nd;
    _t->y = A->y + (dist)*(B->y - A->y)/nd;   
    _t->z = A->z + (dist)*(B->z - A->z)/nd;   
}