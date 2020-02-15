#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;

class ArestaGrafo{
    int primeiroVertice, segundoVertice, valorPeso;

public:
    ArestaGrafo(int primeiroV, int segundoV, int valorPeso){
        primeiroVertice = primeiroV;
        segundoVertice = segundoV;
        this->valorPeso = valorPeso;
    }

    int obterPrimeiroVertice(){
        return primeiroVertice;
    }

    int obterSegundoVertice(){
        return segundoVertice;
    }

    int obterValorPeso(){
        return valorPeso;
    }

    bool operator < (const ArestaGrafo& arestaGrafo2) const{
        return (valorPeso < arestaGrafo2.valorPeso);
    }
};

class Grafo{
    int x;

public:
    vector<ArestaGrafo> arestasGrafo;
    Grafo(int x){
        this->x = x;
    }

    void addArestaGrafo(int primeiroV, int segundoV, int valorPeso){
        ArestaGrafo arestaGrafo(primeiroV, segundoV, valorPeso);
        arestasGrafo.push_back(arestaGrafo);
    }

    int busca(int setI[], int a){
        if(setI[a] == -1)
            return a;
        return busca(setI, setI[a]);
    }

    void unir(int setI[], int primeiroV, int segundoV){
        int primeiroV_set = busca(setI, primeiroV);
        int segundoV_set = busca(setI, segundoV);
        setI[primeiroV_set] = segundoV_set;
    }

    void algoritmoDeKruskal(){
        vector<ArestaGrafo> arvore;
        int size_arestasGrafo = arestasGrafo.size();

        sort(arestasGrafo.begin(), arestasGrafo.end());

        int * setI = new int[arestasGrafo.size()];

        memset(setI, -1, sizeof(int) * arestasGrafo.size());

        for(int i = 0; i < size_arestasGrafo; i++){
            int primeiroV = busca(setI, arestasGrafo[i].obterPrimeiroVertice());
            int segundoV = busca(setI, arestasGrafo[i].obterSegundoVertice());

            if(primeiroV != segundoV){
                arvore.push_back(arestasGrafo[i]);
                unir(setI, primeiroV, segundoV);
            }
        }

        int size_arvore = arvore.size();
        int resultado = 0;

        for(int i = 0; i < size_arvore; i++){
            int primeiroV = arvore[i].obterPrimeiroVertice();
            int segundoV = arvore[i].obterSegundoVertice();
            cout << "(" << primeiroV << ", " << segundoV << ") = " << arvore[i].obterValorPeso() << endl;
	    resultado += arvore[i].obterValorPeso();
        }
        cout << resultado << "\n\n\n";
    }
};

int main(int argc, char *argv[]){
    int w, k;
    int init, final, valorPeso;
    scanf("%d %d", &w, &k);
    Grafo z(w);

    for( int i = 0; i < k; i++){
        scanf("%d %d %d", &init, &final, &valorPeso);
        z.addArestaGrafo(init, final, valorPeso);
   }

    z.algoritmoDeKruskal();

    return 0;
}