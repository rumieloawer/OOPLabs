#include <iostream>
#include <vector>

using namespace std;

class Vector {
private:
    vector<int> elements;

public:
    Vector(const vector<int>& elems) : elements(elems) {}

    template<typename T>
    T& access(size_t index) const {
        if (index >= elements.size()) {
            throw out_of_range("Index out of range");
        }
        return const_cast<T&>(elements[index]);
    }

    int& operator[](size_t index) {
        return access<int>(index);
    }

    const int& operator[](size_t index) const {
        return access<const int>(index);
    }

    int size() const {
        return elements.size();
    }

    Vector operator*(const Vector& other) const {
        if (elements.size() != other.size()) {
            throw invalid_argument("Vectors must be of the same size for multiplication");
        }
        vector<int> result(elements.size());
        for (size_t i = 0; i < elements.size(); ++i) {
            result[i] = elements[i] * other[i];
        }
        return Vector(result);
    }

    Vector& operator+(int n) {
        if (n < 0 || static_cast<size_t>(n) >= elements.size()) {
            throw out_of_range("N is out of range");
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
        Vector vec1({1, 2, 3, 4});
        Vector vec2({5, 6, 7, 8});

        cout << "vec1: ";
        vec1.print();
        cout << "vec2: ";
        vec2.print();

        cout << "vec1[2]: " << vec1[2] << endl;

        cout << "Size of vec1: " << vec1.size() << endl;

        Vector vec3 = vec1 * vec2;
        cout << "vec1 * vec2: ";
        vec3.print();

        vec1 + 1;
        cout << "vec1 + 1: ";
        vec1.print();

        cout << "vec1[10]: " << vec1[10] << endl;
    } catch (const out_of_range& e) {
        cerr << "Out of range error: " << e.what() << endl;
    } catch (const invalid_argument& e) {
        cerr << "Invalid argument error: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "Standard exception: " << e.what() << endl;
    }

    return 0;
}
