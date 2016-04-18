#include "nrainhas.h"

int NRainhas::obterPontuacao(vector<int> genetica) {
	
    int pontuacao = genetica.size();
    bool estado[genetica.size()] = {false};

    for(int i=0; i<genetica.size(); i++) {
        for(int j=i+1; j<genetica.size(); j++) {
            if( abs(i-j)==abs(genetica[i]-genetica[j]) || genetica[i]==genetica[j]) {
                estado[j] = true;
                estado[i] = true;
            }
        }
        if(estado[i]) {
            pontuacao--;
        }
    }
    return pontuacao;
}

NRainhas::NRainhas(int tamCromossomo, int tamPopulacao, double probCruzamento, double probMutacao) {
    srand(time(NULL));
    
    this->tamCromossomo = tamCromossomo;
    this->tamPopulacao = tamPopulacao;
	this->probCruzamento = probCruzamento;
    this->probMutacao = probMutacao;

    vector<int> genetica;
    Cromossomo* cromossomo;
    for(int i=0; i<tamPopulacao; i++) {
    	for(int j=0; j<tamCromossomo; j++) {
    		int posX = rand()%tamCromossomo;
        	genetica.push_back(posX);
    	}
    	cromossomo = new Cromossomo(tamCromossomo, genetica, obterPontuacao(genetica));    	
   		
   		populacao.push_back(*cromossomo);

    	genetica.clear();
    	delete cromossomo;
    }
}

int NRainhas::getPontuacao(Cromossomo cromossomo) {
    return cromossomo.getPontuacao();
}

int NRainhas::getMelhor() {
    int iMelhor = 0;
    int pontMelhor = getPontuacao(populacao[0]);

    for(int i=1; i<tamPopulacao; i++) {
        int pont = getPontuacao(populacao[i]);
        if(pontMelhor < pont) {
            pontMelhor = pont;
            iMelhor = i;
        }
    }
    return iMelhor;
}

Cromossomo NRainhas::cruzamento(vector<int> genetica1, vector<int> genetica2) {
    int ind = rand()%(tamCromossomo-1);
    vector<int> novaGenetica;

    for(int i=0; i<tamCromossomo; i++) {
        if(i<=ind) {
            novaGenetica.push_back(genetica1[i]);
        }
        else {
            novaGenetica.push_back(genetica2[i]);
        }
    }
    Cromossomo novo(tamCromossomo,novaGenetica, obterPontuacao(novaGenetica));

    return novo;
}

void NRainhas::mutacao(Cromossomo& cromossomo) {
    vector<int> genetica = cromossomo.getGenetica();

    int pos = rand()%tamCromossomo;
    int pos2;
    int swap;

    do {
        pos2 = rand()%tamCromossomo;
    } while(pos == pos2);

    swap = genetica[pos];
    genetica[pos] = genetica[pos2];
    genetica[pos2] = swap;

    cromossomo.setGenetica(genetica);
    cromossomo.setPontuacao(obterPontuacao(genetica));
}

Cromossomo NRainhas::torneio() {
    int pontMelhor = 0;
    vector<int> melhor;
    int geracao = 0;
    for(int i=0; pontMelhor!=tamCromossomo; i++) {
        for(int j=0; j<tamPopulacao;) {
            double prob = ((double) rand() / ((double)RAND_MAX +1));
            Cromossomo cromossomo;
            int idCromo1 = rand() % tamPopulacao;
            int idCromo2;
            do {
                idCromo2 = rand() % tamPopulacao;
            } while(idCromo1==idCromo2);

            if(prob<=probCruzamento) {
                j++;
                cromossomo = cruzamento(populacao[idCromo1].getGenetica(), populacao[idCromo2].getGenetica());

                prob = ((double) rand() / ((double)RAND_MAX +1));

                if(prob<probMutacao) {
                    mutacao(cromossomo);
                }

                if(populacao[idCromo1].getPontuacao()<cromossomo.getPontuacao()) {
                    populacao[idCromo1] = cromossomo;
                }
            }
        }

        geracao = i+1;
        
        int iMelhor = getMelhor();
        melhor = populacao[iMelhor].getGenetica();
        pontMelhor = populacao[iMelhor].getPontuacao();

        cout << "> " << geracao << '_' << pontMelhor << endl; 
    }
    
    system("clear");
    
    Cromossomo mc(tamCromossomo, melhor, pontMelhor, geracao);

    return mc;
}