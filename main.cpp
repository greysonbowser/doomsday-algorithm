#include <iostream>
#include <cmath>
#include <string>

void initialize(int &MM, int &DD, int &YYYY);
void algo(int MM, int DD, int YYYY, int &doomsday);
std::string dayOfWeek(int doomsday);

int main() {
    int MM, DD, YYYY, doomsday;
    do {
        initialize(MM, DD, YYYY);
    } while (MM > 12 || DD > 31);

    algo(MM, DD, YYYY, doomsday);
    std::string day = dayOfWeek(doomsday);
    std::cout << MM << "/" << DD << "/" << YYYY << " is a " << day << std::endl;
    return 0;
}

void initialize(int &MM, int &DD, int &YYYY) {
    std::cout << "Enter a valid date using the format MM/DD/YYYY: " << std::endl;
    char slash;
    std::cin >> MM >> slash >> DD >> slash >> YYYY;
}

void algo(int MM, int DD, int YYYY, int &doomsday) {
    int century = YYYY / 100;
    int centuryAnchor;
    switch (century % 4) {
        case 0: centuryAnchor = 2;
            break;
        case 1: centuryAnchor = 0;
            break;
        case 2: centuryAnchor = 5;
            break;
        case 3: centuryAnchor = 3;
            break;
    }
    int yearPart = YYYY % 100;
    int yearContribution = (yearPart / 12) + (yearPart % 12) + ((yearPart % 12) / 4);
    int baseDoomsday = (centuryAnchor + yearContribution) % 7;
    int monthDoomsday;
    switch (MM) {
        case 1: monthDoomsday = (YYYY % 4 == 0 && (YYYY % 100 != 0 || YYYY % 400 == 0)) ? 4 : 3;
            break;
        case 2: monthDoomsday = (YYYY % 4 == 0 && (YYYY % 100 != 0 || YYYY % 400 == 0)) ? 29 : 28;
            break;
        case 3: monthDoomsday = 14;
            break;
        case 4: monthDoomsday = 4;
            break;
        case 5: monthDoomsday = 9;
            break;
        case 6: monthDoomsday = 6;
            break;
        case 7: monthDoomsday = 11;
            break;
        case 8: monthDoomsday = 8;
            break;
        case 9: monthDoomsday = 5;
            break;
        case 10: monthDoomsday = 10;
            break;
        case 11: monthDoomsday = 7;
            break;
        case 12: monthDoomsday = 12;
            break;
        default: monthDoomsday = 0;
            break;
    }
    doomsday = (baseDoomsday + (DD - monthDoomsday)) % 7;
    if (doomsday < 0) doomsday += 7;
}

std::string dayOfWeek(int doomsday) {
    switch (doomsday) {
        case 0: return "Sunday";
        case 1: return "Monday";
        case 2: return "Tuesday";
        case 3: return "Wednesday";
        case 4: return "Thursday";
        case 5: return "Friday";
        case 6: return "Saturday";
        default: return "Error";
    }
}
