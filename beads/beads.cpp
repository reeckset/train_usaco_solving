/*
ID: henriqu16
TASK: beads
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ofstream out ("beads.out"); 
    ifstream in ("beads.in");
    int numberOfBeads;
    in >> numberOfBeads;
    string sequenceOfBeads;
    in >> sequenceOfBeads;

    int maxTotal = 0;

    for(int i = 0; i < numberOfBeads; i++){
            char firstColor = 'w';
            char secondColor = 'w';
            for(int j = i; j < numberOfBeads*2; j++){
                if(j - i >= numberOfBeads){
                    maxTotal = numberOfBeads;
                    break;
                }
                if(secondColor != 'w'){
                    if(sequenceOfBeads[j%numberOfBeads] != secondColor && sequenceOfBeads[j%numberOfBeads] != 'w'){
                        maxTotal = max(maxTotal, j-i);
                        break;
                    }
                }else if(firstColor == 'w'){
                   firstColor = sequenceOfBeads[j%numberOfBeads];
                }else{
                    if(sequenceOfBeads[j%numberOfBeads] != firstColor && sequenceOfBeads[j%numberOfBeads] != 'w'){
                        secondColor = sequenceOfBeads[j%numberOfBeads];
                    }
                }
            }
            
    }

    out << min(maxTotal, numberOfBeads) << endl;

    return 0;
}
