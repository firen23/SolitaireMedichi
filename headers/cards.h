//
// Created by firen on 27.10.2022.
//

#ifndef SOLITAIREMEDICHI_CARDS_H
#define SOLITAIREMEDICHI_CARDS_H
#include <string>

enum Suit
{
    Spades = 's',
    Diamonds = 'd',
    Hearts = 'h',
    Clubs = 'c'
};

enum Par
{
    Six = '6',
    Seven = '7',
    Eight = '8',
    Nine = '9',
    Ten = 't',
    Jack = 'J',
    Queen = 'Q',
    King = 'K',
    Ace = 'A'
};

struct Card
{
    Par par;
    Suit suit;

    std::string to_string()
    {
        return {static_cast<char>(par), static_cast<char>(suit)};
    }

    bool operator==(Card card)
    {
        return (par == card.par) && (suit == card.suit);
    }
};


#endif //SOLITAIREMEDICHI_CARDS_H
