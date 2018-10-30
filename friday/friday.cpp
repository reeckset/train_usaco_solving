/*
ID: henriqu16
TASK: friday
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ofstream out ("friday.out"); 
    ifstream in ("friday.in");
    int N;
    in >> N;
    vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    map<int, int> frequencyOfWeekdays;
    int weekday = 0;
    for(int year = 1900; year < 1900 + N; year++){
       for(unsigned int m = 0; m < daysInMonth.size(); m++){
           frequencyOfWeekdays[weekday]++;
           weekday = (weekday + 
              ((m == 1 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
              ? daysInMonth[m]+1 : daysInMonth[m])) % 7;
       }
    }
    for( int i = 0; i < 7; i++){
        out << frequencyOfWeekdays[i] << (i < 6 ? " " : "");
    }
    out << endl;
    return 0;
}
