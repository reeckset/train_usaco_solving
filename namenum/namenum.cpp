/*
ID: henriqu16
TASK: namenum
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> mapppp('Z');

int getLetterNumber(char letter){
    return mapppp[letter];
}

void searchWord(const vector<string> &dictionary, const string &wantedNumber, ofstream &out){
    bool foundSome = false;
    for(string word : dictionary){
        bool found = true;
        for(unsigned int i = 0; i < wantedNumber.size(); i++){
            int number = wantedNumber[i] - '0';
            if(getLetterNumber(word[i]) != number || word.size() != wantedNumber.size()){
                found = false;
                break;
            }
        }
        if(found){
            out << word << endl;
            foundSome = true;
        }
    }
    if(!foundSome)
    out << "NONE\n";
}

int main(){

    mapppp['A'] = 2;
    mapppp['B'] = 2;
    mapppp['C'] = 2;
    mapppp['D'] = 3;
    mapppp['E'] = 3;
    mapppp['F'] = 3;
    mapppp['G'] = 4;
    mapppp['H'] = 4;
    mapppp['I'] = 4;
    mapppp['J'] = 5;
    mapppp['K'] = 5;
    mapppp['L'] = 5;
    mapppp['M'] = 6;
    mapppp['N'] = 6;
    mapppp['O'] = 6;
    mapppp['P'] = 7;
    mapppp['R'] = 7;
    mapppp['S'] = 7;
    mapppp['T'] = 8;
    mapppp['U'] = 8;
    mapppp['V'] = 8;
    mapppp['W'] = 9;
    mapppp['X'] = 9;
    mapppp['Y'] = 9;


    ofstream out ("namenum.out"); 
    ifstream in ("namenum.in");
    ifstream dic ("dict.txt");
    
    vector<string> dictionary;

    cout << "Reading dictionary" << endl;

    string newWord;
    while (std::getline(dic, newWord)){
        dictionary.push_back(newWord);
    }

    cout << "Read dictionary successfully" << endl;

    string wantedNumber;
    in >> wantedNumber;

    cout << "Searching for word..." << endl;

    searchWord(dictionary, wantedNumber, out);

    return 0;
}
