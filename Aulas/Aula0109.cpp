// Resolução de problemas com ordenação
/*Problema1 - Dado um vetor V com n elementos verifique se há elementos repetidos.
template<typename T>
bool haRepitidos(vector<T> V, int n){}*/


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <cstdio>

using namespace std;

// void embaralhar(int *array, size_t n, int seed){
//     srand(seed);
//     if (n > 1) {
//         size_t i;
//         for (i = 0; i < n - 1; i++) {
//           size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
//           int t = array[j];
//           array[j] = array[i];
//           array[i] = t;
//         }
//     }
// }

// std::vector<int> gerar_vetor_aleatorio_sem_reps(int n, int seed){
//     int* saida = new int[n];
    
//     for(int i = 0; i < n; i++)
//         saida[i] = i;
    
//     embaralhar(saida, n, seed);
    
//     std::vector<int> v;
//     v.reserve(n);

//     for(int i = 0; i < n; i++)
//         v.push_back(saida[i]);
    
//     delete[] saida;

//     return v;
// }

// // passado em referencia para não copiar o vetor inteiro
// // colocar um ponteiro em um elemento do vetor e comparar ele com resto dos elementos
// // é considerado brute force, o requerimento computacional comforme o tamanho do vetor
// // aumenta é quadratico: em um vetor V = {1, 8, 0, 9, 4, 2}, o int i começa no primeiro elemento
// // e o j começa em i+1, o i percorre n-1
// template<typename T>
// bool haRepetidos(vector<T> &v){
//     for(int i = 0; i < v.size()-1; i++){
//         for(int j = i + 1; j < v.size(); j++){
//             if(v[i] == v[j]){
//                 return true;
//             }
//         }
//     }
//     return false;
// }
// // o v.size()-1 garante que i percorra n-1, e o if verifica que são iguais
// // é equação [(n²+n)/2]-n
// /*
// Definição: H ordenação de um vetor V onde V=[v0, v1, v2, v3, ..., vV-1],
// é um vetor V'=[v0', v1', v2', ..., vV'-1] tal que V' possui os mesmo elementos
// de V, mas v0' <= v1' <= v2' <= v3' <= ... <= vV'-1
// Ex:{V=[7, 4, 6, 1, 0, 2]
//     V'=[0, 1, 2, 4, 6, 7]}
// Exz:{V=[0, 4, 2, 1, 6, 2, 1]
//      V'=[0, 1, 1, 2, 2, 4, 6]}
// */


// template<typename T>
// bool haRepetidosO(vector<T> &v){
//     sort(v.begin(), v.end());
//     for(int i = 0; i < v.size() - 1; i++){
//         if(v[i] == v[i+1]){
//             return true;
//         }
//     }
//     return false;
// }



// int main(){
//     vector<int> v = { 1, 8, 0, 9, 4, 2 };
//     vector<int> u = { 6, 0, 9, 2, 8, 1, 1 };
//     vector<string> s = { "banana", "melão", "mamão", "melão"};

//     vector<int> grandao
//         = gerar_vetor_aleatorio_sem_reps(50000, 99);

//     // cout << haRepetidos(v) << "\n";
//     // cout << haRepetidos(u) << "\n";
//     // cout << haRepetidos(s) << "\n";

//     // cout << haRepetidosO(v) << "\n";
//     // cout << haRepetidosO(u) << "\n";
//     // cout << haRepetidosO(s) << "\n";

//     cout << haRepetidosO(grandao) << "\n";

// }

/*
Problema 2 - Dado um vetor V com n posições,
retorne o v-ésimo maior elemento deste vetor.
Por exemplo, se n=1, retorne o maior.
Se n=2 retorne o segundo maior.
Suponha que todos os elementos de v sejam distintos.
*/
template<typename T>
T kesimoMaior(vector<T> &v, int k){
    sort(v.begin(), v.end());
    return v[v.size()-k];
}

// Se v não puder ser alterado
template<typename T>
T kesimoMaiorO(const vector<T> &v, int k){
    vector<T> u= v;
    sort(u.begin(), u.end());
    return u[u.size()-k];
}

