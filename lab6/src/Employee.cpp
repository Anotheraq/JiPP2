
#include "Employee.hpp"

Employee::Employee(std::string _id, std::string _name, std::string _surname, std::string _position)
{
    id = _id;
    name = _name;
    surname = _surname;
    position = _position;
}

void Employee::set_depid(std::string _departmentid)
{
    departmentid = _departmentid;
}

std::string Employee::getid()
{
    return id;
}
std::string Employee::getname()
{
    return name;
}
std::string Employee::getsurname()
{
    return surname;
}
std::string Employee::getdepartmentid()
{
    return departmentid;
}
std::string Employee::getposition()
{
    return position;
}
