#ifndef SENECA_DIRECTORY_H
#define SENECA_DIRECTORY_H
#include "Resource.h"
#include <string>
#include <vector>

namespace seneca{
    class Directory: public Resource{
        //std::vector that holds pointers to Resource objects. 
        //Each element of the vector can either be a Directory or a File.
        std::vector<Resource*> m_contents{};
        public:
        Directory()= default;
        //a custom constructor that receives the name of the directory as a string 
        //and uses it to initialize the Directory object.

        Directory(const std::string &directory);
        ~Directory();
        void update_parent_path(const std::string&);
        NodeType type() const;
        // std::string path() const;
        std::string name() const;
        Resource *find(const std::string &, const std::vector<OpFlags> & = {});
        int count() const;
        std::string path() const;
        size_t size() const;
        Directory& operator+=(Resource*);
    };
}

#endif
