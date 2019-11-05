//
// Created by Jan Engelke on 04/11/2019.
//
#include <iostream>
#include <vector>
#include <string>
#include "1D-Robot.h"
using namespace std;

vector<float> sense(vector<float> p,
                    string z,
                    vector<string> world,
                    float pHit,
                    float pMiss ){

    vector<float> q(p.size(), 0);
    float s = 0;
    for (int i = 0; i < p.size(); i++){

        float hit = 0;
        if (z == world[i]){
            hit = 1;
        }

        q[i] = p[i] * (hit * pHit + (1 - hit) * pMiss);
        s += q[i];
    }

    //cout << sum << endl;
    for (float & i : q){  // for (int i = 0; i < q.size(); i++){
        i = i / s;      //     q[i] = q[i] / s;}
    }

    //print_p(p);
    return q;
}

vector<float> move(vector<float> p,
                    int u,
                    float pExact,
                    float pOvershoot,
                    float pUndershoot ){

    vector<float> q(p.size(), 0);
    float s = 0;
    for (int i = 0; i < p.size(); i++){
        // The modulo operator behaves a bit different in C++ with negatives
        // If we took it as -1 % p.size(), we'd get zero instead of four
        // -1 + p.size() will give us what we would get from -1 % p.size in Python
        if (i - u < 0) {
            s = pExact * p[(i - u) + p.size()];
        }
        else {
            s = pExact * p[(i - u) % p.size()];
        }
        if (i - u - 1 < 0) {
            s = s + pOvershoot * p[(i - u - 1) + p.size()];
        }
        else{
            s = s + pOvershoot * p[(i - u - 1) % p.size()];
        }
        if (i - u + 1 < 0) {
            s = s + pUndershoot * p[(i - u + 1) + p.size()];
        }
        else{
            s = s + pUndershoot * p[(i - u + 1) % p.size()];
        }
        q[i] = s;
    }


    print_p(p);
    return q;
}

void print_p(vector<float> p){

    for (float i : p){      // for (int i = 0; i < p.size(); i++ ){
        cout << i << "  ";  //     cout << p[i] << endl;}
    }
    cout << endl;
}
