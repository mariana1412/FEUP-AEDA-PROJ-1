#include "Visualize_Information.h"

int visualize_clients(const Base &Porto, const Base &Lisboa, const Base &Faro){

    string b;
    int size;
    cout << endl << endl << "-------------- VISUALIZE CLIENTS --------------" << endl << endl;

    cout << "Base:";
    getline(cin, b);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout <<  "Invalid base. Please insert a valid input: ";
        getline(cin, b);
    }

    verification_base(b);
    if (b == "Porto"){
        size = Porto.getClients().size();
        if(size != 0){
            for(int i =0; i < size; i++){
                cout << "--> Client " << i+1 <<endl;
                cout << Porto.getClients()[i] << endl;
            }
        }
        else {
            cout << "We do not have informations to show! " << endl;
        }

    }
    else if (b == "Lisboa"){
        size = Lisboa.getClients().size();
        if(size != 0){
            for(int i =0; i < size; i++){
                cout << "--> Client " << i+1 <<endl;
                cout << Lisboa.getClients()[i] << endl;
            }
        }
        else {
            cout << "We do not have informations to show! " << endl;
        }
    }
    if (b == "Faro"){
        size = Faro.getClients().size();
        if(size != 0){
            for(int i =0; i < size; i++){
                cout << "--> Client " << i+1 <<endl;
                cout << Faro.getClients()[i] << endl;
            }
        }
        else {
            cout << "We do not have informations to show! " << endl;
        }
    }


    int option;
    cout << endl << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Visualize Information. " << endl;
    menu_int_options(option, 1, 2);
    return option;
}


int visualize_blaclist(const Base &Porto, const Base &Lisboa, const Base &Faro){
    string b;
    int size;
    cout << endl << endl << "-------------- VISUALIZE BLACKLIST --------------" << endl << endl;

    cout << "Base:";
    getline(cin, b);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout <<  "Invalid base. Please insert a valid input: ";
        getline(cin, b);
    }

    verification_base(b);
    if (b == "Porto"){
        size = Porto.getBlackList().size();
        if(size!=0){
            for(int i =0; i<size; i++){
                cout << "--> Client " << i+1 <<endl;
                cout << Porto.getBlackList()[i] << endl;
            }
        }
        else {
            cout << "We do not have informations to show! " << endl;
        }

    }
    else if (b == "Lisboa"){
        size = Lisboa.getBlackList().size();
        if(size!=0){
            for(int i =0; i<size; i++){
                cout << "--> Client " << i+1 <<endl;
                cout << Lisboa.getBlackList()[i] << endl;
            }
        }
        else {
            cout << "We do not have informations to show! " << endl;
        }
    }
    if (b == "Faro"){
        size = Faro.getBlackList().size();
        if(size!=0){
            for(int i =0; i<size; i++){
                cout << "--> Client " << i+1 <<endl;
                cout << Faro.getBlackList()[i] << endl;
            }
        }
        else {
            cout << "We do not have informations to show! " << endl;
        }
    }

    int option;
    cout << endl << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Visualize Information. " << endl;
    menu_int_options(option, 1, 2);
    return option;
}

int visualize_employees(const Base &Porto, const Base &Lisboa, const Base &Faro) {
    string b;
    int size;
    cout << endl << endl << "-------------- VISUALIZE EMPLOYEES --------------" << endl << endl;

    cout << "Base:";
    getline(cin, b);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout <<  "Invalid base. Please insert a valid input: ";
        getline(cin, b);
    }

    verification_base(b);


    if (b == "Porto"){
        size = Porto.getEmployees().size();
        if(size != 0){
            for(int i =0; i< size; i++){
                Admin *a= dynamic_cast<Admin *> (Porto.getEmployees()[i]);
                if (a != NULL){
                    cout << "--> Employee " << i+1 << endl;
                    cout << a << endl;
                }
                else {
                    Deliverer *d= dynamic_cast<Deliverer *> (Porto.getEmployees()[i]);
                    cout << "--> Employee " << i+1 << endl;
                    cout << d << endl;
                }
            }
        }
        else {
            cout << "We do not have informations to show! " << endl;
        }
    }
    else if (b == "Lisboa"){
        size = Lisboa.getEmployees().size();
        if(size != 0){
            for(int i =0; i< size; i++){
                Admin *a= dynamic_cast<Admin *> (Lisboa.getEmployees()[i]);
                if (a != NULL){
                    cout << "--> Employee " << i+1 << endl;
                    cout << a << endl;
                }
                else {
                    Deliverer *d= dynamic_cast<Deliverer *> (Lisboa.getEmployees()[i]);
                    cout << "--> Employee " << i+1 << endl;
                    cout << d << endl;
                }
            }
        }
        else {
            cout << "We do not have informations to show! " << endl;
        }
    }
    if (b == "Faro"){
        size = Faro.getEmployees().size();
        if(size != 0){
            for(int i =0; i< size; i++){
                Admin *a= dynamic_cast<Admin *> (Faro.getEmployees()[i]);
                if (a != NULL){
                    cout << "--> Employee " << i+1 << endl;
                    cout << a << endl;
                }
                else {
                    Deliverer *d= dynamic_cast<Deliverer *> (Faro.getEmployees()[i]);
                    cout << "--> Employee " << i+1 << endl;
                    cout << d << endl;
                }
            }
        }
        else {
            cout << "We do not have informations to show! " << endl;
        }
    }
    int option;
    cout << endl << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Visualize Information. " << endl;
    menu_int_options(option, 1, 2);
    return option;
}

