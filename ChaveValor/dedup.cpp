//conjuntos implementados com hashing
#include <unordered_set>
#include <vector>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

std::vector<int> gerar_vetor_aleatorio(int n, int seed, int max){
    std::vector<int> v;
    v.reserve(n);
    srand(seed);
    for(int i = 0; i < n; i++){
        v.push_back(rand() % max);
    }
    return v;
}

vector<int> dedup(const vector<int>& v){
    //cria um dicionario (conjunto) vazio
    unordered_set<int> d;
    //inserir todo elemento de v em d
    for(int x : v){
        d.insert(x);
    }

    vector<int> saida;
    //passar por todos os elementos do conjunto
    //e copiá-los na saída
    for(int x : d){
        saida.push_back(x);
    }

    return saida;
}

int main(int argc, char** argv){
    int n = stoi(argv[1]);

    vector<int> v = gerar_vetor_aleatorio(n, 99, n / 100);

    // for(int i : v){
    //     cout << i << ", ";
    // }
    // cout << "\n";

    vector<int> s = dedup(v);

    // for(int i : s){
    //     cout << i << ", ";
    // }
    // cout << "\n";

    cout << s.size() << " elementos únicos."
         << "\n";

    return 0;
}