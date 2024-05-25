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
        int index = 0;
        string currentSequence = "";
        // bool newSequence = false;
        // deal with "> "
        while (getline(file, line)) {
            cout << "Reading line: " << line << endl;
            if (line.empty()) {
            continue;
            }
            if (line[0] != '>') {
            //+=ATGCGTA....etra..
            currentSequence += line;
            } else {
            if (!currentSequence.empty()) {
                sequences[index] = currentSequence;
                 cout << "Stored sequence " << index << ": " << sequences[index] << endl; // 调试输出存储的序列
                currentSequence.clear();
                index++;
            }
            }
        }
        if (!currentSequence.empty() && index < numSequences) {
        sequences[index] = currentSequence;
}
     }
     file.close();

    }


    size_t ProteinDatabase::size() const{
         return numSequences;
    }

    string ProteinDatabase::operator[](size_t index) const{
        if(index<numSequences){
            return sequences[index];
        }
        return "";
    } 
    
    // rule of three
    ProteinDatabase::~ProteinDatabase() {
    if(sequences){
        delete[] sequences;
        sequences =nullptr; 
    }
    }
    
    ProteinDatabase::ProteinDatabase(const ProteinDatabase &other) {
        *this = other;
    }
    
    ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& other){
        if(this !=&other){
            if (other.numSequences==0){
                numSequences=0;
                return *this;
            }
            numSequences=other.numSequences;
            if(sequences){
                delete [] sequences;
            sequences = new string[other.numSequences];
                for (int i=0; i< numSequences;i++){
                    sequences[i]=other.sequences[i];
                }
            }
        }
        return *this;
    }




}