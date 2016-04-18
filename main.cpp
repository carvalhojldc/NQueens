#include <iostream>
#include <vector>
#include "cromossomo.h"
#include "nrainhas.h"

using namespace std;

int main() {

	int tamTabuleiro = 8;
	int tamPopulacao = 70;
	double probMutacao = 0.01;
	double probCruzamento = 0.8;
	int menu;	

	system("clear");

	do {
		cout << "(1) Tamanho do tamuleiro = " << tamTabuleiro << endl;
		cout << "(2) Tamanho da população = " << tamPopulacao << endl;
		cout << "(3) Probabilidade de mutação = " << probMutacao << endl;
		cout << "(4) Probabilidade de cruzamento = " << probCruzamento << endl;
		cout << "(5) Seguir..." << endl;
		cout << "(0) Cancelar..." << endl;
		
		cout << "\nEntre com o numero correspondente: ";
		cin >> menu;

		switch(menu) {
			case(1):
				cout << "Entre com o novo tamanho para o tabulerio: ";
				cin >> tamTabuleiro;
				break;
			case(2):
				cout << "Entre com o novo tamanho para a população: ";
				cin >> tamPopulacao;
				break;
			case(3):
				cout << "Entre com a nova probabilidade de mutação: ";
				cin >> probMutacao;
				break;
			case(4):
				cout << "Entre com a nova probabilidade de cruzamento: ";
				cin >> probCruzamento;
			case(0):
				return 0;
		}
		system("clear");
	} while(menu!=5);

	int tamCromossomo = tamTabuleiro;

    NRainhas nrainhas(tamCromossomo, tamPopulacao, probCruzamento, probMutacao);

    Cromossomo melhorCromossomo = nrainhas.torneio();
    vector<int> genetica = melhorCromossomo.getGenetica();

    cout << "Geração = " << melhorCromossomo.getGeracao() << endl;
    cout << "Genética = ";
    for(int i=0; i<melhorCromossomo.getTamanho(); i++) {
    	cout << genetica[i] << 	' ';
    }
    cout << endl;
    cout << "Pontuação = " << melhorCromossomo.getPontuacao() << endl;

    return 0;
}
