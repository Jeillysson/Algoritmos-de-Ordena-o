#include <iostream>
using namespace std;

void bubbleSort(int itens[],int tamanho){
	for (int i = tamanho -1; i > 0; i --){
		for (int j = 0; j < tamanho -1; j ++ ){
			if (itens[j] > itens[j + 1]){
				int aux = itens[j];
				itens[j] = itens[j+1];
				itens[j+1] = aux;
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
	
	bubbleSort(array, tamanho);
	
	for (int i = 0; i < tamanho; i ++) {
		cout << array[i];
	}
	
}
