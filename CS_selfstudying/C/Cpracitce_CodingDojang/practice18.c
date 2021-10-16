#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count_tokens(const char* str, char delim);
char** get_tokens(const char* str, char delim);

int main(void)
{
  char** tokens = get_tokens("++All+Along+the+Watchtower++", '+');

  char* sol[4] = {"All", "Along", "the", "Watchtower"};

    for (int i=0; i<4; i++) {
      if (tokens[i] && strcmp(tokens[i], sol[i]) == 0)
        printf("Q4-2 tokens[%d] ok\n", i);
      else
        printf("Q4-2 ERROR: tokens[%d] error\n" ,i);
    }
  return 0;
}

int count_tokens(const char* str, char delim) 
{
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
