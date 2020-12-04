#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "sqlite3/sqlite3.h"


class Matrix
{
    private:
        double ** arr;
        int n_class {}, m_class {};
    public:
        
        Matrix(int n, int m);                           // konstruktor przyjmujący dwa argumenty typu int tworzący macierz o podanych wymiarach zainicjalizowaną zerami
        Matrix(int n);                                  //konstruktor przyjmujący jeden argument typu int tworzący macierz kwadratową o podanym rozmiarze zainicjalizowaną zerami
        Matrix(std::string filename, std::string path); //dodatkowy konstruktor jako argument przyjmujący ścieżkę do bazy dannych o podanym wcześniej formacie i na jego podstawie tworzący nową macierz na podstawie przekazanego pliku
        
        void set(int n, int m, double val); //metoda ustawiająca wartość elementu (n, m) na val
        double get(int x, int y);           //metoda pobierająca element (n, m)
       
        Matrix add(Matrix m2);      //metoda przyjmująca jako argument inną macierz i zwracająca jako wynik nową macierz będącą sumą bieżącej macierzy oraz macierzy przekazanej jako argument
        Matrix subtract(Matrix m2); //metoda przyjmująca jako argument inną macierz i zwracająca jako wynik nową macierz będącą różnicą bieżącej macierzy oraz macierzy przekazanej jako argument
        Matrix multiply(Matrix m2); //metoda przyjmująca jako argument inną macierz i zwracająca jako wynik nową macierz będącą iloczynem bieżącej macierzy oraz macierzy przekazanej jako argumen
       
        int rows(); //metoda zwracająca liczbę wierszy macierzy
        int cols(); //metoda zwracająca liczbę kolumn macierzy

        void store(std::string filename,std::string path);//metoda zapisująca macierz w bazie dannych
        void print();               //metoda wyświetlająca macierz na ekranie
};