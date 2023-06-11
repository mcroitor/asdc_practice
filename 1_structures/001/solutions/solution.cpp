#include <string>
#include <iostream>

class Student
{
    std::string _first_name;
    std::string _last_name;
    std::string _group;

public:
    Student(std::string _first_name, std::string _last_name, std::string _group);
    Student operator = (const Student &student);

    std::string firstName() const;
    std::string lastName() const;
    std::string group() const;
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