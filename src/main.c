#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <float.h>
#include <time.h>

#include <points.h>
#include <fabrik.h>

int main(int argc, char const *argv[])
{
    // // defining origin
    // Point2D* start = (Point2D*)malloc(sizeof(Point2D));
    // start->x = 0.0;
    // start->y = 0.0;
    // // defining currend end effector position
    // Point2D* end = (Point2D*)malloc(sizeof(Point2D));
    // end->x = 6.0;
    // end->y = 5.0;
    // // setting up current position of each link
    // Point2D* p0 = (Point2D*)malloc(sizeof(Point2D));
    // Point2D* p1 = (Point2D*)malloc(sizeof(Point2D));
    // Point2D* p2 = (Point2D*)malloc(sizeof(Point2D));
    // Point2D* p3 = (Point2D*)malloc(sizeof(Point2D));
    // // p0 and p3 are set accordingly to start and end since they are the base and end effector in our system
    // p0->x = start->x;
    // p0->y = start->y;
    // p0->_next = p1;
    // p1->_prev = p0;
    // p1->x = 3.0;
    // p1->y = 3.0;
    // p1->_next = p2;
    // p2->_prev = p1;
    // p2->x = 6.0;
    // p2->y = 3.0;
    // p2->_next = p3;
    // p3->_prev = p2;
    // p3->x = end->x;
    // p3->y = end->y;


    //same for 3d
    Point3D* start3d = (Point3D*)malloc(sizeof(Point3D));
    start3d->x = 0.0;
    start3d->y = 0.0;
    start3d->z = 0.0;
    // defining currend end effector position
    Point3D* end3d = (Point3D*)malloc(sizeof(Point3D));
    end3d->x = 6.0;
    end3d->y = 5.0;
    end3d->z = 1.0;
    // setting up current position of each link
    Point3D* p03d = (Point3D*)malloc(sizeof(Point3D));
    Point3D* p13d = (Point3D*)malloc(sizeof(Point3D));
    Point3D* p23d = (Point3D*)malloc(sizeof(Point3D));
    Point3D* p33d = (Point3D*)malloc(sizeof(Point3D));
    // p0 and p3 are set accordingly to start and end since they are the base and end effector in our system
    p03d->x = start3d->x;
    p03d->y = start3d->y;
    p03d->z = start3d->z;
    p03d->_next = p13d;
    p13d->_prev = p03d;
    p13d->x = 3.0;
    p13d->y = 3.0;
    p13d->z = 3.0;
    p13d->_next = p23d;
    p23d->_prev = p13d;
    p23d->x = 6.0;
    p23d->y = 3.0;
    p23d->z = 2.0;
    p23d->_next = p33d;
    p33d->_prev = p23d;
    p33d->x = end3d->x;
    p33d->y = end3d->y;
    p33d->z = end3d->z;
    
   
    
    
    

    // defininf goal

    // Point2D goal;
    Point3D goal3d;
    if (argc < 4){
        printf("insufficient amount of arguments");
        return 1;
    }
    // goal.x = strtod(argv[1],NULL);
    // goal.y = strtod(argv[2],NULL);
    goal3d.x = strtod(argv[1],NULL);
    goal3d.y = strtod(argv[2],NULL);
    goal3d.z = strtod(argv[3],NULL);
    // print_all(p0);
    // solve_fabrik(p0, goal, DBL_EPSILON);
    // print_all(p0);
    print_all3d(p03d);
    solve_fabrik3d(p03d, goal3d, DBL_EPSILON);
    print_all3d(p03d);
    /* code */
    return 0;
}
