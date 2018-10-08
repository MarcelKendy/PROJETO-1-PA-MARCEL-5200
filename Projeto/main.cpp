#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <iomanip>
#include <stdlib.h>

using namespace std;

//SORTS
//SELECTION_SORT
void selection_sort(int *array, int n){
    int aux, minor, position; bool change;
    for(int i = 0; i < n - 1; i++){
        minor = array[i];
        position = i;
        change = false;
        for(int j = i+1; j < 10; j++){
            if(array[j] < minor){
                minor = array[j];
                position = j;
                change = true;
            }

        }
        if(change){
           aux = array[i];
           array[i] = minor;
           array[position] = aux;
        }
    }
}
//////////////////////////////////////////////////////////////
//INSERTION_SORT
void insertion_sort(int *array, int n){
    int i, j; int aux;
    for(i = 1; i < n; i++){
        aux = array[i];
        for(j = i; (j > 0) && (aux < array[j - 1]); j--){
            array[j] = array[j - 1];
        }
        array[j] = aux;
    }
}
//////////////////////////////////////////////////////////////
//SHELL_SORT
void shell_sort(int *array, int n)
{
    for(int gap = n/2; gap > 0; gap /= 2){
        for(int i = gap; i < n; i += 1){
            int aux = array[i]; int j;
            for(j = i; j >= gap && array[j - gap] > aux; j -= gap){
                array[j] = array[j - gap];
            }
            array[j] = aux;
        }
    }
}
//////////////////////////////////////////////////////////////
//MERGE_SORT
//PART 1
void merge(int *array, int low, int high, int mid){
	int i, j, k, temp[high-low+1];
	i = low; k = 0; j = mid + 1;
	while(i <= mid && j <= high){
		if(array[i] < array[j]){
			temp[k] = array[i]; k++; i++;
		}else{
			temp[k] = array[j]; k++; j++;
		}
	}
	while(i <= mid){
		temp[k] = array[i]; k++; i++;
	}
	while(j <= high){
		temp[k] = array[j]; k++; j++;
	}
	for(i = low; i <= high; i++){
		array[i] = temp[i-low];
	}
}
//PART 2
void merge_sort(int *array, int low, int high){
	int mid;
	if(low < high){
        mid = (low + high) / 2;
		merge_sort(array, low, mid);
		merge_sort(array, mid + 1, high);
		merge(array, low, high, mid);
	}
}

void heapify(int *array, int n, int i)
{
    int largest = i;  // O maior e a raiz
    int l = 2*i + 1;  // l de left = 2*i + 1
    int r = 2*i + 2;  // r de right = 2*i + 2

    // Se o filho da esquerda e maior que a raiz
    if (l < n && array[l] > array[largest])
        largest = l;

    // Se o da direita e o maior ate agora
    if (r < n && array[r] > array[largest])
        largest = r;

    // Se o maior nao e a raiz
    if (largest != i)
    {
        swap(array[i], array[largest]);

        // Recursivo
        heapify(array, n, largest);
    }
}

void heap_sort(int *array, int n)
{
    // build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    // Extrai os elementos
    for (int i=n-1; i>=0; i--)
    {
        // Coloca a raiz no final
        swap(array[0], array[i]);

        // reduz a heap
        heapify(array, i, 0);
    }
}
// So pra trocar dois elementos
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* Eu usei o ultimo elemento como pivo, coloco ele na posicao correta no sorted array, e o que for menor vai pra esquerda e maior direita*/
int partition (int array, int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quick_sort(int *array, int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
    }
}






