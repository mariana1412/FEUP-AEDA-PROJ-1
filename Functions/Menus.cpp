#include "Menus.h"

int MainMenu(){
    int option;

    cout << "---------------- MENU ----------------" << endl<<endl;
    cout << "1. Clients Management" << endl;
    cout << "2. Order" << endl;
    cout << "3. Search by" << endl;
    cout << "4. Employees Management (only administrators) " << endl;
    cout << "5. Restaurants Management (only administrators) " << endl;
    cout << "6. Profits Calculation (only administrators) " << endl;
    cout << "0. Exit" << endl;

    cout << endl << "Choose an option from the menu(integer number): ";
    cin >> option;
    menu_int_options(option,0,6);

    cin.ignore(1000,'\n');
    return option;
}

int ClientsManagement(){
    int option;
    cout << "---------------- CLIENTS MANAGEMENT ----------------" << endl<<endl;
    cout << "1. Create Client " << endl;
    cout << "2. Modify Client" << endl;
    cout << "3. Remove Client " << endl;
    cout << "4. Return to the main menu " << endl;
    cout << "0. Exit" << endl;

    cout << endl << "Choose an option from the menu(integer number): ";
    cin >> option;
    menu_int_options(option,0,4);

    cin.ignore(1000,'\n');
    return option;
}
int EmployeesManagement(){
    int option;
    cout << "---------------- Employee MANAGEMENT ----------------" << endl<<endl;
    cout << "1. Create Employee " << endl;
    cout << "2. Modify Employee" << endl;
    cout << "3. Remove Employee " << endl;
    cout << "4. Return to the main menu " << endl;
    cout << "0. Exit" << endl;

    cout << endl << "Choose an option from the menu(integer number): ";
    cin >> option;
    menu_int_options(option,0,4);

    cin.ignore(1000,'\n');
    return option;
}
int SearchBy() {
    int option;
    cout << "---------------- SEARCH BY ----------------" << endl << endl;
    cout << "1. Restaurant " << endl;
    cout << "2. Area" << endl;
    cout << "3. Price " << endl;
    cout << "4. Type of culinary " << endl;
    cout << "5. Return to the main menu " << endl;
    cout << "0. Exit" << endl;

    cout << endl << "Choose an option from the menu(integer number): ";
    cin >> option;
    menu_int_options(option, 0, 5);

    cin.ignore(1000, '\n');
    return option;
}



int RestaurantsManagement(){
    int option;
    cout << "---------------- Restaurant MANAGEMENT ----------------" << endl<<endl;
    cout << "1. Create Restaurant " << endl;
    cout << "2. Modify Restaurant" << endl;
    cout << "3. Remove Restaurant " << endl;
    cout << "4. Return to the main menu " << endl;
    cout << "0. Exit" << endl;

    cout << endl << "Choose an option from the menu(integer number): ";
    cin >> option;
    menu_int_options(option,0,4);

    cin.ignore(1000,'\n');
    return option;
}

int Order(){
    return 0;
}





int ProfitsCalculation(){
    int option;
    cout << "---------------- Profit Calculation by ----------------" << endl<<endl;
    cout << "1. Base " << endl;
    cout << "2. Provider" << endl;
    cout << "3. Client " << endl;
    cout << "4. Time Interval " << endl;
    cout << "5. Return to the main menu " << endl;
    cout << "0. Exit" << endl;

    cout << endl << "Choose an option from the menu(integer number): ";
    cin >> option;
    menu_int_options(option,0,5);

    cin.ignore(1000,'\n');
    return option;
}