#include <string>
#include <iostream>

class Student
{
    std::string _first_name;
    std::string _last_name;
    std::string _group;

public:
    Student(std::string _first_name, std::string _last_name, std::string _group) 
        : _first_name(std::move(_first_name)), 
          _last_name(std::move(_last_name)), 
          _group(std::move(_group)) 
    {};
    Student& operator = (const Student &student) = default;

    std::string firstName() const {
        return _first_name;
    }
    std::string lastName() const {
        return _last_name;
    }
    std::string group() const {
        return _group;
    }
};

std::ostream & operator << (std::ostream &os, const Student &student)
{
    os << "[ " 
        << student.firstName() 
        << ", " 
        << student.lastName() 
        << ", " 
        << student.group()
        << " ]";
    return os;
}

std::istream & operator >> (std::istream &is, Student &student)
{
    std::string first_name;
    std::string last_name;
    std::string group;
    is >> first_name >> last_name >> group;
    student = Student(first_name, last_name, group);
    return is;
}

int main() {
    Student student ("Firstname", "Lastname", "group");
    std::cin >> student;

    std::cout << student << std::endl;
    return 0;
}