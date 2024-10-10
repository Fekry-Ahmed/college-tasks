template <typename T>
class Array {
private:
    T* data;
    int capacity;
    int size;

public:
    Array(int cap = 10) : capacity(cap), size(0) {
        data = new T[capacity];
    }

    ~Array() {
        delete[] data;
    }

    void push(T item) {
        if (size == capacity) expand();
        data[size++] = item;
    }

    T get(int index) const {
        if (index < 0 || index > size) throw "Index out of bounds";
       
        return data[index];
    }

    int getSize() const {
        return size;
    }

private:
    void expand() {
        capacity *= 2;
        T* newData = new T[capacity];
        for (int i = 0; i < size; i++) newData[i] = data[i];
        
        delete[] data;
        data = newData;
    }
};
