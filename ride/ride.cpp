/*
ID: henriqu16
TASK: ride
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int getValue(string str){
    int total = 1;
    for(unsigned int i = 0; i < str.size(); i++){
        total *= str[i] - 'A' + 1;
    }
    return total;
}

int main(){
    ofstream out ("ride.out"); 
    ifstream in ("ride.in");
    string commet, group;
    in >> commet;
    in >> group;
    int commetVal = getValue(commet);
    int groupVal = getValue(group);
    if(groupVal % 47 == commetVal % 47){
        out << "GO\n";
    }else{
        out << "STAY\n";
    }
    return 0;
}
