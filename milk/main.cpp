/*
ID: henriqu16
TASK: milk
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ofstream out ("milk.out"); 
    ifstream in ("milk.in");

    map<int, int> priceAmountMap;
    
    int neededMilk, amountOfFarmers;
    in >> neededMilk;
    in >> amountOfFarmers;

    for(int i = 0; i < amountOfFarmers; i++){
        int price, amount;
        in >> price >> amount;
        if(priceAmountMap.find(price) == priceAmountMap.end()){
            priceAmountMap[price] = amount;
        }else{
            priceAmountMap[price] += amount;
        }
    }

    int total = 0;
    int totalPrice = 0;
    for(auto priceAmount : priceAmountMap){
        if(priceAmount.second + total >= neededMilk){
            totalPrice += (neededMilk - total) * priceAmount.first;
            break;
        }else{
            total += priceAmount.second;
            totalPrice += priceAmount.first * priceAmount.second;
        }
    }

    out << totalPrice << endl;
    return 0;
}
