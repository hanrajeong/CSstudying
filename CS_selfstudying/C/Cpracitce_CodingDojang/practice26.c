#include <stdio.h>

struct Point2D {
    int x;
    int y;
};
 
void movePoint2D(struct Point2D *p, int m_x, int m_y)
{
    p->x += m_x;
    p->y += m_y;
}

int main()
{
    struct Point2D p1;
    int offsetX, offsetY;
 
    scanf("%d %d %d %d", &p1.x, &p1.y, &offsetX, &offsetY);

    movePoint2D(&p1, offsetX, offsetY);

    printf("%d %d\n", p1.x, p1.y);

    return 0;
}