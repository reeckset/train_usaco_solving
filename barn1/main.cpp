/*
ID: henriqu16
TASK: barn1
LANG: C++                
*/

#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ofstream out ("barn1.out");
    ifstream in ("barn1.in");

    int numberOfBoards, nbrOfStalls, nbrOfOccupiedStalls;
    in >> numberOfBoards >> nbrOfStalls >> nbrOfOccupiedStalls;

    if(numberOfBoards >= nbrOfOccupiedStalls){
        out << nbrOfOccupiedStalls << endl;
        return 0;
    }

    
    int lastOccupiedStall, firstOccupiedStall;
    set<int> occuppiedStalls;
    for(int i = 0; i < nbrOfOccupiedStalls; i++){
        int currStall;
        in >> currStall;
        occuppiedStalls.insert(currStall);
    }

    firstOccupiedStall = (*(occuppiedStalls.begin()));

    int gapSum = 0;
    int lastNbr = firstOccupiedStall-1;
    set<pair<int, int>, greater<pair<int, int>>> gapStallSet;
    for(auto currStall : occuppiedStalls){
        int currGap = currStall - lastNbr - 1;
        gapSum += currGap;
        gapStallSet.insert({currGap, currStall});
        lastNbr = currStall;
    }


    auto currIterator = gapStallSet.begin();
    for(int i = 0; i < numberOfBoards - 1; i++){
        gapSum -= (currIterator)->first;
        currIterator++;
    }

    out << gapSum + nbrOfOccupiedStalls << endl;

    //out << total << endl;
    
    return 0;
}
