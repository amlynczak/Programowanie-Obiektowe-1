#pragma once
#include<iostream>
#include<vector>

#include"Data.h"

/**
 * @brief pojedynczy element listy
 * 
 */
struct Node{
    Data* data;
    Node* next;
};

/**
 * @brief klasa List przechowujaca zadaną listę
 * 
 */
class List {
    /**
     * @brief operator << potrzebny do wypisywania elementow listy
     * 
     * @param ostrm 
     * @param a 
     * @return std::ostream& 
     */
    friend std::ostream &operator<<(std::ostream &ostrm, const List &a){
        ostrm << "[ ";
        Node* current = a._head;
        while(current != nullptr){
            ostrm << *(current->data) << " ";
            current = current->next;
        }
        ostrm << "]" << std::endl;
        return ostrm;
    };
public:
    /**
     * @brief potrzebny do dzialania enum z Begin i End
     * 
     */
    enum Insertion{Begin, End};

    /**
     * @brief Construct a new List object
     * 
     */
    List(): _head(nullptr), _end(nullptr) {};
    /**
     * @brief Destroy the List object
     * 
     */
    ~List();
    /**
     * @brief Construct a new List object using already existing cp object
     * 
     * @param cp 
     */
    List(const List& cp);

    /**
     * @brief dodaje do listy istniejacy juz element klasy Data (defaultowo dodaje na koniec)
     * 
     * @param dat 
     * @param position 
     * @return List& 
     */
    List& insert(Data& dat, Insertion position = End);
    /**
     * @brief dodaje do listy istniejacy element Fraction (default na koniec)
     * 
     * @param frac 
     * @param position 
     * @return List& 
     */
    List& insert(Fraction frac, Insertion position = End);
    /**
     * @brief dodaje do listy element StringData (default na koniec)
     * 
     * @param str 
     * @param position 
     * @return List& 
     */
    List& insert(StringData str, Insertion position = End);
    /**
     * @brief dodaje do listy element CharData
     * 
     * @param c 
     * @param position 
     * @return List& 
     */
    List& insert(CharData c, Insertion position = End);
    /**
     * @brief drukuje zawartosc listy
     * 
     */
    void print()const;
    /**
     * @brief powinno znajdowac rowny dla frac element listy
     * 
     * @param frac 
     * @return Fraction* 
     */
    Fraction *find(Fraction frac)const;
    /**
     * @brief powinno odwracac liste
     * 
     * @return List& 
     */
    List& reverse();
    /**
     * @brief powinno zwracac wektor z przekonwertowanymi z ulamkow na liczby dziesietne elementy listy (elementy typu frac)
     * 
     * @return std::vector<double> 
     */
    std::vector<double> eval()const;

    /**
     * @brief do kopiowania odpowiednich elementow danych typow
     * 
     * @param text 
     * @return List 
     */
    List copy_if(bool text = true)const;


    /**
     * @brief operator = do kopiowania
     * 
     * @param cp 
     * @return List& 
     */
    List& operator=(const List& cp);

private:
    /**
     * @brief _head - poczatek listy, _end - koniec listy
     * 
     */
    Node* _head;
    Node* _end;
};