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


    cout << "Welcome to Ugh Eats! We are going to tranform your lunch/dinner in a unforgetable gastronomical experience!\n"<<endl<<endl;
    extract_Clients(Porto, Lisboa, Faro);
    extract_Restaurants(Porto, Lisboa, Faro);
    extract_Deliveries(Porto, Lisboa,Faro);
    extract_Employees(Porto, Lisboa, Faro);
    extract_Bases(Porto, Lisboa, Faro);

    cout << "What are you?\n";
    cout << "1. Administrator\n";
    cout << "2. Client\n";

    menu_int_options(op, 1, 2);

    if (op == 1) {
        is_client = false;
    }
    else if (op == 2) {
        is_client = true;
    }


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
                    else if (choice == 2) {
                        if ((modify_order(Porto, Lisboa, Faro) == 0) || (modify_order(Porto, Lisboa, Faro) == 1)) {
                            break;
                        }
                        else {
                            menu = 2;
                        }
                    }
                    else if (choice == 3) {
                        if ((remove_order(Porto, Lisboa, Faro) == 0) || (remove_order(Porto, Lisboa, Faro) == 1)) {
                            break;
                        } else {
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
                        //aux = ProfitsByBase( Porto,Lisboa,Faro);
                        if(aux==1){
                            break;
                        }
                        else if(aux==2){
                            menu=6;
                        }

                    }
                    else if (choice == 2) {
                        //aux = ProfitsByRestaurant(Porto, Lisboa, Faro);
                        if(aux==1){
                            break;
                        }
                        else if(aux==2){
                            menu=6;
                        }
                    }
                    else if (choice == 3) {
                        //aux=ProfitsByClient(Porto, Lisboa, Faro);
                        if(aux==1){
                            break;
                        }
                        else if(aux==2){
                            menu=6;
                        }
                    }
                    else if (choice == 4) {
                        //aux=ProfitsByTimeInterval(Porto, Lisboa, Faro);
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
                        //aux = VisualizeAllClients( Porto,Lisboa,Faro);
                        if(aux==1){
                            break;
                        }
                        else if(aux==2){
                            menu=7;
                        }

                    }
                    else if (choice == 2) {
                        //aux = VisualizeBlacklistClients(Porto, Lisboa, Faro);
                        if(aux==1){
                            break;
                        }
                        else if(aux==2){
                            menu=7;
                        }
                    }
                    else if (choice == 3) {
                        //aux=VisualizeAllEmployees(Porto, Lisboa, Faro);
                        if(aux==1){
                            break;
                        }
                        else if(aux==2){
                            menu=7;
                        }
                    }
                    else if (choice == 4) {
                        //aux=VisualizeAllRestaurants(Porto, Lisboa, Faro);
                        if(aux==1){
                            break;
                        }
                        else if(aux==2){
                            menu=6;
                        }
                    }
                    else if (choice == 5) {
                        //aux=VisualizeAllDeliveries(Porto, Lisboa, Faro);
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