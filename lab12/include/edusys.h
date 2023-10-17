#pragma once
#include"student.h"
#include"school.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<memory>

class Student;
class SchoolClass;

/**
 * @brief system w lasie
 * 
 */
class EduSys{
public:
    /**
     * @brief Construct a new Edu Sys object
     * 
     * @param students 
     */
    EduSys(std::vector<std::shared_ptr<Student>> students): _candidates(students) {};
    /**
     * @brief Construct a new Edu Sys object
     * 
     * @param schools 
     */
    EduSys(std::vector<std::shared_ptr<SchoolClass>> schools): _schools(schools) {};
    //EduSys(std::vector<Student> students);

    /**
     * @brief Construct a new Edu Sys object
     * 
     * @param school 
     */
    EduSys(std::shared_ptr<SchoolClass> school);
    
    /**
     * @brief drukuje uczniow kandydatow
     * 
     */
    void printStud()const;
    /**
     * @brief funkcja sortujaca
     * 
     */
    void sortpoints();
    /**
     * @brief rekrutuje do szkoly
     * 
     */
    void recruit();
    /**
     * @brief Get the Average Stud Score object
     * 
     * @return double 
     */
    double getAverageStudScore()const;
    /**
     * @brief drukuje kto sie dostal
     * 
     */
    void printRecruit()const;

    /**
     * @brief operatory +=
     * 
     * @param candidate 
     */
    void operator+=(std::shared_ptr<Student>& candidate);
    void operator+=(std::shared_ptr<Student> candidate);
    void operator+=(std::shared_ptr<SchoolClass> school);

    //lab 12 zajecia

    /**
     * @brief Construct a new Edu Sys object
     * 
     * @param schools 
     * @param students 
     */
    EduSys(std::vector<std::shared_ptr<SchoolClass>> &schools, std::vector<std::shared_ptr<Student>> &students){
        for(const auto& newstudent: students){
            _candidates.push_back(newstudent);
        }
        for(const auto& newschool : schools){
            _schools.push_back(newschool);
        }
        
    };

    /**
     * @brief znajduje szukanego studenta
     * 
     * @param name 
     * @return std::shared_ptr<Student> 
     */
    std::shared_ptr<Student> findStudent(std::string name){
        std::shared_ptr<Student> temp;
        return temp;
    }

    /**
     * @brief drukuje szkoly
     * 
     */
    void printPlaces(){
        
    }

    /**
     * @brief drukuje kandydatow
     * 
     */
    void printApplicants(){

    }

protected:
    std::vector<std::shared_ptr<SchoolClass>> _schools;
    std::vector<std::shared_ptr<Student>> _candidates;
};