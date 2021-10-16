#include <stdio.h>

typedef struct {
  int ID;
  char* name;
} person;

int linear_search(person* players, int len, int id) {
  int i;
  for (i=0; i < len; i++) {
    if (players[i].ID == id)
      return i;
  }

  // if reached here, id not found;
  return -1;
}

int binary_search(person* players, int len, int id) {
  int start = 0, end = len-1, mid;
  while (start<=end) {
//    printf("[%d, %d]\n", start, end); // debugging
    mid = (start+end)/2;
    if (id==players[mid].ID)
      return mid;
    else if  (id < players[mid].ID)
      end = mid-1;
    else // id > players[mid].ID
      start = mid+1;
  }

  // if reached here, id not found;
  return -1;
}

int main() { 
  person lst[] = {
    {001, "Oh Il-nam"},
    {067, "Kang Sae-byeok"},
    {101, "Jang Deok-su"},
    {111, "Byeong-gi"},
    {199, "Ali Abdul"},
    {218, "Cho Sang-woo"},
    {240, "Ji-yeong"},
    {456, "Seong Gi-hun"}
  };

  int index = binary_search(lst, 8, 199);
  if (index >=0)
    printf("ID = %03d, name = %s\n", lst[index].ID, lst[index].name);
  else
    printf("ID not found\n");
  return 0;
}

