#ifndef NRAINHAS_H
#define NRAINHAS_H

#include <iostream>

#include <vector>
#include <ctime>
#include <cstdlib>

#include "cromossomo.h"

using namespace std;

class NRainhas {
private:
    vector< Cromossomo > populacao;
    int tamCromossomo;
    int tamPopulacao;
    double probCruzamento;
    double probMutacao;

    int obterPontuacao(vector<int> genetica);

public:
    NRainhas(int tamCromossomo, int tamPopulacao, double probCruzamento, double probMutacao);
    int getPontuacao(Cromossomo cromossomo);
    int getMelhor();
    Cromossomo cruzamento(vector<int> genetica1, vector<int> genetica2);
    void mutacao(Cromossomo& cromossomo);
    Cromossomo torneio();
};

#endif // NRAINHAS_H
