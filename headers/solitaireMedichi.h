//
// Created by firen on 27.10.2022.
//

#ifndef SOLITAIREMEDICHI_SOLITAIREMEDICHI_H
#define SOLITAIREMEDICHI_SOLITAIREMEDICHI_H

#include "decks.h"
#include <string>
#include <vector>
#include <deque>
#include <iostream>

using Iter = std::vector<std::deque<Card>>::iterator;

bool IsDevelops(const Card &card1, const Card &card2)
{
    return (card1.par == card2.par) || (card1.suit == card2.suit);
}

void Collapse(std::vector<std::deque<Card>> &process, Iter pos1, Iter pos2) // refs?
{
    pos1->insert(pos1->end(), pos2->begin(), pos2->end());
    process.erase(pos2);
}

void PrintMidProcess(std::vector<std::deque<Card>> &process)
{
    std::cout << "------------" << std::endl;
    for (std::deque<Card> deque : process)
    {
        for (Card card : deque)
        {
            std::cout << card.to_string() << ' ';
        }
        std::cout << std::endl;
    }
}

std::string PrintResult(std::vector<std::deque<Card>> &process)
{
    std::string result;
    for (auto deque : process)
    {
        result += "[";
        for (auto card : deque)
        {
            result += ' ' + card.to_string();
        }
        result += " ]";
    }
    return result;
}

std::string PlaySolitaire(Deck36 &deck)
{
    std::string stringResult("[");
    std::vector<std::deque<Card>> process;
//    std::vector<std::deque<Card>> result;

    process.push_back(std::deque<Card> { deck[0] });
    process.push_back(std::deque<Card> { deck[1] });
    process.push_back(std::deque<Card> { deck[2] });

    for (auto deque : process)
    {
        stringResult += ' ' + deque.front().to_string();
    }

    if (IsDevelops(process.front().back(), process.back().back())) // ?
    {
        Collapse(process, process.begin(), process.begin()+1);
        stringResult += " ] [";
    }

    for (int i = 3; i < deck.Size(); i++)
    {
        process.push_back(std::deque<Card> { deck[i] });
        stringResult += ' ' + deck[i].to_string();

        if (IsDevelops((process.end()-3)->back(), (process.end()-1)->back()))
        {
            Collapse(process, process.end()-3, process.end()-2);
            stringResult += " ] [";
            bool isDevelops = true;

            while (isDevelops)
            {
                isDevelops = false;

                for (auto iter = process.begin(); iter < process.end()-2; iter++)
                {
                    if (IsDevelops(iter->back(), (iter+2)->back()))
                    {
                        Collapse(process, iter, iter+1);
                        isDevelops = true;
                        break;
                    }
                }
            }
        }
    }

    stringResult += " ]";

    if (process.size() > 2)
    {
        stringResult = std::string();
    }

    return stringResult;
}

#endif //SOLITAIREMEDICHI_SOLITAREMEDICHI_H
