#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include <chrono>
#include <iostream>
#include <string>

//dynamically allocated array of objects of type T
namespace seneca{
    template <typename T>
    class Collection{
        T *m_items{nullptr};
        size_t m_num{};
        std::string m_name{};
        //functio pointer 跟int pointer一樣
        //a pointer to a function that returns void and receives two parameters of type const Collection<T>& and const T& in that order.
        void (*informAdded)(const Collection<T>& , const T& ){nullptr};
        public:
        Collection()=default;
        Collection(const std::string& name){
            if(!name.empty()){
                m_name=name;
            }else{
                m_name="";

            }
            m_num =0;
            m_items=nullptr;
            //function pointer 也要起始
            informAdded=nullptr;
        }
        Collection(const Collection & c)=delete;
        //function pointer  doesn't need to delete
        ~Collection(){
            if(m_items!=nullptr){
                delete[] m_items;
                m_items=nullptr;
            }
        }
        const std::string& name() const{
            return m_name;
        }

        size_t size() const{
            return m_num;
        }

        //stores the address of the callback function (observer) into an attribute. 
        //This parameter is a pointer to a function that returns void and accepts two parameters: a collection and an item that has just been added to the collection. This function is called when an item is added to the collection.
        void setObserver(void (*observer)(const Collection<T>&, const T&)){
            //stores the address of the callback function
            informAdded=observer;

        }
        Collection<T>& operator+=(const T& item){
            //adds a copy of item to the collection, 
            //only if the collection doesn't contain an item with the same title. 
            //If item is already in the collection, this function does nothing. 
            //If the item is not yet in the collection, this function:
            //resizes the array of items to accommodate the new item
            //if an observer has been registered, 
            //this operator calls the observer function passing the current object (*this) and the new item as arguments.
            //ASSUMPTION: type T has a member function called title() that returns the title of the item (std::string).
           bool found=false;
           for(size_t i=0; i<m_num;i++){
             if(m_items[i].title()==item.title()){
                found=true;
                break;
             }
           }
           //not found
            if (!found){
                //temp to store item 
                T *temp =new T[m_num+1];
                for (size_t i =0; i< m_num; i++){
                    temp[i]=m_items[i];
                }
                temp[m_num]=item;
                //delete m_items 
                delete[] m_items;
                m_items=temp;
                m_num +=1;
                //first arg is Collection ,
                if (informAdded!=nullptr){
                    informAdded(*this,item);
                } 
            }
            return *this;
        }
        T& operator[](size_t idx) const{
            if(m_num-1<idx){
               throw std::out_of_range("Bad index [" + std::to_string(idx) +
                              "]. Collection has [" + std::to_string(m_num) +
                              "] items.");
            }else{
                return m_items[idx];
            }
        }

        T *operator[](const std::string &title) const {
            for (size_t i = 0; i < m_num; i++) {
            if (m_items[i].title() == title) {
                return &m_items[i];
            }
            }
            return nullptr;
        };


        friend std::ostream &operator<<(std::ostream &os, const Collection &c){
            for(size_t i=0; i<c.m_num;i++){
                os<<c.m_items[i];
            }
            return os;
        }
    };

}


#endif