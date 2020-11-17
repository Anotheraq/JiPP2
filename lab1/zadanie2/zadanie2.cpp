#include <iostream>
#include <string>


int main(int argc, char *argv[])
{

        std::string word = "";
        for(int i = 1; i < argc; i++)
            word += argv[i];
        
        if (word == "")//sprawdzenie poprawnosci danych wejsciowych
        { 
            std::cout << "Prosze podac ciag znakow";
            exit(0);
        }//ifend
        
        for(int i = 0, j = word.length()-1; i < j; i++,j--) //i - poczatek slowa, j - koniec
        {
            if(tolower(word[i])!=tolower(word[j]))//sprawdzenie warunka
            {
                std::cout << "Podany ciag nie jest palindromem";
                exit(0);
            }//ifend
        }//forend
        
        std::cout << "Podany ciag jest palindromem" << std::endl;
        
        system("pause");    
        return 0;
}