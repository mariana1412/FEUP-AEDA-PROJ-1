#include "Menus.h"

int MainMenu(){
    int option;
    cout << "--------------------------------------"<<endl;
    cout << "---------------- MENU ----------------" << endl<<endl;
    cout << "1. Clients Management" << endl;
    cout << "2. Order Management" << endl;
    cout << "3. Search by" << endl;
    cout << "4. Employees Management (only administrators) " << endl;
    cout << "5. Restaurants Management (only administrators) " << endl;
    cout << "6. Profits Calculation (only administrators) " << endl;
    cout << "7. Visualize Information (only administrators "<<endl;
    cout << "0. Exit" << endl;
    cout << "--------------------------------------"<<endl;
    menu_int_options(option,0,7);

    cin.ignore(1000,'\n');
    return option;
}

int ClientsManagement(){
    int option;
    cout << "--------------------------------------"<<endl;
    cout << "---------------- CLIENTS MANAGEMENT ----------------" << endl<<endl;
    cout << "1. Create Client " << endl;
    cout << "2. Modify Client" << endl;
    cout << "3. Remove Client " << endl;
    cout << "4. Return to the main menu " << endl;
    cout << "0. Exit" << endl;
    cout << "--------------------------------------"<<endl;
    menu_int_options(option,0,4);

    cin.ignore(1000,'\n');
    return option;
}
int EmployeesManagement(){
    int option;
    cout << "--------------------------------------"<<endl;
    cout << "---------------- EMPLOYEE MANAGEMENT ----------------" << endl<<endl;
    cout << "1. Create Employee " << endl;
    cout << "2. Modify Employee" << endl;
    cout << "3. Remove Employee " << endl;
    cout << "4. Return to the main menu " << endl;
    cout << "0. Exit" << endl;
    cout << "--------------------------------------"<<endl;

    menu_int_options(option,0,4);

    cin.ignore(1000,'\n');
    return option;
}
int SearchBy() {
    int option;
    cout << "--------------------------------------"<<endl;
    cout << "---------------- SEARCH BY ----------------" << endl << endl;
    cout << "1. Restaurant " << endl;
    cout << "2. Area" << endl;
    cout << "3. Price " << endl;
    cout << "4. Type of culinary " << endl;
    cout << "5. Return to the main menu " << endl;
    cout << "0. Exit" << endl;
    cout << "--------------------------------------"<<endl;
    menu_int_options(option, 0, 5);

    cin.ignore(1000, '\n');
    return option;
}

int RestaurantsManagement(){
    int option;
    cout << "-------------------------------------------------------"<<endl;
    cout << "---------------- RESTAURANT MANAGEMENT ----------------" << endl<<endl;
    cout << "1. Create Restaurant " << endl;
    cout << "2. Modify Restaurant" << endl;
    cout << "3. Remove Restaurant " << endl;
    cout << "4. Return to the main menu " << endl;
    cout << "0. Exit" << endl;
    cout << "--------------------------------------"<<endl;
    menu_int_options(option,0,4);
    cout << "-------------------------------------------------------"<<endl;
    cin.ignore(1000,'\n');
    return option;
}

int Order(){
    int option;
    cout << "--------------------------------------------------"<<endl;
    cout << "---------------- ORDER MANAGEMENT ----------------" << endl<<endl;
    cout << "1. Create Order " << endl;
    cout << "2. Modify Order (only administrators)" << endl;
    cout << "3. Remove Order (only administrators)" << endl;
    cout << "4. Return to the main menu " << endl;
    cout << "0. Exit" << endl;
    cout << "--------------------------------------------------"<<endl;
    menu_int_options(option,0,4);

    cin.ignore(1000,'\n');
    return option;
}


int ProfitsCalculation(){
    int option;
    cout << "-------------------------------------------------------"<<endl;
    cout << "---------------- PROFIT CALCULATION BY ----------------" << endl<<endl;
    cout << "1. Base " << endl;
    cout << "2. Restaurant" << endl;
    cout << "3. Client " << endl;
    cout << "4. Time Interval " << endl;
    cout << "5. Return to the main menu " << endl;
    cout << "0. Exit" << endl;

    menu_int_options(option,0,5);
    cout << "-------------------------------------------------------"<<endl;
    cin.ignore(1000,'\n');
    return option;
}
int VisualizeInformation(){
    int option;
    cout << "-------------------------------------------------------"<<endl;
    cout << "---------------- VISUALIZE INFORMATION ----------------" << endl<<endl;
    cout << "1. View all clients " << endl;
    cout << "2. View clients in the blacklist" << endl;
    cout << "3. View all employees" << endl;
    cout << "4. View all restaurants " << endl;
    cout << "5. View all deliveries " << endl;
    cout << "6. Return to the main menu"<<endl;
    cout << "0. Exit" << endl;

    menu_int_options(option,0,6);
    cout << "-------------------------------------------------------"<<endl;
    cin.ignore(1000,'\n');
    return option;
}