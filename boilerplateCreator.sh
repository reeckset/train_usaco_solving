#!/bin/sh
 
#define parameters which are passed in.
PROB=$1
mkdir $PROB
cd $PROB
 
touch main.cpp
touch $PROB.in
 
#define the template.
cat > main.cpp << EOF
/*
ID: henriqu16
TASK: $PROB
LANG: C++                
*/

#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ofstream out ("$PROB.out");
    ifstream in ("$PROB.in");


    
    return 0;
}
EOF