#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

#include <points.h>
#include <fabrik.h>

int main(int argc, char const *argv[])
{
    if (argc < 4){
        printf("insufficient amount of arguments");
        return 1;
    }
    // goal.x = strtod(argv[1],NULL);
    // goal.y = strtod(argv[2],NULL);
    double x = strtod(argv[1],NULL);
    double y = strtod(argv[2],NULL);
    double z = strtod(argv[3],NULL);
    generate_mycobot280pi(x, y, z);
    return 0;
}
