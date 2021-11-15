  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>


  #include "assignment2.h"


  void test_q1()  {
    song bd = {"All Along the Watchtower", "Bob Dylan", 1968};
    song jj = {"Mercedes Benz", "Janis Joplin", 1971};
    song lz = {"Stairway to Heaven", "Led Zeppelin", 1971};

    int tmp;
    tmp = add_song("songs.db", bd);
    if (tmp == 1)
      printf("Q1-1 ok\n");
    else
      printf("Q1-1 ERROR : expected 1, return = %d\n", tmp);

    tmp = add_song("songs.db", jj);
    if (tmp == 1)
      printf("Q1-2 ok\n");
    else
      printf("Q1-2 ERROR : expected 1, return = %d\n", tmp);

    tmp = add_song("songs.db", lz);
    if (tmp == 1)
      printf("Q1-3 ok\n");
    else
      printf("Q1-3 ERROR : expected 1, return = %d\n", tmp);

    tmp = add_song("songs.db", jj);
    if (tmp == 0)
      printf("Q1-4 ok\n");
    else
      printf("Q1-4 ERROR : expected 0, return = %d\n", tmp);

    song* s_mb = find_song("songs.db", "Mercedes Benz");
    if (s_mb && strcmp(s_mb->artist, "Janis Joplin") == 0)
      printf("Q1-5 ok\n");
    else
      printf("Q1-5 ERROR, Mercedes Benz not found\n");
    if (s_mb)
      free(s_mb);

    song* s_ds = find_song("some_other_file.db", "Money for Nothing");
    if (s_ds == NULL)
      printf("Q1-5 ok\n");
    else
      printf("Q1-5 ERROR, found \"Money for Nothing\"\n");
    if (s_ds)
      free(s_ds);
  }

  void test_q2() {
    if (fib3(5) == 11) printf("Q2-1 ok\n");
    else printf("Q2-1 ERROR\n");

    if (fib3(19) == 55403) printf("Q2-2 ok\n");
    else printf("Q2-2 ERROR\n");

    if (fib3(30) == 45152016) printf("Q2-3 ok\n");
    else printf("Q2-3 ERROR\n");

    if (fib3(50) == 8864740270458) printf("Q2-4 ok\n");
    else printf("Q2-4 ERROR\n");

  }

  void test_q3() {
    int ar1[] = {1,2,3,4,5,4,3,2,1};
    if (linear_search_rec_first(ar1,9,2) == 1) printf("Q3-1 ok\n");
    else printf("Q3-1 ERROR\n");

    if (linear_search_rec_first(ar1,9,5) == 4) printf("Q3-2 ok\n");
    else printf("Q3-2 ERROR\n");

    if (linear_search_rec_last(ar1,9,2) == 7) printf("Q3-3 ok\n");
    else printf("Q3-3 ERROR\n");

    if (linear_search_rec_last(ar1,9,4) == 5) printf("Q3-4 ok\n");
    else printf("Q3-4 ERROR\n");

    if (linear_search_rec_last(ar1,6,8) == -1) printf("Q3-5 ok\n");
    else printf("Q3-5 ERROR\n");

  }

  void test_q4() {
    int count = count_tokens("---HELLO-WORLD-dot-c--", '-');
    if (count == 4) printf("Q4-1 ok\n");
    else printf("Q4-1 ERROR\n");

    char** tokens = get_tokens("++All+Along+the+Watchtower++", '+');

    if (tokens==NULL) {
      printf("Q4-2 ERROR: tokens==NULL\n");
      return;
    }

    char* sol[4] = {"All", "Along", "the", "Watchtower"};

    for (int i=0; i<4; i++) {
      if (tokens[i] && strcmp(tokens[i], sol[i]) == 0)
        printf("Q4-2 tokens[%d] ok\n", i);
      else
        printf("Q4-2 ERROR: tokens[%d] error\n" ,i);
    }
    


  }

  int main() {
    test_q1();
    test_q2();
    test_q3();
    test_q4();

    return 0;
  }