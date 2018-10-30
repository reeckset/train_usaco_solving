/*
ID: henriqu16
TASK: gift1
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int getValue(string str){
    
}

int main(){
    ofstream out ("gift1.out"); 
    ifstream in ("gift1.in");
    map<string, int> people;
    int numberOfPeople;
    in >> numberOfPeople;
    vector<string> peopleNames(numberOfPeople);
    for(int i = 0; i < numberOfPeople; i++){
        string currName;
        in >> currName;
        people[currName] = 0;
        peopleNames[i] = currName;
    }
    for(int i = 0; i < numberOfPeople; i++){
        string personName;
        int amount, numberOfReceivers;
        in >> personName >> amount >> numberOfReceivers;
        people[personName] -= amount - (numberOfReceivers > 0 ? (amount % numberOfReceivers) : 0);
        for(int j = 0; j < numberOfReceivers; j++){
            string receiverName;
            in >> receiverName;
            people[receiverName] += amount / numberOfReceivers;
        }
    }
    for(string name : peopleNames){
        out << name << " " << people[name] << endl;
    }
    return 0;
}
