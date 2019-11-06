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

    aux.erase(remove(aux.begin(), aux.end(), ' '), aux.end());
    if (aux.find_last_not_of(numbers) == string::npos) return true;

    return false;
}

bool verification_nif(string aux) {

    int counter = 0;

    aux.erase(remove(aux.begin(), aux.end(), ' '), aux.end());
    if (!verification_int(aux)) return false;

    return (aux.size() == 9);
}

bool verification_all_letters(string aux) { //verifica se há carateres invalidos numa string, ou seja , so sao aceites letras ou espaços
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    aux.erase(remove(aux.begin(), aux.end(), ' '), aux.end());
    if (aux.find_last_not_of(alphabet) == string::npos) return true;

    return false;
}

bool verification_date(string aux) {

    remove_extra_whitespaces(aux);

    if(aux.size() != 10) return false;
    if(count(aux.begin(), aux.end(), '/') != 2) return false;

    int del1 = aux.find_first_of('/'), del2 = aux.find_last_of('/');

    if(del1 != 2 && del2 != 5) return false;
    if(!(verification_int(aux.substr(0, 2)) && verification_int(aux.substr(3, 2)) && verification_int(aux.substr(6, 4)))) return false;

    return true;
}

void verification_base(string &aux){

    formatting_string(aux);

    while(aux != "Porto" && aux != "Lisboa" && aux != "Faro"){
        cout << "Invalid base (Porto, Lisboa, Faro). Please insert a valid one: ";
        getline(cin, aux);
        formatting_string(aux);
    }

}


