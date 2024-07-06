#include "Directory.h"


namespace seneca{

    Directory::Directory(const std::string & name){
        if (name.back() != '/') {
            m_name = name + "/";
        } else {
            m_name = name;
        }  
        };

        //sets the parent path to the parameter. For each resource that this directory holds,
        // this member should also set their absolute path locations to the full absolute path of this directory.
    void Directory::update_parent_path(const std::string &path){
            // see th w6_p1.cpp 
            m_parent_path = path;
            for (auto & resource : m_contents) {
                resource->update_parent_path(m_parent_path + m_name);
            }
    }

        Directory::~Directory() {
        for (auto resource : m_contents) {
            delete resource;
        }
    }

     std::string Directory::name() const  {
        return m_name;
    }
    
    //: a query that returns Flags::DIR.
    NodeType Directory::type() const{
        return NodeType::DIR;
    }
    
    //
    size_t Directory::size() const{
        // is the sum of the individual sizes of each resource
        size_t sum =0;
        //This member returns 0u if the directory is empty.
        if(m_contents.empty()){
            //0u means 0;
            return sum;
        }
        for (auto resource : m_contents){
            //like for each loop 
            sum+=resource->size();
        }
        return sum;
    }

    Directory& Directory::operator+=(Resource* r){
        //This member should check for existing resources in the directory with the same name:
       if(!find(r->name(),{OpFlags::RECURSIVE})){
        //f no match is found, add the resource and update the absolute path location of the
        //added resource with the directory's full absolute path.
        //put r in m_content vectotr push_back
        //沒有找到符合的放到陣列裡
            m_contents.push_back(r);
        //原先加進去的 r 要更新他
           r->update_parent_path(m_parent_path + m_name);
       }else {
        // 如果找到匹配项，抛出异常
        throw std::runtime_error("Resource with the same name already exists");
     }
        return *this;
    }
     Resource *Directory::find(const std::string & name, const std::vector<OpFlags> & flags){
            //no flags
            if(flags.empty()){
                for (auto resource :m_contents){
                    //directory whose name matches the given string 
                    if(resource->name()==name){
                        //return address beacause Vector* 
                        return resource;
                    }
                }
                return nullptr ;

            }
            // have flags
            //weird..........
            if(flags[0]==OpFlags::RECURSIVE){
                for (auto resource :m_contents){
                    //directory whose name matches the given string 
                    if(resource->name()==name){
                        //return address beacause Vector* 
                        return resource;
                    }else if(resource->type()==NodeType::DIR){
                        //recursive
                        //fuck there is no find() in Resource.h
                        // resource->find(name,flags);
                        // resource pointer should become Directory pointer. 
                        // doesn't teach this shit
                         return dynamic_cast<Directory *>(resource)->find(name, flags);
                    }
                }
               
            }
             return nullptr;
    }
     int Directory::count() const{
        return m_contents.size();

     }
     std::string Directory::path() const{
         return m_parent_path+m_name;
     }
     
}