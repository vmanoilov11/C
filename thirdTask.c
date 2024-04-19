#include <stdio.h>

int isValidDate(int day, int month, int year);
int calculateDayOfWeek(int day, int month, int year);
int isLeapYear(int year);

int main() {
    int day, month, year;
    printf("Въведете ден: ");
    scanf("%d", &day);
    printf("Въведете месец: ");
    scanf("%d", &month);
    printf("Въведете година: ");
    scanf("%d", &year);
    if (!isValidDate(day, month, year)) {
        printf("Невалидна дата!\n");
        return 1;
    }
    int dayOfWeek = calculateDayOfWeek(day, month, year);
    switch (dayOfWeek) {
        case 0:
            printf("Денят на седмицата е: Неделя\n");
            break;
        case 1:
            printf("Денят на седмицата е: Понеделник\n");
            break;
        case 2:
            printf("Денят на седмицата е: Вторник\n");
            break;
        case 3:
            printf("Денят на седмицата е: Сряда\n");
            break;
        case 4:
            printf("Денят на седмицата е: Четвъртък\n");
            break;
        case 5:
            printf("Денят на седмицата е: Петък\n");
            break;
        case 6:
            printf("Денят на седмицата е: Събота\n");
            break;
        default:
            printf("Грешка при изчисление на деня от седмицата!\n");
            break;
    }
    return 0;
}

int isValidDate(int day, int month, int year) {
    if (year < 0 || month < 1 || month > 12 || day < 1) {
        return 0;
    }
    int daysInMonth;
    switch (month) {
        case 2:
            daysInMonth = isLeapYear(year) ? 29 : 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            daysInMonth = 30;
            break;
        default:
            daysInMonth = 31;
            break;
    }
    return day <= daysInMonth;
}

int calculateDayOfWeek(int day, int month, int year) {
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;
    return (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
}

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
