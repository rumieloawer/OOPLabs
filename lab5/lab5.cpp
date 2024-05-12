#include <iostream>
#include <string>
using namespace std;

class Worker {
private:
    string name;
    string last_name;
    int age;
    string job;
public:

    Worker() {
        cout << "Default constructor!" << endl;
    }

    Worker(string n, string l, int a, string j): name(n), last_name(l), age(a), job(j) {
        cout << "Constructor whit parameters!" << endl;
    }

    ~Worker() {
        cout << "Destructor working" << endl;
    }

    string operator [](int index) const
    {
        return index == 0 ? name : last_name;
    }

    Worker operator()(string job_name) const
    {
        return Worker(name, last_name, age,  job + job_name);
    }

    friend ostream& operator<<(ostream& os, const Worker& worker);
    friend istream& operator>>(istream& is, Worker& worker);
};

ostream& operator<<(ostream& os, const Worker& worker)
{
    os << "Name: " << worker.name << "; Last name: " << worker.last_name << "; Age: " << worker.age << "; Job: " << worker.job;
    return os;
}

istream& operator>>(istream& is, Worker& worker) {
    cout << "Enter name: ";
    is >> worker.name;
    cout << "Enter last name: ";
    is >> worker.last_name;
    cout << "Enter age: ";
    is >> worker.age;
    cout << "Enter job: ";
    is >> worker.job;
    return is;
};

int main() {
    Worker worker1("Oleg", "Zelenskii", 19, "");
    worker1 = worker1("Developer");
    cout << worker1 << endl;
    cin >> worker1;
    cout << worker1 << endl;
    return 0;
}
