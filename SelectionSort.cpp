#include <iostream>
using namespace std;

void selectionSort(int itens[], int tam){
	for (int i = 0; i < tam; i ++){
		int min = i;
		for (int  j = i + 1; j < tam; j ++) {
			if (itens[j] < itens[min]){
				min = j;
			}
		}
		int aux = itens[min];
		itens[min] = itens[i];
		itens[i] = aux;
	}
}

void insertionSort(int itens[], int tamanho){
	int j;
	int aux;
	for (int i = 1; i < tamanho; i ++){
		aux = itens[i];
		j = i - 1;
		while (aux < itens[j] && j >= 0){
			itens[j+1] = itens[j];
			j --;
		}
		itens[j+1] = aux;
	}
}


void bubbleSort(int itens[], int tamanho){
	for (int i = tamanho -1; i < 0; i --){
		for (int j = 0; j < i -1; j ++){
			if (itens[j] > itens [j+1]){
				int aux =itens[j];
				itens[j] = itens[j+1];
				itens[j+1] = aux;
			}
		}
	}
}


void shellSort(int itens[], int tamanho){
	int aux, j;
	int h = 1;
	while (h < tamanho){
		h = 3 * h + 1;
	}
	while ( h > 1){
		h = h / 3;
		for (int i = h; i < tamanho; i ++){
			aux = itens[i];
			j = i;
			while (itens[j-h] > aux){
				itens[j] = itens[j-h];
				j -= h;
				if ( j < h) break;
			}
			itens[j] = aux;
		}
	}
}

// MERGER SORT

void mergeSort_comb(int itens[],int inicio, int meio, int fim){
	int i,j;
	int tam1 = (meio-inicio) +1;
	int tam2 = fim - meio;
	int aux1[tam1],aux2[tam2];

	for (i = 0; i < tam1; i ++){
		aux1[i] = itens[inicio + i];
	}
	for (j = 0; j < tam2; j ++){
		aux2[j] = itens[meio + 1 + j];
	}

	i = j = 0;

	for (int k = inicio; k < fim; k ++){
		if( i == tam1){
			itens[k] = aux2[j];
			j++;
		}else if(j == tam2){
			itens[k] = aux1[i];
			i++;
		}else if(aux1[i] < aux2[j]){
			itens[k] = aux1[i];
			i++;
		}else{
			itens[k] = aux2[j];
			j++;
		}
	}
}

void mergeSort_div(int itens[],int inicio,int fim){
	if (inicio < fim){
		int meio = (inicio + fim) /2;
		mergeSort_div(itens,inicio,meio);
		mergeSort_div(itens,meio+1,fim);
		mergeSort_comb(itens,inicio,meio,fim);
	}
}

void mergeSort(int itens[],int tamanho){
	mergeSort_div(itens,0, tamanho-1);
}

//



int busca_normal (int itens[], int tamanho, int chave){
	if (tamanho != 0){
		for (int i = 0; i < tamanho; i ++ ){
			if (itens[i] == chave){
				return itens[i];
			}
		}
	}
	return -1;
}



int busca_binaria(int itens[],int tamanho, int chave){
	int pos = -1;
	if (tamanho == 0){
		return -1;
	} else {
		int inicio = 0;
		int fim = tamanho -1;
		while (chave != itens[pos] && inicio < fim){
			pos = (inicio + fim)/2;
			if (chave < itens[pos]){
				fim = pos - 1;
			} else
				inicio = pos + 1;
		}
		if (chave == itens[pos]){
			return itens[pos];
		} else
			return -1;
	}
}



int main(){
	int tamanho = 12;
	int array [12] = {4,7,6,2,0,8,15,21,9,11,20,1};

	cout << "VETOR DESORDENADO" << endl;
	for (int i = 0; i < tamanho; i ++) {
		cout << array[i] << " ";
	}
	cout << endl;
	cout << "SELECTION SORT" << endl;
	selectionSort(array, tamanho);
	for (int i = 0; i < tamanho; i ++) {
		cout << array[i] << " ";
	}
	cout << endl;

	cout << "INSERTION SORT" << endl;
	insertionSort(array, tamanho);
	for (int i = 0; i < tamanho; i ++) {
		cout << array[i] << " ";
	}
	cout << endl;

	cout << "BUBBLE SORT" << endl;
	bubbleSort(array, tamanho);
	for (int i = 0; i < tamanho; i ++) {
		cout << array[i] << " ";
	}
	cout << endl;



	cout << "SHELL SORT" << endl;
	shellSort(array, tamanho);
	for (int i = 0; i < tamanho; i ++) {
		cout << array[i] << " ";
	}
	cout << endl;


	cout << "MERGE SORT" << endl;
	mergeSort(array, tamanho);
	for (int i = 0; i < tamanho; i ++) {
		cout << array[i] << " ";
	}
	cout << endl;



	cout << "BUSCA BINARIA" << endl;
	cout << busca_binaria(array,tamanho,20) << endl;
	cout << "BUSCA NORMAL" << endl;
	cout << busca_normal(array,tamanho,15)<< endl;

}