int main()
{
    // ARRAYS
    int *array10;
    int *array1000;
    int *array10000;
    int *array100000;
    int *array1000000;
    int *array10Rand;
    int *array1000Rand;
    int *array10000Rand;
    int *array100000Rand;
    int *array1000000Rand;
    int *array10Asc;
    int *array1000Asc;
    int *array10000Asc;
    int *array100000Asc;
    int *array1000000Asc;
    int *array10Desc;
    int *array1000Desc;
    int *array10000Desc;
    int *array100000Desc;
    int *array1000000Desc;

    array10 =  new int [10];
    array1000 =  new int [1000];
    array10000 =  new int [10000];
    array100000 =  new int [100000];
    array1000000 =  new int [1000000];

    array10Rand =  new int [10];
    array1000Rand =  new int [1000];
    array10000Rand =  new int [10000];
    array100000Rand =  new int [100000];
    array1000000Rand =  new int [1000000];

    array10Asc =  new int [10];
    array1000Asc =  new int [1000];
    array10000Asc =  new int [10000];
    array100000Asc =  new int [100000];
    array1000000Asc =  new int [1000000];

    array10Desc =  new int [10];
    array1000Desc =  new int [1000];
    array10000Desc =  new int [10000];
    array100000Desc =  new int [100000];
    array1000000Desc =  new int [1000000];


    //FILLING RAND ARRAYS
    for(int i = 0; i < 10; i++){
        array10Rand[i] = rand() % 100;
    }
    for(int i = 0; i < 1000; i++){
        array1000Rand[i] = rand() % 100;
    }
    for(int i = 0; i < 10000; i++){
        array10000Rand[i] = rand() % 100;
    }
    for(int i = 0; i < 100000; i++){
        array100000Rand[i] = rand() % 100;
    }
    for(int i = 0; i < 1000000; i++){
        array1000000Rand[i] = rand() % 100;
    }

//    //FILLING ASCENDING ARRAYS
    for(int i = 0; i < 10; i++){
        array10Asc[i] = i;
    }
    for(int i = 0; i < 1000; i++){
        array1000Asc[i] = i;
    }
    for(int i = 0; i < 10000; i++){
        array10000Asc[i] = i;
    }
    for(int i = 0; i < 100000; i++){
        array100000Asc[i] = i;
    }
    for(int i = 0; i < 1000000; i++){
        array1000000Asc[i] = i;
    }

//    //FILLING DESCENDING ARRAYS
    double aux = 10;
    for(int i = 0; i < 10; i++){
        array10Desc[i] = aux - i;
    }
    aux = 1000;
    for(int i = 0; i < 1000; i++){
        array1000Desc[i] = aux - i;
    }
    aux = 10000;
    for(int i = 0; i < 10000; i++){
        array10000Desc[i] = aux - i;
    }
    aux = 100000;
    for(int i = 0; i < 100000; i++){
        array100000Desc[i] = aux - i;
    }
    aux = 1000000;
    for(int i = 0; i < 1000000; i++){
        array1000000Desc[i] = aux - i;
    }
    //TESTS
//    std::cout.precision(4);
    clock_t a1, a2, a3, a4, a5;
    FILE *file;
    file = fopen ("RESULTS_PA.txt","w");
    int x;
    while(1){
        cout << "Digite 1 para registrar o SELECION, 2 PARA O INSERTION, 3 PARA O SHELL, 4 PARA O MERGE 5 PARA HEAP 6 PARA QUICK E 0 PARA FINALIZAR" << endl;
        cin >> x;
        if(x == 0) break;
        switch(x){
            case 1:
                fprintf (file,"RESULTADOS DO SELECTION SORT\n\n");
                fprintf (file,"ARRAYS RANDOMS\n");
                // GARANTINDO QUE SEMPRE SERAO OS MESMOS ARRAYS

                for(int i = 0; i < 10; i++){
                     array10[i] = array10Rand[i];
                }
                for(int i = 0; i < 1000; i++){
                   array1000[i] = array1000Rand[i];
                }
                for(int i = 0; i < 10000; i++){
                   array10000[i] = array10000Rand[i];
                }
                for(int i = 0; i < 100000; i++){
                   array100000[i] = array100000Rand[i];
                }
                for(int i = 0; i < 1000000; i++){
                   array1000000[i] = array1000000Rand[i];
                }

                a1 = clock();
                selection_sort(array10,10);
                a1 = clock() - a1;
                a2 = clock();
                selection_sort(array1000,1000);
                a2 = clock() - a2;
                a3 = clock();
                selection_sort(array10000,10000);
                a3 = clock() - a3;
                a4 = clock();
                selection_sort(array100000,100000);
                a4 = clock() - a4;
                a5 = clock();
                selection_sort(array1000000,1000000);
                a5 = clock() - a5;

                fprintf (file,"ARRAY RAND 10:\n");
                fprintf (file,"%f\n",((float)a1)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY RAND 1000:\n");
                fprintf (file,"%f\n",((float)a2)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY RAND 10000:\n");
                fprintf (file,"%f\n",((float)a3)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY RAND 100000:\n");
                fprintf (file,"%f\n",((float)a4)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY RAND 1000000:\n");
                fprintf (file,"%f\n\n\n",((float)a5)/CLOCKS_PER_SEC);


                fprintf (file,"ARRAYS CRESCENTES\n");
                // GARANTINDO QUE SEMPRE SERAO OS MESMOS ARRAYS

                for(int i = 0; i < 10; i++){
                     array10[i] = array10Asc[i];
                }
                for(int i = 0; i < 1000; i++){
                   array1000[i] = array1000Asc[i];
                }
                for(int i = 0; i < 10000; i++){
                   array10000[i] = array10000Asc[i];
                }
                for(int i = 0; i < 100000; i++){
                   array100000[i] = array100000Asc[i];
                }
                for(int i = 0; i < 1000000; i++){
                   array1000000[i] = array1000000Asc[i];
                }

                a1 = clock();
                selection_sort(array10,10);
                a1 = clock() - a1;
                a2 = clock();
                selection_sort(array1000,1000);
                a2 = clock() - a2;
                a3 = clock();
                selection_sort(array10000,10000);
                a3 = clock() - a3;
                a4 = clock();
                selection_sort(array100000,100000);
                a4 = clock() - a4;
                a5 = clock();
                selection_sort(array1000000,1000000);
                a5 = clock() - a5;

                fprintf (file,"ARRAY CRESCENTE 10:\n");
                fprintf (file,"%f\n",((float)a1)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY CRESCENTE 1000:\n");
                fprintf (file,"%f\n",((float)a2)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY CRESCENTE 10000:\n");
                fprintf (file,"%f\n",((float)a3)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY CRESCENTE 100000:\n");
                fprintf (file,"%f\n",((float)a4)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY CRESCENTE 1000000:\n");
                fprintf (file,"%f\n\n\n",((float)a5)/CLOCKS_PER_SEC);


                fprintf (file,"ARRAYS DECRESCENTES\n");
                // GARANTINDO QUE SEMPRE SERAO OS MESMOS ARRAYS

                for(int i = 0; i < 10; i++){
                     array10[i] = array10Desc[i];
                }
                for(int i = 0; i < 1000; i++){
                   array1000[i] = array1000Desc[i];
                }
                for(int i = 0; i < 10000; i++){
                   array10000[i] = array10000Desc[i];
                }
                for(int i = 0; i < 100000; i++){
                   array100000[i] = array100000Desc[i];
                }
                for(int i = 0; i < 1000000; i++){
                   array1000000[i] = array1000000Desc[i];
                }

                a1 = clock();
                selection_sort(array10,10);
                a1 = clock() - a1;
                a2 = clock();
                selection_sort(array1000,1000);
                a2 = clock() - a2;
                a3 = clock();
                selection_sort(array10000,10000);
                a3 = clock() - a3;
                a4 = clock();
                selection_sort(array100000,100000);
                a4 = clock() - a4;
                a5 = clock();
                selection_sort(array1000000,1000000);
                a5 = clock() - a5;

                fprintf (file,"ARRAY DECRESCENTE 10:\n");
                fprintf (file,"%f\n",((float)a1)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY DECRESCENTE 1000:\n");
                fprintf (file,"%f\n",((float)a2)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY DECRESCENTE 10000:\n");
                fprintf (file,"%f\n",((float)a3)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY DECRESCENTE 100000:\n");
                fprintf (file,"%f\n",((float)a4)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY DECRESCENTE 1000000:\n");
                fprintf (file,"%f\n\n\n",((float)a5)/CLOCKS_PER_SEC);

                fprintf (file,"SELECTION SORT TERMINADO!\n\n");

                break;

            case 2:
                fprintf (file,"RESULTADOS DO INSERTION SORT\n\n");
                fprintf (file,"ARRAYS RANDOMS\n");
                // GARANTINDO QUE SEMPRE SERAO OS MESMOS ARRAYS

                for(int i = 0; i < 10; i++){
                     array10[i] = array10Rand[i];
                }
                for(int i = 0; i < 1000; i++){
                   array1000[i] = array1000Rand[i];
                }
                for(int i = 0; i < 10000; i++){
                   array10000[i] = array10000Rand[i];
                }
                for(int i = 0; i < 100000; i++){
                   array100000[i] = array100000Rand[i];
                }
                for(int i = 0; i < 1000000; i++){
                   array1000000[i] = array1000000Rand[i];
                }

                a1 = clock();
                insertion_sort(array10,10);
                a1 = clock() - a1;
                a2 = clock();
                insertion_sort(array1000,1000);
                a2 = clock() - a2;
                a3 = clock();
                insertion_sort(array10000,10000);
                a3 = clock() - a3;
                a4 = clock();
                insertion_sort(array100000,100000);
                a4 = clock() - a4;
                a5 = clock();
                insertion_sort(array1000000,1000000);
                a5 = clock() - a5;

                fprintf (file,"ARRAY RAND 10:\n");
                fprintf (file,"%f\n",((float)a1)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY RAND 1000:\n");
                fprintf (file,"%f\n",((float)a2)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY RAND 10000:\n");
                fprintf (file,"%f\n",((float)a3)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY RAND 100000:\n");
                fprintf (file,"%f\n",((float)a4)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY RAND 1000000:\n");
                fprintf (file,"%f\n\n\n",((float)a5)/CLOCKS_PER_SEC);

                fprintf (file,"ARRAYS CRESCENTES\n");

                // GARANTINDO QUE SEMPRE SERAO OS MESMOS ARRAYS

                for(int i = 0; i < 10; i++){
                     array10[i] = array10Asc[i];
                }
                for(int i = 0; i < 1000; i++){
                   array1000[i] = array1000Asc[i];
                }
                for(int i = 0; i < 10000; i++){
                   array10000[i] = array10000Asc[i];
                }
                for(int i = 0; i < 100000; i++){
                   array100000[i] = array100000Asc[i];
                }
                for(int i = 0; i < 1000000; i++){
                   array1000000[i] = array1000000Asc[i];
                }

                a1 = clock();
                insertion_sort(array10,10);
                a1 = clock() - a1;
                a2 = clock();
                insertion_sort(array1000,1000);
                a2 = clock() - a2;
                a3 = clock();
                insertion_sort(array10000,10000);
                a3 = clock() - a3;
                a4 = clock();
                insertion_sort(array100000,100000);
                a4 = clock() - a4;
                a5 = clock();
                insertion_sort(array1000000,1000000);
                a5 = clock() - a5;

                fprintf (file,"ARRAY CRESCENTES 10:\n");
                fprintf (file,"%f\n",((float)a1)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY CRESCENTES 1000:\n");
                fprintf (file,"%f\n",((float)a2)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY CRESCENTES 10000:\n");
                fprintf (file,"%f\n",((float)a3)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY CRESCENTES 100000:\n");
                fprintf (file,"%f\n",((float)a4)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY CRESCENTES 1000000:\n");
                fprintf (file,"%f\n\n\n",((float)a5)/CLOCKS_PER_SEC);

                fprintf (file,"ARRAYS DECRESCENTES\n");
                // GARANTINDO QUE SEMPRE SERAO OS MESMOS ARRAYS

                for(int i = 0; i < 10; i++){
                     array10[i] = array10Desc[i];
                }
                for(int i = 0; i < 1000; i++){
                   array1000[i] = array1000Desc[i];
                }
                for(int i = 0; i < 10000; i++){
                   array10000[i] = array10000Desc[i];
                }
                for(int i = 0; i < 100000; i++){
                   array100000[i] = array100000Desc[i];
                }
                for(int i = 0; i < 1000000; i++){
                   array1000000[i] = array1000000Desc[i];
                }

                a1 = clock();
                insertion_sort(array10,10);
                a1 = clock() - a1;
                a2 = clock();
                insertion_sort(array1000,1000);
                a2 = clock() - a2;
                a3 = clock();
                insertion_sort(array10000,10000);
                a3 = clock() - a3;
                a4 = clock();
                insertion_sort(array100000,100000);
                a4 = clock() - a4;
                a5 = clock();
                insertion_sort(array1000000,1000000);
                a5 = clock() - a5;

                fprintf (file,"ARRAY DECRESCENTE 10:\n");
                fprintf (file,"%f\n",((float)a1)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY DECRESCENTE 1000:\n");
                fprintf (file,"%f\n",((float)a2)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY DECRESCENTE 10000:\n");
                fprintf (file,"%f\n",((float)a3)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY DECRESCENTE 100000:\n");
                fprintf (file,"%f\n",((float)a4)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY DECRESCENTE 1000000:\n");
                fprintf (file,"%f\n\n\n",((float)a5)/CLOCKS_PER_SEC);

                fprintf (file,"INSERTION SORT TERMINADO!\n\n");
                break;

            case 3:
                fprintf (file,"RESULTADOS DO SHELL SORT\n\n");
                fprintf (file,"ARRAYS RANDOMS\n");
                // GARANTINDO QUE SEMPRE SERAO OS MESMOS ARRAYS

                for(int i = 0; i < 10; i++){
                     array10[i] = array10Rand[i];
                }
                for(int i = 0; i < 1000; i++){
                   array1000[i] = array1000Rand[i];
                }
                for(int i = 0; i < 10000; i++){
                   array10000[i] = array10000Rand[i];
                }
                for(int i = 0; i < 100000; i++){
                   array100000[i] = array100000Rand[i];
                }
                for(int i = 0; i < 1000000; i++){
                   array1000000[i] = array1000000Rand[i];
                }

                a1 = clock();
                shell_sort(array10,10);
                a1 = clock() - a1;
                a2 = clock();
                shell_sort(array1000,1000);
                a2 = clock() - a2;
                a3 = clock();
                shell_sort(array10000,10000);
                a3 = clock() - a3;
                a4 = clock();
                shell_sort(array100000,100000);
                a4 = clock() - a4;
                a5 = clock();
                shell_sort(array1000000,1000000);
                a5 = clock() - a5;

                fprintf (file,"ARRAY RAND 10:\n");
                fprintf (file,"%f\n",((float)a1)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY RAND 1000:\n");
                fprintf (file,"%f\n",((float)a2)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY RAND 10000:\n");
                fprintf (file,"%f\n",((float)a3)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY RAND 100000:\n");
                fprintf (file,"%f\n",((float)a4)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY RAND 1000000:\n");
                fprintf (file,"%f\n\n\n",((float)a5)/CLOCKS_PER_SEC);

                fprintf (file,"ARRAYS CRESCENTES\n");
                // GARANTINDO QUE SEMPRE SERAO OS MESMOS ARRAYS

                for(int i = 0; i < 10; i++){
                     array10[i] = array10Asc[i];
                }
                for(int i = 0; i < 1000; i++){
                   array1000[i] = array1000Asc[i];
                }
                for(int i = 0; i < 10000; i++){
                   array10000[i] = array10000Asc[i];
                }
                for(int i = 0; i < 100000; i++){
                   array100000[i] = array100000Asc[i];
                }
                for(int i = 0; i < 1000000; i++){
                   array1000000[i] = array1000000Asc[i];
                }

                a1 = clock();
                shell_sort(array10,10);
                a1 = clock() - a1;
                a2 = clock();
                shell_sort(array1000,1000);
                a2 = clock() - a2;
                a3 = clock();
                shell_sort(array10000,10000);
                a3 = clock() - a3;
                a4 = clock();
                shell_sort(array100000,100000);
                a4 = clock() - a4;
                a5 = clock();
                shell_sort(array1000000,1000000);
                a5 = clock() - a5;

                fprintf (file,"ARRAY CRESCENTES 10:\n");
                fprintf (file,"%f\n",((float)a1)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY CRESCENTES 1000:\n");
                fprintf (file,"%f\n",((float)a2)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY CRESCENTES 10000:\n");
                fprintf (file,"%f\n",((float)a3)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY CRESCENTES 100000:\n");
                fprintf (file,"%f\n",((float)a4)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY CRESCENTES 1000000:\n");
                fprintf (file,"%f\n\n\n",((float)a5)/CLOCKS_PER_SEC);

                fprintf (file,"ARRAYS DECRESCENTES\n");
                // GARANTINDO QUE SEMPRE SERAO OS MESMOS ARRAYS

                for(int i = 0; i < 10; i++){
                     array10[i] = array10Desc[i];
                }
                for(int i = 0; i < 1000; i++){
                   array1000[i] = array1000Desc[i];
                }
                for(int i = 0; i < 10000; i++){
                   array10000[i] = array10000Desc[i];
                }
                for(int i = 0; i < 100000; i++){
                   array100000[i] = array100000Desc[i];
                }
                for(int i = 0; i < 1000000; i++){
                   array1000000[i] = array1000000Desc[i];
                }

                a1 = clock();
                shell_sort(array10,10);
                a1 = clock() - a1;
                a2 = clock();
                shell_sort(array1000,1000);
                a2 = clock() - a2;
                a3 = clock();
                shell_sort(array10000,10000);
                a3 = clock() - a3;
                a4 = clock();
                shell_sort(array100000,100000);
                a4 = clock() - a4;
                a5 = clock();
                shell_sort(array1000000,1000000);
                a5 = clock() - a5;

                fprintf (file,"ARRAY DECRESCENTES 10:\n");
                fprintf (file,"%f\n",((float)a1)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY DECRESCENTES 1000:\n");
                fprintf (file,"%f\n",((float)a2)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY DECRESCENTES 10000:\n");
                fprintf (file,"%f\n",((float)a3)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY DECRESCENTES 100000:\n");
                fprintf (file,"%f\n",((float)a4)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY DECRESCENTES 1000000:\n");
                fprintf (file,"%f\n\n\n",((float)a5)/CLOCKS_PER_SEC);

                fprintf (file,"SHELL SORT TERMINADO!\n\n");

                break;

            case 4:
                fprintf (file,"RESULTADOS DO MERGE SORT\n\n");
                fprintf (file,"ARRAYS RANDOMS\n");
                // GARANTINDO QUE SEMPRE SERAO OS MESMOS ARRAYS

                for(int i = 0; i < 10; i++){
                     array10[i] = array10Rand[i];
                }
                for(int i = 0; i < 1000; i++){
                   array1000[i] = array1000Rand[i];
                }
                for(int i = 0; i < 10000; i++){
                   array10000[i] = array10000Rand[i];
                }
                for(int i = 0; i < 100000; i++){
                   array100000[i] = array100000Rand[i];
                }
                for(int i = 0; i < 1000000; i++){
                   array1000000[i] = array1000000Rand[i];
                }

                a1 = clock();
                merge_sort(array10,0,9);
                a1 = clock() - a1;
                a2 = clock();
                merge_sort(array1000,0,999);
                a2 = clock() - a2;
                a3 = clock();
                merge_sort(array10000,0,9999);
                a3 = clock() - a3;
                a4 = clock();
                merge_sort(array100000,0,99999);
                a4 = clock() - a4;
                a5 = clock();
                merge_sort(array1000000,0,999999);
                a5 = clock() - a5;

                fprintf (file,"ARRAY RAND 10:\n");
                fprintf (file,"%f\n",((float)a1)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY RAND 1000:\n");
                fprintf (file,"%f\n",((float)a2)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY RAND 10000:\n");
                fprintf (file,"%f\n",((float)a3)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY RAND 100000:\n");
                fprintf (file,"%f\n",((float)a4)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY RAND 1000000:\n");
                fprintf (file,"%f\n\n\n",((float)a5)/CLOCKS_PER_SEC);

                fprintf (file,"ARRAYS CRESCENTES\n");
                // GARANTINDO QUE SEMPRE SERAO OS MESMOS ARRAYS

                for(int i = 0; i < 10; i++){
                     array10[i] = array10Asc[i];
                }
                for(int i = 0; i < 1000; i++){
                   array1000[i] = array1000Asc[i];
                }
                for(int i = 0; i < 10000; i++){
                   array10000[i] = array10000Asc[i];
                }
                for(int i = 0; i < 100000; i++){
                   array100000[i] = array100000Asc[i];
                }
                for(int i = 0; i < 1000000; i++){
                   array1000000[i] = array1000000Asc[i];
                }

                a1 = clock();
                merge_sort(array10,0,9);
                a1 = clock() - a1;
                a2 = clock();
                merge_sort(array1000,0,999);
                a2 = clock() - a2;
                a3 = clock();
                merge_sort(array10000,0,9999);
                a3 = clock() - a3;
                a4 = clock();
                merge_sort(array100000,0,99999);
                a4 = clock() - a4;
                a5 = clock();
                merge_sort(array1000000,0,999999);
                a5 = clock() - a5;

                fprintf (file,"ARRAY CRESCENTES 10:\n");
                fprintf (file,"%f\n",((float)a1)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY CRESCENTES 1000:\n");
                fprintf (file,"%f\n",((float)a2)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY CRESCENTES 10000:\n");
                fprintf (file,"%f\n",((float)a3)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY CRESCENTES 100000:\n");
                fprintf (file,"%f\n",((float)a4)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY CRESCENTES 1000000:\n");
                fprintf (file,"%f\n\n\n",((float)a5)/CLOCKS_PER_SEC);

                fprintf (file,"ARRAYS DECRESCENTES\n");
                // GARANTINDO QUE SEMPRE SERAO OS MESMOS ARRAYS

                for(int i = 0; i < 10; i++){
                     array10[i] = array10Desc[i];
                }
                for(int i = 0; i < 1000; i++){
                   array1000[i] = array1000Desc[i];
                }
                for(int i = 0; i < 10000; i++){
                   array10000[i] = array10000Desc[i];
                }
                for(int i = 0; i < 100000; i++){
                   array100000[i] = array100000Desc[i];
                }
                for(int i = 0; i < 1000000; i++){
                   array1000000[i] = array1000000Desc[i];
                }

                a1 = clock();
                merge_sort(array10,0,9);
                a1 = clock() - a1;
                a2 = clock();
                merge_sort(array1000,0,999);
                a2 = clock() - a2;
                a3 = clock();
                merge_sort(array10000,0,9999);
                a3 = clock() - a3;
                a4 = clock();
                merge_sort(array100000,0,99999);
                a4 = clock() - a4;
                a5 = clock();
                merge_sort(array1000000,0,999999);
                a5 = clock() - a5;

                fprintf (file,"ARRAY DECRESCENTES 10:\n");
                fprintf (file,"%f\n",((float)a1)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY DECRESCENTES 1000:\n");
                fprintf (file,"%f\n",((float)a2)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY DECRESCENTES 10000:\n");
                fprintf (file,"%f\n",((float)a3)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY DECRESCENTES 100000:\n");
                fprintf (file,"%f\n",((float)a4)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY DECRESCENTES 1000000:\n");
                fprintf (file,"%f\n\n\n",((float)a5)/CLOCKS_PER_SEC);

                fprintf (file,"MERGE SORT TERMINADO!\n\n");

                break;
                 case 5:
                fprintf (file,"RESULTADOS DO HEAP SORT\n\n");
                fprintf (file,"ARRAYS RANDOMS\n");
                // GARANTINDO QUE SEMPRE SERAO OS MESMOS ARRAYS

                for(int i = 0; i < 10; i++){
                     array10[i] = array10Rand[i];
                }
                for(int i = 0; i < 1000; i++){
                   array1000[i] = array1000Rand[i];
                }
                for(int i = 0; i < 10000; i++){
                   array10000[i] = array10000Rand[i];
                }
                for(int i = 0; i < 100000; i++){
                   array100000[i] = array100000Rand[i];
                }
                for(int i = 0; i < 1000000; i++){
                   array1000000[i] = array1000000Rand[i];
                }

                a1 = clock();
                heap_sort(array10,10);
                a1 = clock() - a1;
                a2 = clock();
                heap_sort(array1000,1000);
                a2 = clock() - a2;
                a3 = clock();
                heap_sort(array10000,10000);
                a3 = clock() - a3;
                a4 = clock();
                heap_sort(array100000,100000);
                a4 = clock() - a4;
                a5 = clock();
                heap_sort(array1000000,1000000);
                a5 = clock() - a5;

                fprintf (file,"ARRAY RAND 10:\n");
                fprintf (file,"%f\n",((float)a1)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY RAND 1000:\n");
                fprintf (file,"%f\n",((float)a2)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY RAND 10000:\n");
                fprintf (file,"%f\n",((float)a3)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY RAND 100000:\n");
                fprintf (file,"%f\n",((float)a4)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY RAND 1000000:\n");
                fprintf (file,"%f\n\n\n",((float)a5)/CLOCKS_PER_SEC);


                fprintf (file,"ARRAYS CRESCENTES\n");
                // GARANTINDO QUE SEMPRE SERAO OS MESMOS ARRAYS

                for(int i = 0; i < 10; i++){
                     array10[i] = array10Asc[i];
                }
                for(int i = 0; i < 1000; i++){
                   array1000[i] = array1000Asc[i];
                }
                for(int i = 0; i < 10000; i++){
                   array10000[i] = array10000Asc[i];
                }
                for(int i = 0; i < 100000; i++){
                   array100000[i] = array100000Asc[i];
                }
                for(int i = 0; i < 1000000; i++){
                   array1000000[i] = array1000000Asc[i];
                }

                a1 = clock();
                heap_sort(array10,10);
                a1 = clock() - a1;
                a2 = clock();
                heap_sort(array1000,1000);
                a2 = clock() - a2;
                a3 = clock();
                heap_sort(array10000,10000);
                a3 = clock() - a3;
                a4 = clock();
                heap_sort(array100000,100000);
                a4 = clock() - a4;
                a5 = clock();
                heap_sort(array1000000,1000000);
                a5 = clock() - a5;

                fprintf (file,"ARRAY CRESCENTE 10:\n");
                fprintf (file,"%f\n",((float)a1)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY CRESCENTE 1000:\n");
                fprintf (file,"%f\n",((float)a2)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY CRESCENTE 10000:\n");
                fprintf (file,"%f\n",((float)a3)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY CRESCENTE 100000:\n");
                fprintf (file,"%f\n",((float)a4)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY CRESCENTE 1000000:\n");
                fprintf (file,"%f\n\n\n",((float)a5)/CLOCKS_PER_SEC);


                fprintf (file,"ARRAYS DECRESCENTES\n");
                // GARANTINDO QUE SEMPRE SERAO OS MESMOS ARRAYS

                for(int i = 0; i < 10; i++){
                     array10[i] = array10Desc[i];
                }
                for(int i = 0; i < 1000; i++){
                   array1000[i] = array1000Desc[i];
                }
                for(int i = 0; i < 10000; i++){
                   array10000[i] = array10000Desc[i];
                }
                for(int i = 0; i < 100000; i++){
                   array100000[i] = array100000Desc[i];
                }
                for(int i = 0; i < 1000000; i++){
                   array1000000[i] = array1000000Desc[i];
                }

                a1 = clock();
                heap_sort(array10,10);
                a1 = clock() - a1;
                a2 = clock();
                heap_sort(array1000,1000);
                a2 = clock() - a2;
                a3 = clock();
                heap_sort(array10000,10000);
                a3 = clock() - a3;
                a4 = clock();
                heap_sort(array100000,100000);
                a4 = clock() - a4;
                a5 = clock();
                heap_sort(array1000000,1000000);
                a5 = clock() - a5;

                fprintf (file,"ARRAY DECRESCENTE 10:\n");
                fprintf (file,"%f\n",((float)a1)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY DECRESCENTE 1000:\n");
                fprintf (file,"%f\n",((float)a2)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY DECRESCENTE 10000:\n");
                fprintf (file,"%f\n",((float)a3)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY DECRESCENTE 100000:\n");
                fprintf (file,"%f\n",((float)a4)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY DECRESCENTE 1000000:\n");
                fprintf (file,"%f\n\n\n",((float)a5)/CLOCKS_PER_SEC);

                fprintf (file,"SELECTION SORT TERMINADO!\n\n");

                break;
                 case 6:
                fprintf (file,"RESULTADOS DO QUICK SORT\n\n");
                fprintf (file,"ARRAYS RANDOMS\n");
                // GARANTINDO QUE SEMPRE SERAO OS MESMOS ARRAYS

                for(int i = 0; i < 10; i++){
                   array10[i] = array10Rand[i];
                }
                for(int i = 0; i < 1000; i++){
                   array1000[i] = array1000Rand[i];
                }
                for(int i = 0; i < 10000; i++){
                   array10000[i] = array10000Rand[i];
                }
                for(int i = 0; i < 100000; i++){
                   array100000[i] = array100000Rand[i];
                }
                for(int i = 0; i < 1000000; i++){
                   array1000000[i] = array1000000Rand[i];
                }

                a1 = clock();
                quick_sort(array10,0,9);
                a1 = clock() - a1;
                a2 = clock();
                quick_sort(array1000,0,999);
                a2 = clock() - a2;
                a3 = clock();
                quick_sort(array10000,0,9999);
                a3 = clock() - a3;
                a4 = clock();
                quick_sort(array100000,0,99999);
                a4 = clock() - a4;
                a5 = clock();
                quick_sort(array1000000,0,999999);
                a5 = clock() - a5;

                fprintf (file,"ARRAY RAND 10:\n");
                fprintf (file,"%f\n",((float)a1)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY RAND 1000:\n");
                fprintf (file,"%f\n",((float)a2)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY RAND 10000:\n");
                fprintf (file,"%f\n",((float)a3)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY RAND 100000:\n");
                fprintf (file,"%f\n",((float)a4)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY RAND 1000000:\n");
                fprintf (file,"%f\n\n\n",((float)a5)/CLOCKS_PER_SEC);


                fprintf (file,"ARRAYS CRESCENTES\n");
                // GARANTINDO QUE SEMPRE SERAO OS MESMOS ARRAYS

                for(int i = 0; i < 10; i++){
                     array10[i] = array10Asc[i];
                }
                for(int i = 0; i < 1000; i++){
                   array1000[i] = array1000Asc[i];
                }
                for(int i = 0; i < 10000; i++){
                   array10000[i] = array10000Asc[i];
                }
                for(int i = 0; i < 100000; i++){
                   array100000[i] = array100000Asc[i];
                }
                for(int i = 0; i < 1000000; i++){
                   array1000000[i] = array1000000Asc[i];
                }

                a1 = clock();
                quick_sort(array10,0,9);
                a1 = clock() - a1;
                a2 = clock();
                quick_sort(array1000,0,999);
                a2 = clock() - a2;
                a3 = clock();
                quick_sort(array10000,0,9999);
                a3 = clock() - a3;
                a4 = clock();
                quick_sort(array100000,0,99999);
                a4 = clock() - a4;
                a5 = clock();
                quick_sort(array1000000,0,999999);
                a5 = clock() - a5;

                fprintf (file,"ARRAY CRESCENTE 10:\n");
                fprintf (file,"%f\n",((float)a1)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY CRESCENTE 1000:\n");
                fprintf (file,"%f\n",((float)a2)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY CRESCENTE 10000:\n");
                fprintf (file,"%f\n",((float)a3)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY CRESCENTE 100000:\n");
                fprintf (file,"%f\n",((float)a4)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY CRESCENTE 1000000:\n");
                fprintf (file,"%f\n\n\n",((float)a5)/CLOCKS_PER_SEC);


                fprintf (file,"ARRAYS DECRESCENTES\n");
                // GARANTINDO QUE SEMPRE SERAO OS MESMOS ARRAYS

                for(int i = 0; i < 10; i++){
                     array10[i] = array10Desc[i];
                }
                for(int i = 0; i < 1000; i++){
                   array1000[i] = array1000Desc[i];
                }
                for(int i = 0; i < 10000; i++){
                   array10000[i] = array10000Desc[i];
                }
                for(int i = 0; i < 100000; i++){
                   array100000[i] = array100000Desc[i];
                }
                for(int i = 0; i < 1000000; i++){
                   array1000000[i] = array1000000Desc[i];
                }

                a1 = clock();
                quick_sort(array10,0,9);
                a1 = clock() - a1;
                a2 = clock();
                quick_sort(array1000,0,999);
                a2 = clock() - a2;
                a3 = clock();
                quick_sort(array10000,0,9999);
                a3 = clock() - a3;
                a4 = clock();
                quick_sort(array100000,0,99999);
                a4 = clock() - a4;
                a5 = clock();
                quick_sort(array1000000,0,999999);
                a5 = clock() - a5;

                fprintf (file,"ARRAY DECRESCENTE 10:\n");
                fprintf (file,"%f\n",((float)a1)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY DECRESCENTE 1000:\n");
                fprintf (file,"%f\n",((float)a2)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY DECRESCENTE 10000:\n");
                fprintf (file,"%f\n",((float)a3)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY DECRESCENTE 100000:\n");
                fprintf (file,"%f\n",((float)a4)/CLOCKS_PER_SEC);
                fprintf (file,"ARRAY DECRESCENTE 1000000:\n");
                fprintf (file,"%f\n\n\n",((float)a5)/CLOCKS_PER_SEC);

                fprintf (file,"SELECTION SORT TERMINADO!\n\n");

                break;
            default:
                cout << "Entrada inválida" << endl;
                break;

        }

    }



// CLOSING
fclose(file);

// CLEANING
delete [] array10;
delete [] array1000;
delete [] array10000;
delete [] array100000;
delete [] array1000000;
delete [] array10Rand;
delete [] array1000Rand;
delete [] array10000Rand;
delete [] array100000Rand;
delete [] array1000000Rand;
delete [] array10Asc;
delete [] array1000Asc;
delete [] array10000Asc;
delete [] array100000Asc;
delete [] array1000000Asc;
delete [] array10Desc;
delete [] array1000Desc;
delete [] array10000Desc;
delete [] array100000Desc;
delete [] array1000000Desc;

    return 0;
}
