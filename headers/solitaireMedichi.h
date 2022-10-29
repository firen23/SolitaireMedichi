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

std::string GetResultString(std::vector<std::deque<Card>> &result)
{
    std::string resultString;
    for (auto deque : result)
    {
        resultString += "[";
        for (auto card : deque)
        {
            resultString += ' ' + card.to_string();
        }
        resultString += " ]";
    }
    return resultString;
}

std::string PlaySolitaire(Deck36 &deck)
{
    std::vector<std::deque<Card>> process;
    std::vector<std::deque<Card>> result;

    process.push_back(std::deque<Card> { deck[0] });
    process.push_back(std::deque<Card> { deck[1] });
    process.push_back(std::deque<Card> { deck[2] });

    result.push_back({ deck[0], deck[1], deck[2] });

    if (IsDevelops(process.front().back(), process.back().back())) // ?
    {
        Collapse(process, process.begin(), process.begin()+1);
        result.push_back({});
    }

    for (int i = 3; i < deck.Size(); i++)
    {
        process.push_back(std::deque<Card> { deck[i] });
        result.back().push_back(deck[i]);

        if (IsDevelops((process.end()-3)->back(), (process.end()-1)->back()))
        {
            Collapse(process, process.end()-3, process.end()-2);
            result.push_back({});
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

    if (process.size() > 2)
    {
        result.clear();
    }
    else
    {
        result.pop_back();
    }

    return GetResultString(result);
}

#endif //SOLITAIREMEDICHI_SOLITAREMEDICHI_H
