#include "Verification_Inputs.h"

void menu_int_options(int &option, int omin, int nmax){
    cout << endl << "Choose an option from the menu (integer number): ";
    cin >> option;
    while (cin.fail() || option > nmax || option < omin) {
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

void verification_int(string &aux) {
    string numbers = "0123456789";

    bool isValid = false;

    while (!isValid || aux == "") {
        if (aux != "") {
            trim(aux);
            isValid = (aux.find_last_not_of(numbers) == string::npos);
        }
        if (!isValid) {
            cout << "Invalid character. Please insert a valid input: ";
            getline(cin, aux);
            if (cin.fail() && cin.eof()) {
                cin.clear();
                continue;
            }
        }
    }
}

void verification_nif(string &aux) {

    bool isValid = false;

    while (!isValid || aux == "") {
        if (aux != "") {
            trim(aux);
            verification_int(aux);
            isValid = (aux.size() == 9);
        }

        if (!isValid) {
            cout << "Invalid nif. Please insert a valid one: ";
            getline(cin, aux);
            if (cin.fail() && cin.eof()) {
                cin.clear();
                continue;
            }
        }
    }

}

void verification_all_letters(string &aux) { //verifica se há carateres invalidos numa string, ou seja , so sao aceites letras ou espaços
    string alphabet = "abcdefghijklmnopqrstuvwxyzãáàâçéêíõóôúüÃÁÀÂÇÉÊÍÕÓÔÚÜ";
    bool isValid = false;

    while (!isValid || aux == "") {
        if (aux != "") {
            trim(aux);
            isValid = (aux.find_last_not_of(alphabet) == string::npos);
        }

        if (!isValid) {
            cout << "Invalid character. Please insert a valid input: ";
            getline(cin, aux);
            if (cin.fail() && cin.eof()) {
                cin.clear();
                continue;
            }
        }
    }
}

void verification_date(string &aux) {

    bool isValid = false;

    while (!isValid || aux == "") {
        if (aux != "") {
            remove_all_whitespaces(aux);
            int del1 = aux.find_first_of('/'), del2 = aux.find_last_of('/');
            if(aux.size() != 10 || count(aux.begin(), aux.end(), '/') != 2 || del1 != 2 && del2 != 5 || !(isNumber(aux.substr(0, 2)) && isNumber(aux.substr(3, 2)) && isNumber(aux.substr(6, 4)))) {
                isValid = false;
            }
            else {
                isValid = true;
            }


        }
        if (!isValid) {
            cout << "Invalid date (format: dd/mm/yyyy). Please insert a valid one: ";
            getline(cin, aux);
            if (cin.fail() && cin.eof()) {
                cin.clear();
                continue;
            }
        }
    }
}

void verification_base(string &aux){

    bool isValid = false;

    while (!isValid || aux == "") {
        if (aux != "") {
            formatting_string(aux);
            isValid = !(aux != "Porto" && aux != "Lisboa" && aux != "Faro");
        }
        if (!isValid) {
            cout << "Invalid base (Porto, Lisboa, Faro). Please insert a valid one: ";
            getline(cin, aux);
            if (cin.fail() && cin.eof()) {
                cin.clear();
                continue;
            }
        }
    }
}

void verification_float(string &aux){
    bool isValid = false;

    while (!isValid || aux == "") {
        if (aux != "") {
            remove_extra_whitespaces(aux);
            if((count(aux.begin(), aux.end(), '.') == 1) || (count(aux.begin(), aux.end(), '.') == 0)){
                for(int i = 0; i < aux.size(); i++){
                    if (!isAlgarism(aux[0])) {
                        isValid = false;
                        break;
                    }
                    if(isAlgarism(aux[i]) || aux[i] == '.'){
                        isValid = true;
                    }
                    else{
                        isValid = false;
                        break;
                    }
                }
            }
        }
        if (!isValid) {
            cout << "Invalid price. Please insert a valid one: ";
            getline(cin, aux);
            if (cin.fail() && cin.eof()) {
                cin.clear();
                continue;
            }
        }
    }
}
