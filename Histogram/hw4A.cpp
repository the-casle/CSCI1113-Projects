//
//  main.cpp
//  Histogram
//
//  Created by Jake Kaslewicz on 3/20/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

void iterateThroughStream(ifstream &stream, int letterGrades[]);

int gradeFromRow(int row, ifstream &stream, bool &lastRow);
// 0=A, 1=B...

char gradeFromString(string row);
// Assumed to be 4th element

void outputHistogram(int letterGrades[]);
// 0=A, 1=B...

int maxHeight(int letterGrades[]);

int main(int argc, const char * argv[]) {
    string file;
    cout << "Which file do you want to open? ";
    cin >> file;

    ifstream inStream;
    inStream.open(file.c_str());
    if(inStream.fail()){
        cout << "Unable to open file.\n";
        exit(1);
    }
    
    int letterGrades[5];
    iterateThroughStream(inStream, letterGrades);
    outputHistogram(letterGrades);
    
    inStream.close();
    return 0;
}

void iterateThroughStream(ifstream &stream, int letterGrades[]){
    bool lastRow = false;
    int i = 0;
    while(!lastRow){
        int gradeIndex = gradeFromRow(i, stream, lastRow);
        if(!lastRow)letterGrades[gradeIndex] += 1;
        i++;
    }
}

int gradeFromRow(int row, ifstream &stream, bool &lastRow){
    string rowString;
    stream >> rowString;
    
    char simplifiedGrade = gradeFromString(rowString);
    if(simplifiedGrade == 'A') return 0;
    else if(simplifiedGrade == 'B') return 1;
    else if(simplifiedGrade == 'C') return 2;
    else if(simplifiedGrade == 'D') return 3;
    else if(simplifiedGrade == 'F') return 4;
    else {
        lastRow = true;
        return 0;
    }
}

char gradeFromString(string row){
    int gradeIndex = 0;
    for(int i = 0; i < 3; i++){
        gradeIndex = row.find(",", gradeIndex) + 1;
    }
    return row[gradeIndex];
}

void outputHistogram(int letterGrades[]){
    ofstream outStream;
    outStream.open("histogram.txt");
    if(outStream.fail()){
        cout << "Unable to open file.\n";
        exit(1);
    }
    
    int height = maxHeight(letterGrades);
    for(int i = height; i > 0; i--){
        outStream << i << "|";
        for(int j = 0; j < 5; j++){
            if(i <= letterGrades[j]){
                outStream << "X";
            } else {
                outStream << " ";
            }
        }
        outStream << endl;
    }
    outStream << "  ABCDF";
    outStream.close();
    cout << "Done making file!\n";
}

int maxHeight(int letterGrades[]){
    int max = 0;
    for(int i = 0; i < 5; i++){
        if(letterGrades[i] > max) max = letterGrades[i];
    }
    return max;
}
