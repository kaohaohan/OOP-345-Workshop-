#include "Filesystem.h"
#include <fstream>
#include "File.h"
namespace seneca{
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
    //first arg is a file and second is a name of the root directory 
       Filesystem::Filesystem(const std::string& fileName, const std::string& rootName ){
        std::ifstream file(fileName);
         if(!file){
            throw std::invalid_argument(
                "Filesystem not created with invalid filename."
            );
         }
        
        m_root = new Directory(rootName); 
        //current root
        m_current = m_root;

        std::string line;
        while(std::getline(file,line)){ 
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
                Directory * current =m_root;
                for(auto n:names){
                    std::cout<<n;
                    if(n.find("/")!=std::string::npos){
                        //is dictory 
                        Directory* subDir =
                        dynamic_cast<Directory*>(current->find(n));

                        if(subDir==nullptr){
                            subDir = new Directory(n);
                            *current+= subDir;
                        }
                        current=subDir;
                    }else{
                        File *file=new File(n,fileContent);
                        *current+=file;
                    }
                }
                
            }else{
                 std::vector<std::string> names=splitPath(line);
                Directory * current =m_root;
                 for (auto n:names){
                     Directory* subDir =
                        dynamic_cast<Directory*>(current->find(n));

                        if(subDir==nullptr){
                            subDir = new Directory(n);
                            *current+= subDir;
                        }
                        current=subDir;
                 }
            }
        }
       }

    Filesystem& Filesystem::operator+=(Resource* r){
        //target of pointer 
        *m_current+=r;
        return *this;
    }

    Directory*  Filesystem::change_directory(const std::string& directory){
        if(directory.empty()){
            m_current=m_root;
        } else {
            Directory * target=
                    dynamic_cast<Directory*>(m_current->find(directory,{OpFlags::RECURSIVE}));
            if(target){
            m_current =target;
            } else{
                throw std::invalid_argument("Cannot change directory! DIR_NAME not found!");
            }
        }
        
        return m_current;
    }

     Directory* Filesystem::get_current_directory() const{
        return m_current;
     }


     Filesystem::~Filesystem(){
        delete m_root;
        m_root=nullptr;
        m_current=nullptr;
     }

      Filesystem::Filesystem(Filesystem &&other){
         *this=std::move(other);
      }
       Filesystem &Filesystem::operator=(Filesystem && other){
            if(this!=&other){
                delete m_root;
                m_root =other.m_root;
                delete m_current;
                m_current=other.m_current;
                other.m_root=nullptr;
                other.m_current=nullptr;
            }
           
            return *this;
       }
}
