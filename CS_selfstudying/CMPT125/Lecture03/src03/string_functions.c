/* Implementations of str_len, str_cpy str_cat without
 * using the stardard library string.h
 */
#include <stdio.h>


// comparing two strings
int str_cmp(const char* s1, const char* s2)
{
  // if they are the same string in the memory, return 0
  if (s1 == s2)
    return 0;
  
  int i=0;

  while(s1[i] != 0 && s2[i] != 0)  // same as s1[i] != '\0'...
  {
    if (s1[i] != s2[i])
      return (s1[i] - s2[i]);
    else
      i++;
  }
  // one of the strings has been traversed
  return s1[i] - s2[i];
}


// Returns the length of the string
int str_len(const char* str)
{
    int i = 0;
    while (str[i] != '\0') // str[i] != 0
    {
        i++;
    }
    return i;

}

// Copies the string pointed by src into the array pointed by dest
// including the terminating null character.
// Returns pointer to dest.
// We assume that the size of dest is at least the length of src + 1.
char* str_cpy (char* dest, const char* src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
    return dest;
}

// Appends a copy of the source string to the destination string.
// Returns pointer to dest.
// We assume that the size of dest is large enough
// to contain the concatenated string, and that the strings do not overlap.
char* str_cat (char* dest, const char* src)
{
    int i = 0;
    while (dest[i] != '\0')
    {
        i++;
    } // compute strlen(dest)
    str_cpy(dest+i, src);
    return dest;
}


int main()
{
    char* a = "These";
    char b[40];

    printf("The length of \"%s\" is %d\n", a, str_len(a));

    str_cpy(b, a);

    printf("%d\n", str_cmp(a, b));

    if (a == b)
      printf("a == b\n");
    else
      printf("a != b\n"); // WHY?


    str_cat(b, " strings");
    printf("b = \"%s\"\n", b); // use \" to print quotation marks
    str_cat(b, " are");
    printf("b = \"%s\"\n", b); // use \" to print quotation marks
    printf("b = \"%s\"\n", str_cat(b, " concatenated.")); // use \" to print quotation marks

    return 0;
}
