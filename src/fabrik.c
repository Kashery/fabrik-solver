#include <fabrik.h>

void solve_fabrik_b(Point2D* links, Point2D goal)
{
    Point2D* _a = find_last(links);
    Point2D* _t = (Point2D*)malloc(sizeof(Point2D));
    _t->x = goal.x;
    _t->y = goal.y;
    while(1){
        double dist = find_dist(_a, _a->_prev);
        _a->x = _t->x;
        _a->y = _t->y;
        _t = find_bet(_a, _a->_prev, dist);
        
        
        _a = _a->_prev;
       
        
        if(_a->_prev == NULL){
            _a->x = _t->x;
            _a->y = _t->y;
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
    _t->y = 0.0;
    while(1){
        double dist = find_dist(_a, _a->_next);
        _a->x = _t->x;
        _a->y = _t->y;
        _t = find_bet(_a, _a->_next, dist);
        
        
        _a = _a->_next;
       
        
        if(_a->_next == NULL){
            _a->x = _t->x;
            _a->y = _t->y;
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
    g->y = goal.y;
    size_t pass = 0;
    while(find_dist(find_last(links), g)>precision){
        solve_fabrik_b(links, goal);
        solve_fabrik_f(links);
        pass = pass + 1;
    }
    printf("finished after %d passes \n", pass);
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