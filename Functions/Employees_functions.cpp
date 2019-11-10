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
    Time b_date=stringToDate(birthdate);


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
            Time v_bdate=stringToDate(date);
            Vehicle v(brand, type, v_bdate);
            Employee* f=new Deliverer(b,name,stoi(nif),v_bdate,income,v,background);
            cout<<f;//mostrar o empregado para confirmaçao
            if (confirm_modifications("create","employee")){
                e.push_back(f);
                cout << "Employee was successfully created!" << endl << endl;

            }
            else{    //caso de nao se confirmar a criaçao
                cout << "Operation was canceled! " << endl << endl;
            }
        }
    }
    //voltar para o menu
    cout << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Clients Management. " << endl;
    menu_int_options(option,1,2);

    return option;
}
int modify_employee(Base &Porto, Base &Lisboa, Base &Faro){

    string b,auxiliar,aux;
    int number,i;
    vector <Employee*> v;
    Base base;
    bool is_valid=false;
    cout << endl << endl << "-------------- MODIFY EMPLOYEE --------------" << endl << endl;
    cout << "Base: ";
    getline(cin, b);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout <<  "Invalid base. Please insert a valid input: ";
        getline(cin, b);
    }

    verification_base(b);

    if (b == "Porto") {
        v = Porto.getEmployees();
        base = Porto;
    }
    else if (b == "Lisboa") {
        v = Lisboa.getEmployees();
        base = Lisboa;
    }
    else if (b == "Faro") {
        v = Faro.getEmployees();
        base = Faro;
    }

    cout << "What do you know about this employee?\n" << endl;//so vamos ter estas duas opçoes porque sao os atributos nao mutaveis do cliente
    cout << "1: Name\n"<< "2: NIF\n" <<"0: Return to the main menu\n" ;
    menu_int_options(number,0,2);

    switch (number) {
        case 0:
            return number;
        case 1:
            cout << "Name: ";
            cin.ignore('\n',1000);
            getline(cin, auxiliar);
            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, auxiliar);
            }
            verification_all_letters(auxiliar);
            i = string_sequential_search_e(v, auxiliar);
            break;
        case 2:
            cout << "NIF: ";
            cin.ignore('\n',1000);
            getline(cin, auxiliar);
            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, auxiliar);
            }
            verification_nif(auxiliar);
            i = int_sequential_search_e(v, stoi(auxiliar));
            break;
    }


    while(i == -1){
        cout << "The employee inserted does not exist. Try again: ";//dar opçao de tentar outra vez
        cout << "What do you know about this employee?\n" << endl;//so vamos ter estas duas opçoes porque sao os atributos nao mutaveis do cliente
        cout << "1: Name\n" << "2: NIF\n"<<"0: Return to the main menu\n";
        menu_int_options(number,1,2);

        switch(number){
            case 0:
                return number;
            case 1:
                cout << "Name: ";
                cin.ignore('\n',1000);
                getline(cin, auxiliar);
                while(cin.fail() && cin.eof()){
                    cin.clear();
                    cout << "Invalid character. Please insert a valid input: ";
                    getline(cin, auxiliar);
                }
                verification_all_letters(auxiliar);
                i = string_sequential_search_e(v, auxiliar);
                break;
            case 2:
                cout << "NIF: ";
                cin.ignore('\n',1000);
                getline(cin, auxiliar);
                while(cin.fail() && cin.eof()){
                    cin.clear();
                    cout << "Invalid character. Please insert a valid input: ";
                    getline(cin, auxiliar);
                }
                verification_nif(auxiliar);
                i = int_sequential_search_e(v, stoi(auxiliar));
                break;
        }
    }


    Admin *a= dynamic_cast<Admin *> (v[i]);
    if(a!=NULL){//quer dizer que é admin
        int op;
        cout << "You can only change the task."<<endl;
        cout<< "What do you wish to do? "<<endl;
        cout<< "1.Change the task\t 2.Return to the Main Menu"<<endl;
        menu_int_options(op,1,2);
        switch(op){
            case 1:{
                cout << "Task: ";
                getline(cin, aux);
                while(cin.fail() && cin.eof()){
                    cin.clear();
                    cout << "Invalid character. Please insert a valid input: ";
                    getline(cin, aux);
                }
                verification_all_letters(aux);
                if(confirm_modifications("modify","employee")){
                    a->setTask(aux);
                    cout << "Employee was successfully created!" << endl << endl;
                }
                else{
                    cout << "Operation was canceled! " << endl << endl;
                }
                //voltar para o menu
                int option;
                cout << "1. Return to Main Menu. " << endl;
                cout << "2. Return to Clients Management. " << endl;
                menu_int_options(option,1,2);

                return option;
            }
            case 2:
            {
                cout << "Operation was canceled! " << endl << endl;
                return 0;
            }
        }

    }
    else{
        Deliverer *d= dynamic_cast<Deliverer*>(v[i]);
        int op;
        cout << "You can only change the allocated vehicle."<<endl;
        cout<< "What do you wish to do? "<<endl;
        cout<< "1.Change the allocated vehicle\n 2.Return to the Main Menu"<<endl;
        menu_int_options(op,1,2);
        switch(op){
            case 1:{
                string brand, type, date;
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
                Time v_bdate=stringToDate(date);
                Vehicle ve(brand, type, v_bdate);
                if(confirm_modifications("modify","employee")){
                    d->setVehicle(ve);
                    cout << "Employee was successfully created!" << endl << endl;
                }
                else{
                    cout << "Operation was canceled! " << endl << endl;
                }
                //voltar para o menu
                int option;
                cout << "1. Return to Main Menu. " << endl;
                cout << "2. Return to Clients Management. " << endl;
                menu_int_options(option,1,2);

                return option;
            }
            case 2:
            {
                cout << "Operation was canceled! " << endl << endl;
                return 0;
            }

        }

    }

    return 0;

}
int remove_employee(Base &Porto, Base &Lisboa, Base &Faro){
    vector<Employee*> v;
    string base, auxiliar;
    int i=0, number,option;

    cout << "-------------- REMOVE CLIENT --------------" << endl;

    cout << "Employee's Base: ";
    getline(cin, base);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, base);
    }
    verification_base(base);

    if (base == "Porto") {
        v = Porto.getEmployees();
    }
    else if (base == "Lisboa") {
        v = Lisboa.getEmployees();
    }
    else if (base == "Faro") {
        v = Faro.getEmployees();
    }
    cout << "What do you know about this employee?\n" << endl;//so vamos ter estas duas opçoes porque sao os atributos nao mutaveis do cliente
    cout << "1: Name\n"<< "2: NIF\n" <<"0: Return to the main menu\n" ;
    menu_int_options(number,0,2);

    switch (number) {
        case 0:
            return number;
        case 1:
            cout << "Name: ";
            cin.ignore('\n',1000);
            getline(cin, auxiliar);
            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, auxiliar);
            }
            verification_all_letters(auxiliar);
            i = string_sequential_search_e(v, auxiliar);
            break;
        case 2:
            cout << "NIF: ";
            cin.ignore('\n',1000);
            getline(cin, auxiliar);
            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, auxiliar);
            }
            verification_nif(auxiliar);
            i = int_sequential_search_e(v, stoi(auxiliar));
            break;
    }

    while (i == -1) {
        cout << "The employee inserted does not exist. Try again: ";//dar opçao de tentar outra
        cout << "What do you know about this employee?\n" << endl;//so vamos ter estas duas opçoes porque sao os atributos nao mutaveis do cliente
        cout << "1: Name\n" << "2: NIF\n"<<"0: Return to the main menu\n";
        menu_int_options(number,1,2);
        switch (number) {
            case 0:
                return number;
            case 1:
                cout << "Name: ";
                cin.ignore('\n',1000);
                getline(cin, auxiliar);
                while(cin.fail() && cin.eof()){
                    cin.clear();
                    cout << "Invalid character. Please insert a valid input: ";
                    getline(cin, auxiliar);
                }
                verification_all_letters(auxiliar);
                i = string_sequential_search_e(v, auxiliar);
                break;
            case 2:
                cout << "NIF: ";
                cin.ignore('\n',1000);
                getline(cin, auxiliar);
                while(cin.fail() && cin.eof()){
                    cin.clear();
                    cout << "Invalid character. Please insert a valid input: ";
                    getline(cin, auxiliar);
                }
                verification_nif(auxiliar);
                i = int_sequential_search_e(v, stoi(auxiliar));
                break;
        }
    }

    cout<< v[i];//mostrar o funcionario
    if (confirm_modifications("remove", "employee")) {
        if (base == "Porto") {
            Porto.getEmployees().erase(Porto.getEmployees().begin() + i);
        }
        else if (base == "Lisboa") {
            Lisboa.getEmployees().erase(Lisboa.getEmployees().begin() + i);
        }
        else if (base == "Faro") {
            Faro.getEmployees().erase(Faro.getEmployees().begin() + i);

        }
        cout << "Employee was successfully removed!" << endl << endl;
    }
    else {//caso de nao se confirmar a remoçao
        cout << "Operation was canceled! " << endl << endl;
    }

    cout << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Clients Management. " << endl;
    menu_int_options(option,1,2);
    return option;
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
int string_sequential_search_e(const vector<Employee*> &v, string x) {//retorna o indice do vetor onde se encontra x
    for (unsigned int i = 0; i < v.size(); i++)
        if (v[i]->getName() == x)
            return i; // encontrou
    return -1; // não encontrou
}

int int_sequential_search_e(const vector<Employee*> &v, int x) {//retorna o indice do vetor onde se encontra x
    for (unsigned int i = 0; i < v.size(); i++)
        if (v[i]->getNif() == x)
            return i; // encontrou
    return -1; // não encontrou
}