#pragma once
#include"customList.h"

/**
 * @brief template klasy UniqList
 * 
 * @tparam T 
 * @tparam S 
 */
template<typename T, bool S> class UniqList : public CustomList<T>{
public:
    /**
     * @brief Construct a new Uniq List object majac na uwadze bool S
     * 
     */
    UniqList(): _uniq(S){};

    /**
     * @brief zwraca pierwszy element w liscie
     * 
     * @return std::list<T>::iterator 
     */
    typename std::list<T>::iterator head(){
        typename std::list<T>::iterator tmp;
        return tmp;
    }

    /**
     * @brief zwraca ostatni element w liscie
     * 
     * @return std::list<T>::iterator 
     */
    typename std::list<T>::iterator tail(){
        typename std::list<T>::iterator tmp;
        return tmp;
    }

protected:
    bool _uniq;
};