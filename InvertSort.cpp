#include <iostream>
using namespace std;

void invertSort(int itens[],int tamanho){
	for (int i = 1; i < tamanho; i ++){
		int auxi = itens[i];
		int j = i - 1;
		while (auxi < itens[j] && j >= 0){
			itens[j+1] = itens[j];
			j -- ;
		}
		itens[j+1] = auxi;
	}
}



int main(){
	
	int tamanho = 7;
	int array [tamanho] = {3,9,5,8,0,4,2};
	
	for (int i = 0; i < tamanho; i ++) {
		cout << array[i];
	}
	
	cout << endl;
	
	invertSort(array, tamanho);
	
	for (int i = 0; i < tamanho; i ++) {
		cout << array[i];
	}
	
}
