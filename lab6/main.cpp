#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include "time.cpp"

using namespace std;

class Logger {
public:
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    void addRecord(const Time& time) {
        string record = "Name: " + time.name + "\n";
        record += "Hours: " + to_string(time.getHours()) + "\n";
        record += "Minutes: " + to_string(time.getMinutes()) + "\n";
        record += "Seconds: " + to_string(time.getSeconds()) + "\n";
        records.push_back(record);
    }

    void saveLog() {
        ofstream file("log.txt");
        if (file.is_open()) {
            time_t now = time(0);
            char* dt = ctime(&now);

            file << "ClassName: Time\n";
            file << "NumberOfEntities: " << Time::instance_count << "\n";
            file << "Time: " << dt << "\n";

            for (const auto& record : records) {
                file << record << "\n";
            }

            file.close();
            cout << "Log saved to log.txt\n";
        } else {
            cerr << "Unable to open file";
        }
    }

private:
    Logger() {}
    vector<std::string> records;
};

int main() {
    Time t1("Time1", 12, 30, 45);
    Time t2("Time2", 10, 15, 20);

    t1.display();
    t2.display();

    Logger& logger = Logger::getInstance();
    logger.addRecord(t1);
    logger.addRecord(t2);

    logger.saveLog();

    return 0;
}
