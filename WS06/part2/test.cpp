#include "Filesystem.h"
#include "fstream"
#include <vector>
#include "Resource.h"
#include "Directory.h"
//pass by refer
void removeSpace(std::string &line){
    if(line.empty()){
        return;
    }
    line.erase(0,line.find_first_not_of(" "));
    line.erase(line.find_last_not_of(" ")+1);
    
}

std::vector<std::string> splitPath(std::string &line){
   std::string currentString;
   std::vector<std::string>  names;

    for(auto c :line){
        //run loop like video/dog/smallDog.png
        //put the each word into currentString at first
        currentString += c; 
       
        if(c=='/'){
            names.push_back(currentString);
            //watch out Final exam will test this.
            currentString.clear();

        }


    }
    //hanlding last word in Filesysem.txt
    //documents/docs/
    if(!currentString.empty()){
    names.push_back(currentString);
    }
  

    return names;
}

int main(){
   std::ifstream file("filesystem.txt");
   std::string line;
   while(std::getline(file, line)){
        
        removeSpace(line);
        // std::cout<<  line<<std::endl;
        if(line.find('|')!=std::string::npos){
            //is a file 
            //line.find('|') return index of line
            std::string filePath = line.substr(0,line.find('|'));
            // cut it from | shit shit
            //in other word, start to | index +1 
            std::string fileContent = line.substr(line.find('|')+1);
            //remove the space
            removeSpace(filePath);
            removeSpace(fileContent);
            //
            // std::cout << filePath << "|"<<fileContent<< std::endl;
            std::vector<std::string> names=splitPath(filePath);

            
            
        }
        

   }
    //
    

}