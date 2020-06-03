//
//  DeckOfCards.cpp
//  Playing Card Class
//
//  Created by Jake Kaslewicz on 4/9/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include "DeckOfCards.hpp"
#include <iostream>

using namespace std;

void DeckOfCards::set(){
    srand((unsigned int)time(0));
    
    for(int i = 0; i < 52; i++){
        deck[i] = i;
    }
    shuffle();
    nextCardIndex = 0;
    
}

void DeckOfCards::shuffle(){
    knuth(deck, 51);
}

int DeckOfCards::dealCard(){
    if(nextCardIndex > 51){
        nextCardIndex = 0;
        shuffle();
    }
    int card = deck[nextCardIndex];
    nextCardIndex++;
    return card;
}

void DeckOfCards::knuth(int array[], int end){
    if(end > 0){
        int random = rand() % end;
        int temp;
        temp = deck[end];
        deck[end] = deck[random];
        deck[random] = temp;
        knuth(deck, end - 1);
        
    }
}
