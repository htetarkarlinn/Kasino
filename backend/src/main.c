#include <stdio.h>
#include "../lib/poker/include/pokergame.h"

int main(void)
{
    Card card;
    card_init(&card, 1, 2);
    printf("Card %s", card_toString(&card));
    return 0;
}
