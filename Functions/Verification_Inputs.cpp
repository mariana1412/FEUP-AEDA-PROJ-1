#include "Verification_Inputs.h"

void menu_int_options(int &option, int nmax){
    cout << endl << "Choose an option from the menu (integer number): ";
    cin >> option;
    while (cin.fail() || option > nmax || option < 0) {
        if (cin.eof()) { //caso de ter sido introduzido o 'crtl-z'
            cin.clear();
            cout << "Invalid operation, please insert a valid one: ";
            cin >> option;
        }
        else { //qualquer outro caso que nao corresponda ao input pretendido
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid operation, please insert a valid one: ";
            cin >> option;
        }
    }
}

bool verification_int(string aux) {
    string numbers = "0123456789";

    aux.erase(std::remove(aux.begin(), aux.end(), ' '), aux.end());
    if (aux.find_last_not_of(numbers) == string::npos) return true;

    return false;
}

bool verification_nif(string aux) {

    int counter = 0;

    aux.erase(std::remove(aux.begin(), aux.end(), ' '), aux.end());
    if (!verification_int(aux)) return false;

    return (aux.size() == 9);
}

bool verification_all_letters(string aux) { //verifica se há carateres invalidos numa string, ou seja , so sao aceites letras ou espaços
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    aux.erase(std::remove(aux.begin(), aux.end(), ' '), aux.end());
    if (aux.find_last_not_of(alphabet) == string::npos) return true;

    return false;
}

bool verification_date(string aux) {

    aux.erase(std::remove(aux.begin(), aux.end(), ' '), aux.end());

    if(aux.size() != 10) return false;
    if(count(aux.begin(), aux.end(), '/') != 2) return false;

    int del1 = aux.find_first_of('/'), del2 = aux.find_last_of('/');

    if(del1 != 4 && del2 != 7) return false;
    if(verification_int(aux.substr(0, 4)) && verification_int(aux.substr(5, 2)) && verification_int(aux.substr(8, 2))) return true;

    return false;
}


