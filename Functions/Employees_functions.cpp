//
// Created by ritap on 09/11/2019.
//

#include "Employees_functions.h"
int create_employee(Base &Porto, Base &Lisboa, Base &Faro){

    string name, b, nif,income,birthdate,task,brand,type,date;
    vector<Admin> ad;
    vector<Deliverer> del;
    Base base;
    int number;
    vector<Delivery> background;
    Vehicle v;


    cout << "-------------- CREATE EMPLOYEE --------------" << endl;

    cout << "What kind of Employee do you wish to create?\n";
    cout << "1: Admin\n" << "2: Deliverer\n";
    menu_int_options(number,1, 2);

    cout << "Base: ";
    getline(cin, b);
    verification_base(b);
/*
    if (b == "Porto") {
        ad = Porto.getAdmin();
        del = Porto.getDeliverer();
        base = Porto;
    }
    else if (b == "Lisboa") {
        ad = Lisboa.getAdmin();
        del = Lisboa.getDeliverer();
        base = Lisboa;
    }
    else if (b == "Faro") {
        ad = Faro.getAdmin();
        del = Faro.getDeliverer();
        base = Faro;
    }

    cout << "Name:";
    getline(cin, name);
    verification_all_letters(name);


    cout << "NIF: ";
    getline(cin, nif);
    verification_nif(nif);

    cout << "Birthdate: ";
    getline(cin, birthdate);
    //work on this


    cout << "Income: ";
    getline(cin, income);
    verification_int(income);
*/
/*

    switch (number) {
        case 1:
            cout << "Task: ";
            getline(cin, task);
            verification_all_letters(task);
            Admin new_admin(b, name, stoi(nif),birthdate,income,task);

        case 2:
            cout << "Vehicle alocated to this Deliver information\n";
            cout << "Brand: ";
            getline(cin, brand);
            cout << "Type: ";
            getline(cin, type);
            cout << "Date: ";
            getline(cin, date);//tratar da data
            v(brand, type, date);

            Deliverer new_deliverer(b,name,stoi(nif),birthdate,income,background);

    }
*/







    return 0;
}
int modify_employee(Base &Porto, Base &Lisboa, Base &Faro){
    return 0;
}
int remove_employee(Base &Porto, Base &Lisboa, Base &Faro){
    return 0;
}
