#ifndef CROMOSSOMO_H
#define CROMOSSOMO_H

#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Cromossomo {
private:
    vector<int> cromossomo;
    int tamCromossomo;
    int pontuacao;
    int geracao;

public:
    Cromossomo();
    Cromossomo(int tamCromossomo, vector<int> genetica, int pontuacao);
    Cromossomo(int tamCromossomo, vector<int> genetica, int pontuacao, int geracao);
    int getPontuacao(void);
    void setPontuacao(int pontuacao);
    vector<int> getGenetica(void);
    void setGenetica(vector<int> genetica);
    int getTamanho(void);
    int getGeracao(void);
    void setGeracao(int geracao);
};

#endif // CROMOSSOMO_H
