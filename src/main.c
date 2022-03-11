#include <stdio.h>
#include <math.h>

#include "ray.h"


int main() {
    Vector x = {1, 0, 0};
    Vector y = {0, 1, 0};
    Vector z = {0, 0, 1};

    Vector i = {2, 3, 4};
    vector_normalize(&i, &i);


    return 0;
}
