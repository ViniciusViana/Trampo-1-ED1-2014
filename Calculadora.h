#ifndef CALCULADORA_H
#define CALCULADORA_H

typedef struct no{
	int digito;//recebe o digito a ser inserido
	struct no *prox;
}NO;

typedef struct lista{
	int tam;//recebe o tamanho do numero que a lista conterá
	struct no *head;
}Lista;

void criaLista(Lista *l);

void printLista(Lista l);

void insereLista(Lista *l, int e);

void insereFim(Lista *l, int e);

Lista soma(Lista *lista_1, Lista *lista_2);

void procuraEmprestador(NO *aux);

void subtrai(Lista *lista_1, Lista *lista_2);

void multiplica(Lista *lista_1, Lista *lista_2);

void liberaLista(Lista *l);

#endif
