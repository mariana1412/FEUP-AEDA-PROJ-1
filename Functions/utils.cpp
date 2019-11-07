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

bool confirm_modifications(string action, string person){

    string cancel;

    if (action == "create") {
        cout << endl << endl << "Are you sure you want to create a " << person << " with this information? " << endl
             << "Insert 'yes' to continue. " << endl << "Insert 'no' to cancel. " << endl << "Answer: ";
        cin >> cancel;
    }

    else if (action == "modify") {
        cout << endl << endl << "Are you sure you want to modify this " << person << " with this information? " << endl
             << "Insert 'yes' to continue. " << endl << "Insert 'no' to cancel. " << endl << "Answer: ";
        cin >> cancel;
    }
    else if (action == "remove") {
        cout << endl << endl << "Are you sure you want to remove this " << person << "?" << endl
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


//Returns a client if str is the client's NIF
vector<Client> stringToClientVectorSearch(string str, const Base& b) {   //Blacklist
    string delimiter = ",";
    vector<string> data;
    vector<int> data_clean;
    vector<Client> result;
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
    for (vector<int>::const_iterator it = data_clean.begin(); it != data_clean.end(); it++){
        for (vector<Client>::const_iterator it1 = b.getClients().begin(); it1 != b.getClients().end(); it1++){
            if ((*it) == it1->getNif())
                result.push_back((*it1));
        }
    }
    return result;
}

Restaurant stringToRestaurantSearch(string str, const Base& b){
    vector<Restaurant> restaurants = b.getRestaurants();
    for (vector<Restaurant>::iterator it = restaurants.begin(); it != restaurants.end(); it++){
        if (str == it->getName())
            return (*it);
    }
}

vector<Delivery> stringToDeliveryVectorSearch(string str, const Base& b){
    string delimiter = ",";
    vector<string> data;
    vector<int> data_clean;
    vector<Delivery> result;
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
    vector<Delivery> deliveries = b.getDeliveries();
    for (vector<int>::const_iterator it = data_clean.begin(); it != data_clean.end(); it++){
        for (vector<Delivery>::const_iterator it1 = deliveries.begin(); it1 != deliveries.end(); it1++){
            if ((*it) == (it1->getId()))
                result.push_back((*it1));
        }
    }
    return result;
}

vector<Product> stringToProductVectorSearch(string str, const Base& b){
    string delimiter = ",";
    vector<string> data;
    vector<string> data_clean;
    vector<Product> result;
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
        data_clean.push_back(i);
    }
    vector<Restaurant> restaurants = b.getRestaurants();
    for (vector<string>::const_iterator it = data_clean.begin(); it != data_clean.end(); it++){
        for (vector<Restaurant>::const_iterator it1 = restaurants.begin(); it1 != restaurants.end(); it1++){
            vector<Product> products = it1->getProducts();
            for (vector<Product>::const_iterator it2 = products.begin();it2 != products.end(); it2++){
                if ((*it) == (it2->getName()))
                    result.push_back((*it2));
            }
        }
    }
    return result;
}

vector<string> stringToStringVector(string str){
    string delimiter = ",";
    vector<string> data;
    vector<string> result;
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
        result.push_back(i);
    }

    return result;
}