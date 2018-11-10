/*
ID: henriqu16
TASK: milk2
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int getActiveTime(map<int,int> times){
    int longerTimeActive = 0;
    int currentStart = times.begin()->first;
    bool isGoingToStart = false;
    for(pair<int, int> time : times){
        if(isGoingToStart){
            currentStart = time.first;
            isGoingToStart = false;
        }

        if(time.second == 0){
            longerTimeActive = max(time.first - currentStart, longerTimeActive);
            isGoingToStart = true;
        }
    }
    return longerTimeActive;
}

int getInactiveTime(map<int,int> times){
    int longerTimeInactive = 0;
    int currentStart = times.begin()->first;
    bool lastWasZero = false;
    for(pair<int, int> time : times){
        if(time.second == 0 && !lastWasZero){
            currentStart = time.first;
            lastWasZero = true;
        }
        if(time.second > 0 && lastWasZero){
            longerTimeInactive = max(time.first - currentStart, longerTimeInactive);
            lastWasZero = false;
        }
    }
    return longerTimeInactive;
}

int main(){
    ofstream out ("milk2.out"); 
    ifstream in ("milk2.in");
    
    map<int, int> times;

    int numberOfFarmers;
    in >> numberOfFarmers;

    int earliestStartTime = INT32_MAX;
    int latestEndTime = INT32_MIN;
    
    for(int i = 0; i < numberOfFarmers; i++){
        int currentFarmerStart, currentFarmerFinish;
        in >> currentFarmerStart >> currentFarmerFinish;

        if ( times.find(currentFarmerStart) == times.end() ){
            times[currentFarmerStart] = 1;
        }else{
            times[currentFarmerStart]++;
        }
        if(currentFarmerStart < earliestStartTime) earliestStartTime = currentFarmerStart;
        if(currentFarmerFinish > latestEndTime) latestEndTime = currentFarmerFinish;

        if ( times.find(currentFarmerFinish) == times.end() ){
            times[currentFarmerFinish] = -1;
        }else{
            times[currentFarmerFinish]--;
        }
    }

    int totalFarmersSoFar = 0;
    map<int, int> newTimes;
    for(pair<int, int> time : times){
        totalFarmersSoFar += time.second;
        newTimes[time.first] = totalFarmersSoFar;
    }

    int longerTimeActive = getActiveTime(newTimes);

    out << longerTimeActive << " " << getInactiveTime(newTimes) << endl;

    return 0;
}
