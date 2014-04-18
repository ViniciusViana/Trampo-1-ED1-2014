/* encher linguiça dps nesse cabeçlho*/

#ifndef CALCULADORA_H
#define CALCULADORA_H
#include<stdio.h>
typedef int elem;


//A struct que vai conter os digitos que representam o número inserido
typedef struct no{
	
	elem digito;
	struct no *prox;
}No;

typedef struct LISTA{
	
	int tam;
	struct no *head;
}LISTA;


//inicialia a LISTA
void inicLista(LISTA *p_l);

//verifica se a LISTA está vazia
int listaVazia(LISTA *p_l);

/* Insere um elemento no inicio da LISTA */
void insereInicio(LISTA *p_l, elem e);

/* Insere um elemento no final da LISTA */
void insereFim(LISTA *p_l, elem e);

/* Remove o elemento que esta no final da LISTA.
   Retorna 0 caso a LISTA esteja vazia */
int removeFim(LISTA *p_l, elem *p_e);

void libera(LISTA *p_l);

/* Exibe o conteudo da LISTA */
void exibe(LISTA *p_l);

#endif
