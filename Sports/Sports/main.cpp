//
//  main.cpp
//  Sports
//
//  Created by Jake Kaslewicz on 5/1/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
#include <cctype>

using namespace std;

class Sport{
public:
    double area;
    int numPlayers;
    int perScore;
    virtual void displayInfo();
};

class TimeSport : public Sport {
public:
    double duration;
};

class football : public TimeSport {
private:
    int downs;

public:
    void displayInfo();
    football();
};

class volleyball : public Sport {
private:
    int perSet;
    double netHeight;

public:
    void displayInfo();
    volleyball();
};

class soccer : public TimeSport{
private:
    int numSubs;

public:
    soccer();
    void displayInfo();
};

class tennis : public Sport{
public:
    tennis();
    void displayInfo();
private:
    int numMatches;
    int perSet;
    double netHeight;
};

football::football()
{
    area = 5351.2;
    duration = 60;
    numPlayers = 11;
    perScore = 7;
    downs = 4;
}

void Sport::displayInfo()
{
    cout << "Area played in: " << area << endl;
    cout << "Number of players: " << numPlayers << endl;
    cout << "Points per score: " << perScore << endl;
}

void football::displayInfo()
{
    cout << "Area played in: " << area << endl;
    cout << "Number of players: " << numPlayers << endl;
    cout << "Points per score: " << perScore << endl;
    cout << "Duration: " << duration << endl;
    cout << "Downs: " << downs << endl;
}

void volleyball::displayInfo()
{
    cout << "Area played in: " << area << endl;
    cout << "Net height: " << netHeight << endl;
    cout << "Number of players: " << numPlayers << endl;
    cout << "Points per score: " << perScore << endl;
    cout << "Points per set: " << perSet << endl;
}

soccer::soccer()
{
    area = 7000;
    duration = 90;
    numPlayers = 11;
    perScore = 1;
    numSubs = 3;
}
volleyball::volleyball()
{
    area = 2.43;
    netHeight = 162;
    numPlayers = 6;
    perScore = 1;
    perSet = 15;
}

void soccer::displayInfo()
{
    cout << "Area played in: " << area << endl;
    cout << "Number of players: " << numPlayers << endl;
    cout << "Points per score: " << perScore << endl;
    cout << "Duration: " << duration << endl;
    cout << "Number of substitutions: " << numSubs << endl;
}

tennis::tennis()
{
    string response;
    cout << "Singles or doubles?\n";
    cin >> response;
    if(response == "singles"){
        area = 195;
        numMatches = 3;
        numPlayers = 1;
        perScore = 1;
        perSet = 6;
        netHeight = 0.914;
    } else {
        area = 260;
        numMatches = 3;
        numPlayers = 2;
        perScore = 1;
        perSet = 6;
        netHeight = 0.914;
    }
}

void tennis::displayInfo()
{
    cout << "Area played in: " << area << endl;
    cout << "Number of players: " << numPlayers << endl;
    cout << "Points per score: " << perScore << endl;
    cout << "Number of matches: " << numMatches << endl;
    cout << "Points per set: " << perSet << endl;
    cout << "Net height: " << netHeight << endl;
}


int main()
{
    string best;
    cout << "What sport do you wish to see information about?\n";
    cout << "The options are: (f)ootball, (v)olleyball, (s)occer or (t)ennis?\n";
    cin >> best;
    
    Sport *x = new Sport();
    if(tolower(best[0]) == 'f')
    {
        x = new football();
    } else if(tolower(best[0]) == 'v'){
        x = new volleyball();
    }
    else if(tolower(best[0]) == 's')
    {
        x = new soccer();
    }
    else if(tolower(best[0]) == 't')
    {
        x = new tennis();
    }
    x->displayInfo();
}
