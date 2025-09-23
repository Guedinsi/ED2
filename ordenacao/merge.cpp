#include <iostream>
#include <vector>
#include <string>
#include "utils.h"

void merge(int *v, int p, int q, int r){
    //0 - Calcular n1 e n2
    int n1 = q - p + 1;
    int n2 = r - q;
    //1 - criar e com os elementos de v[p..1]
    int *e = new int[n1];
    for(int i = 0; i < n1; i++)
        e[i] = v[p+i];
    //2 - criar d com os elementos de v[q+1...r]
    int *d = new int[n2];
    for(int j = 0; j < n2; j++)
        d[j] = v[q+1+j];
    
    int k = p; 
    int i = 0, j = 0;

    while( (i < n1) && (j < n2) ){
        if(e[i] <= d[j]){
            v[k] = e[i];
            i++;
        }
        else{ //d[j] < e[i]
            v[k] = d[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        v[k] = e[i];
        i++, k++;
    }
    while(j < n2){
        v[k] = d[j];
        j++, k++;
    }
    delete[] e;
    delete[] d;
}

void mergeSort(int *v, int e, int d){
    if(e < d){
        int m = (e + d)/2;
        mergeSort(v, e, m);
        mergeSort(v, m+1, d);
        merge(v, e, m, d);
    }
}

int main(int argc, char** argv){
    // int v[] = {1, 7, 9, 0, 5, 8};
    // int p = 0, q = 2, r = 5;

    // merge(v, p, q, r);
    // for(int i = 0; i < 6; i++){
    //     std::cout << v[i] << ", ";
    // }
    // std::cout << "\n";

    using namespace std;

    int n = stoi(argv[1]);
    
    vector<int> v = gerar_vetor_aleatorio(n, 99, n * 100);
    imprimir_vetor(v.data(), n);
    mergeSort(v.data(), 0, n-1);
    imprimir_vetor(v.data(), n);
}