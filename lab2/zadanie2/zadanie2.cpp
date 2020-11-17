#include <iostream>
void fun(int &i, int &j);

int main()
{
    int x, s;
    
    std::cout<<"Prosze podac dwie cyfry: ";
    std::cin >> x >> s;
    
    std::cout << "Do zamiany: x = "<< x << " | s = " << s << std::endl;

    fun(x,s);
    
    std::cout << "Po zamianie: x = "<< x << " | s = " << s;
    system("pause");
    return 0;
}

void fun(int &i, int &j)
{   
    int temp;
    
    temp = i;     //lub mozna bylo wykourzystac #include <algorithm> a zatem std::swap(*i,*j) takze jak i w pierwszym zadaniu
    i = j;
    j = temp;

}