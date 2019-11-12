#include "Visualize_Information.h"

int visualize_clients(const Base &Porto, const Base &Lisboa, const Base &Faro){

    string b;


    cout << endl << endl << "-------------- VISUALIZE CLIENTS --------------" << endl << endl;

    cout << "Base: ";
    getline(cin, b);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout <<  "Invalid base. Please insert a valid input: ";
        getline(cin, b);
    }

    verification_base(b);
    if (b == "Porto"){
        for(int i =0; i<Porto.getClients().size(); i++){
            cout << Porto.getClients()[i] << endl;
        }
    }
    else if (b == "Lisboa"){
        for(int i =0; i<Lisboa.getClients().size(); i++){
            cout << Lisboa.getClients()[i] << endl;
        }
    }
    if (b == "Faro"){
        for(int i =0; i<Faro.getClients().size(); i++){
            cout << Faro.getClients()[i] << endl;
        }
    }


    int option;
    cout << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Visualize Information. " << endl;
    menu_int_options(option, 1, 2);
    return option;
}


int visualize_blaclist(const Base &Porto, const Base &Lisboa, const Base &Faro){
    string b;
    cout << endl << endl << "-------------- VISUALIZE BLACKLIST --------------" << endl << endl;

    cout << "Base: ";
    getline(cin, b);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout <<  "Invalid base. Please insert a valid input: ";
        getline(cin, b);
    }

    verification_base(b);
    if (b == "Porto"){
        for(int i =0; i<Porto.getBlackList().size(); i++){
            cout << Porto.getBlackList()[i] << endl;
        }
    }
    else if (b == "Lisboa"){
        for(int i =0; i<Lisboa.getBlackList().size(); i++){
            cout << Lisboa.getBlackList()[i] << endl;
        }
    }
    if (b == "Faro"){
        for(int i =0; i<Faro.getBlackList().size(); i++){
            cout << Faro.getBlackList()[i] << endl;
        }
    }

    int option;
    cout << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Visualize Information. " << endl;
    menu_int_options(option, 1, 2);
    return option;
}

int visualize_employees(const Base &Porto, const Base &Lisboa, const Base &Faro) {
    string b;
    cout << endl << endl << "-------------- VISUALIZE EMPLOYEES --------------" << endl << endl;

    cout << "Base: ";
    getline(cin, b);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout <<  "Invalid base. Please insert a valid input: ";
        getline(cin, b);
    }

    verification_base(b);


    if (b == "Porto"){
        for(int i =0; i<Porto.getEmployees().size(); i++){
            Admin *a= dynamic_cast<Admin *> (Porto.getEmployees()[i]);
            if (a != NULL){
                cout << a << endl;
            }
            else {
                Deliverer *d= dynamic_cast<Deliverer *> (Porto.getEmployees()[i]);
                cout << d << endl;
            }
        }
    }
    else if (b == "Lisboa"){
        for(int i =0; i<Lisboa.getEmployees().size(); i++){
            Admin *a= dynamic_cast<Admin *> (Lisboa.getEmployees()[i]);
            if (a != NULL){
                cout << a << endl;
            }
            else {
                Deliverer *d= dynamic_cast<Deliverer *> (Lisboa.getEmployees()[i]);
                cout << d << endl;
            }
        }
    }
    if (b == "Faro"){
        for(int i =0; i<Faro.getEmployees().size(); i++){
            Admin *a= dynamic_cast<Admin *> (Faro.getEmployees()[i]);
            if (a != NULL){
                cout << a << endl;
            }
            else {
                Deliverer *d= dynamic_cast<Deliverer *> (Faro.getEmployees()[i]);
                cout << d << endl;
            }
        }
    }
    int option;
    cout << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Visualize Information. " << endl;
    menu_int_options(option, 1, 2);
    return option;
}

int visualize_restaurants(const Base &Porto, const Base &Lisboa, const Base &Faro){
    string b;
    cout << endl << endl << "-------------- VISUALIZE RESTAURANTS --------------" << endl << endl;

    cout << "Base: ";
    getline(cin, b);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout <<  "Invalid base. Please insert a valid input: ";
        getline(cin, b);
    }

    verification_base(b);
    if (b == "Porto"){
        for(int i =0; i<Porto.getRestaurants().size(); i++){
            cout << Porto.getRestaurants()[i] << endl;
        }
    }
    else if (b == "Lisboa"){
        for(int i =0; i<Lisboa.getRestaurants().size(); i++){
            cout << Lisboa.getRestaurants()[i] << endl;
        }
    }
    if (b == "Faro"){
        for(int i =0; i<Faro.getRestaurants().size(); i++){
            cout << Faro.getRestaurants()[i] << endl;
        }
    }

    int option;
    cout << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Visualize Information. " << endl;
    menu_int_options(option, 1, 2);
    return option;
}


int visualize_deliveries(const Base &Porto, const Base &Lisboa, const Base &Faro){
    string b;
    cout << endl << endl << "-------------- VISUALIZE DELIVERIES --------------" << endl << endl;

    cout << "Base: ";
    getline(cin, b);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout <<  "Invalid base. Please insert a valid input: ";
        getline(cin, b);
    }

    verification_base(b);
    if (b == "Porto"){
        for(int i =0; i<Porto.getDeliveries().size(); i++){
            cout << Porto.getDeliveries()[i] << endl;
        }
    }
    else if (b == "Lisboa"){
        for(int i =0; i<Lisboa.getDeliveries().size(); i++){
            cout << Lisboa.getDeliveries()[i] << endl;
        }
    }
    if (b == "Faro"){
        for(int i =0; i<Faro.getDeliveries().size(); i++){
            cout << Faro.getDeliveries()[i] << endl;
        }
    }

    int option;
    cout << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Visualize Information. " << endl;
    menu_int_options(option, 1, 2);
    return option;
}