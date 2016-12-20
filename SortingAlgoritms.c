#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*********
   @author PaweŁ Lelental
   Academy Project for Algorithms and Data Structures subject
   PJATK GDAŃSK
 **********/




/******************** Swap method********************/

void swap(int *a, int *b)
{
        *a^=*b;
        *b^=*a;
        *a^=*b;
}
/********************Order of Arrays********************/
void randomized(int* arr, int size)
{
        srand(time(NULL));
        long range = 10000;
        for (int i = 0; i <= size; i++)
        {
                arr[i] = 1 + (rand() * range) / RAND_MAX;
        }

}

void sorted(int* arr, int size){
        for(int i = 0; i<= size; i++) {
                arr[i] = i;
        }
}

void backwards(int *arr, int size){
        for (int i=0; i<size; i++) {
                arr[i]=size-i;
        }
}
/******************** Sorting Algorithms********************/
void max_heapify(int* arr, int i, int size)
{

        int left = 2*i+1;
        int right = 2*i+2;
        int largest;

        if (left <= size && (arr[left] > arr[i]))
                largest = left;
        else largest = i;

        if (right <= size && (arr[right] > arr[largest]))
                largest = right;

        if (largest != i)
        {
                swap(&arr[i], &arr[largest]);
                max_heapify(arr, largest, size);
        }

}

void build_max_heap(int* arr, int size)
{
        for (int i = ((size - 1) / 2); i >= 0; i--)
        {
                max_heapify(arr, i, size);
        }

}

void heap_sort(int* arr, int size)
{

        build_max_heap(arr, size);
        for (int i = size; i >= 1; i--)
        {
                swap(&arr[i], &arr[0]);
                size--;
                max_heapify(arr, 0, size);
        }
}



void bubble_sort(int* arr, int size)
{
        int i, j, tmp;
        for (i = 0; i < size; i++)
        {
                for (j = 0; j < size - 1; j++)
                {
                        if (arr[j + 1] < arr[j])
                        {
                                swap(&arr[j], &arr[j+1]);
                        }
                }
        }
}




void hoare_quick_sort(int* arr, int begin, int end){
        {
                if (begin>=end) return;
                int middle=(begin+end)/2;
                int pivot=arr[middle];
                int i=begin;
                int j=end;
                while (i<=j)
                {
                        while (arr[i]<pivot) i++;
                        while (arr[j]>pivot) j--;
                        if (i<=j)
                        {
                                int temp = arr[i];
                                arr[i] = arr[j];
                                arr[j] = temp;
                                i++;
                                j--;
                        }
                }
                if (j>begin)
                        hoare_quick_sort(arr, begin, j);
                if (i<end)
                        hoare_quick_sort(arr, i, end);
        }
}


void insertion_sort(int* arr, int size){

        int i, j, tmp;
        for(i = 1; i < size; i++)
        {
                tmp = arr[i];
                for (j = i - 1; j >= 0 && arr[j] > tmp; j--)
                        arr[j + 1] = arr[j];
                arr[j + 1] = tmp;
        }
}

int partition(int* arr, int begin, int end, int pivot_index)
{
        int pivot = arr[pivot_index];
        do
        {
                while (arr[begin] < pivot) begin++;
                while (arr[end] > pivot) end--;
                if (begin < end && arr[begin] != arr[end])
                {
                        swap(&arr[begin],&arr[end]);
                }
                else
                {
                        return end;
                }
        } while (begin < end);
        return end;
}
void lomuto_quick_sort(int* arr, int begin, int end)
{
        if (begin < end)
        {
                int pivot = (begin + end) / 2;
                int pivot_new = partition(arr, begin, end, pivot);
                lomuto_quick_sort(arr, begin, pivot_new - 1);
                lomuto_quick_sort(arr, pivot_new + 1, end);
        }
}

/******************** Menu********************/

void end_of_sorting(int *arr, double start, double end){

        for (int i = 0; i <= 1000000; i++)
                printf("%d ", arr[i]);
        printf("\n\nRozmiar tablicy: %d\n", 1000000);
        printf("Czas dzialania samego algorytmu sortujacego(bez wczytywania danych i wypisywania tablicy): %f sekund\n", (double)(end - start) / CLOCKS_PER_SEC);

}

void algorithms_choice(int* arr, int size){

        system("cls");
        printf("Jakim algorytmem chcesz posortowac tablice?");
        printf("\n1. HeapSort");
        printf("\n2. BubbleSort");
        printf("\n3. Lomuto QuickSort");
        printf("\n4. Hoare QuickSort");
        printf("\n5. InsertionSort");
        printf("\n6.Wyjscie\n");

        int key;
        scanf("%d", &key);
        getchar();

        switch (key)
        {
        case 1:
                clock_t start_heap_sort = clock();
                heap_sort(arr, size);
                clock_t end_heap_sort = clock();
                end_of_sorting(arr,start_heap_sort,end_heap_sort);
                free(arr);
                break;
        case 2:
                clock_t start_bubble_sort = clock();
                bubble_sort(arr, size+1);
                clock_t end_bubble_sort = clock();
                end_of_sorting(arr,start_bubble_sort,end_bubble_sort);
                free(arr);
                break;

        case 3:
                clock_t start_lomuto_sort = clock();
                lomuto_quick_sort(arr,0,size);
                clock_t end_lomuto_sort = clock();
                end_of_sorting(arr,start_lomuto_sort,end_lomuto_sort);
                free(arr);
                break;


        case 4:
                clock_t start_hoare_sort = clock();
                hoare_quick_sort(arr,0,size);
                clock_t end_hoare_sort = clock();
                end_of_sorting(arr,start_hoare_sort,end_hoare_sort);
                free(arr);
                break;

        case 5:
                clock_t start_insertion_sort = clock();
                insertion_sort(arr,size+1);
                clock_t end_insertion_sort = clock();
                end_of_sorting(arr,start_insertion_sort,end_insertion_sort);
                free(arr);
                break;
        case 6:
                exit(1);
                break;
        default:
                printf("\nWcisnales zly przycisk.");
                break;
        }





}


void start_menu(int* arr, int size){

        system( "cls" );
        printf("Witaj!. W jakiej kolejności maja byc ulozne elementy w tablicy?");
        printf("\n1. Od najmniejszego do najwiekszego");
        printf("\n2. Od najwieszkego do najmniejszego");
        printf("\n3. Losowo");
        printf("\n4. Wyjdz\n");


        int key2;
        scanf("%d", &key2);
        getchar();
        switch(key2) {

        case 1:
                sorted(arr,size);
                algorithms_choice(arr,size);
                break;
        case 2:
                backwards(arr,size);
                algorithms_choice(arr,size);
                break;
        case 3:
                randomized(arr,size);
                algorithms_choice(arr,size);
                break;
        case 4:
                exit(1);
                break;
        default:
                printf("\nWcisnales zly przycisk.");
                break;
        }

}
/******************** Main********************/

int main()
{
        clock_t begin = clock();
        int* arr = malloc(1000000 * sizeof(int));
        int size = 1000000;
        start_menu(arr,size);
        clock_t end = clock();
        printf("Czas dzialania calego programu: %f sekund \n", (double)(end - begin) / CLOCKS_PER_SEC);

        return 0;
}
