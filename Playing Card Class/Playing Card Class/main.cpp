//
//  main.cpp
//  Playing Card Class
//
//  Created by Jake Kaslewicz on 4/9/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
#include "DeckOfCards.hpp"
using namespace std;

const int deals = 10000;

void displayHand(int hand[], int size);
int scoreDealer(int hand[], int size);
int simplifyCard(int card);

int main(int argc, const char * argv[]) {
    DeckOfCards deck;
    deck.set();
    
    /*for(int i = 0; i < 13; i++){
        int hand[4];
        for(int j = 0; j < 4; j++){
            hand[j] = deck.dealCard();
        }
        displayHand(hand, 4);
        cout << endl;
    }*/
    
    int natural = 0, seventeen = 0, eighteen = 0, nineteen = 0, twenty= 0, twentyone= 0, bust = 0;
    
    for(int i = 0; i < deals; i++){
        int size = 2;
        int hand[21];
        int score = 0;
        for(int j = 0; j < size; j++){
            hand[j] = deck.dealCard();
        }
        score = scoreDealer(hand, size);
        while(score < 17){
            hand[size] = deck.dealCard();
            size++;
            score = scoreDealer(hand, size);
        }
        if(score == 21 && size == 2){
            natural++;
        }
        
        if(score == 17){
            seventeen++;
        } else if(score == 18){
            eighteen++;
        } else if(score == 19){
            nineteen++;
        } else if(score == 20){
            twenty++;
        } else if (score == 21){
            twentyone++;
        } else {
            bust++;
        }
    }
    
    cout << "Number of natural blackjack hands: " << natural << " (" << ((double)natural / deals * 100.0) << "%)" << endl;
    cout << "hands of 17: " << seventeen << " (" << ((double)seventeen / deals * 100.0) << "%)" << endl;
    cout << "hands of 18: " << eighteen << " (" << ((double)eighteen / deals * 100.0) << "%)" << endl;
    cout << "hands of 19: " << nineteen << " (" << ((double)nineteen / deals * 100.0) << "%)" << endl;
    cout << "hands of 20: " << twenty << " (" << ((double)twenty / deals * 100.0) << "%)" << endl;
    cout << "hands of 21: " << twentyone << " (" << ((double)twentyone / deals * 100.0) << "%)" << endl;
    cout << "dealer bust: " << bust << " (" << ((double)bust / deals * 100.0) << "%)" << endl;
    
    return 0;
}

void displayHand(int hand[], int size){
    for(int i = 0; i < size; i++){
        int card = simplifyCard(hand[i]);
        if(card == 0) cout << "A ";
        else if(card > 0 && card < 10){
            cout << (card + 1) << " ";
        } else if(card == 10){
            cout << "J ";
        } else if(card == 11){
            cout << "Q ";
        } else if(card == 12){
            cout << "K ";
        }
    }
}

int scoreDealer(int hand[], int size){
    int score = 0;
    for(int i = 0; i < size; i++){
        int card = simplifyCard(hand[i]);
        if(card > 0 & card < 10){
            score += (card + 1);
        } else if(card >= 10){
            score += 10;
        }
    }
    for(int i = 0; i < size; i++){ // Accounting the aces.
        int card = simplifyCard(hand[i]);
        if(card == 0){
            if((score + 11) <= 21){
                score += 11;
            } else {
                score += 1;
            }
        }
    }
    return score;
}

int simplifyCard(int card){
    bool simple = false;
    while(!simple){
        int newCalc = card - 13;
        if(newCalc < 0){
            simple = true;
        } else {
            card -= 13;
        }
    }
    return card;
}
