// template
#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H
#include <iomanip>
#include <string>
#include <iostream>
#include "Book.h"

namespace seneca
{
    template <typename T, unsigned int C>

    class Collection
    {
    private:
        T m_items[C];
        unsigned int m_size = 0;
        unsigned int m_capacity = C;
        static T m_smallestItem;
        static T m_largestItem;

    protected:
        void setSmallestItem(const T &item)
        {
            if (item < m_smallestItem)
            {
                m_smallestItem = item;
            }
        };
        void setLargestItem(const T &item)
        {
            if (item > m_largestItem)
            {
                m_largestItem = item;
            }
        };

    public:
        T getSmallestItem()
        {
            return m_smallestItem;
        };
        T getLargestItem()
        {
            return m_largestItem;
        };

        unsigned int size()
        {
            return m_size;
        };

        unsigned int capacity()
        {
            return m_capacity;
        }
        bool operator+=(const T &item)
        {
            if (size() == capacity())
            {
                return false;
            }
            else
            {
                setSmallestItem(item);
                setLargestItem(item);
                // adds the received object as a new item to the end of the collection of the collection.

                m_items[m_size] = item;
                // updates the size of the collection (number of items stored).
                m_size += 1;
                return true;
            }
        }
        std::ostream &print(std::ostream &os)
        {

            os << "[";
            for (unsigned i = 0; i < m_size; i++)
            {
                if (i > 0)
                {
                    os << ", ";
                }
                os << m_items[i];
            }
            os << "]" << std::endl;
            return os;
        };
    };
    // initialize it t
    template <typename T, unsigned C>
    T Collection<T, C>::m_smallestItem = T(9999);

    template <typename T, unsigned C>
    T Collection<T, C>::m_largestItem = T(-9999);

    // Specialization for Book with capacity 10

    template <>
    class Collection<Book, 10>
    {
    private:
        Book m_items[10];
        unsigned int m_size = 0;
        unsigned int m_capacity = 10;
        static Book m_smallestItem;
        static Book m_largestItem;

    protected:
        void setSmallestItem(const Book &item)
        {
            if (item < m_smallestItem)
            {
                m_smallestItem = item;
            }
        };
        void setLargestItem(const Book &item)
        {
            if (item > m_largestItem)
            {
                m_largestItem = item;
            }
        };

    public:
        Book getSmallestItem()
        {
            return m_smallestItem;
        };
        Book getLargestItem()
        {
            return m_largestItem;
        };

        unsigned int size()
        {
            return m_size;
        };

        unsigned int capacity()
        {
            return m_capacity;
        }
        bool operator+=(const Book &item)
        {
            if (size() == capacity())
            {
                return false;
            }
            else
            {
                setSmallestItem(item);
                setLargestItem(item);
                // adds the received object as a new item to the end of the collection of the collection.

                m_items[m_size] = item;
                // updates the size of the collection (number of items stored).
                m_size += 1;
                return true;
            }
        }
        std::ostream &print(std::ostream &os)
        {

            os << "[";
            for (unsigned i = 0; i < m_size; i++)
            {
                if (i > 0)
                {
                    os << ", ";
                }
                os << m_items[i];
            }
            os << "]" << std::endl;
            return os;
        };
    };
    Book
        Collection<Book, 10>::m_smallestItem = Book("", 1, 10000);
    Book
        Collection<Book, 10>::m_largestItem = Book("", 10000, 1);

}

#endif