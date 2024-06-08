// template
#ifndef SENECA_ORDERCOLLECTION_H
#define SENECA_ORDERCOLLECTION_H

namespace seneca
{
    template <typename T>
    class OrderedCollection : public Collection<T, 72>
    {
    public:
        bool operator+=(const T &item)
        {
            if (this->size() == this->capacity())
            {
                return false;
            }
            else
            {
                for (unsigned int i = 0; i < this->size(); i++)
                {
                    if (this->m_items[i] > item)
                    {
                        // 換
                        for (unsigned int j = this->size(); j > i; j--)
                        {
                            // 現在的往後一格
                            this->m_items[j] = this->m_items[j - 1];
                        }
                        this->m_items[i] = item;
                        this->setSmallestItem(item);
                        this->setLargestItem(item);
                        this->incrSize();
                        return true;
                    }
                }

                this->m_items[this->size()] = item;
                this->setSmallestItem(item);
                this->setLargestItem(item);
                this->incrSize();

                return true;
            }
        }
    };
}
#endif