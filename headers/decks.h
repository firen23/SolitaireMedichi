//
// Created by firen on 27.10.2022.
//

#ifndef SOLITAIREMEDICHI_DECKS_H
#define SOLITAIREMEDICHI_DECKS_H

#include "cards.h"
#include <algorithm>
#include <random>

struct Deck36
{
    size_t number_of_cards = 36;
    Card cards[36] = { {Par::Six, Suit::Spades},
                       {Par::Six, Suit::Diamonds},
                       {Par::Six, Suit::Hearts},
                       {Par::Six, Suit::Clubs},
                       {Par::Seven, Suit::Spades},
                       {Par::Seven, Suit::Diamonds},
                       {Par::Seven, Suit::Hearts},
                       {Par::Seven, Suit::Clubs},
                       {Par::Eight, Suit::Spades},
                       {Par::Eight, Suit::Diamonds},
                       {Par::Eight, Suit::Hearts},
                       {Par::Eight, Suit::Clubs},
                       {Par::Nine, Suit::Spades},
                       {Par::Nine, Suit::Diamonds},
                       {Par::Nine, Suit::Hearts},
                       {Par::Nine, Suit::Clubs},
                       {Par::Ten, Suit::Spades},
                       {Par::Ten, Suit::Diamonds},
                       {Par::Ten, Suit::Hearts},
                       {Par::Ten, Suit::Clubs},
                       {Par::Jack, Suit::Spades},
                       {Par::Jack, Suit::Diamonds},
                       {Par::Jack, Suit::Hearts},
                       {Par::Jack, Suit::Clubs},
                       {Par::Queen, Suit::Spades},
                       {Par::Queen, Suit::Diamonds},
                       {Par::Queen, Suit::Hearts},
                       {Par::Queen, Suit::Clubs},
                       {Par::King, Suit::Spades},
                       {Par::King, Suit::Diamonds},
                       {Par::King, Suit::Hearts},
                       {Par::King, Suit::Clubs},
                       {Par::Ace, Suit::Spades},
                       {Par::Ace, Suit::Diamonds},
                       {Par::Ace, Suit::Hearts},
                       {Par::Ace, Suit::Clubs},
    };

    void Shuffle()
    {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(std::begin(cards), std::end(cards), g);
    }

    void Shuffle(int n)
    {
        for (int i = 0; i < n; i++)
            Shuffle();
    }

    void Reverse()
    {
        std::vector<Card> temp(std::begin(cards), std::end(cards));
        std::reverse(temp.begin(), temp.end());
        for (int i = 0; i < number_of_cards; i++)
            cards[i] = temp[i];
    }

    void Print()
    {
        for (int i = 0; i < number_of_cards; i++)
        {
            std::cout << cards[i].to_string() << ' ';
        }
        std::cout << std::endl;
    }

    void PrintReverse()
    {
        for (int i = number_of_cards - 1; i >= 0; i--)
        {
            std::cout << cards[i].to_string() << ' ';
        }
        std::cout << std::endl;
    }
};

#endif //SOLITAIREMEDICHI_DECKS_H
