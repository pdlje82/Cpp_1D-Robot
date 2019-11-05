//
// Created by Jan Engelke on 04/11/2019.
//
#include <vector>
#include <string>
using namespace std;

vector<float> sense(vector<float> p, string z, vector<string> world, float pHit, float pMiss ){
    vector<float> q(p.size(), 0);
    for (int i = 0; i < p.size(); i++){
        bool hit = false;
        if (z == world[i]){
            hit = true;
        }
        q[i] = p[i] * (hit * pHit + (1 - hit) * pMiss);
    }
    float sum = 0;
    for (float f : q){  // for (int i = 0; i < q.size(); i++){
        sum = sum + f;  //     sum = sum + q[i];}
    }
    for (float & i : q){  // for (int i = 0; i < q.size(); i++){
        i = i / sum;      //     q[i] = q[i] / sum;}
    }
    return q;
}

vector<float> move(vector<float> p, int u, float pExact, float pOvershoot, float pUndershoot ){
    vector<float> q(p.size(), 0);
    for (int i = 0; i < p.size(); i++){
        float s = pExact * p[(i - u) % p.size()];
        s = s + pOvershoot * p[(i - u - 1) % p.size()];
        s = s + pUndershoot * p[(i - u + 1) % p.size()];
        q[i] = s;
    }
    return q;
}
