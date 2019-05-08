#pragma once
#include <stdexcept>
#include <limits>

template<class T> class stack {
public:
    typedef size_t size_type;
    typedef T& reference;
    typedef const T& const_reference;

    stack() : _size(0), _capacity(0) { 
        _data = new T[_capacity];
    }

    stack(const stack& other) {
       _size = other.size();
       _capacity = calculateGrowth(_size);
       _data = new T[_capacity];

       std::copy(other.data(), other.data() + _size, _data);
    }

    ~stack() {
        if (_data != nullptr) {
            delete[] _data;
            _data = nullptr;
        }
    }

    stack(std::initializer_list<T> list) {
        _size = list.size();
        _capacity = calculateGrowth(_size);
        _data = new T[_capacity];

        std::copy(list.begin(), list.end(), _data);
    }

    reference top() {
        if (_size == 0) {
            throw new std::length_error("stack is empty");
        }
        return _data[_size - 1];
    }

    const_reference top() const {
        return top();
    }

    bool empty() {
        return _size == 0;
    }

    size_type size() const {
        return _size;
    }

    void push(const_reference value) {
        if (_size + 1 > _capacity) {
            reallocate(_size + 1);
        }

        _data[_size] = value;
        ++_size;
    }

    void pop() {
        top().~T();
        --_size;
    }

    T* data() {
        return _data;
    }

    const T* data() const {
        return _data;
    }
private:
    size_type _size;
    size_type _capacity;
    T* _data;

    size_type max_size() const {
        return std::numeric_limits<size_type>::max();
    }

    size_type calculateGrowth(size_type newSize) const {
        if (_capacity > max_size() - _capacity / 2) {
            return newSize;
        }

        const size_type geometric = _capacity * 1.5;

        if (geometric < newSize) {
            return newSize;
        }

        return geometric;
    }

    void reallocate(size_type minSize) {
        const size_type newCapacity = calculateGrowth(minSize);

        T* newData = new T[newCapacity];
        std::copy(_data, _data + _size, newData);
        delete[] _data;

        _data = newData;
        _capacity = newCapacity;
    }
};