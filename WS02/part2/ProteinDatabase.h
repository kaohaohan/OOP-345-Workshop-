#ifndef SENECA_PROTEINDATABASE_H
#define SENECA_PROTEINDATABASE_H
#include <chrono>
#include <iostream>
namespace seneca{
    class ProteinDatabase {
    std::string* sequences=nullptr; 
    size_t numSequences{};   
    void loadFromFile(const char* filename);

public:
    //a no-argument default constructor
    ProteinDatabase() = default; 
    //a 1-argument constructor that receives 
    ///as parameter a string containing the name of a file from which this member function populates the current object. 

    ProteinDatabase(const char* filename); 
    
    //query using const 
    size_t size() const; 
    std::string operator[](size_t index) const; 

    ~ProteinDatabase(); 
    // rule of three
    ProteinDatabase(const ProteinDatabase& filename);
    ProteinDatabase &operator=(const ProteinDatabase& p);
    //rule of five
    ProteinDatabase(ProteinDatabase && p);
    ProteinDatabase &operator=(ProteinDatabase&& p);
 
};
}


#endif