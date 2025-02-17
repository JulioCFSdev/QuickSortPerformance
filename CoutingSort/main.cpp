#include <iostream>
#include <bits/stdc++.h>
#include <time.h>
#include <vector>

using namespace std;

void vetorcrescente(long int array[], int n) {
    
    for(long int i = 1; i < n; i++){
        array[i] = i;
    }
    
}

void vetordecrescente(long int array[], int n) {
    
    for(int i = 1; i < n; i++){
        array[i] = n - i;
    }
    
}

void vetorcrescentedecrescente(long int array[], int n) {
    
	for(long int value = 0; value < n; value++)
	{
		if(value <= (n/2))
		{
			array[value] = value;
		}
		else
		{
			array[value] = n - value - 1;
		}
	}  
}

void vetordecrescentecrescente(long int array[], int n) {
    
	for(long int value = 0; value < n; value++)
	{
		if(value <= (n/2))
		{
			array[value] = n - value;
		}
		else
		{
			array[value] = value;
		}
	}
    
}

void vetoraleatorio(long int array[], int n) {
    
    srand(1);
	vector<long int> v(100000);
	
	generate(v.begin(), v.end(), rand);
	for(int i = 0; i < n; i++){
		array[i] = v[i]%10;
	}
}


void countSort(long int arr[], int n) {
  
  	// Inicializa os arrays auxiliares e o maior elemento do array
    long int arr1[n];
    long int count_arr[n];
    int x = arr[0];

	// Determina qual � o maior valor do array
    for (int i = 1; i < n; i++) {
        if (arr[i] > x)
        x = arr[i];
    }

	// Preenche o vetor de contagem dos elementos com 0
    for (int i = 0; i <= x; ++i) {
        count_arr[i] = 0;
    }

	// Quantifica o n�mero de ocorr�ncias que o elemento ter� no array
    for (int i = 0; i < n; i++) {
        count_arr[arr[i]]++;
    }
	
	// Increntando o n�mero de occorrencia de n�meros menores ou iguais a ele
	// Determina qual ser� a maior posi��o que o elemento pode estar
    for (int i = 1; i <= x; i++) {
        count_arr[i] += count_arr[i - 1];
    }

	// Determina a posi��o ordednada no vetor auxiliar e ordena o vetor de ocorrencias
    for (int i = n - 1; i >= 0; i--) {
        arr1[count_arr[arr[i]] - 1] = arr[i];
        count_arr[arr[i]]--;
    }
	
	// Transforma o array de entrada em uma array ordenado
    for (int i = 0; i < n; i++) {
        arr[i] = arr1[i];
    }
}

void display(long int arr[], int n) {
    for (long int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int main() {
    
	clock_t start_time;
	
    long int arr[100000];
    long int n = 100000;
    
    
    vetorcrescente(arr, n);
    start_time = clock();
    countSort(arr, n);
    start_time = clock() - start_time;
    cout << "Tempo de executacao: " << (start_time/CLOCKS_PER_SEC) << endl;
    cout << "Ordenamento de vetor em ordem Crescente completo" << endl;
    
    vetordecrescente(arr, n);
    //display(arr, n);
    start_time = clock();
    countSort(arr, n);
    start_time = clock() - start_time;
    cout << "Tempo de executacao: " << (start_time/CLOCKS_PER_SEC) << endl;
    cout << "Ordenamento de vetor em ordem Decrescente completo" << endl;

    vetorcrescentedecrescente(arr, n);
    //display(arr, n);
    start_time = clock();
    countSort(arr, n);
    start_time = clock() - start_time;
    cout << "Tempo de executacao: " << (start_time/CLOCKS_PER_SEC) << endl;
    cout << "Ordenamento de vetor em ordem Crecente Decrescente completo" << endl;

    vetordecrescentecrescente(arr, n);
    //display(arr, n);
    start_time = clock();
    countSort(arr, n);
    start_time = clock() - start_time;
    cout << "Tempo de executacao: " << (start_time/CLOCKS_PER_SEC) << endl;
    cout << "Ordenamento de vetor em ordem Crecente Decrescente completo" << endl;


    vetoraleatorio(arr, n);    
    //display(arr, n);
    start_time = clock();
    countSort(arr, n);
    start_time = clock() - start_time;
    cout << "Tempo de executacao: " << (start_time/CLOCKS_PER_SEC) << endl;
    cout << "Ordenamento de vetor em ordem Aleatorio completo" << endl;

    
    return 0;
}
