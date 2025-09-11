#include "utils.h"
#include <vector>
#include <cstdlib>


int pos_maior(int *v, int ini, int fim){
    int m = ini;
    for(int i = ini+1; i <= fim; i++){
        if(v[i] > v[m]){
            m = i;
        }
    }
    return m;
}

void SelectionSort(int* v, int n){
    for(int i = n-1; i > 0; i--){ 
        int m = pos_maior(v, 0, i);
        trocar(v, m, i);
    }
}

/*  
    argc e argv leem a linha de comando
    argv é um vetor que aponta pros elementos da linha de comando
    argv[0] é o nome do comando, argv[1] é o numero de elementos do vetor
    ./selection 100
    time ./selection 1000 > /dev/null
*/

int main(int argc, char** argv){
    //int n = 5;
    int n = 5;
    if (argc > 1){
        n = atoi(argv[1]);
    }

    std::vector<int> v;
    v = gerar_vetor_aleatorio(n, 99, n*100);

    imprimir_vetor(v.data(), v.size());

    SelectionSort(v.data(), v.size());

    imprimir_vetor(v.data(), v.size());
}