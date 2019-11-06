#include "utils.h"

string cleaning_invalid_characters(string line) { // retirar acentos e cedilhas, susbtituindo pelos caracteres validos correspondentes
    string aux, l;

    for (int i = 0; i < line.size(); i++) {
        l = to_string(line[i]);
        if (l == "à" || l == "á" || l == "ã" || l == "â") {
            aux += 'a';
        }
        else if (l == "À" || l == "Á" || l == "Â" || l == "Ã") {
            aux += 'A';
        }
        else if (l == "é" || l == "ê") {
            aux += 'e';
        }
        else if (l == "É" || l == "Ê") {
            aux += 'E';
        }
        else if (l == "í") {
            aux += 'i';
        }
        else if (l == "Í") {
            aux += 'I';
        }
        else if (l == "ó" || l == "õ" || l == "ô") {
            aux += 'o';
        }
        else if (l == "Ó" || l == "Õ" || l == "Ô") {
            aux += 'O';
        }
        else if (l == "ú") {
            aux += 'u';
        }
        else if (l == "Ú") {
            aux += 'U';
        }
        else if (l == "ç") {
            aux += 'c';
        }
        else if (l == "Ç") {
            aux += 'C';
        }
        else if (line[i]=='\x1a') {
            aux = '0';
        }
        else {
            aux += line[i];
        }
    }
    return aux;
}

void trim(string &str){
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
}

void formatting_string(string &str) { //formatar a string para que todas as letras sejam minusculas menos a primeira letra de cada palavra

    str = cleaning_invalid_characters(str);
    str = remove_extra_whitespaces(str);

    transform(str.begin(), str.end(), str.begin(), ::tolower);//toda a string é colocada em minusculas

    str = " " + str;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ' && isalpha(str[i + 1])) {
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


int string_sequential_search(const vector<Client> &v, string x) {//retorna o indice do vetor onde se encontra x
    for (unsigned int i = 0; i < v.size(); i++)
        if (v[i].getName() == x)
            return i; // encontrou
    return -1; // não encontrou
}
int int_sequential_search(const vector<Client> &v, int x) {//retorna o indice do vetor onde se encontra x
    for (unsigned int i = 0; i < v.size(); i++)
        if (v[i].getNif() == x)
            return i; // encontrou
    return -1; // não encontrou
}

bool confirm_client(string action){

    if (action == "create"){
        string cancel;
        cout << endl << endl << "Are you sure you want to create a client with this information? " << endl << "Insert 'yes' to continue. " << endl << "Insert 'no' to cancel. " << endl << "Answer: ";
        cin >> cancel;

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
    }


}