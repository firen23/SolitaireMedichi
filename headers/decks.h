//
// Created by firen on 27.10.2022.
//

#ifndef SOLITAIREMEDICHI_DECKS_H
#define SOLITAIREMEDICHI_DECKS_H

#include "cards.h"
#include <algorithm>
#include <random>
#include <set>


class Deck36
{
private:
    Card cards[36];
    size_t number_of_cards = 36;

public:
    Deck36()
    {
        cards[0] = {Par::Six, Suit::Spades};
        cards[1] = {Par::Six, Suit::Diamonds};
        cards[2] = {Par::Six, Suit::Hearts};
        cards[3] = {Par::Six, Suit::Clubs};
        cards[4] = {Par::Seven, Suit::Spades};
        cards[5] = {Par::Seven, Suit::Diamonds};
        cards[6] = {Par::Seven, Suit::Hearts};
        cards[7] = {Par::Seven, Suit::Clubs};
        cards[8] = {Par::Eight, Suit::Spades};
        cards[9] = {Par::Eight, Suit::Diamonds};
        cards[10] = {Par::Eight, Suit::Hearts};
        cards[11] = {Par::Eight, Suit::Clubs};
        cards[12] = {Par::Nine, Suit::Spades};
        cards[13] = {Par::Nine, Suit::Diamonds};
        cards[14] = {Par::Nine, Suit::Hearts};
        cards[15] = {Par::Nine, Suit::Clubs};
        cards[16] = {Par::Ten, Suit::Spades};
        cards[17] = {Par::Ten, Suit::Diamonds};
        cards[18] = {Par::Ten, Suit::Hearts};
        cards[19] = {Par::Ten, Suit::Clubs};
        cards[20] = {Par::Jack, Suit::Spades};
        cards[21] = {Par::Jack, Suit::Diamonds};
        cards[22] = {Par::Jack, Suit::Hearts};
        cards[23] = {Par::Jack, Suit::Clubs};
        cards[24] = {Par::Queen, Suit::Spades};
        cards[25] = {Par::Queen, Suit::Diamonds};
        cards[26] = {Par::Queen, Suit::Hearts};
        cards[27] = {Par::Queen, Suit::Clubs};
        cards[28] = {Par::King, Suit::Spades};
        cards[29] = {Par::King, Suit::Diamonds};
        cards[30] = {Par::King, Suit::Hearts};
        cards[31] = {Par::King, Suit::Clubs};
        cards[32] = {Par::Ace, Suit::Spades};
        cards[33] = {Par::Ace, Suit::Diamonds};
        cards[34] = {Par::Ace, Suit::Hearts};
        cards[35] = {Par::Ace, Suit::Clubs};
    }

    size_t Size()
    {
        return number_of_cards;
    }

    void Set(int pos, Card card)
    {
        auto currentPosition = std::find(std::begin(cards), std::end(cards), card);
        *currentPosition = cards[pos];
        cards[pos] = card;
    }

    Card& operator[](int i)
    {
        return cards[i];
    }

    Card operator[](int i) const
    {
        return cards[i];
    }

    bool isCorrect()
    {
//        std::set<Card> set(cards, cards + number_of_cards); // cant use set, need to overload operators
//        return set.size() == number_of_cards;
        for (int i = 0; i < number_of_cards - 1; i++)
        {
            for (int j = i + 1; j < number_of_cards; j++)
            {
                if (cards[i] == cards[j])
                {
                    return false;
                }
            }
        }
        return true;
    }

    void Shuffle(int fromPosition = 0)
    {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(std::begin(cards)+fromPosition, std::end(cards), g);
    }

    void Shuffle(int times, int fromPosition)
    {
        for (int i = 0; i < times; i++)
            Shuffle(fromPosition);
    }

    void Print()
    {
        for (int i = 0; i < number_of_cards; i++)
        {
            std::cout << cards[i].to_string() << ' ';
        }
        std::cout << std::endl;
    }
};

#endif //SOLITAIREMEDICHI_DECKS_H
