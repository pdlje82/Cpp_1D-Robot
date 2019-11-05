//
// Created by Jan Engelke on 04/11/2019.
//
using namespace std;

#ifndef INC_01_1D_ROBOT_1D_ROBOT_H
#define INC_01_1D_ROBOT_1D_ROBOT_H
#endif //INC_01_1D_ROBOT_1D_ROBOT_H

vector<float> sense(vector<float> p,
                    string z,
                    vector<string> world,
                    float pHit,
                    float pMiss );
vector<float> move(vector<float> p,
                    int u,
                    float pExact,
                    float pOvershoot,
                    float pUndershoot );
void print_p(vector<float> p);
