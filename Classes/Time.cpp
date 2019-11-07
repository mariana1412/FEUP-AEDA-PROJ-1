#include "Time.h"
Time::Time(){
    this-> hour=0;
    this-> minutes=0;
    this-> day=0;
    this-> month=0;
    this-> year=0;
}

Time::Time(int hour, int minutes, int day, int month, int year){
    this-> hour=hour;
    this-> minutes=minutes;
    this-> day=day;
    this-> month=month;
    this-> year=year;
}
int Time::getHour() const{
    return hour;
}
int Time::getMinutes() const{
    return minutes;
}
int Time::getDay() const{
    return day;
}
int Time::getMonth() const{
    return month;
}
int Time::getYear() const{
    return year;
}

void Time::setHour(int hour){
    this->hour=hour;
}

void Time::setMinutes(int minutes){
    this->minutes = minutes;
}

void Time::setDay(int day){
    this->day = day;
}

void Time::setMonth(int month){
    this->month = month;
}

void Time::setYear(int year) {
    this->year = year;
}

void Time::setHour(string str){
    string delimiter = ":";
    vector<string> data;
    vector<int> data_clean;
    size_t pos = 0;
    string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        data.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    data.push_back(str);
    for (auto & i : data) {
        trim(i);
        data_clean.push_back(stoi(i));
    }
    this->setHour(data_clean.at(0));
    this->setMinutes(data_clean.at(1));

}

void Time::setDate(string str){
    string delimiter = "/";
    vector<string> data;
    vector<int> data_clean;
    size_t pos = 0;
    string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        data.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    data.push_back(str);
    for (auto & i : data) {
        trim(i);
        data_clean.push_back(stoi(i));
    }
    this->setDay(data_clean.at(0));
    this->setMonth(data_clean.at(1));
    this->setYear(data_clean.at(2));

}
void Time::setTime(string str){
    replace(str.begin(), str.end(), ':', '/');
    replace(str.begin(), str.end(), ',', '/');
    string delimiter = "/";
    vector<string> data;
    vector<int> data_clean;
    size_t pos = 0;
    string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        data.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    data.push_back(str);
    for (auto & i : data) {
        trim(i);
        data_clean.push_back(stoi(i));
    }
    this->setDay(data_clean[0]);
    this->setMonth(data_clean[1]);
    this->setYear(data_clean[2]);
    this->setHour(data_clean[3]);
    this->setMinutes(data_clean[4]);
}


bool Time::isValid() {// verifica se a data é valida,ou seja, nao tem um n maior de mês do que o possivel e o mesmo com os dias
    if (month > 12 || day > numberOfDays(month, year) || hour > 23 || minutes > 59) {
        return false;
    }
    return true;
}
bool Time::isEqualTo(const Time& date) { // verifica se duas datas sao iguais

    return (date.day == day && date.month == month && date.year == year && date.hour == hour && date.minutes == minutes);
}
bool Time::isNotEqualTo(const Time& date) {// verifica se duas datas nao sao iguais
    return (isEqualTo(date));
}

bool Time::isAfter(const Time& date) {// verifica se a data é depois da outra
    return (date.year < year || (date.year == year && date.month < month) || (date.year == year && date.month == month && date.day < day));
}
bool Time::isBefore(const Time& date) {// verifica se a data é antes da outra
    return (!isAfter(date) && !isEqualTo(date));
}

//--------------------------------------------------------------------------------------------------------------------------------

bool leap_year(int year) { // verifica se é um ano bissexto ou nao
    if (year % 4 == 0 && year % 100 != 0 && year % 400 == 0) {//forma de determinar se um ano é bissexto ou nao
        return true;
    }
    return false;
}

int numberOfDays(int month, int year) {// retorna o n de dias que o respetivo mês tem
    switch (month) {
        case 2:
        {
            if (leap_year(year)) {//fevereiro
                return 29;
            }
            else {
                return 28;
            }
        }
        case 4:
            return 30;

        case 6:
            return 30;

        case 9:
            return 30;

        case 11:
            return 30;

        default:
            return 31;
    }
}