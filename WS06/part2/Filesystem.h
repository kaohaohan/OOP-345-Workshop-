#ifndef SENECA_FILESYSTEM_H
#define SENECA_FILESYSTEM_H
#include "Resource.h"
#include <string>
#include <vector>
#include "Directory.h"

namespace seneca{
    class Filesystem{
        Directory * m_root{};
        Directory* m_current{};
        public:
        Filesystem()=default;
        Filesystem(const std::string& fileName, const std::string& rootName="" );
        Filesystem& operator+=(Resource*);
        Directory* change_directory(const std::string& d ="");
        Directory* get_current_directory() const;
        ~Filesystem();

        //this module supports move operations.
        Filesystem(const Filesystem &) = delete;
        Filesystem(Filesystem &&other);
        Filesystem &operator=(Filesystem &&);
        
    };
}

#endif
