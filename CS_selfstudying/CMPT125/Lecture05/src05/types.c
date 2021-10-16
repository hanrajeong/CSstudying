#include <stdio.h>

    typedef int whole_number;

    enum {bold = 1, italic = 2, underline = 4};

    enum suits {Hearts, Spades, Clubs, Diamonds}; // default Hearts = 0, Spades = 1, Clubs = 2, Diamonds = 3;
    typedef enum suits suit; // give the type 'enum suits' the name 'suit'


    enum {zero, one, two}; // giving a name is not necessary

int main()
{

    whole_number n = 10; // same as int n = 10;
    printf("%d\n", n);


    // enum emphasis var = italic; // the type is 'enum emphasis'
    // printf("var = %d\n", var);


    suit cards[3] = {Hearts, 2, Diamonds};
    printf("cards = {%d, %d, %d, %d}\n", cards[0], cards[1], cards[2], cards[3]);

    printf("bold = %d\n" , bold);
    printf("two = %d\n" , two);


    return 0;
}
