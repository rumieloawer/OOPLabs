#include <iostream>
#include <string>

using namespace std;

class Dish {
private:
    string name;
    string dish_type;
    int cooking_time;

public:

    Dish() {
        name = "air fried with sesame seeds in soy sauce";
        dish_type = "edible";
        cooking_time = 60;

        cout << "default constructor" << endl;
    }

    Dish(string n, string dt, int ct = 0) : name(n), dish_type(dt), cooking_time(ct) {
        cout << "constructor with parameters" << endl;
    }

    Dish(const Dish &other) : name(other.name), dish_type(other.dish_type), cooking_time(other.cooking_time) {
        cout << "copy constructor" << endl;
    }

    void get_dish_info() {
        cout << "Name: " << name << "\nType: " << dish_type << "\nCooking time: " << cooking_time << endl;
    }

    ~Dish() {
        cout << "destructor is working" << endl;
    }
};


int main() {
    Dish air = Dish();
    Dish borsch = Dish("borsch", "main dish", 180);
    Dish borsch2 = borsch;
    return 0;
}
