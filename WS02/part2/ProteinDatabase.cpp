#include <iostream>
#include <chrono>
#include "ProteinDatabase.h"
#include <cstring>
#include <fstream>

using namespace std;

namespace seneca{
    ProteinDatabase::ProteinDatabase(const char* filename): sequences(nullptr), numSequences(0) {
        loadFromFile(filename);
    }

    void ProteinDatabase::loadFromFile(const char* filename){
        ifstream file(filename);
         if (!file.is_open()) {
            throw runtime_error("Could not open file");
             // 1. Count the number of protein sequences!!!
              }
           string line;
        while (getline(file, line)) {
            if (line.empty()) {
                continue;
            }
            if (line[0] == '>') {
                numSequences++;
            }
        }   
        // If no sequences found, return early
        if (numSequences == 0) {
            file.close();
            return;
        }

        
        //2. deal with sequences and allocated sequences
        sequences = new string[numSequences];
        file.clear();
       
        file.seekg(0); 

        // 3. re-reads the file and loads the protein sequences
        size_t index = 0;
        string currentSequence = "";
        // bool newSequence = false;
        // deal with "> "
        while (getline(file, line)) {
           
            if (line.empty()) {
            continue;
            }
            if (line[0] != '>') {
            //+=ATGCGTA....etra..
            currentSequence += line;
            } else {
            if (!currentSequence.empty()) {
                sequences[index] = currentSequence;
                
                currentSequence.clear();
                index++;
            }
            }
        }
        if (!currentSequence.empty() && index < numSequences) {
        sequences[index] = currentSequence;
        }
   
     file.close();

    }


    size_t ProteinDatabase::size() const{
         return numSequences;
    }

    string ProteinDatabase::operator[](size_t index) const{
        if(index<numSequences && sequences){
            return sequences[index];
        } else {
            return "";
        }

    } 
    
    // rule of three
    ProteinDatabase::~ProteinDatabase() {
    if(sequences){
        delete[] sequences;
        sequences =nullptr; 
    }
    }
    
    ProteinDatabase::ProteinDatabase(const ProteinDatabase & p) {
        *this = p;
    }
    
    ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& p){
        if(this !=&p){
            if (p.numSequences==0){
                numSequences=0;
                return *this;
            }
            
            numSequences=p.numSequences;
            if(sequences){
                delete[] sequences; 
                }
                sequences = new string[p.numSequences];
                for (size_t i=0; i< numSequences;i++){
                    sequences[i]=p.sequences[i];
                    
            }
        }
        return *this;

    }
    ProteinDatabase::ProteinDatabase(ProteinDatabase && p){
        *this =std::move(p);
     }
    ProteinDatabase &ProteinDatabase::operator=(ProteinDatabase&& p){
        if(this!= &p){
            delete[] sequences;
            sequences = p.sequences;
            p.sequences =nullptr;
            numSequences= p.numSequences;
        }
        return *this;
    }


    
}