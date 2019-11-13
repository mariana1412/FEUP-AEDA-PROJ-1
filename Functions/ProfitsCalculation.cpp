#include "ProfitsCalculation.h"

int ProfitsByBase(Base p, Base l, Base f){
    float profit=0;
    int option,op;
    Base b;
    vector<Delivery> v;
    cout << "From which base do you want to know the profit?"<<endl;
    cout << "\t 1.Porto \t 2.Lisboa \t 3.Faro "<<endl;
    menu_int_options(op, 1,3);
    switch (op){
        case 1:
            for(int i = 0; i < p.getDeliveries().size(); i++){
                profit += p.getDeliveries()[i].getFinalPrice();
            }
            break;
        case 2:
            for(int i = 0; i < l.getDeliveries().size(); i++){
                profit += l.getDeliveries()[i].getFinalPrice();
            }
            break;
        case 3:
            for(int i = 0; i < f.getDeliveries().size(); i++){
                profit += f.getDeliveries()[i].getFinalPrice();
            }
            break;
    }

    cout << "The profit of this base is "<< profit<<" euros." <<endl;

    cout << endl << "1. Return to Main Menu. " << endl;
    cout << "2. Return to  Profit Calculation. " << endl;
    menu_int_options(option,1,2);
    return option;
}

int ProfitsByRestaurant(Base p, Base l , Base f){
    int option,op;
    string base,aux;
    Restaurant restaurant;
    bool isValid;
    float profit;
    Base b;

    cout << "From which base is the restaurant you want to know the profit?"<<endl;
    cout << "\t 1.Porto \t 2.Lisboa \t 3.Faro "<<endl;
    menu_int_options(op, 1,3);
    cin.ignore(1000,'\n');
    switch (op) {
        case 1:
            base = "Porto";
            break;
        case 2:
            base = "Lisboa";
            break;
        case 3:
            base = "Faro";
            break;
    }

    cout << "Insert the name of the restaurant : ";
    getline(cin, aux);

    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, aux);
    }
    formatting_string(aux);
    do{
        try {
            if (base == "Porto") restaurant = p.searchRestaurant(aux);
            else if (base == "Lisboa") restaurant = l.searchRestaurant(aux);
            else if(base == "Faro") restaurant = f.searchRestaurant(aux);
            isValid = true;
        }
        catch (RestaurantNotFound &msg){
            cout << endl << endl << "ATENTION: Restaurant '" << msg.getName() << "' does not exist." << endl << endl;
            isValid = false;
            cout << "Try again. Insert the name of the restaurant: ";
            getline(cin, aux);

            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, aux);
            }
            formatting_string(aux);
        }
    } while(!isValid);

    profit = restaurant.getRevenue();
    cout << "The profit of this restaurant is "<< profit<<" euros."<<endl;


    cout << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Profit Calculation. " << endl;
    menu_int_options(option,1,2);
    return option;
}
int ProfitsByClient(Base p, Base l, Base f){
    int op,option,i;
    Base b;
    string aux;
    float profit=0;

    cout << "From which base is the client you want to know the outlay?"<<endl;
    cout << "\t1.Porto \t 2.Lisboa \t 3.Faro "<<endl;
    menu_int_options(op, 1,3);
    cin.ignore (1000, '\n');
    switch (op){
        case 1:
            b= p;
            break;
        case 2:
            b=l;
            break;
        case 3:
            b=f;
            break;
    }
    cout << "What is the name of the client you want to know the outlay? ";
    getline(cin, aux);
    while (cin.fail() && cin.eof()) {
        cin.clear();
        cout << "Invalid character. Please insert a valid input:";
        getline(cin, aux);
    }
    verification_all_letters(aux);
    i = string_sequential_search_aux(b.getClients(), aux);
    if (i == -1) {
        cout << "The client inserted does not exist. Try again:"<<endl;//dar opçao de tentar outra
        while (i == -1) {
            cout << "What is the name of the client you want to know the outlay? ";
            getline(cin, aux);
            while (cin.fail() && cin.eof()) {
                cin.clear();
                cout << "Invalid character. Please insert a valid input:";
                getline(cin, aux);
            }
            verification_all_letters(aux);
            i = string_sequential_search_aux(b.getClients(), aux);
        }
    }
    int nif = b.getClients()[i].getNif();
    vector<Delivery>:: const_iterator it_d = b.getDeliveries().begin();
    for (it_d; it_d != b.getDeliveries().end(); it_d++){
        if((*it_d).getNif()==nif){
            profit += (*it_d).getFinalPrice();
        }

    }


    cout << "The profit of this client is "<< profit<<" euros."<<endl;

    cout << endl << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Profit Calculation. " << endl;
    menu_int_options(option,1,2);
    return option;
}
int ProfitByTimeInterval(Base p, Base l , Base f){
    int option,op;
    string s;
    Time d1,d2;
    float profit = 0;

    cout << "Inferior limit of the interval.";
    cout << "Date (in the dd/mm/yyy format):";
    getline(cin, s),
    d1=verification_date(s);
    cout << "Hour (in the hh:mm format ):";
    getline(cin,s);
    verification_hour(s);
    stringToHours(d1,s);
    cout << "Superior limit of the interval.";
    cout << "Date (in the dd/mm/yyy format):";
    getline(cin, s),
    d2=verification_date(s);
    cout << "Hour (in the hh:mm format ):";
    getline(cin,s);
    verification_hour(s);
    stringToHours(d2,s);
    while(d1>d2){
        cout << "This interval is not valid. Please, try again:"<<endl;
        cout << "Inferior limit of the interval.";
        cout << "Date (format: dd/mm/yyy):";
        getline(cin, s),
                d1=verification_date(s);
        cout << "Hour (format: hh:mm ):";
        getline(cin,s);
        verification_hour(s);
        stringToHours(d1,s);
        cout << "Superior limit of the interval.";
        cout << "Date (format: dd/mm/yyy):";
        getline(cin, s),
                d2=verification_date(s);
        cout << "Hour (format: hh:mm ):";
        getline(cin,s);
        verification_hour(s);
        stringToHours(d2,s);
    }
    cout << "From which base do you want to know the profit in this interval?"<<endl;
    cout << "\t 1.Porto \t 2.Lisboa \t 3.Faro "<<endl;
    menu_int_options(op, 1,3);
    switch (op){
        case 1:
            for(int i = 0; i < p.getDeliveries().size(); i++){
                if((p.getDeliveries()[i].getTime()>d1) &&(d2>p.getDeliveries()[i].getTime())){
                    profit += p.getDeliveries()[i].getFinalPrice();
                }
                else{
                    continue;
                }

            }
            break;
        case 2:
            for(int i = 0; i < l.getDeliveries().size(); i++){
                if((l.getDeliveries()[i].getTime()>d1) &&(d2>l.getDeliveries()[i].getTime())){
                    profit += l.getDeliveries()[i].getFinalPrice();
                }
                else{
                    continue;
                }
            }
            break;
        case 3:
            for(int i = 0; i < f.getDeliveries().size(); i++){
                if((f.getDeliveries()[i].getTime()>d1) &&(d2>f.getDeliveries()[i].getTime())){
                    profit += f.getDeliveries()[i].getFinalPrice();
                }
                else{
                    continue;
                }
            }
            break;
    }

    cout << "The profit in general in this time interval is "<< profit<<" euros." <<endl;

    cout << "1. Return to Main Menu. " << endl;
    cout << "2. Return to  Profit Calculation. " << endl;
    menu_int_options(option,1,2);
    return option;
}
void stringToHours(Time &d,string s){
    string delimiter =":",aux;
    size_t pos=0;
    vector<int> hours;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        aux =  s.substr(0, pos);
        formatting_string(aux);
        hours.push_back(stoi(aux));
        s.erase(0, pos + delimiter.length());
    }

    d.setHour(hours[0]);
    d.setMinutes(hours[1]);
}
void verification_hour(string &aux){
    bool isValid = false;

    while (!isValid || aux == "") {
        if (aux != "") {
            remove_all_whitespaces(aux);
            int del1 = aux.find_first_of(':');
            if(aux.size() !=5  || count(aux.begin(), aux.end(), ':') != 1 || del1 !=2 || !(isNumber(aux.substr(0, 2)) && isNumber(aux.substr(3, 2)) )) {
                isValid = false;
            }
            else if (stoi(aux.substr(0,2))>24 || stoi(aux.substr(0,2))<0||stoi(aux.substr(3,2))>60 ||stoi(aux.substr(0,2))<0){
                isValid = false;
            }
            else {
                isValid = true;
            }
        }
        if (!isValid) {
            cout << "Invalid hour (format: hh:mm). Please insert a valid one: ";
            getline(cin, aux);
            if (cin.fail() && cin.eof()) {
                cin.clear();
                continue;
            }
        }
    }

}

int string_sequential_search_aux(const vector<Client> &v, string x) {//retorna o indice do vetor onde se encontra x
    for ( unsigned int i = 0; i < v.size(); i++)
        if (v[i].getName() == x)
            return i; // encontrou
    return -1; // não encontrou
}