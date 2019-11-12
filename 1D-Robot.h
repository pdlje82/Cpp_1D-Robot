//
// Created by Jan Engelke on 04/11/2019.
//

#ifndef INC_01_1D_ROBOT_1D_ROBOT_H
#define INC_01_1D_ROBOT_1D_ROBOT_H

std::vector<float> sense(std::vector<float> p,
                         std::string z,
                         std::vector<std::string> world,
                    float pHit,
                    float pMiss );
std::vector<float> move(std::vector<float> p,
                   int u,
                   float pExact,
                   float pOvershoot,
                   float pUndershoot );
void print_p(std::vector<float> p);

#endif //INC_01_1D_ROBOT_1D_ROBOT_H

