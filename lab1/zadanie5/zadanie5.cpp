#include<iostream>


int main()
{
	const int a = 2, b = 3;
	int A[a][b], B[a][b], W[a][b];
	
	
	//wczytanie wartosci pierwszej macierzy
	for(int i=0;i<a;i++)
	{	
		for(int j=0;j<b;j++)
        {
            std::cout << "Prosze podac A[" << i << "]" << "[" << j << "]: " <<std::endl;
        	std::cin>>A[i][j]; 
        
        }
	}
	//wczytanie wartosci drugiej macierzy
	for(int i=0;i<a;i++)
    {
		for(int j=0;j<b;j++)
		{
            std::cout << "Prosze podac B[" << i << "]" << "[" << j << "]: " <<std::endl;
		    std::cin>>B[i][j];
			W[i][j] = A[i][j] + B[i][j]; //dodawanie do siebie macierzy A i B
		}
    }
	
    //wynik
    std::cout<< "Wynik dodawania: " << std::endl;
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<b;j++)
	    	std::cout<<W[i][j]<<" "; 
		std::cout<<std::endl;
	}
	
    system("pause");
    return 0;
}