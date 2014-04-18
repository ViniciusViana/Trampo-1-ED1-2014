/* encher linguiça dps nesse cabeçlho*/

#include<stdio.h>
#include "calculadora.h"

//inicialia a LISTA
void inicLista(LISTA *lista_num){
	lista_num->head = NULL;
}

//verifica se a LISTA está vazia
int listaVazia(LISTA *lista_num){
	if(lista_num->head == NULL)
		return 1;//1 = a lista está vazia
	return 0;//0 = a lista não está vazia
}

/* Insere um elemento no inicio da LISTA */
void insereInicio(LISTA *lista_num, elem e){
	No *novo; //novo digito a ser inserido na lista
	novo = malloc(sizeof(NO));
	novo->digito = e;//novo nó recebe o digito 'e'
	novo->prox = lista_num->head;//insere elemento na lista
	lista_num->head = novo;
}

/* Insere um elemento no final da LISTA */
void insereFim(LISTA *lista_num, elem e){
	
	if(listaVazia){
		insereInicio(lista_num, e);
	}else{
		No *novo, *aux; //novo digito a ser inserido na lista
		novo = malloc(sizeof(NO));
		novo->digito = e;//novo nó recebe o digito 'e'
		aux = lista_num->head;
		//percorre a lista em busca do final
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		novo->prox = NULL;//insere elemento na lista
		aux->prox = novo;
	}
}

/* Remove o elemento que esta no final da LISTA.
   Retorna 0 caso a LISTA esteja vazia
int removeFim(LISTA *lista_num, elem *p_e)*/

void libera(LISTA *lista_num){
	No *libera_no, *percorre_lista;
	percorre_lista = lista_num->head;
	
	while(percorre_lista != NULL){
		libera_no = percorre_lista;
		percorre_lista = percorre_lista->prox;
		free(libera_no);
	}
}


/* Exibe o conteudo da LISTA */
void exibe(LISTA *lista_num);

#endif
