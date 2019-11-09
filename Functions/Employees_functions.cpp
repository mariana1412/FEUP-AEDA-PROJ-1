#include "Employees_functions.h"
int create_employee(Base &Porto, Base &Lisboa, Base &Faro){//the income of admin is set to 2500 in line 64

    string name, b, nif,birthdate,task,brand,type,date;
    vector<Employee*> e;
    Base base;
    int number,option;
    vector<Delivery> background;
    float income=0;
    Admin a;
    bool is_Valid=false;



    cout <<endl<< "-------------- CREATE EMPLOYEE --------------" << endl;

    cout << "What kind of Employee do you wish to create?\n";
    cout << "1: Admin\n" << "2: Deliverer\n";
    menu_int_options(number,1, 2);

    cout << "Base: ";
    cin.ignore('\n',1000);
    getline(cin, b);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, b);
    }
    verification_base(b);

    if (b == "Porto") {
        e = Porto.getEmployees();
        base = Porto;
    }
    else if (b == "Lisboa") {
        e = Lisboa.getEmployees();
        base = Lisboa;
    }
    else if (b == "Faro") {
        e = Faro.getEmployees();
        base = Faro;
    }


    cout << "Name:";
    getline(cin, name);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, name);
    }
    verification_all_letters(name);


    cout << "NIF: ";
    getline(cin, nif);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, nif);
    }
    verification_nif(nif);

    //check if already exists
    do{
        try{
            employee_already_exists(nif,base);
            is_Valid=true;
        }
        catch(EmployeeAlreadyExists &msg){
            cout <<endl<< "ATENTION: Employee with NIF "<< msg.getNIF()<<" already exists."<<endl;
            is_Valid=false;
            cout << "Try again!"<<endl;
            cout << "NIF: ";
            getline(cin, nif);
            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, nif);
            }
            verification_nif(nif);
        }

    }while(!is_Valid);


    cout << "Birthdate: ";
    getline(cin, birthdate);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, birthdate);
    }
    verification_date(birthdate);
    Time b_date;
    b_date.setDate(birthdate);


    switch (number) {
        case 1:
        {
            cout << "Task: ";
            getline(cin, task);
            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, task);
            }
            verification_all_letters(task);
            income =2500;
            Employee* f=new Admin(b, name, stoi(nif),b_date,income,task);

            cout<<f;//mostrar o empregado para confirmaçao
            if (confirm_modifications("create","employee")){
                e.push_back(f);
                cout << "Employee was successfully created!" << endl << endl;

            }
            else{    //caso de nao se confirmar a criaçao
                cout << "Operation was canceled! " << endl << endl;
                //voltar para o menu
                cout << "1. Return to Main Menu. " << endl;
                cout << "2. Return to Clients Management. " << endl;
                menu_int_options(option,1,2);

                return option;
            }
        }


        case 2:
            {
            cout << "Vehicle alocated to this Deliver information\n";
            cout << "Brand: ";
            getline(cin, brand);
            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, brand);
            }
            verification_all_letters(brand);
            cout << "Type: ";
            getline(cin, type);
            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, type);
            }
            verification_all_letters(type);
            cout << "Date: ";
            getline(cin, date);
            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, date);
            }
            verification_date(date);
            Time v_bdate;
            v_bdate.setDate(date);
            Vehicle v(brand, type, v_bdate);
            Employee* f=new Deliverer(b,name,stoi(nif),v_bdate,income,v,background);
            cout<<f;//mostrar o empregado para confirmaçao
            if (confirm_modifications("create","employee")){
                e.push_back(f);
                cout << "Employee was successfully created!" << endl << endl;

            }
            else{    //caso de nao se confirmar a criaçao
                cout << "Operation was canceled! " << endl << endl;
                //voltar para o menu
                cout << "1. Return to Main Menu. " << endl;
                cout << "2. Return to Clients Management. " << endl;
                menu_int_options(option,1,2);

                return option;
            }
        }
    }
}
int modify_employee(Base &Porto, Base &Lisboa, Base &Faro){





    return 0;
}
int remove_employee(Base &Porto, Base &Lisboa, Base &Faro){
    return 0;
}


bool employee_already_exists(string nif, Base &b){
    vector<Employee*> e= b.getEmployees();
    vector<Employee*>::const_iterator it = b.getEmployees().begin();

    while(it != b.getEmployees().end()){
        if (stoi(nif) == (*it)->getNif()){
            throw EmployeeAlreadyExists(nif);
        }
        advance(it, 1);
    }
    return true;

}
