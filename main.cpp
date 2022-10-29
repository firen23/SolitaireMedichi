#include <iostream>
#include "headers\decks.h"
#include "headers\solitaireMedichi.h"

int main() {
    int deckConstPositions = 3;
    Deck36 deck;
    deck.Shuffle(7, deckConstPositions);
    deck.Set(0, {Par::Jack, Suit::Diamonds});
    deck.Set(1, {Par::Nine, Suit::Spades});
    deck.Set(2, {Par::Ace, Suit::Diamonds});
//    deck.Print();
//    std::cout << std::boolalpha << deck.isCorrect() << std::endl;
//    deck.Shuffle(7, deckConstPositions);

//    deck.cards[0] = {Par::Jack, Suit::Diamonds};
//    deck.cards[1] = {Par::Nine, Suit::Spades};
//    deck.cards[2] = {Par::Ace, Suit::Diamonds};
//    deck.cards[3] = {Par::Queen, Suit::Clubs};
//    deck.cards[4] = {Par::King, Suit::Clubs};
//    deck.cards[5] = {Par::Jack, Suit::Hearts};
//    deck.cards[6] = {Par::Nine, Suit::Clubs};
//    deck.cards[7] = {Par::King, Suit::Hearts};
//    deck.cards[8] = {Par::Seven, Suit::Spades};
//    deck.cards[9] = {Par::Six, Suit::Spades};
//    deck.cards[10] = {Par::Queen, Suit::Diamonds};
//    deck.cards[11] = {Par::King, Suit::Spades};
//    deck.cards[12] = {Par::Queen, Suit::Spades};
//    deck.cards[13] = {Par::Ace, Suit::Spades};
//    deck.cards[14] = {Par::Seven, Suit::Clubs};
//    deck.cards[15] = {Par::Seven, Suit::Diamonds};
//    deck.cards[16] = {Par::Ten, Suit::Spades};
//    deck.cards[17] = {Par::Nine, Suit::Hearts};
//    deck.cards[18] = {Par::Ace, Suit::Clubs};
//    deck.cards[19] = {Par::Nine, Suit::Diamonds};
//    deck.cards[20] = {Par::Eight, Suit::Spades};
//    deck.cards[21] = {Par::Ten, Suit::Hearts};
//    deck.cards[22] = {Par::Six, Suit::Diamonds};
//    deck.cards[23] = {Par::Ten, Suit::Diamonds};
//    deck.cards[24] = {Par::Ace, Suit::Hearts};
//    deck.cards[25] = {Par::Six, Suit::Hearts};
//    deck.cards[26] = {Par::Ten, Suit::Clubs};
//    deck.cards[27] = {Par::Seven, Suit::Hearts};
//    deck.cards[28] = {Par::King, Suit::Diamonds};
//    deck.cards[29] = {Par::Jack, Suit::Clubs};
//    deck.cards[30] = {Par::Eight, Suit::Diamonds};
//    deck.cards[31] = {Par::Six, Suit::Clubs};
//    deck.cards[32] = {Par::Queen, Suit::Hearts};
//    deck.cards[33] = {Par::Eight, Suit::Clubs};
//    deck.cards[34] = {Par::Jack, Suit::Spades};
//    deck.cards[35] = {Par::Eight, Suit::Hearts};

    int n = 1000;
    int i = 1;
    std::string result;
    for (; i < n; i++)
    {
        result = PlaySolitaire(deck);
        if (!result.empty()) break;
        deck.Shuffle(7, deckConstPositions);
    }

    if (i == n)
    {
        std::cout << "Fail after " << n << " times" << std::endl;
    }
    else
    {
        deck.Print();
        std::cout << "Iteration: " << i << std::endl;
        std::cout << result << std::endl;
    }

    return 0;
}
