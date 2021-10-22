#include <stdio.h>
#include <stdlib.h>


// WHY IS THIS WRONG?
char* get_name() {
  printf( "Please enter your name: " );

  // should be enough space for a name
  char *line = (char*)malloc(10*sizeof(char));
  
  // reads at most 1023 chars from stdin, up to first newline, 
  // EOF or error.
  if( fgets( line, 10, stdin ) == 0 ) // we ALWAYS check for I/O errors
  {
    perror( "failed to read a name" );
    exit(1);
  }
  
  return line; 
}	

int main( void )
{
  char* name = get_name();

  // works if we are *lucky*
  printf( "Your name is %s\n", name );

  return 0;
}	       
