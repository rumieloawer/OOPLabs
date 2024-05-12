#include <iostream>
#include <string>
using namespace std;

class Vector {
private:
    int length;
    double direction;
    double start_x;
    double start_y;
    double end_x;
    double end_y;

public:
    Vector() {
        length = 5;
        direction = 358.0;
        start_x = 6.0;
        start_y = 8.0;
        end_x = 3.0;
        end_y = 5.0;
    }

    Vector(int len, double dir, double st_x, double st_y, double en_x, double en_y) {
        length = len;
        direction = dir;
        start_x = st_x;
        start_y = st_y;
        end_x = en_x;
        end_y = en_y;
    }

    Vector operator+(const Vector& other) const {
        Vector result;
        result.length = length + other.length;
        return result;
    }

    Vector& operator+=(int number) {
        length += number;
        return *this;
    }

    Vector& operator=(const Vector& other) {
        length = other.length;
        direction = other.direction;
        start_x = other.start_x;
        start_y = other.start_y;
        end_x = other.end_x;
        end_y = other.end_y;
        return *this;
    }

    Vector operator++() {
        Vector result(*this);
        ++result.length;
        return result;
    }

    friend ostream& operator<<(ostream& out, const Vector& vec) {
        cout << "Length: " << vec.length << ", Direction: " << vec.direction
            << ", Starting point: " << vec.start_x << vec.start_y << ", End point: " << vec.end_x << vec.end_y;
        return out;
    }
};

int main() {
    Vector Vector1;
    Vector Vector2(7, 87.0, 3.0, 9.0, 2.0, 8.0);

    cout << "Addition result: " << (Vector1 + Vector2) << endl;

    int number;
    cout << "Enter the number to multiply: ";
    cin >> number;
    Vector1 += number;
    Vector2 += number;
    cout << "The result of multiplication: Vector1 = " << Vector1 << ", Vector2 = " << Vector2 << endl;

    Vector1 = Vector2;
    cout << "Assignment result: Vector1 = " << Vector1 << endl;

    Vector Vector3 = ++Vector1;
    cout << "The result of the increment: Vector3 = " << Vector3 << endl;

    return 0;
}
