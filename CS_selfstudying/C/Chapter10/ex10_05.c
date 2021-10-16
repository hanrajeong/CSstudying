#include <stdio.h>

int main(void)
{
  int select_num = 0;
  char answer;
  int car_reservation[10] = {0};

  while(1)
  {
    printf("Would you like to select the model number of the car? ");
    scanf("%c", &answer, sizeof(answer));

    if(answer == 'N' || answer == 'n')
    {
      break;
    }
    else if(answer == 'Y' || answer == 'y')
    {
      printf("The model number of car: 1 2 3 4 5 6 7 8 9 10\n");
      printf("The Reservation status : ");

      for (int i = 0; i < 10; i++)
      {
        printf("%02d ", car_reservation[i]);
      }
    retry: 

      printf("\nPlease select the model number you want to make a reservation: ");
      scanf("%d", &select_num);

      if(select_num < 0 || select_num > 10)
      {
        goto retry;
      }
      else
      {
        if(car_reservation[select_num] == 1)
        {
          printf("All the car you selected is reserved. Sorry. Please select another model.\n");
          goto retry;
        }
        else
        {
          printf("You reservation has been completed.\n");
          car_reservation[select_num] = 1;
        }
      }
    }
    else
    {
      printf("please type y or n only.\n");
      printf("please type again\n");
    }
  }

  return 0;
}