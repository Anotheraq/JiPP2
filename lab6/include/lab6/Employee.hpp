#ifndef EMPL_HPP
#define EMPL_HPP

#include <string>

class Employee
{
    private:
    std::string id;
    std::string name;
    std::string surname;
    std::string departmentid;
    std::string position;
    

    public:
    Employee(std::string _id, std::string _name, std::string _surname, std::string _position);
    
    void set_depid(std::string _departmentid);
    std::string getid();

    std::string getname();

    std::string getsurname();

    std::string getdepartmentid();

    std::string getposition();
};
#endif