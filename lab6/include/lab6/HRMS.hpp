#ifndef HRMS_HPP
#define HRMS_HPP

#include <vector>
#include <map>

#include "Employee.hpp"
#include "exceptions.hpp"
class HRMS
{
private:
    std::map <std::string, Employee> id_em;
    std::map <std::string, std::vector<std::string>> did_id;
    std::map <std::string, double> em_sal;
public:
    void add(Employee &employee, std::string departmentId, double salary);
    void changeSalary(std::string employeeId, double salary);
    void printDepartment(std::string departmentId);
    void printSalaries();
    void printSalariesSorted();
};
#endif