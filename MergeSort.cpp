#include <iostream>
using namespace std;

void mergeSort (int itens[], int tamanho){
	int inicio = 0;
	int fim = tamanho-1;
	void mergeSort_div(int itens[], int inicio, int fim){
	 	int meio = (inicio + fim)/2;
		if (inicio < fim){
			mergeSort_div(itens, inicio, meio);
			mergeSort_div(itens,meio + 1, fim);
		}
	 	void mergeSort_comb(int itens[], int inicio, int meio, int fim){
			int tamanho = meio - inicio + 1;
			int tamanho2 = fim - meio;
			for (int i = 0; i < tamanho; i ++){
				int auxi[i] = itens[inicio + i];
			}
			for (int j = 0; j < tamanho2; j ++ ){
				int auxi2[j] = itens[meio+1+j];
			}
			int cont = 0;
			int cont2 = 0;
			for (int k = inicio; k < fim; k ++){
				if (cont == tamanho){
					itens[k] = auxi2[j];
					cont2 ++;
				} else if (cont2 == tamanho2){
					itens[k] = auxi1[i];
					cont ++;
				} else if (auxi[cont] < auxi2[cont2]){
					itens[k] = auxi[cont];
					cont ++;
				} else
					itens[k] = aux2[cont2];
					cont2 ++;
			}
		}
	 }
}

int main(){

	int tamanho = 7;
	int array [tamanho] = {3,9,5,8,0,4,2};

	for (int i = 0; i < tamanho; i ++) {
		cout << array[i];
	}

	cout << endl;

	mergeSort(array, tamanho);

	for (int i = 0; i < tamanho; i ++) {
		cout << array[i];
	}

	return 0;
}
