#include"edusys.h"
#include<numeric>

/*EduSys::EduSys(std::vector<Student> students){
    for(const auto& student : students){
        //std::shared_ptr<Student> newStudent = new Student(student);
        _candidates.push_back(student);
    }
}*/

EduSys::EduSys(std::shared_ptr<SchoolClass> school){
    _schools.push_back(school);
}

void EduSys::printStud()const{
    for(const auto& student: _candidates){
        student->print();
    }
    std::cout<<std::endl;
}

void EduSys::sortpoints(){
    std::sort(_candidates.begin(), _candidates.end(), [](const std::shared_ptr<Student> a, const std::shared_ptr<Student> b) {
                  return a->getPoints() > b->getPoints();
              }
            );
}

void EduSys::recruit(){
    for (auto& student : _candidates) {
        bool accepted = false;
        for (auto& school : student->getPreferredSchools()) {
            if (school->freeSeats()) {
                school->addStudent(student);
                student->setAcceptedIn(school);
                accepted = true;
                break;
            }else{
               student->setAcceptedIn(nullptr);
            }
        }
    }
}

double EduSys::getAverageStudScore()const{
    if (_candidates.empty()) {
        return 0.0;
    }
    double sum = std::accumulate(_candidates.begin(), _candidates.end(), 0.0,
        [](double total, const std::shared_ptr<Student> student) {
            return total + student->getPoints();
        }
    );
    return sum / _candidates.size();
}

void EduSys::printRecruit()const{
    for (const auto& school : _schools) {
        school->print();
    }
}

void EduSys::operator+=(std::shared_ptr<Student>& candidate){;
    _candidates.push_back(candidate);
}

void EduSys::operator+=(std::shared_ptr<Student> candidate){
    _candidates.push_back(candidate);
}


void EduSys::operator+=(std::shared_ptr<SchoolClass> school){
    _schools.push_back(school);
}
