#include <fabrik.h>

void solve_fabrik_b(Point2D* links, Point2D goal)
{
    Point2D* _a = find_last(links);
    Point2D* _t = (Point2D*)malloc(sizeof(Point2D));
    _t->x = goal.x;
    _t->z = goal.z;
    while(1){
        double dist = find_dist(_a, _a->_prev);
        _a->x = _t->x;
        _a->z = _t->z;
        _t = find_bet(_a, _a->_prev, dist);
        
        
        _a = _a->_prev;
       
        
        if(_a->_prev == NULL){
            _a->x = _t->x;
            _a->z = _t->z;
            break;
        }
    }
    return;
}

void solve_fabrik_b3d(Point3D* links, Point3D goal)
{
    Point3D* _a = find_last3d(links);
    Point3D* _t = (Point3D*)malloc(sizeof(Point3D));
    _t->x = goal.x;
    _t->y = goal.y;
    _t->z = goal.z;
    while(1){
        double dist = find_dist3d(_a, _a->_prev);
        _a->x = _t->x;
        _a->y = _t->y;
        _a->z = _t->z;
        _t = find_bet3d(_a, _a->_prev, dist);
        
        
        _a = _a->_prev;
       
        
        if(_a->_prev == NULL){
            _a->x = _t->x;
            _a->y = _t->y;
            _a->z = _t->z;
            break;
        }
    }
    return;
}

void solve_fabrik_f(Point2D* links)
{
    Point2D* _a = links;
    Point2D* _t = (Point2D*)malloc(sizeof(Point2D));
    _t->x = 0.0;
    _t->z = 0.0;
    while(1){
        double dist = find_dist(_a, _a->_next);
        _a->x = _t->x;
        _a->z = _t->z;
        _t = find_bet(_a, _a->_next, dist);
        
        
        _a = _a->_next;
       
        
        if(_a->_next == NULL){
            _a->x = _t->x;
            _a->z = _t->z;
            break;
        }
    }
    return;
}

void solve_fabrik_f3d(Point3D* links)
{
    Point3D* _a = links;
    Point3D* _t = (Point3D*)malloc(sizeof(Point3D));
    _t->x = 0.0;
    _t->y = 0.0;
    _t->z = 0.0;
    while(1){
        double dist = find_dist3d(_a, _a->_next);
        _a->x = _t->x;
        _a->y = _t->y;
        _a->z = _t->z;
        _t = find_bet3d(_a, _a->_next, dist);
        
        
        _a = _a->_next;
       
        
        if(_a->_next == NULL){
            _a->x = _t->x;
            _a->y = _t->y;
            _a->z = _t->z;
            break;
        }
        
    }
    return;
}

void solve_fabrik(Point2D* links, Point2D goal, double precision)
{
    
    Point2D* g = (Point2D*)malloc(sizeof(Point2D));
    
    g->x = goal.x;
    g->z = goal.z;
    size_t pass = 0;
    
    
    while(find_dist(find_last(links), g)>precision){
        
        solve_fabrik_b(links, goal);
        solve_fabrik_f(links);
        pass = pass + 1;
        
    }
    
    //printf("finished after %d passes \n", pass);
}

void solve_fabrik3d(Point3D* links, Point3D goal, double precision)
{
    Point3D* g = (Point3D*)malloc(sizeof(Point3D));
    g->x = goal.x;
    g->y = goal.y;
    g->z = goal.z;
    size_t pass = 0;
    while(find_dist3d(find_last3d(links), g)>precision){
        solve_fabrik_b3d(links, goal);
        solve_fabrik_f3d(links);
        print_all3d(links);
        pass = pass + 1;
    }
    printf("finished after %d passes \n", pass);
}
double generate_mycobot280pi(double x, double y, double z){
    
    Point3D* p03d = (Point3D*)malloc(sizeof(Point3D));
    Point3D* p13d = (Point3D*)malloc(sizeof(Point3D));
    Point3D* p23d = (Point3D*)malloc(sizeof(Point3D));
    Point3D* p33d = (Point3D*)malloc(sizeof(Point3D));
    Point3D* p43d = (Point3D*)malloc(sizeof(Point3D));
    // p0 and p3 are set accordingly to start and end since they are the base and end effector in our system
    p03d->x = 0.0;
    p03d->y = 0.0;
    p03d->z = 0.0;

    p03d->_next = p13d;
    p13d->_prev = p03d;
    p13d->x = 0.0;
    p13d->y = 0.0;
    p13d->z = 131.56;

    p13d->_next = p23d;
    p23d->_prev = p13d;
    p23d->x = 0,0;
    p23d->y = 0.0;
    p23d->z = p23d->_prev->z + 110.4;

    p23d->_next = p33d;
    p33d->_prev = p23d;
    p33d->x = 0.0;
    p33d->y = 0.0;
    p33d->z = p33d->_prev->z + 96.0;

    p33d->_next = p43d;
    p43d->_prev = p33d;
    p43d->x = 0.0;
    p43d->y = 0.0;
    p43d->z = p43d->_prev->z + 73.18;
    
   
    
    
    
    

    // defininf goal

    // Point2D goal;
    Point3D goal3d;
    // goal.x = strtod(argv[1],NULL);
    // goal.y = strtod(argv[2],NULL);
    goal3d.x = x;
    goal3d.y = y;
    goal3d.z = z;

    double joint1 = atan2(-goal3d.y, goal3d.x);
    
    // goal3d.z/(sqrt(goal3d.x*goal3d.x+ goal3d.y*goal3d.y + goal3d.z*goal3d.z));
    Point2D* p1 = (Point2D*)malloc(sizeof(Point2D));
    Point2D* p2 = (Point2D*)malloc(sizeof(Point2D));
    Point2D* p3 = (Point2D*)malloc(sizeof(Point2D));
    Point2D* p4 = (Point2D*)malloc(sizeof(Point2D));
    p1->x = 0.0;
    p1->z = 131.56;

    p1->_next = p2;
    p2->_prev = p1;
    p2->x = 0,0;
    p2->z = p2->_prev->z + 110.4;

    p2->_next = p3;
    p3->_prev = p2;
    p3->x = 0.0;
    p3->z = p3->_prev->z + 96.0;

    p3->_next = p4;
    p4->_prev = p3;
    p4->x = 0.0;
    p4->z = p4->_prev->z + 73.18;

    Point2D goal2d;
    goal2d.x = sqrt(goal3d.x*goal3d.x + goal3d.y*goal3d.y);
    goal2d.z = goal3d.z - p13d->z;
    // print_all(p0);
    // solve_fabrik(p0, goal, DBL_EPSILON);
    // print_all(p0);
    // x to x
    // y to z
    solve_fabrik(p1, goal2d, DBL_EPSILON);


    p13d->x = p1->x*cos(-joint1);
    p13d->y = p1->x*sin(-joint1);
    p13d->z = p1->z + p13d->z;
    
    p23d->x = p2->x*cos(-joint1);
    p23d->y = p2->x*sin(-joint1);
    p23d->z = p2->z + p13d->z;

    p33d->x = p3->x*cos(-joint1);
    p33d->y = p3->x*sin(-joint1);
    p33d->z = p3->z + p13d->z;

    p43d->x = p4->x*cos(-joint1);
    p43d->y = p4->x*sin(-joint1);
    p43d->z = p4->z + p13d->z;
    
    // printf("%f\n", joint1);
    print_all3d(p03d);
    free_3d(p03d);
    free_2d(p1);

    return joint1;
}