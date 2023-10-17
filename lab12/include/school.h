#pragma once
#include"student.h"
#include<iostream>
#include<vector>
#include<memory>

/**
 * @brief deklaracja klasy
 * 
 */
class Student;

/**
 * @brief klasa dla szkoly
 * 
 */
class SchoolClass{
public:
    /**
     * @brief Construct a new School Class object
     * 
     * @param name 
     * @param seats 
     */
    SchoolClass(std::string name, int seats): _name(name), _maxSeats(seats){};

    /**
     * @brief zwraca _name
     * 
     * @return std::string 
     */
    std::string getclass()const;
    /**
     * @brief zwraca maksymalna liczbe miejsc
     * 
     * @return int 
     */
    int getmax()const;
    /**
     * @brief drukuje informacje
     * 
     */
    void print()const;
    /**
     * @brief sprawdza, czy sa wolne miejsca
     * 
     * @return true 
     * @return false 
     */
    bool freeSeats()const;
    /**
     * @brief dodaje studenta do szkoly
     * 
     * @param student 
     */
    void addStudent(std::shared_ptr<Student> student);

    ///na lab12

    /**
     * @brief zwraca liczbe miejsc w szkole
     * 
     * @return int 
     */
    int getlimit()const{
        return _maxSeats;
    }
    /**
     * @brief zmienia liczbe miesce w szkole
     * 
     * @param newLimit 
     */
    void setlimit(int newLimit){
        _maxSeats = newLimit;
    }
    /**
     * @brief zwraca liczbe wolnych miejsc
     * 
     * @return int 
     */
    int getfree()const{
        return (_maxSeats - _accepted.size());
    }
protected:
    std::string _name;
    int _maxSeats;
    std::vector<std::shared_ptr<Student>> _accepted;
};