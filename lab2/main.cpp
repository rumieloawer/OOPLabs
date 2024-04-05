#include <iostream>

using namespace std;

class Time {
private:
    int hours = NULL;
    int minutes = NULL;
    int seconds = NULL;
    const int ERA = 23;
    const int TIME_M_S = 59;
    const int ZERO = 0;

    bool check_time(int hours, int minutes, int seconds) {
                if (hours >= ZERO && hours <= ERA && minutes >= ZERO && minutes <= TIME_M_S && seconds >= ZERO && seconds <= TIME_M_S) {
            return true;
        } else {
            cout << "Error: Invalid time values" << endl;
            return false;
        }
    }

public:
    Time(int h, int m, int s) {
        if (check_time(h, m, s)) {
            hours = h;
            minutes = m;
            seconds = s;
        }
    }

    int getHours() {
        return hours;
    }

    int getMinutes() {
        return minutes;
    }

    int getSeconds() {
        return seconds;
    }

    void setTime(int h, int m, int s) {
        if (check_time(h, m, s)) {
            hours = h;
            minutes = m;
            seconds = s;
        }
    }

    void displayTime() {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }
};

int main() {
    Time time1(12, 30, 45);
    time1.displayTime();
    return 0;
}
