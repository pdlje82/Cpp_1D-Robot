#include <iostream>
#include <vector>
#include <string>
#include "1D-Robot.h"
using namespace std;

int main() {
    vector<float> p(5, 0.2);
    vector<string> world = {"green", "red", "red", "green", "green"};
    vector<string> measurements = {"red", "green"};
    vector<int> motions = {1, 1};
    float pHit = 0.6;
    float pMiss = 0.2;
    float pExact = 0.8;
    float pOvershoot = 0.1;
    float pUndershoot = 0.1;

    for (int k = 0; k < measurements.size(); k++ ){
        p = sense(p, measurements[k], world, pHit, pMiss);
        p = move(p, motions[k], pExact, pOvershoot, pUndershoot);
    }
    print_p(p);
    return 0;
}

