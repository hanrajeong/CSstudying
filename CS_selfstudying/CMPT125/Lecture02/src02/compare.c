#include <stdio.h>

// if a[0...length-1] is equal to b[0...length-1] returns -1
// otherwise, returns first index where a[i] != b[i]
int compare(const int a[], const int b[], int length)
{
    int i = 0;
    if (a==b)
        return -1; //a와 b가 같은 것을 가르키는 pointer의 경우 code를 줄이기위해서 이 코드를 넣는게 좋아보인다하심.
    while (i < length)
    {
        if (a[i] != b[i])
            return i;
        i++;
    }
    return -1; // -1 means they are equal
}

int main()
{

    int a1[6] = {1,2,3,4,5,6};
    int a2[6] = {1,2,3,4,8,6};
    int a3[6] = {1,2,3,4,8,6};

    if (a2 == a3) //They are no the same. They have the same values but, different adresses => == sign으로 비교하면 not same.
        printf("USING==  The arrays a2 and a3 are the same\n");
    else
        printf("USING==  The arrays a2 and a3 are NOT the same\n");

    int comp = compare(a1, a2, 4);
    if (comp == -1)
        printf("The arrays a1 and a2 are equal in the first 4 elements\n");
    else
        printf("The arrays a1 and a2 differ in position %d\n", comp);

    comp = compare(a1, a3, 6);
    if (comp == -1)
        printf("The arrays a1 and a3 are equal in the first 6 elements\n");
    else
        printf("The arrays a1 and a3 differ in position %d\n", comp);

    comp = compare(a2, a3, 6);
    if (comp == -1)
        printf("The arrays a2 and a3 are equal\n");
    else
        printf("The arrays a2 and a3 differ in position %d\n", comp);

    return 0;
}

