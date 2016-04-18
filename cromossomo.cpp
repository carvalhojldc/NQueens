#include "cromossomo.h"

Cromossomo::Cromossomo() {
	this->pontuacao = 0;
	this->tamCromossomo = 0;
	this->geracao = 0;
}

Cromossomo::Cromossomo(int tamCromossomo, vector<int> genetica, int pontuacao) {
	this->tamCromossomo = tamCromossomo;
    this->cromossomo = genetica;
    this->pontuacao = pontuacao;
    this->geracao = 0;
}

Cromossomo::Cromossomo(int tamCromossomo, vector<int> genetica, int pontuacao, int geracao) {
	this->tamCromossomo = tamCromossomo;
    this->cromossomo = genetica;
    this->pontuacao = pontuacao;
    this->geracao = geracao;
}

int Cromossomo::getPontuacao(void) {
	return pontuacao;
}

void Cromossomo::setPontuacao(int pontuacao) {
    this->pontuacao = pontuacao;
}

vector<int> Cromossomo::getGenetica(void) {
    return cromossomo;
}

void Cromossomo::setGenetica(vector<int> genetica) {
    this->cromossomo = genetica;
}

int Cromossomo::getTamanho(void) {
	return tamCromossomo;
}

int Cromossomo::getGeracao(void) {
	return geracao;
}

void Cromossomo::setGeracao(int geracao) {
	this->geracao = geracao;
}
