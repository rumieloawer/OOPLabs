#include <iostream>

using namespace std;

class Time {
private:
    int hours = NULL;
    int minutes = NULL;
    int seconds = NULL;
    const int ERA = 23;
    const int TIME_M_S = 59;

    bool check_time(int check_hours = 0, int check_minutes = 0, int check_seconds = 0){
        if(check_hours != 0){
            if()
        }
    }

    bool check_hours(int checked_hours) {
        if (checked_hours >= 0 && checked_hours <= 23) {
            return true;
        } else {
            cout << "Error: Invalid hours value" << endl;
            return false;
        }
    }

    bool check_minutes(int checked_minutes) {
        if (checked_minutes >= 0 && checked_minutes <= 59) {
            return true;
        } else {
            cout << "Error: Invalid minutes value" << endl;
            return false;
        }
    }

    bool check_seconds(int checked_seconds) {
        if (checked_seconds >= 0 && checked_seconds <= 59) {
            return true;
        } else {
            cout << "Error: Invalid seconds value" << endl;
            return false;
        }
    }

public:
    Time(int h, int m, int s) {
        hours = h ? check_hours(h) : 0;

        minutes = m ? check_minutes(m) : 0;

        seconds = s ? check_seconds(s) : 0;
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

    void setHours(int h) {
        if (check_hours(h)) {
            hours = h;
        }
    }

    void setMinutes(int m) {
        if (check_minutes(m)) {
            minutes = m;
        }
    }

    void setSeconds(int s) {
        if (check_seconds(s))
            seconds = s;
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
