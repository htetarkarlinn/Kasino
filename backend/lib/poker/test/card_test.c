#include "utils/testing.h"
#include "pokergame.h"
#include <string.h>

TEST(test_card_toString)
{
    Card card;
    card_init(&card, 1, 2);
    ASSERT(strcmp(card_toString(&card), "2 of Spades") == 0);
    card_init(&card, 2, 2);
    ASSERT(strcmp(card_toString(&card), "2 of Hearts") == 0);
    card_init(&card, 3, 2);
    ASSERT(strcmp(card_toString(&card), "2 of Diamonds") == 0);
    card_init(&card, 4, 13);
    ASSERT(strcmp(card_toString(&card), "K of Clubs") == 0);
    card_destroy(&card);
}

int main()
{
    RUN_TEST(test_card_toString);
    return failed;
}