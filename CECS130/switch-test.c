#include <stdio.h>

int main(void)
{
  int constant = 1;
  //No default define, value not a case in switch
  switch(constant)
    {
    case 0:
    printf("0\n");
    break;
    }
}
