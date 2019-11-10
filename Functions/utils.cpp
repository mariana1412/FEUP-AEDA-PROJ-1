#include "utils.h"

bool isNumber(string n){

    for(int i = 0; i<n.size(); i++){
        if(!isAlgarism(n[i])) return false;
    }

    return true;
}

bool isAlgarism(char n){
    string numbers = "0123456789";
    n = toupper(n);

    if (numbers.find(n) != string::npos) {
        return true;
    }
    return false;
}

bool isLetter(char a) {
    string alphabet = "abcdefghijklmnopqrstuvwxyzãáàâçéêíõóôúüÃÁÀÂÇÉÊÍÕÓÔÚÜ";
    a = tolower(a);

    if (alphabet.find(a) != string::npos) {
        return true;
    }

    return false;
}

void trim(string &str){
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
}

void formatting_string(string &str) { //formatar a string para que todas as letras sejam minusculas menos a primeira letra de cada palavra

    str = remove_extra_whitespaces(str);

    transform(str.begin(), str.end(), str.begin(), ::tolower);//toda a string é colocada em minusculas

    str = " " + str;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ' && isLetter(str[i + 1])) {
            str[i + 1] = toupper(str[i + 1]);// coloca a primeira letra de cada palavra a maiuscula
        }
    }
    trim(str);
}

void remove_all_whitespaces(string &aux){
    aux.erase(remove(aux.begin(), aux.end(), ' '), aux.end());
}

string remove_extra_whitespaces(string aux) {
    string auxiliar;
    bool spacefound = false;
    trim(aux);

    for (int i = 0; i < aux.size(); i++) {
        if (aux[i] == ' ' && !spacefound) {
            auxiliar += ' ';
            spacefound = true;
        }
        else if (aux[i] != ' ') {
            auxiliar += aux[i];
            spacefound = false;
        }
    }

    return auxiliar;
}

bool confirm_modifications(string action, string str){

    string cancel;

    if (action == "create") {
        cout << endl << endl << "Are you sure you want to create a " << str << " with this information? " << endl
             << "Insert 'yes' to continue. " << endl << "Insert 'no' to cancel. " << endl << "Answer: ";
        cin >> cancel;
    }

    else if (action == "modify") {
        cout << endl << endl << "Are you sure you want to modify this " << str << " with this information? " << endl
             << "Insert 'yes' to continue. " << endl << "Insert 'no' to cancel. " << endl << "Answer: ";
        cin >> cancel;
    }
    else if (action == "remove") {
        cout << endl << endl << "Are you sure you want to remove this " << str << "?" << endl
             << "Insert 'yes' to continue. " << endl << "Insert 'no' to cancel. " << endl << "Answer: ";
        cin >> cancel;
    }

    while (cin.fail()) {
        if (cin.eof()) {
            cin.clear();
            cout << "Invalid operation, please insert a valid one: ";
            cin >> cancel;
        }
    }

    formatting_string(cancel);

    while (cin.fail() || (cancel != "Yes" && cancel != "No")) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid operation, please insert a valid one: ";
        cin >> cancel;
        while (cin.fail()) {
            if (cin.eof()) {
                cin.clear();
                cout << "Invalid operation, please insert a valid one: ";
                cin >> cancel;
            }
        }

        formatting_string(cancel);
    }


    if(cancel == "Yes") return true;

    return false;
}
