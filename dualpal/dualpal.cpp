/*
ID: henriqu16
TASK: dualpal
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

bool isPalindromeInBase(int num, int base){
    string square = convertToBaseB(num, base);
    string reversedSquare = square;
    reverse(reversedSquare.begin(), reversedSquare.end());
    return square == reversedSquare;
}

int main(){
    ofstream out ("dualpal.out"); 
    ifstream in ("dualpal.in");
    
    int n,s;

    in >> n >> s;

    int numbersFound = 0;
    for(int i = s+1; numbersFound < n; i++){
        int palindromesFound = 0;
        for(int b = 2; b <= 10; b++){
            if(isPalindromeInBase(i, b)){
                palindromesFound++;
            }
            if(palindromesFound == 2){
                out << i << endl;
                numbersFound++;
                break;
            }
        }
    }

    return 0;
}
