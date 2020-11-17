#include <iostream>
 
template < typename T >
void MySwap(T* x, T*y)
{
    T temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    std::cout << "INT: " << std::endl;
    int x, y;
    x = 85;
    y = 27;
    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
    MySwap(&x, &y);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

    std::cout << "__" << std::endl;
    std::cout << "FLOAT: " << std::endl;
    float fx, fy;
    fx = 8.41;
    fy = 3.1;
    std::cout << "Before swap: x = " << fx << ", y = " << fy << std::endl;
    MySwap(&fx, &fy);
    std::cout << "After swap: x = " << fx << ", y = " << fy << std::endl;
    std::cout << "__" << std::endl;
    std::cout << "CHAR: " << std::endl;
    char ax, ay;
    ax = 'a'; 
    ay = 'b';
    std::cout << "Before swap: x = " << ax << ", y = " << ay << std::endl;
    MySwap(&ax, &ay); 
    std::cout << "After swap: x = " << ax << ", y = " << ay << std::endl;

    system("pause");
    return 0;
}