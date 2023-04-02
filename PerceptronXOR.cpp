#include <iostream>
#include <vector>
using namespace std;

int sigmoide(float v){
    if(v >= 0){
        return 1;
    } else{
        return 0;
    }
}

int perceptron(vector<float> x, vector<float> w, float b){
    float v = 0;
    for(int i=0; i<x.size(); i++){
        v += w[i] * x[i];
    }
    v += b;
    int y = sigmoide(v);
    return y;
}

int NOT(vector<float> x){
    vector<float> w = {-1};
    float bNOT = 0.5;
    return perceptron(x, w, bNOT);
}

int AND(vector<float> x){
    vector<float> w = {1, 1};
    float bAND = -1.5;
    return perceptron(x, w, bAND);
}

int OR(vector<float> x){
    vector<float> w = {1, 1};
    float bOR = -0.5;
    return perceptron(x, w, bOR);
}

int XOR(vector<float> x){
    int y1 = AND(x);
    int y2 = OR(x);
    vector<float> final_x = {float(y2), float(NOT({float(y1)}))};
    int finalOutput = AND(final_x);
    return finalOutput;
}

int main(){
    vector<float> test1 = {0, 1};
    vector<float> test2 = {1, 1};
    vector<float> test3 = {0, 0};
    vector<float> test4 = {1, 0};

    cout << "XOR(" << 0 << ", " << 1 << ") = " << XOR(test1) << endl;
    cout << "XOR(" << 1 << ", " << 1 << ") = " << XOR(test2) << endl;
    cout << "XOR(" << 0 << ", " << 0 << ") = " << XOR(test3) << endl;
    cout << "XOR(" << 1 << ", " << 0 << ") = " << XOR(test4) << endl;

    return 0;
}