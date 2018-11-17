/*
ID: henriqu16
TASK: palsquare
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

string smthn = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string convertToBaseB(int number, int base){
    string result = "";
    do{
        result += smthn[number % base];
        number /= base;
    }while(number != 0);

    reverse(result.begin(), result.end());

    return result;
}

int main(){
    ofstream out ("palsquare.out"); 
    ifstream in ("palsquare.in");
    
    int base;

    in >> base;

    int currNumber = 1;
    while(currNumber < 300){
        string square = convertToBaseB(currNumber * currNumber, base);
        string reversedSquare = square;
        reverse(reversedSquare.begin(), reversedSquare.end());
        if(square == reversedSquare){
            out << convertToBaseB(currNumber, base) << " " << square << endl;
        }

        currNumber++;
    }

    return 0;
}
