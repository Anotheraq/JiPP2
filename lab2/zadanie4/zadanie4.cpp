#include <iostream>
template <typename T> T SumMult(T a, T b, T& sum)
{
    sum = a + b;
    return a * b;
}



int main()
{
    float a, b, sum;
    
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;
    
    std::cout << "Iloczyn = " << SumMult(a, b, sum) << std::endl;
    std::cout << "Suma = " << sum << std::endl;
    
    system("pause");
    return 0;
}
