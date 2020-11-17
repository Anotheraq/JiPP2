#include <iostream>

int main()
{
    int a = 0,b = 0;
    std::cout << "Prosze podac a, b jaki sa > 1: ";
    while(a <= 1 && b <= 1) //sprawdzenie poprawnosci danych wejsciowych
    {
        std::cin >> a >> b;
        if(a <= 1 || b <= 1)
        {
            std::cout << "a lub b jest <= 1, prosze sprobowac jeszcze raz" << std::endl;
        }//ifend
    }//whileend
    
    int sumaA = 0;
    
    for(int i = 1;i < a;i++)//Suma a loop
    {
        if(a%i == 0)
            sumaA += i;
    }//for end
    int sumaB = 0;
    
    for(int i = 1; i < b; i++)//Suma b loop
    {
        if(b%i == 0)
            sumaB += i;
        
    }//for end
    
    std::cout << "Suma a = " << sumaA << std::endl << "Suma b = " << sumaB << std::endl;
    
    if (sumaA==b+1 && sumaB==a+1)//sprawdzenie koniecznego warunku
    {
        std::cout << "Liczby sa skojarzonymi" << std::endl;
    }else{
        std::cout << "Liczby sa nieskojarzonymi" << std::endl;
    }
    system("pause");
    return 0;
}