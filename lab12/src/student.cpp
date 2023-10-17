#include"student.h"
#include"school.h"
#include"edusys.h"

void Student::print()const{
    std::cout << _name << ": " << _points << " [ ";
    for (const auto& school : _preferred_schools) {
        std::cout << school->getclass() << " ";
    }
    std::cout << "] --> ";
    if (_acceptedIn != nullptr) {
        std::cout << _acceptedIn->getclass();
    } else {
        std::cout << "kandydat";
    }
    std::cout << std::endl;
}

std::string Student::getName()const{
    return _name;
}

int Student::getPoints()const{
    return _points;
}

std::shared_ptr<SchoolClass> Student::getAcceptedSchool()const{
    return _acceptedIn;
}

void Student::setAcceptedIn(std::shared_ptr<SchoolClass> school){
    _acceptedIn = school;
}

std::vector<std::shared_ptr<SchoolClass>> Student::getPreferredSchools()const{
    return _preferred_schools;
}