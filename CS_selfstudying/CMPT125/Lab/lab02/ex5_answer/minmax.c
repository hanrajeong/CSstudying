#include "minmax.h"

int min(int x,int y, int z){
    int min_number;
    if (x>y)
        min_number= y;
    else
        min_number= x;
    if (min_number>z)
        return z;
    else
        return min_number;
    
}


int max(int x,int y, int z){
    
    int max_number;
    if (x>y)
        max_number= x;
    else
        max_number= y;

    if (max_number>z)
        return max_number;
    else
        return z;
    
}