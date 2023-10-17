#pragma once
#include<iostream>
#include<list>
#include<algorithm>
#include<iterator>

/**
 * @brief template klasy customList
 * 
 * @tparam T 
 */
template<typename T> class CustomList : public std::list<T>{
public:
    /**
     * @brief drukowanie elementow listy
     * 
     */
    void print()const{
        for (auto const &i: _list){
            std::cout << i << " ";
        }
        std::cout<<std::endl;
    };

    /**
     * @brief push na fronta wartosci wal
     * 
     * @param val 
     * @return CustomList<T>& 
     */
    CustomList<T>& push_front(T val){
        _list.push_front(val);
        return *this;
    };

    /**
     * @brief push na backa wartosci val
     * 
     * @param val 
     * @return CustomList<T>& 
     */
    CustomList<T>& push_back(T val){
        _list.push_back(val);
        return *this;
    };

    /**
     * @brief pop front
     * 
     * @return CustomList<T>& 
     */
    CustomList<T>& pop_front(){
        _list.pop_front();
        return *this;
    };

    /**
     * @brief sprawdza, czy val jest na liscie
     * 
     * @param val 
     * @return true 
     * @return false 
     */
    bool contains(T val){
        return true;
    };

    /**
     * @brief znajduje wartosic val w liscie
     * 
     * @param val 
     * @return std::list<T>::iterator 
     */
    typename std::list<T>::iterator find(T val){
        return std::find(this->begin(), this->end(), val);
    };

    /**
     * @brief usuwa dany element z listy
     * 
     * @param it 
     * @return CustomList<T>& 
     */
    CustomList<T>& erase(typename std::list<T>::iterator it){
        _list.erase(it);
        return *this;
    };

    /**
     * @brief odwraca liste
     * 
     * @return CustomList<T> 
     */
    CustomList<T> copy_reversed()const{
        return *this;
    };

    /**
     * @brief usuwa duplikaty
     * 
     * @return CustomList<T>& 
     */
    CustomList<T>& removeDuplicates(){
        return *this;
    };

    /**
     * @brief sumuje wartosci listy
     * 
     * @return T 
     */
    T sumAll(){
        T sum;
        return sum;
    };

    /**
     * @brief opeartor << do drukowania
     * 
     * @param ostr 
     * @param a 
     * @return std::ostream& 
     */
    friend std::ostream &operator<<(std::ostream &ostr, const CustomList &a){
        a.print();
        return ostr;
    };

    /**
     * @brief operator[]
     * 
     * @param it 
     * @return const T 
     */
    const T operator[](typename std::list<T>::iterator it){
        T ret;
        return ret; 
    };

    /**
     * @brief reverse do obracania listy
     * 
     * @return CustomList<T>& 
     */
    CustomList<T>& reverse(){
        _list.reverse();
        return *this;
    };

protected:
    std::list<T> _list;
};