int visualize_restaurants(const Base &Porto, const Base &Lisboa, const Base &Faro){
    string b;
    cout << endl << endl << "-------------- VISUALIZE RESTAURANTS --------------" << endl << endl;
    int size;
    cout << "Base:";
    getline(cin, b);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout <<  "Invalid base. Please insert a valid input: ";
        getline(cin, b);
    }

    verification_base(b);
    if (b == "Porto"){
        size = Porto.getRestaurants().size();
        if(size != 0){
            for(int i =0; i< size; i++){
                cout << "--> Restaurant " << i+1 << endl;
                cout << Porto.getRestaurants()[i] << endl;
            }
        }
        else {
            cout << "We do not have informations to show! " << endl;
        }

    }
    else if (b == "Lisboa"){
        size = Lisboa.getRestaurants().size();
        if(size != 0){
            for(int i =0; i< size; i++){
                cout << "--> Restaurant " << i+1 << endl;
                cout << Lisboa.getRestaurants()[i] << endl;
            }
        }
        else {
            cout << endl << "We do not have informations to show! " << endl;
        }
    }
    if (b == "Faro"){
        size = Faro.getRestaurants().size();
        if(size != 0){
            for(int i =0; i< size; i++){
                cout << "--> Restaurant " << i+1 << endl;
                cout << Faro.getRestaurants()[i] << endl;
            }
        }
        else {
            cout << endl << "We do not have informations to show! " << endl;
        }
    }

    int option;
    cout << endl << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Visualize Information. " << endl;
    menu_int_options(option, 1, 2);
    return option;
}


int visualize_deliveries(const Base &Porto, const Base &Lisboa, const Base &Faro){
    string b;
    int size;
    cout << endl << endl << "-------------- VISUALIZE DELIVERIES --------------" << endl << endl;

    cout << "Base:";
    getline(cin, b);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout <<  "Invalid base. Please insert a valid input: ";
        getline(cin, b);
    }

    verification_base(b);
    if (b == "Porto"){
        size = Porto.getDeliveries().size();
        if(size != 0){
            for(int i =0; i< size; i++){
                cout << "--> Delivery " << i+1 << endl;
                cout << Porto.getDeliveries()[i] << endl;
            }
        }
        else {
            cout << endl << "We do not have informations to show! " << endl;
        }
    }
    else if (b == "Lisboa"){
        size = Lisboa.getDeliveries().size();
        if(size != 0){
            for(int i =0; i< size; i++){
                cout << "--> Delivery " << i+1 << endl;
                cout << Lisboa.getDeliveries()[i] << endl;
            }
        }
        else {
            cout << endl << "We do not have informations to show! " << endl;
        }
    }
    if (b == "Faro"){
        size = Faro.getDeliveries().size();
        if(size != 0){
            for(int i =0; i< size; i++){
                cout << "--> Delivery " << i+1 << endl;
                cout << Faro.getDeliveries()[i] << endl;
            }
        }
        else {
            cout << endl << "We do not have informations to show! " << endl;
        }
    }

    int option;
    cout << endl << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Visualize Information. " << endl;
    menu_int_options(option, 1, 2);
    return option;
}