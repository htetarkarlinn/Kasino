#include "pokergame.h"
#include <string.h>
#include <stdlib.h>

void card_init(Card *aCardPtr, int suit, int rank)
{
  aCardPtr->suit = suit;
  aCardPtr->rank = rank;
}

char *card_toString(Card *aCardPtr)
{
  char *str = (char *)malloc(sizeof(char) * 20);
  char *tmp = (char *)malloc(sizeof(char) * 5);
  if (aCardPtr == NULL)
    return NULL;
  switch (aCardPtr->rank)
  {
  case 11:
    strcpy(str, "J");
    break;
  case 12:
    strcpy(str, "Q");
    break;
  case 13:
    strcpy(str, "K");
    break;
  case 14:
    strcpy(str, "A");
    break;
  default:
    sprintf(tmp, "%d", aCardPtr->rank);
    strcpy(str, tmp);
    break;
  }

  strcat(str, " of ");

  switch (aCardPtr->suit)
  {
  case 1:
    strcat(str, "Spades");
    break;
  case 2:
    strcat(str, "Hearts");
    break;
  case 3:
    strcat(str, "Diamonds");
    break;
  case 4:
    strcat(str, "Clubs");
    break;
  default:
    sprintf(tmp, "%d", aCardPtr->suit);
    strcat(str, tmp);
    break;
  }

  free(tmp);
  return str;
}

int card_compare(const void *a, const void *b)
{
  return ((*(Card **)(a))->rank) - ((*(Card **)(b))->rank);
}
void card_destroy(Card *aCardPtr)
{
  free(aCardPtr);
}
