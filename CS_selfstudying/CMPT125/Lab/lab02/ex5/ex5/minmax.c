#include "minmax.h"

int min(int x,int y, int z){

    int m = x;
    if (m > y)
        m = y;
    if (m > z)
        m = z;
    
    return m;
}


int max(int x,int y, int z){
    
    int m = x;
    if (m < y)
        m = y;
    if (m < z)
        m = z;
    
    return m;
}