#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "assignment2.h"

//adding song will be operated by checking find_song function,
//so if the given title is not in the file, then we will add new one.
//for this problem, I got the idea from the CMPT125 website, 2020 CMPT125 class Homework 2.
int add_song(const char* file_name, song s) {

  //open the file with the given file name
  //however, if there is no such file, we need to write the new one, so the mode is 'a+'
  FILE *file_s;
  file_s = fopen(file_name, "a+");

  //check if there is song by the given title with the find_song function
  //if it returns 0, which means there exists, the function will return 0.
  song *existed_song = find_song(file_name, s.title);
  if (existed_song)
  {
    return 0;
  }

  //if there is no such song, we will store the value as the following structure.
  //The reason for storing title length, artist length is for storing the value with the iteration in find_song function.
  int title_l = strlen(s.title);
  int artist_l = strlen(s.artist);

  //storing the value, close the file and return 1
  fprintf(file_s, "%d %d %d %s %s\n", title_l, artist_l, s.year, s.title, s.artist);
  fclose(file_s);
  return 1;
}

song* find_song(const char* file_name, const char* title) {
  FILE *file_song;

  //open the file with given name, will not change the file, so just "r"
  file_song = fopen(file_name, "r");

  //For the case this funtion is called without add_song and there is no such file, then return null;
  if (!file_song)
  {
    return NULL;
  }

  char* song_title;
  char* song_artist;
  int song_year;
  int title_len;
  int artist_len;
  bool check = false;
  song* check_s = NULL;

  while (!check)
  {
    //fprintf(file_s, "%d %d %d %s %s\n", title_l, artist_l, s.year, s.title, s.artist);
    //This is the structure of the storing data
    //so, will read the first three integers and storing them in the variable.
    if(fscanf(file_song, "%d %d %d", &title_len, &artist_len, &song_year) == EOF)
    {
      check = true;
    }
    //and then store the data for song title and artist information.
    else
    {
      //since there can be space between the title or artist, so rather than using scanf,
      //I will use malloc function with the size of title_len and artist_len
      //and then store each character by iteration.
      song_title = (char*)malloc((title_len+1)*sizeof(char));
      song_artist = (char*)malloc((artist_len+1)*sizeof(char));

      fgetc(file_song); //this is for skipping the space
      for (int i =0; i<title_len; i++)
      {
        song_title[i] = (char)fgetc(file_song);
      }
      song_title[title_len] = '\0';
      fgetc(file_song); //and then skipping the space again
      for (int j = 0; j<artist_len; j++)
      {
        song_artist[j] = (char)fgetc(file_song);
      }
      song_artist[artist_len] = '\0';
      fgetc(file_song); //this is for skipping \n

      if (strcmp(song_title, title) == 0)
      {
        check_s = (song*)malloc(sizeof(song)); //make the check_s and then store the information, and return at the last.
        check_s -> title = song_title;
        check_s -> artist = song_artist;
        check_s -> year = song_year;
        check = true;
      }
      else
      {
        free(song_title);  // since I used malloc above, I need to free the data.
        free(song_artist);
      }
    }
  }
  fclose(file_song);
  return check_s;
}


unsigned long fib3(unsigned int n) {
  // in order to make the code faster, I used iteration rather than recursion.
  long* fib = (long*)malloc((n+1)*sizeof(long));

  //This case is for checking the error case,
  if (fib == NULL)
  {
    return -1;
  }

  fib[0] = 0;
  fib[1] = 1;
  fib[2] = 2;

  // make the case for n=0, 1, 2 which are actually given in the problem,
  // This is for making the code faster, avoid the iteration.
  if(n==0)
  {
    return 0;
  }
  else if(n==1)
  {
    return 1;
  }
  else if(n==2)
  {
    return 2;
  }
  else
  {
    for (int i = 3; i<=n; i++)
    {
      fib[i] = fib[i-1] + fib[i-2] + fib[i-3];
    }
    return fib[n];
  }
}

int linear_search_rec_first(int* ar, int length, int number) {
  // implement me
  
  int result;
  // checking whether the moved pointer, which pointing to the new array's first element is equal to the searching number.
  if(ar[0] == number)
  {
    return 0;
  }
  if(length == 1)
  {
    if(ar[0]==number)
    {
      return 0;
    }
    else
    {
      return -1;
    }
  }
  else
  {
    // this part is for recursion
    // finding the index by moving the pointer one index backward and then moving the length one step forward
    result = linear_search_rec_first(ar + 1, length - 1, number);
    // if the result is equal to -1, it means it fails to find the given number
    // if not so, just adding 1 everytime during recursion, so make it to follow the index
    // otherwise, just return -1 and finish.
    if(result != -1) 
    {
      return result + 1;
    }
    else
    {
      return -1;
    }
  }
}




int linear_search_rec_last(int* ar, int length, int number) {
  //length-1: because the index counts from 0
  //make the length decrease by one and the keep compare ar[length-1] == number
  //then return the length-1 if it matched.
  //since it is comparing from the last, we can just simply the first found index.
  if(length-1 >= 0)
  {
    if(ar[length-1] == number)
    {
      return length-1;
    }
    else
    {
      return linear_search_rec_last(ar, length-1, number);
    }
  }
  return -1;
}


int count_tokens(const char* str, char delim) {
  int i = 1; //it starts from 1, because I will compare the previous index value with the present one. n-1 with n.
  //Therefore, since I can't check the index 0 value, I will check with the if-else.
  int count;
  //if the given str is empty
  if((str!=NULL) && (str[0]=='\0'))
  {
    return 0;
  }
  else if(str[0]==delim) //if it starts with delim
  {
    count = 0;
  }
  else //if it starts with the alphabet
  {
    count = 1;
  }

  while(1)
  { 
    if(str[i]=='\0') //to check whether the search is over by comparing with \0 (since this is the string)
    {
      break;
    }
    else if(str[i-1]==delim && str[i]!=delim) //just count delim-alphabet case.
    {
      count++;
    }
    i++;
  }
  return count;
}


char** get_tokens(const char* str, char delim) {
  // get the number of tokens in the string with the above function
  // this is to check how many tokens we need to store.
  int token_number = count_tokens(str, delim);

  // If there is no token, then return NULL
  if(token_number == 0)
  {
    return NULL;
  }
  int i = 0;
  //this is for copying the array with the str.
  //I did this because we cannot use strtok function with the given "pointer" to the string.

  char *strs = malloc(sizeof(str)*sizeof(char**));
  strcpy(strs, str);


  char **tokens = malloc((token_number + 1)*sizeof(char*));
  
  char *token = strtok(strs, &delim);
  
  //store the token in tokens as the array
  while(token != NULL)
  {
    tokens[i] = token;
    i++;
    token = strtok(NULL, &delim);
  }
  return tokens;
}
