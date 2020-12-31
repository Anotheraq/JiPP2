
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "HRMS.hpp"


void HRMS::add(Employee &employee, std::string departmentId, double salary)
{
    employee.set_depid(departmentId);

    std::string empid = employee.getid();
    this->id_em.emplace(std::pair<std::string, Employee>(empid, employee));
    this->did_id[departmentId].push_back(empid);
    this->em_sal[empid] = salary;
}

void HRMS::changeSalary(std::string employeeId, double salary)
{   
    std::cout << "Changing salary for employee with id: " << employeeId << " at " << salary << " zl" << std::endl;
    try
    {
        if(this->em_sal.find(employeeId) == this->em_sal.end())
        {
            throw MyException("No employee with given id { " + employeeId + " } exists");
        }
        this->em_sal[employeeId] = salary;
    }
    catch(MyException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void HRMS::printDepartment(std::string departmentId)
{   
    try
    {
        if(this->did_id.find(departmentId) == this->did_id.end())
        {
            throw MyException( "No department with given id { " + departmentId + " } exists");
        }

        std::cout << "Employees at department " << departmentId << ":"<< std::endl;
        auto department = this->did_id[departmentId];

        for(std::string id: department)
        {
            Employee &emp = this->id_em.find(id)->second;
            std::cout << id << ": " << emp.getname() << " " << emp.getsurname() << std::endl;
        }
    }
    catch(MyException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void HRMS::printSalaries()
{
    std::cout << "Salaries: " << std::endl;
    for(auto &a: this->id_em)
    {
        Employee& emp = a.second;
        std::cout << "Salary: " << em_sal[emp.getid()] << " zl " << std::setw(10) << "| ";
        std::cout << "ID: " << emp.getid() << std::setw(10) << "| ";
        std::cout << "Name: " << emp.getname() << std::setw(10) << "| ";
        std::cout << "Surname: " << emp.getsurname() << std::setw(10) << "| ";
        std::cout << "Position: " << emp.getposition() << std::setw(10) << "| ";
        std::cout << "Department id: " << emp.getdepartmentid() << std::endl;
        std::cout << "+-------------------------------------------------------------------------------------------------------+" << std::endl;
    }
}

void HRMS::printSalariesSorted()
{
    std::cout << "Sotred by salaries: " << std::endl;
    std::vector<std::pair<std::string, Employee>> temp(this->id_em.begin(), this->id_em.end());
    std::sort(temp.begin(), temp.end(),
    [this](std::pair<std::string, Employee>& e1, std::pair<std::string, Employee>& e2){
        return this->em_sal[e1.first] > this->em_sal[e2.first];
    });

    for(auto &a: temp)
    {
        Employee& emp = a.second;
        std::cout << "Salary: " << em_sal[emp.getid()] << " zl " << std::setw(10) << "| ";
        std::cout << "ID: " << emp.getid() << std::setw(10) << "| ";
        std::cout << "Name: " << emp.getname() << std::setw(10) << "| ";
        std::cout << "Surname: " << emp.getsurname() << std::setw(10) << "| ";
        std::cout << "Position: " << emp.getposition() << std::setw(10) << "| ";
        std::cout << "Department id: " << emp.getdepartmentid() << std::endl;
        std::cout << "+-------------------------------------------------------------------------------------------------------+" << std::endl;
    }
}
