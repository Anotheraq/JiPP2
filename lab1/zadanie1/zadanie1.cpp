#include <iostream>
#include <string>

using namespace std;

void printArr(int* array, size_t size);
void sortArr(int* array, size_t size);

int main(int argc, const char* argv[])
{
    int* arr = new int[argc - 1];//deklaracja macierzy arr
    for (size_t i = 1; i < argc; i++) 
        arr[i - 1] = stoi(argv[i]);
    
    sortArr(arr, argc - 1);//wywolanie funkcji sortArr
    
    cout << "out = ";//wynik koncowy(1)
    
    printArr(arr, argc - 1);//wywolanie funkcji printArr
    
    delete[] arr;
    system("pause");

    return 0;
}

void printArr(int* arr, size_t size)//wywod posortowanej macierzy
{
    for (size_t i = 0; i < size; i++) 
        cout << arr[i] << " ";//wynik koncowy(2)
    cout << endl;
}

void sortArr(int* arr, size_t size)//sortowanie macierzy
{
    size_t i, j;
    int q;
    for (i = 1; i < size; i++)
    {
        q = arr[i];
        
        j = i - 1;

        while (j >= 0 && arr[j] > q)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }//whileend
        arr[j + 1] = q;
    }//forend
}