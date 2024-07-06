#ifndef SENECA_FILE_H
#define SENECA_FILE_H
#include "Resource.h"
#include <string>

namespace seneca
{
    class File:public Resource{
        std::string m_contents;
        public:
         File() = default;
         File(const std::string &name, const std::string &contents = "");
         // sets the parent path to the parameter.
         void update_parent_path(const std::string& path);
         NodeType type() const;
         std::string path() const;
         std::string name() const;
         int count() const;
         size_t size() const; 

    };
} 


#endif