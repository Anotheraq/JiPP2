#include <iostream>
#include <ctime>
#include "HRMS.hpp"
#include "Employee.hpp"

int main()
{
    srand(time(NULL));
    std::vector<std::string> dep{"D1", "D2", "D3"};

    std::vector<Employee> emps{
        {"001","Aleksander","Jaworski","Senior Java developer"},
        {"002","Dawid","Jaworski","Senior C++ Developer"},
        {"003","Mikolaj","Sikora","Junior C++ Developer"},
        {"004","Robert","Ostrowski","Junior Java Developer"},
        {"005","Fryderyk","Wojcik","Teamlead"},
        {"006","Hubert","Krajewska","Software Tester"},
        {"007","Milosz","Duda","Cleaning manager"},
        {"008","Ireneusz","Jankowski","Security guard"},
        {"009","Ludwik","Sokolowski","Project Manager"},
        {"010","Norbert","Nowak","Fullstack C++ Developer"},
    };
    
    HRMS hrms;
    int deprand;
    double salary;
    for(auto &emp: emps)
    {
        deprand = rand() % 3;
        salary = (double)rand();
        hrms.add(emp, dep.at(deprand), salary);
    }
    hrms.printDepartment(dep.at(1));

    hrms.printSalaries();
    hrms.changeSalary("002",4444.4);
    hrms.printSalariesSorted();
    system("pause");
    return 0;
}