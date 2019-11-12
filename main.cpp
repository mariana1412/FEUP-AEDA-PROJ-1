#include <iostream>
#include <Windows.h>
#include "Functions/ReadingFiles.h"
#include "Functions/WriteToFile.h"
#include "Functions/Verification_Inputs.h"
#include "Functions/Menus.h"
#include "Functions/Clients_functions.h"
#include "Functions/Employees_functions.h"
#include "Functions/Restaurants_functions.h"
#include "Functions/Order_functions.h"
#include "Functions/ProfitsCalculation.h"
#include "Functions/Visualize_Information.h"

const vector<string> nearby_Porto = { "Matosinhos", "Vila Nova de Gaia", "Maia", "Gondomar", "Porto" };
const vector<string> nearby_Lisboa = { "Oeiras", "Loures", "Amadora", "Odivelas","Lisboa" };
const vector<string> nearby_Faro = { "Loulé","Olhão", "São Brás de Alportel","Faro" };

using namespace std;

int main() {

    SetConsoleOutputCP(1254);
    SetConsoleCP(1254);
    Base Porto, Lisboa, Faro;
    bool is_client;
    int op;
    string verification;



    cout << "Welcome to Ugh Eats! We are going to tranform your lunch/dinner in a unforgetable gastronomical experience!\n"<<endl<<endl;
    extract_Clients(Porto, Lisboa, Faro);
    extract_Restaurants(Porto, Lisboa, Faro);
    extract_Deliveries(Porto, Lisboa,Faro);
    extract_Employees(Porto, Lisboa, Faro);
    extract_Bases(Porto, Lisboa, Faro);
    Base og_Porto, og_Lisboa, og_Faro;
    og_Porto = Porto; og_Lisboa = Lisboa; og_Faro = Faro;

    cout << "What are you?\n";
    cout << "1. Administrator\n";
    cout << "2. Client\n";

    menu_int_options(op, 1, 2);
    cin.ignore(1000, '\n');
    if (op == 1){
        cout << "Please enter your admin NIF (Press 0 to login as a client): ";
        while (true) {
            getline(cin, verification);
            if (verification == "0"){
                is_client = true;
                break;
            }
            while (cin.fail() && cin.eof()) {
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, verification);

            }
            verification_nif(verification);
            if (stringToAdminSearch(verification, Porto)){
                cout << "Logged in as a Porto admin" << endl;
                is_client = false;
                break;
            }
            if (stringToAdminSearch(verification, Lisboa)){
                cout << "Logged in as a Lisboa admin" << endl;
                is_client = false;
                break;
            }
            if (stringToAdminSearch(verification, Faro)){
                cout << "Logged in as a Faro admin" << endl;
                is_client = false;
                break;
            }
            cout << "That NIF is not from an admin! Please enter an admin's NIF or enter 0 to login as a client: ";
        }
    }

    if (op == 2)
        is_client = true;


    int menu;

    do {
        menu = MainMenu();
        if (menu == 1) {
            int choice,aux;
            do {
                choice = ClientsManagement();
                if (choice == 1) {
                    aux=create_client(Porto, Lisboa, Faro);
                    if(aux==1){
                        break;
                    }
                    else if(aux == 2){
                        menu =1;
                    }

                }
                else if (choice == 2) {
                    aux=modify_client(Porto, Lisboa, Faro);
                    if(aux==1){
                        break;
                    }
                    else if(aux == 2){
                        menu =1;
                    }
                }
                else if (choice == 3) {
                    aux=remove_client(Porto, Lisboa, Faro);
                    if(aux==1){
                        break;
                    }
                    else if(aux == 2){
                        menu=1;
                    }
                }
                else if (choice == 0) {
                    menu = 0;
                    break;
                }

            } while (choice != 4);
        }
        else if (menu == 2) {
            int choice,aux;
            do {
                if (is_client){
                    cout << endl<<"ATENTION: You do not have access to this functionality.\n"<<endl;
                    choice = 0;
                    break;
                }
                else{
                    choice = Order();
                    if (choice == 1) {
                        aux=create_order(Porto, Lisboa, Faro);
                        if ((aux == 0) || (aux == 1)) {
                            break;
                        }
                        else {
                            menu = 2;
                        }
                    }
                    else if (choice == 0) {
                        menu = 0;
                        break;
                    }
                }

            } while (choice != 4);
        }
        else if (menu == 3) {
            int choice;
            do {
                choice = SearchBy();
                if (choice == 1) {
                    //TO DO: SearchByRestaurant();
                }
                else if (choice == 2) {
                    //TO DO : SearchByArea();
                }
                else if (choice == 3) {
                    //TO DO: SearchByPrice();
                }
                else if (choice == 4) {
                    //TO DO: SearchByTypeOfCulinary();
                }
                else if (choice == 0) {
                    menu = 0;
                    break;
                }

            } while (choice != 5);
        }
        else if (menu == 4) {
            int choice,aux;
            do {
                if (is_client) {
                    cout << endl<<"ATENTION: You do not have access to this functionality.\n"<<endl;
                    choice = 0;
                    break;
                }
                else {
                    choice = EmployeesManagement();
                    if (choice == 1) {
                        aux=create_employee(Porto, Lisboa, Faro);
                        if(aux==1){
                            break;
                        }
                        else if (aux==2){
                            menu = 4;
                        }
                    }
                    else if (choice == 2) {
                        aux=modify_employee(Porto, Lisboa, Faro);
                        if (aux==1) {
                            break;
                        }
                        else if (aux==2) {
                            menu = 4;
                        }
                    }
                    else if (choice == 3) {
                        aux=remove_employee(Porto, Lisboa, Faro);
                        if(aux==1){
                            break;
                        }
                        else if(aux==2){
                            menu = 4;
                        }
                    }

                    else if (choice == 0) {
                        menu = 0;
                        break;
                    }
                }
            } while (choice != 4);


        }

        else if (menu == 5){
            int choice,aux;
            do {
                if (is_client) {
                    cout << endl<<"ATENTION: You do not have access to this functionality.\n"<<endl;
                    choice = 0;
                    break;
                }
                else {
                    choice = RestaurantsManagement();
                    if (choice == 1) {
                        aux=create_restaurant(Porto, Lisboa, Faro);
                        if(aux==1){
                            break;
                        }
                        else if(aux==2){
                            menu=5;
                        }
                    }
                    else if (choice == 2) {
                        aux=modify_restaurant(Porto, Lisboa, Faro);
                        if(aux==1){
                            break;
                        }
                        else if(aux==2){
                            menu=5;
                        }

                    }
                    else if (choice == 3) {
                       aux= remove_restaurant(Porto, Lisboa, Faro);
                        if(aux==1){
                            break;
                        }
                        else if(aux==2){
                            menu=5;
                        }

                    }
                    else if (choice == 0) {
                        menu = 0;
                        break;
                    }
                }
            } while (choice != 4);
        }
        else if (menu == 6) {
            int choice,aux;
            do {
                if (is_client) {
                    cout << endl<<"ATENTION: You do not have access to this functionality.\n"<<endl;
                    choice = 0;
                    break;
                }
                else {
                    choice = ProfitsCalculation();
                    if (choice == 1) {
                        aux = ProfitsByBase( Porto,Lisboa,Faro);
                        if(aux==1){
                            break;
                        }
                        else if(aux==2){
                            menu=6;
                        }

                    }
                    else if (choice == 2) {
                        aux = ProfitsByRestaurant(Porto, Lisboa, Faro);
                        if(aux==1){
                            break;
                        }
                        else if(aux==2){
                            menu=6;
                        }
                    }
                    else if (choice == 3) {
                        aux=ProfitsByClient(Porto, Lisboa, Faro);
                        if(aux==1){
                            break;
                        }
                        else if(aux==2){
                            menu=6;
                        }
                    }
                    else if (choice == 4) {
                        aux=ProfitByTimeInterval(Porto, Lisboa, Faro);
                        if(aux==1){
                            break;
                        }
                        else if(aux==2){
                            menu=6;
                        }
                    }
                    else if (choice == 0) {
                        menu = 0;
                        break;
                    }

                }
            } while (choice != 5);
        }

        else if(menu == 7){
            int choice,aux;
            do {
                if (is_client) {
                    cout << endl<<"ATENTION: You do not have access to this functionality.\n"<<endl;
                    choice = 0;
                    break;
                }
                else {
                    choice = VisualizeInformation();
                    if (choice == 1) {
                        aux = visualize_clients( Porto,Lisboa,Faro);
                        if(aux==1){
                            break;
                        }
                        else if(aux==2){
                            menu=7;
                        }

                    }
                    else if (choice == 2) {
                        aux = visualize_blaclist(Porto, Lisboa, Faro);
                        if(aux==1){
                            break;
                        }
                        else if(aux==2){
                            menu=7;
                        }
                    }
                    else if (choice == 3) {
                        aux = visualize_employees(Porto, Lisboa, Faro);
                        if(aux==1){
                            break;
                        }
                        else if(aux==2){
                            menu=7;
                        }
                    }
                    else if (choice == 4) {
                        aux = visualize_restaurants(Porto, Lisboa, Faro);
                        if(aux==1){
                            break;
                        }
                        else if(aux==2){
                            menu=6;
                        }
                    }
                    else if (choice == 5) {
                        aux = visualize_deliveries(Porto, Lisboa, Faro);
                        if(aux==1){
                            break;
                        }
                        else if(aux==2){
                            menu=7;
                        }
                    }
                    else if (choice == 0) {
                        menu = 0;
                        break;
                    }

                }
            } while (choice != 6);
        }

    } while (menu != 0);

    cout << endl;
    cout << endl << "Thank you! We hope you've enjoyed your experience with Ugh Eats!" << endl;
    write_Clients(Porto, Lisboa, Faro);
    write_Restaurants(Porto, Lisboa, Faro);
    write_Deliveries(Porto, Lisboa, Faro);
    write_Employees(Porto, Lisboa, Faro);
    write_Bases(Porto, Lisboa, Faro);
    return 0;
}