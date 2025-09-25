#include <iostream>
#include <vector>
#include <string>
#include "utils.h"

int partition(int *v, int p, int r){
    int x = v[r];
    int i = p - 1;
    for(int j = p; j < r; j++){
        if(v[j] <= x){
            i++;
            trocar(v, i, j);
        }
    }
    trocar(v, i+1, r);
    return i + 1;
}

void quicksort(int *v, int p, int r){
    if(p < r){
        int q = partition(v, p, r);
        quicksort(v, p, q-1);
        quicksort(v, q+1, r);
    }
}


int main(int argc, char** argv){

    using namespace std;

    int n = stoi(argv[1]);
    
    vector<int> v = gerar_vetor_aleatorio(n, 99, n * 100);
    imprimir_vetor(v.data(), n);
    quicksort(v.data(), 0, n-1);
    imprimir_vetor(v.data(), n);
}