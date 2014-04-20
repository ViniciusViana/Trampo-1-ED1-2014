#include "calculadora.h"
#include <stdio.h>
#include <stdlib.h>

void criaLista(Lista *l){
	l->head = NULL;
	l->tam = 0;
}

void insereLista(Lista *l, int e){
	NO *novo;
	novo = malloc(sizeof(NO));
	novo->digito = e;
	novo->prox = l->head;
	l->head = novo;
}

void printLista(Lista l){
	NO *aux;
	aux = l.head;
	//percorre a lista imprimindo todos os seus elementos
	while(aux != NULL){
		printf("%d", aux->digito);
		aux = aux->prox;
	}
}

void soma(Lista *lista_1, Lista *lista_2)
{

	int soma;//variável que recebe a soma de dois dígitos apenas
	NO *aux_1, *aux_2;//ponteiros que auxiliam na varredura das listas 1 e 2 respectivamente
	Lista adicao;//lista que recebe a soma dos numeros contidos nas duas listas
	int vai_um = 0;//contabiliza se a soma de dois digitos foi maior que 10
				   //(e portanto é necessário passar 1 para a proxima soma de digitos)

	criaLista(&adicao);
	aux_1 = lista_1->head;
	aux_2 = lista_2->head;

	//realiza a soma de dois digitos até um dos números "acabar"
	while(aux_1 != NULL && aux_2 != NULL){
		//se a soma for maior que nove, é necessário passar 1 para o próximo digito
		if((soma = (aux_1->digito + aux_2->digito + vai_um)) > 9){
			insereLista(&adicao, (soma - 10));
			vai_um = 1;
		}else{
			insereLista(&adicao, soma);
			vai_um = 0;
		}
		soma = 0;
		aux_1 = aux_1->prox;
		aux_2 = aux_2->prox;
	}
	//se os dois numeros acabaram verifica se a ultima soma foi maior que dez ou não para adicionar 1 (ou não) na frente do número
	if(aux_1 == NULL && aux_2 == NULL){
		if(vai_um == 1){
			insereLista(&adicao, 1);
		}
	}else{
		//se o numero que a lista 1 contém acabou, percorre-se a lista 2 até acabar, para adicionar esse digitos tambem
		if(aux_1 == NULL){
			while(aux_2 != NULL){
				//se os dois numeros acabaram verifica se a ultima soma foi maior
				//que dez ou não para adicionar 1 (ou não) na proxima soma
				if(vai_um == 1){
					insereLista(&adicao, (aux_2->digito + 1));
					vai_um = 0;
				}else{
					insereLista(&adicao, aux_2->digito);
				}
				aux_2 = aux_2->prox;
			}
		}else{
			//se o numero que a lista 2 contém acabou, percorre-se a lista 1 até acabar, para adicionar esse digitos tambem
			while(aux_1 != NULL){
				//se os dois numeros acabaram verifica se a ultima soma foi maior
				//que dez ou não para adicionar 1 (ou não) na proxima soma
				if(vai_um == 1){
					insereLista(&adicao, (aux_1->digito + 1));
					vai_um = 0;
				}else{
					insereLista(&adicao, aux_1->digito);
				}
				aux_1 = aux_1->prox;
			}
		}
	}
	printLista(adicao); //imprimi a soma
	liberaLista(&adicao);
}

//essa função auxilia a subtração de dois números.
//quando tenta-se subtrair um digito que é menor que outro,
//é necessário "tomar emprestado" 1 do proximo digito.
//No entanto, pode ser que o proximo numero seja 0 e, portanto,
//será necessário percorrer os digitos, até achar um que não seja 0,
//"tomar emprestado" dele para realizar a subtração entre os digitos iniciais
void procuraEmprestador(NO *aux){
	NO *achaEmprestador;

	achaEmprestador = aux;
	achaEmprestador->digito = achaEmprestador->digito + 10;//o número receberá '1' emprestado, que entra na frente dele
														  //, ou seja, será adicionado 10 ao número que necessita de empréstimo

	while(achaEmprestador->prox->digito == 0 && achaEmprestador->prox != NULL){
		achaEmprestador->prox->digito = 9;//cada zero (que não pode emprestar nada ao número anterior)
										 // vai receber emprestado 1 ("virar" 10) e depois emprestará 1 ("virando" 9)
		achaEmprestador = achaEmprestador->prox;
	}
	//se o proximo número pode emprestar 1, subtrai-se dele o 1 emprestado
	if(achaEmprestador->prox->digito != 0){
		achaEmprestador->prox->digito = achaEmprestador->prox->digito - 1;
	}
}

void subtrai(Lista *lista_1, Lista *lista_2){

	int sub;//variável que recebe a diferença de dois dígitos apenas
	int sinal;//verifica se será necessário o uso do sinal negativo (caso o primeiro numero seja menor que o segundo)
	NO *aux_1, *aux_2;//ponteiros que auxiliam na varredura das listas 1 e 2 respectivamente
	Lista subtract;//lista que recebe a diferença dos numeros contidos nas duas listas

	criaLista(&subtract);

	//tratamento para colocar o maior numero no topo da subtração
	if(lista_1->tam > lista_2->tam){
		aux_1 = lista_1->head;
		aux_2 = lista_2->head;
		sinal = 0;
	}else{
		if(lista_1->tam < lista_2->tam){
			aux_1 = lista_2->head;
			aux_2 = lista_1->head;
			sinal = 1;
		//se os numeros tem mesmo tamanho, verifica-se qual dos digitos iniciais é maior
		}else{
			aux_1 = lista_1->head;
			aux_2 = lista_2->head;
			//percorre-se as listas até achar chegar ao final (primeiro dígito do número)
			while(aux_1->prox != NULL && aux_2->prox != NULL){
				aux_1 = aux_1->prox;
				aux_2 = aux_2->prox;
			}
			//se o digito do numero contido na lista 1 for maior que o da lista 2, nº da lista 1 é maior que o da lista 2
			if(aux_1->digito > aux_2->digito){
				aux_1 = lista_1->head;
				aux_2 = lista_2->head;
				sinal = 0;
			//caso contrário, nº da lista 2 é maior que o da lista 1
			}else{
				aux_1 = lista_2->head;
				aux_2 = lista_1->head;
				sinal = 1;
			}
		}
	}

		//faz a subtração dos dois numeros
		while(aux_1 != NULL && aux_2 != NULL){
			//se a diferença dos dois digitos for negativa, é necessário "emprestar 1" do digito a seguir
			if( (sub = (aux_1->digito - aux_2->digito)) < 0 ){
				procuraEmprestador(aux_1);
				sub = aux_1->digito - aux_2->digito;
				insereLista(&subtract, sub);
			}else{
				insereLista(&subtract, sub);
			}
			sub = 0;
			aux_1 = aux_1->prox;
			aux_2 = aux_2->prox;
		}
		//caso a subtração acabe e ainda haja digitos no número maior, adiciona-se estes números na lista que contém a subtração
		while(aux_1 != NULL){
			insereLista(&subtract, aux_1->digito);
			aux_1 = aux_1->prox;
		}

	    //resolve o problema do sinal, caso o primeiro numero digitado seja menor que o segundo (portanto a soma dá um nº negativo)
		if(sinal == 0){
			printLista(subtract);
		}else{
			printf("-");
			printLista(subtract);
		}

		liberaLista(&subtract);
}

void liberaLista(Lista *l){
	NO *aux, *remove;
	aux = l->head;
	while(aux != NULL){
		remove = aux;
		aux = aux->prox;
		free(remove);
	}
	l->head = NULL;
}
