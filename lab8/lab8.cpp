#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Vector {
public:
    virtual ~Vector() {}
    virtual double module() const = 0;
    virtual void printCoordinates() const = 0;
};

class Vector2D : public Vector {
private:
    double x, y;

public:
    Vector2D(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

    double module() const override {
        return sqrt(x * x + y * y);
    }

    void printCoordinates() const override {
        cout << "Vector2D(" << x << ", " << y << ")" << endl;
    }

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }
};

class Vector3D : public Vector {
private:
    double x, y, z;

public:
    Vector3D(double xCoord, double yCoord, double zCoord) : x(xCoord), y(yCoord), z(zCoord) {}

    double module() const override {
        return sqrt(x * x + y * y + z * z);
    }

    void printCoordinates() const override {
        cout << "Vector3D(" << x << ", " << y << ", " << z << ")" << endl;
    }

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    double getZ() const {
        return z;
    }
};

int main() {
    vector<Vector*> vectors;

    vectors.push_back(new Vector2D(3, 4));
    vectors.push_back(new Vector3D(1, 2, 2));

    for (const auto& vec : vectors) {
        vec->printCoordinates();
        cout << "Module: " << vec->module() << endl;
    }

    for (auto& vec : vectors) {
        delete vec;
    }

    return 0;
}
