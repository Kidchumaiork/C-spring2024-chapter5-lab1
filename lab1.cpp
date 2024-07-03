#include <iostream>
#include <iomanip>
#include <cstdint>
using namespace std;

int main() {
    int workDays;
    int x = 0;
    uint64_t totalPay = 0;

    cout << "Please enter the number of worked days:\n";
    cin >> workDays;

    if (workDays < 1 || workDays > 60) {
        cout << "Invalid number of days." << "\n";
        do {
            cout << "Enter the number of days again:" << "\n";
            cin >> workDays;
            if (workDays < 1 || workDays > 60) {
                cout << "Invalid number of days." << "\n";
            }
        } while (workDays < 1 || workDays > 60);
    }

    uint64_t salary = 1;
    const int scalingFactor = 100;

    for (int day = 1; day <= workDays; ++day) {
        uint64_t salaryDecimal = salary % scalingFactor;
        uint64_t salaryInteger = salary / scalingFactor;
        cout << "Day: " << day << ", Payment: " << salaryInteger << "." << setw(2) << setfill('0') << salaryDecimal << "\n";
        totalPay += salary;
        salary *= 2;
    }

    uint64_t totalPayDecimal = totalPay % scalingFactor;
    uint64_t totalPayInteger = totalPay / scalingFactor;
    cout << "Total: " << totalPayInteger << "." << setw(2) << setfill('0') << totalPayDecimal << "\n";
    return 0;
}