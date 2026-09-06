#ifndef CONTAINER_H
#define CONTAINER_H

#include <string>
#include <stdexcept>

namespace LibrarySystem {

// Generic container used to store Books or Members.
// NOTE: a template class's implementation must live in the header (no matching
// .cpp), since the compiler needs the full definition at each instantiation site.
//
// T is expected to expose getId() (int) and getName() (std::string) so that
// find() can be overloaded to search either by id or by name/title.
template <typename T>
class Container {
private:
    T* data;
    int size;
    int capacity;

    void grow() {
        int newCapacity = (capacity == 0) ? 4 : capacity * 2;
        T* newData = new T[newCapacity];
        for (int i = 0; i < size; ++i) newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    Container() : data(nullptr), size(0), capacity(4) {
        data = new T[capacity];
    }

    // Copy constructor
    Container(const Container<T>& other) : data(nullptr), size(other.size), capacity(other.capacity) {
        data = new T[capacity];
        for (int i = 0; i < size; ++i) data[i] = other.data[i];
    }

    // Assignment operator
    Container<T>& operator=(const Container<T>& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];
            for (int i = 0; i < size; ++i) data[i] = other.data[i];
        }
        return *this;
    }

    ~Container() {
        delete[] data;
        data = nullptr;
    }

    void add(const T& item) {
        if (size >= capacity) grow();
        data[size++] = item;
    }

    bool removeAt(int index) {
        if (index < 0 || index >= size) return false;
        for (int i = index; i < size - 1; ++i) data[i] = data[i + 1];
        --size;
        return true;
    }

    // Overloaded find() - search by ID
    int find(int id) const {
        for (int i = 0; i < size; ++i) {
            if (data[i].getId() == id) return i;
        }
        return -1;
    }

    // Overloaded find() - search by name/title
    int find(const std::string& name) const {
        for (int i = 0; i < size; ++i) {
            if (data[i].getName() == name) return i;
        }
        return -1;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) throw std::out_of_range("Container index out of range");
        return data[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= size) throw std::out_of_range("Container index out of range");
        return data[index];
    }

    int getSize() const { return size; }
    bool isEmpty() const { return size == 0; }
};

} // namespace LibrarySystem

#endif // CONTAINER_H
