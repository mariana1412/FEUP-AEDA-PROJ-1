#include "Clients_functions.h"
int create_client(vector <Client> &Clients, string name_file, vector <Pack> Packs) { // //remove o cliente, atualiza o vector dos clientes e o ficheiro dos clientes

    int option;
    string aux;
    Client new_client;
    Address address;

    system("cls");
    cout << "-------------- CREATE CLIENT --------------" << endl;

    string base;
    cout << "Base: ";
    getline(cin, base);
    new_client.setClientBase(base);

    cout << "Name:";
    getline(cin, aux);
    new_client.setClientName(aux);

    cout << "NIF: ";
    getline(cin, aux);
    new_client.setClientNIF(aux);

    cout << "Address: ";
    getline(cin, aux);
    new_client.setClientAddress(aux);



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

    cancel = resize_function(cancel);
    cancel = formatting_string(cancel);

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

        cancel = resize_function(cancel);
        cancel = formatting_string(cancel);

    }



    if (cancel == "Yes") {
        clients.push_back(new_client); //acrescentar o novo cliente ao vetor dos Clientes

        update_clients(Clients, name_file); //passar nova informação para o ficheiro
        system("cls");

        cout << "Client successfully was created!" << endl << endl;
    }


    else {
        system("cls");

        cout << "Operation was canceled!" << endl << endl;
    }


    cout << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Clients Management. " << endl;


    cout << endl << "Choose what you want to do (integer number): ";
    cin >> option;


    while (cin.fail() || option > 2 || option <= 0) {
        if (cin.eof()) {
            cin.clear();
            cout << "Invalid operation, please insert a valid one: ";
            cin >> option;
        }
        else {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid operation, please insert a valid one: ";
            cin >> option;
        }
    }

    cin.ignore(1000, '\n');
    return option;

}