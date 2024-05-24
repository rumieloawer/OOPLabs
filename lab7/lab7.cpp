#include <iostream>

using namespace std;

class Pair {
protected:
    int a, b;

public:
    Pair(int a, int b) : a(a), b(b) {}

    bool operator==(const Pair &other) const {
        return (a == other.a) && (b == other.b);
    }

    bool compareProducts(const Pair &other) const {
        return (a * b) == (other.a * other.b);
    }

    Pair operator-(const Pair &other) const {
        return Pair(a - other.a, b - other.b);
    }

    friend ostream &operator<<(ostream &os, const Pair &pair) {
        os << "Pair(" << pair.a << ", " << pair.b << ")";
        return os;
    }
};

class Rational : public Pair {
public:
    Rational(int a, int b) : Pair(a, b) {}

    Rational operator+(const Rational &other) const {
        return Rational(a * other.b + other.a * b, b * other.b);
    }

    Rational operator/(const Rational &other) const {
        if (other.a == 0) {
            throw invalid_argument("Cannot divide by a Rational number with numerator 0");
        }
        return Rational(a * other.b, b * other.a);
    }

    Rational operator-(const Rational &other) const {
        return Rational(a * other.b - other.a * b, b * other.b);
    }
};

void demonstrateSubstitution(Pair *baseObj) {

    cout << "Original object: " << *baseObj << endl;
    Pair resultSub = *baseObj - Pair(1, 1);
    cout << "Subtraction result: " << resultSub << endl;

    const Rational *rationalObj = dynamic_cast<const Rational *>(baseObj);
    if (rationalObj) {
        Rational resultAdd = *rationalObj + Rational(1, 1);
        Rational resultDiv = *rationalObj / Rational(1, 1);
        Rational resultSubRational = *rationalObj - Rational(1, 1);
        cout << "Addition result: " << resultAdd << endl;
        cout << "Division result: " << resultDiv << endl;
        cout << "Subtraction result (Rational): " << resultSubRational << endl;
    }
}

int main() {
    Pair pairInstance(5, 3);
    Rational rationalInstance(5, 3);

    demonstrateSubstitution(&pairInstance);
    demonstrateSubstitution(&rationalInstance);

    return 0;
}