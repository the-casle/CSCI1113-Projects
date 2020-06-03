//
//  DeckOfCards.hpp
//  Playing Card Class
//
//  Created by Jake Kaslewicz on 4/9/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#ifndef DeckOfCards_hpp
#define DeckOfCards_hpp

#include <stdio.h>
class DeckOfCards{
public:
    void set();
    void shuffle();
    int dealCard();
    
private:
    int deck[52];
    int nextCardIndex;
    void knuth(int array[], int end);
};

#endif /* DeckOfCards_hpp */
