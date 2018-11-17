/*
ID: henriqu16
TASK: transform
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;


bool checkTransformation(vector<string> originalMatrix, vector<string> transformedMatrix, 
                    bool invertCoordinates, bool invertOutsideLoop, bool invertInsideLoop){


    int x, y;
    for(int i = 0; i < (int)originalMatrix.size(); i++){
        if(invertOutsideLoop){
            x = originalMatrix.size() - i - 1;
        }else{
            x = i;
        }
        for(int j = 0; j < (int)originalMatrix.size(); j++){
            if(invertInsideLoop){
                y = originalMatrix.size() - j - 1;
            }else{
                y = j;
            }

            char transformedCharacter;
            if(invertCoordinates){
                transformedCharacter = transformedMatrix[x][y];
            }else{
                transformedCharacter = transformedMatrix[y][x];
            }
            
            if(transformedCharacter != originalMatrix[j][i]){
                return false;
            }
        }
    }
    return true;
}

vector<string> readMatrix(ifstream &in, int size){
    vector<string> matrix;
    for(int i = 0; i < size; i++){
        string newLine;
        in >> newLine;
        matrix.push_back(newLine);
    }
    return matrix;
}


int main(){
    ofstream out ("transform.out"); 
    ifstream in ("transform.in");
    
    int matrixSize;
    vector<string> originalMatrix, transformedMatrix;
    in >> matrixSize;

    originalMatrix = readMatrix(in, matrixSize);
    transformedMatrix = readMatrix(in, matrixSize);

    if(checkTransformation(originalMatrix, transformedMatrix, true, false, true)){ 
        out << 1 << endl;
    }else if(checkTransformation(originalMatrix, transformedMatrix, false, true, true)){
        out << 2 << endl;
    }else if(checkTransformation(originalMatrix, transformedMatrix, true, true, false)){
        out << 3 << endl;
    }else if(checkTransformation(originalMatrix, transformedMatrix, true, false, false)
    || checkTransformation(originalMatrix, transformedMatrix, false, false, true)
    || checkTransformation(originalMatrix, transformedMatrix, true, true, true)){
        out << 5 << endl;
    }else  if(checkTransformation(originalMatrix, transformedMatrix, false, true, false)){
        out << 4 << endl;
    }else if(checkTransformation(originalMatrix, transformedMatrix, false, false, false)){
        out << 6 << endl;
    }else{
        out << 7 << endl;
    }

    return 0;
}
