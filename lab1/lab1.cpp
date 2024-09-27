#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

const char *FILE_NAME = "info.dat";
const char MAX_NUM = 13;
const int MAXLEN = 255;
#pragma pack(push, 1)

struct Student {
    char surname[MAXLEN];
    char group_number[MAXLEN];
    char address[MAXLEN];
    char phone_number[MAX_NUM];
};

#pragma pack(pop)

Student arr[MAXLEN];
int student_index = 0;
int menu();
void readFromFile(const char *fileName);
void saveToFile(const char *fileName);
void addNew();
void del();
void sort_data();
void print_students();
void modify();

int main() {
    while (true) {
        switch (menu()) {
            case 1:
                readFromFile(FILE_NAME);
                break;
            case 2:
                saveToFile(FILE_NAME);
                break;
            case 3:
                addNew();
                break;
            case 4:
                del();
                break;
            case 5:
                sort_data();
                break;
            case 6:
                modify();
                break;
            case 7:
                return 0;
            default:
                cout << "Wrong choice!" << endl;
        }
    }
}

int menu() {
    cout << "\n" << "Choose\n" << "1-For look up from a file\n" << "2-To write to a file\n" << "3-To add a record\n"
         << "4-To delete the record\n" << "5-To sort by surname\n" << "6-To change record\n" << "7-To exit\n" << "\n"
         << "Your choice: ";

    char ans_char[MAXLEN];
    int ans;
    cin.getline(ans_char, MAXLEN);
    ans = stoi(ans_char);
    return ans;
}

void saveToFile(const char *fileName) {
    ofstream f;
    f.open(fileName, ios::binary);
    f.write((char *) arr, sizeof(Student) * student_index);
    f.close();
    cout << "The entered data is saved to a file\n";
}

void readFromFile(const char *fileName) {
    ifstream f;
    f.open(fileName, ios::binary);

    if (!f) {
        cout << "The file does not exist";
    }
    else {
        Student stud;
        student_index = 0;
        while (true) {
            f.read((char *) &stud, sizeof(stud));
            if (f.eof())
                break;
            arr[student_index] = stud;
            student_index++;
        }
        f.close();
        cout << "Data read from file\n";
        print_students();
    }
}

void addNew() {
    cout << "Adding a new record\n\n";
    cout << "Record number " << student_index + 1 << "\n";
    cout << "Enter your surname: ";
    cin.getline(arr[student_index].surname, MAXLEN);
    cout << "Enter the group number: ";
    cin.getline(arr[student_index].group_number, MAXLEN);
    cout << "Enter the address: ";
    cin.getline(arr[student_index].address, MAXLEN);
    cout << "Enter a phone number: ";
    cin.getline(arr[student_index].phone_number, MAX_NUM);

    student_index++;
    cout << "\n";
    print_students();
}

void del() {
    char student_number_str[MAXLEN];
    int student_number;

    cout << "Select the record number to be deleted: ";
    cin.getline(student_number_str, MAXLEN);
    student_number = stoi(student_number_str);

    if (student_number < 0 || student_number > student_index) {
        cout << "Wrong index!";
        return NULL;
    }

    for (int i = student_number - 1; i < student_index; i++) {
        arr[i] = arr[i + 1];
    }
    student_index--;

    cout << "\n";
    print_students();
}

bool compare_by_surname(const Student &stud1, const Student &stud2) {
    return strcmp(stud1.surname, stud2.surname) < 0;
}

void sort_data() {
    sort(begin(arr), begin(arr) + student_index, compare_by_surname);
    print_students();
}

void print_students() {
    for (int i = 0; i < student_index; i++) {
        cout << i + 1 << "\t" << arr[i].surname << "\t"
             << arr[i].group_number << "\t"
             << arr[i].address << "\t"
             << arr[i].phone_number << endl;
    }
    cout << "\n";
}

void get_input(const char* message, char* destination, int maxLength) {
    cout << message;
    cin.getline(destination, maxLength);
}

void modify() {
    char student_number_str[MAXLEN];
    int student_number;

    cout << "Select Student id you want to change\n";
    cin.getline(student_number_str, MAXLEN);
    student_number = stoi(student_number_str);

    student_number--;

    getInput("Enter your surname: ", arr[student_number].surname, MAXLEN);
    getInput("Enter the group number: ", arr[student_number].group_number, MAXLEN);
    getInput("Enter the address: ", arr[student_number].address, MAXLEN);
    getInput("Enter a phone number: ", arr[student_number].phone_number, MAX_NUM);

    cout << "\n";
    print_students();
}