#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class Error : public exception {
private:
    string message;

public:
    explicit Error(const string& msg) : message(msg) {}

    const char* what() const noexcept override {
            return message.c_str();
    }
};

template<typename T>
class Vector {
private:
    vector<T> elements;

public:
    Vector(const vector<T>& elems) : elements(elems) {}

    T& operator[](size_t index) {
        if (index >= elements.size()) {
            throw Error("Index out of range");
        }
        return elements[index];
    }

    const T& operator[](size_t index) const {
        if (index >= elements.size()) {
            throw Error("Index out of range");
        }
        return elements[index];
    }

    size_t size() const {
        return elements.size();
    }

    Vector<T> operator*(const Vector<T>& other) const {
        if (elements.size() != other.size()) {
            throw Error("Vectors must be of the same size for multiplication");
        }
        vector<T> result(elements.size());
        for (size_t i = 0; i < elements.size(); ++i) {
            result[i] = elements[i] * other[i];
        }
        return Vector<T>(result);
    }

    Vector<T>& operator+(int n) {
        if (n < 0 || static_cast<size_t>(n) >= elements.size()) {
            throw Error("N is out of range");
        }
        for (size_t i = 0; i < elements.size(); ++i) {
            elements[i] += n;
        }
        return *this;
    }

    void print() const {
        for (const auto& elem : elements) {
            cout << elem << " ";
        }
        cout << endl;
    }
};

int main() {
    try {
        Vector<int> vec1({1, 2, 3, 4});
        Vector<int> vec2({5, 6, 7, 8});

        cout << "vec1: ";
        vec1.print();
        cout << "vec2: ";
        vec2.print();

        cout << "vec1[2]: " << vec1[2] << endl;
        cout << "Size of vec1: " << vec1.size() << endl;

        Vector<int> vec3 = vec1 * vec2;
        cout << "vec1 * vec2: ";
        vec3.print();

        vec1 + 1;
        cout << "vec1 + 1: ";
        vec1.print();

        cout << "vec1[10]: " << vec1[10] << endl;

    } catch (const Error& e) {
        cerr << "Error: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "Standard exception: " << e.what() << endl;
    }

    try {
        Vector<double> vec4({1.1, 2.2, 3.3, 4.4});
        Vector<double> vec5({5.5, 6.6, 7.7, 8.8});

        cout << "vec4: ";
        vec4.print();
        cout << "vec5: ";
        vec5.print();

        cout << "vec4[2]: " << vec4[2] << endl;
        cout << "Size of vec4: " << vec4.size() << endl;

        Vector<double> vec6 = vec4 * vec5;
        cout << "vec4 * vec5: ";
        vec6.print();

        vec4 + 1;
        cout << "vec4 + 1: ";
        vec4.print();

        cout << "vec4[10]: " << vec4[10] << endl;

    } catch (const Error& e) {
        cerr << "Error: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "Standard exception: " << e.what() << endl;
    }

    return 0;
}
