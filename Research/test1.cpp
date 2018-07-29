#include <vector>
#include <iostream>
#include <cmath>

#define BOX_SIZE 20 
#define HEIGHT 10

int main(){

    vector<int[3]> meshPar;
    vector<bool> mask;
    vector<float> quan;
    int a(0);

    for(int i = -BOX_SIZE; i < BOX_SIZE; i += 2){
        for(int j = -BOX_SIZE; j < BOX_SIZE; j += 2){
            for(int z = -BOX_SIZE; z < BOX_SIZE; z += 2){
                mashPar.push_back([i, j, k]);
                if(k >= 0 && HEIGHT >= k){
                    a = HEIGHT - k;
                }

                else{
                    a = 0;
                }

                if((k >= 0 && HEIGHT >= k) && (-a <= i && i <= a) && (-a <= j && j <= a)){
                    mask.push_back(true);
                    quan.push_back(pow(10, a) + 0.0001);
                }

                else{
                    mask.push_back(false);
                    quan.push_back(0.00001);
                }
            }   
        }        
    }
}