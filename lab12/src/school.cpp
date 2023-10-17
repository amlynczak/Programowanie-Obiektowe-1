#include"school.h"
#include"student.h"
#include"edusys.h"

std::string SchoolClass::getclass()const{
    return _name;
}

int SchoolClass::getmax()const{
    return _maxSeats;
}

void SchoolClass::print()const{
    std::cout << _name << " - " << _maxSeats - this->getfree() << "/" << _maxSeats << ": ";
    if (_accepted.empty()){
        std::cout << "brak przyjetych" << std::endl;
    }else{
        for(const auto& student : _accepted){
            std::cout << std::endl;
            std::cout << student->getName() << ": " << student->getPoints() << " ";
            if (student->getAcceptedSchool()->getclass() == this->getclass()){
                std::cout << "--> " << _name;
            }else{
                std::cout << "--> nieprzyjety";
            }
        }
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
}

bool SchoolClass::freeSeats()const{
    return _accepted.size() < _maxSeats;
}

void SchoolClass::addStudent(std::shared_ptr<Student> student){
    _accepted.push_back(student);
}