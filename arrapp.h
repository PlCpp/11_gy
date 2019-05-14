#ifndef __ARR_APP
#define __ARR_APP

#include<algorithm>
#include<vector>
#include<iterator>
#include<iostream>

template<class T>
class array_appender
{
    std::vector<T*> arrays;

    public:

        array_appender(T* t, const int& n) {
            for (int i = 0;i < n;++i) arrays.push_back((t+i));
        }

        array_appender(const std::vector<T>& v) {
            for (int i = 0;i < v.size(); ++i) arrays.push_back(&v[i]);
        }

        void append(T* t, const int& n) {
            for (int i = 0; i < n; ++i) arrays.push_back((t+i));
        }

        void append(std::vector<T>& v) {
            for (int i = 0; i < v.size(); ++i) arrays.push_back(&v[i]);
        }

        int size () const {
            return arrays.size();
        }

        const T& at(const int& index) const {
            return *arrays[index];
        }

        T& operator[] (const int& index) const {
            return *arrays[index];
        }

        class iterator : public std::iterator<std::input_iterator_tag, T> {
            array_appender<T>* parent;
            int index;

            public:
                iterator(array_appender<T>* parent , const int& index) {
                    this->parent = parent;
                    this->index = index;
                }

                iterator& operator++() {
                    index++;
                    return *this;
                }

                T& operator*() {
                    return (*parent)[index];
                }

                T& operator->() {
                    return (*parent)[index];
                }

                bool operator==(const iterator& it) const {
                    return parent == it.parent && index == it.index;
                }

                bool operator!=(const iterator& it) const {
                    return !(*this == it);
                }

        };

        iterator begin() {
            return iterator(this, 0);
        }

        iterator end() {
            return iterator(this, size());
        }
};

#endif