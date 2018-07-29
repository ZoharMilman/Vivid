#include <iostream>
#include <vector>

int main(){

    float [18] quan = {0};
    float[18][3] meshPar = {0};
    int counter(0);
    for(int i = 2; i > -4; i-= 2){
        for(int j = 2; j > -4; j-= 2){
            for(int z = 2; z > -2; z-= 2){

                meshPar[counter][0] = i;
                meshPar[counter][1] = j;
                meshPar[counter][2] = z;
                counter ++;
            }   
        }   
    }

    for(int i = 0; i < 18; i++){
        
        quan[i] = 1;
    }

    quan[9] = 2;

    return 0;
}