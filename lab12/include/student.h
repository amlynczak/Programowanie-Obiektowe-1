#pragma once
#include"school.h"
#include<iostream>
#include<vector>
#include<memory>

/**
 * @brief deklaracja klasy
 * 
 */
class SchoolClass;

/**
 * @brief klasa dla uczniow
 * 
 */
class Student{
public:
    /**
     * @brief Construct a new Student object
     * 
     * @param name 
     * @param points 
     * @param schools 
     */
    Student(std::string name, int points, std::vector<std::shared_ptr<SchoolClass>> schools): _name(name), _points(points), _preferred_schools(schools), _acceptedIn(nullptr) {};
    
    /**
     * @brief Construct a new Student object
     * 
     * @param student 
     */
    Student(std::shared_ptr<Student> student): _name(student->getName()), _points(student->getPoints()), _preferred_schools(student->getPreferredSchools()), _acceptedIn(student->getAcceptedSchool()) {};

    /**
     * @brief drukuje info o studencie
     * 
     */
    void print()const;
    /**
     * @brief Get the Name object
     * 
     * @return std::string 
     */
    std::string getName()const;
    /**
     * @brief Get the Points object
     * 
     * @return int 
     */
    int getPoints()const;
    /**
     * @brief Get the Accepted School object
     * 
     * @return std::shared_ptr<SchoolClass> 
     */
    std::shared_ptr<SchoolClass> getAcceptedSchool()const;
    /**
     * @brief Set the Accepted In object
     * 
     * @param school 
     */
    void setAcceptedIn(std::shared_ptr<SchoolClass> school);
    /**
     * @brief Get the Preferred Schools object
     * 
     * @return std::vector<std::shared_ptr<SchoolClass>> 
     */
    std::vector<std::shared_ptr<SchoolClass>> getPreferredSchools()const;

    //lab12 zajecia

    /**
     * @brief rezygnacja ze szkoly
     * 
     */
    void dropout(){

    }
    /**
     * @brief aplikacja do szkoly
     * 
     * @param school 
     */
    void apply(std::shared_ptr<SchoolClass> school){

    }
    /**
     * @brief aplikacja do szkoly
     * 
     * @param schools 
     */
    void apply(std::vector<std::shared_ptr<SchoolClass>> schools){

    }
protected:
    std::string _name;
    int _points;
    std::vector<std::shared_ptr<SchoolClass>> _preferred_schools;
    std::shared_ptr<SchoolClass> _acceptedIn;
};