#include <iostream>
#include <string>

using namespace std;

class Time {
public:
    static int instance_count;
    string name;

    Time(string name, int hours, int minutes, int seconds)
            : name(name), hours(hours), minutes(minutes), seconds(seconds) {
        ++instance_count;
    }

    ~Time() {
        --instance_count;
    }

    void display() const {
        cout << "Time: " << hours << ":" << minutes << ":" << seconds << endl;
    }

    int getHours() const { return hours; }
    int getMinutes() const { return minutes; }
    int getSeconds() const { return seconds; }

private:
    int hours;
    int minutes;
    int seconds;
};

int Time::instance_count = 0;