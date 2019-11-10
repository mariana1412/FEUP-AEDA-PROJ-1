#include "Clients_functions.h"

int create_client(Base &Porto, Base &Lisboa, Base &Faro) {
    string aux,b;
    vector<Client> v;
    Client new_client;
    Base base;
    bool is_Valid;
    int option;

    cout << "-------------- CREATE CLIENT --------------" << endl;

    cout << "Base:";
    getline(cin, aux);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, aux);
    }
    verification_base(aux);
    new_client.setBase(aux);

    if (aux == "Porto") {
        base = Porto;
        b="Porto";
    }
    else if (aux == "Lisboa") {
        base = Lisboa;
        b="Lisboa";
    }
    else if(aux == "Faro"){
        base = Faro;
        b="Faro";
    }
    v=base.getClients();

    cout << "Name:";
    getline(cin, aux);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, aux);
    }
    verification_all_letters(aux);
    new_client.setName(aux);

    cout << "NIF:";
    getline(cin, aux);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, aux);
    }
    verification_nif(aux);
    do{
        try{
            client_already_exists(aux,base);
            is_Valid=true;
        }
        catch(ClientAlreadyExists &msg){
            cout <<endl<< "ATENTION: Client with NIF "<< msg.getNIF()<<" already exists."<<endl;
            is_Valid=false;
            cout << "Try again!"<<endl;
            cout << "NIF:";
            getline(cin, aux);
            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, aux);
            }
            verification_nif(aux);
        }

    }while(!is_Valid);
    new_client.setNif(stoi(aux));


    cout << "Address:";//nao ha verificaçao porque pode ter tanto letras como numeros
    getline(cin, aux);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, aux);
    }
    new_client.setAddress(aux);

    cout << "County: ";
    getline(cin, aux);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, aux);
    }
    new_client.setCounty(aux);
    verification_all_letters(aux);
    new_client.setBlack(false);



    cout <<endl<<endl<< "----------------------------------------------"<<endl;
    cout<<new_client;//para confirmar  a informaçao
    if (confirm_modifications("create", "client")) {
        cout<<endl<<endl;
        try {
            black_list(base, new_client.getNif());//se o cliente estiver na black_list é rejeitado
        }
        catch (BlackList &e) {
            cout << e.getMsg() << endl<<endl;
            cout << "1. Return to Main Menu. " << endl;
            cout << "2. Return to Clients Management. " << endl;
            menu_int_options(option,1,2);
            return option;
        }
        try {
            out_of_area(v, new_client.getCounty(),b);//caso o cliente nao resida no concelho da base ou nos concelhos fronteira tambem é rejeitado
        }
        catch (OutOfArea &b) {
            cout << b.getMsg() << endl<<endl;
            cout << "1. Return to Main Menu. " << endl;
            cout << "2. Return to Clients Management. " << endl;
            menu_int_options(option,1,2);
            return option;
        }

        if (new_client.getBase() == "Porto") {
            Porto.addClient(new_client);
            cout << "Client was successfully created!" << endl << endl;
        }
        else if (new_client.getBase() == "Lisboa") {
            Lisboa.addClient(new_client);
            cout << "Client was successfully created!" << endl << endl;
        }
        else if(new_client.getBase() == "Faro"){
            Faro.addClient(new_client);
            cout << "Client was successfully created!" << endl << endl;
        }
    }
    else {    //caso de nao se confirmar a criaçao
        cout << "Operation was canceled! " << endl << endl;
    }
    //voltar para o menu
    cout << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Clients Management. " << endl;
    menu_int_options(option,1,2);

    return option;
}

int modify_client(Base &Porto, Base &Lisboa, Base &Faro) {

    vector<Client> v;
    string base;
    int i=0;
    string auxiliar;
    int number, option,op;

    cout << "-------------- MODIFY CLIENT --------------" << endl;

    cout << "Client's Base: ";
    getline(cin, base);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, base);
    }
    verification_base(base);

    if (base == "Porto") {
        v = Porto.getClients();
    }
    else if (base == "Lisboa") {
        v = Lisboa.getClients();
    }
    else if (base == "Faro") {
        v = Faro.getClients();
    }


    cout << "What do you know about this client?\n" << endl;//so vamos ter estas duas opçoes porque sao os atributos nao mutaveis do cliente
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
            i = string_sequential_search_c(v, auxiliar);
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
            i = int_sequential_search_c(v, stoi(auxiliar));
            break;
    }

    if (i == -1) {
        cout << "The client inserted does not exist. Try again: ";//dar opçao de tentar outra vez
        while(i == -1){
            cout << "What do you know about this client?\n" << endl;//so vamos ter estas duas opçoes porque sao os atributos nao mutaveis do cliente
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
                    i = string_sequential_search_c(v, auxiliar);
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
                    i = int_sequential_search_c(v, stoi(auxiliar));
                    break;

            }

        }
    }
    else {
        string new_info, new_info2, new_info3;
        cout << v[i];        //mostrar o cliente para saber o que quer mudar
        cout << "What do you wish to change?\n";
        cout << "1: Base\n" << "2: Address\n" << "3: Both";
        menu_int_options(option,1,3);
        if (option == 1) {
            cout << "Base: ";
            cin.ignore('\n',1000);
            getline(cin, new_info);
            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, new_info);
            }
            verification_base(new_info);
            base = new_info;
            if (base == "Porto") {
                v = Porto.getClients();
            }
            else if (base == "Lisboa") {
                v = Lisboa.getClients();
            }
            else if (base == "Faro") {
                v = Faro.getClients();
            }
            if (confirm_modifications("modify", "client")) {
                try {
                    out_of_area(v, v[i].getCounty(),new_info);//caso o cliente nao resida no concelho da base ou nos concelhos fronteira tambem é rejeitado
                }
                catch (OutOfArea &b) {
                    cout << b.getMsg() << endl;
                    cout << "1. Return to Main Menu. " << endl;
                    cout << "2. Return to Clients Management. " << endl;
                    menu_int_options(option,1,2);
                    return option;
                }
                if (base == "Porto") {
                    Porto.getClients()[i].setBase(new_info);
                }
                else if (base == "Lisboa"){
                    Lisboa.getClients()[i].setBase(new_info);
                }
                else if (base == "Faro"){
                    Faro.getClients()[i].setBase(new_info);
                }
                cout << "Client was successfully modified!" << endl << endl;
            }
            else {//caso de nao se confirmar a mudança
                cout << "Operation was canceled! " << endl << endl;
            }
        }
        else if (option == 2) {
            cout << "Address: ";
            cin.ignore('\n',1000);
            getline(cin, new_info);
            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, new_info);
            }
            cout << "County: ";
            getline(cin, new_info2);
            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, new_info2);
            }
            verification_all_letters(new_info2);
            if (confirm_modifications("modify", "client")) {
                try {
                    out_of_area(v, new_info2,base);//caso o cliente nao resida no concelho da base ou nos concelhos fronteira tambem é rejeitado
                }
                catch (OutOfArea &b) {
                    cout << b.getMsg() << endl;
                    cout << "1. Return to Main Menu. " << endl;
                    cout << "2. Return to Clients Management. " << endl;
                    menu_int_options(option,1,2);
                    return option;
                }
                if (base == "Porto") {
                    Porto.getClients()[i].setAddress(new_info);
                    Porto.getClients()[i].setCounty(new_info2);
                    cout << "Client was successfully modified!" << endl << endl;
                }
                else if (base == "Lisboa") {
                    Lisboa.getClients()[i].setAddress(new_info);
                    Lisboa.getClients()[i].setCounty(new_info2);
                    cout << "Client was successfully modified!" << endl << endl;
                }
                else if (base == "Faro") {
                    Faro.getClients()[i].setAddress(new_info);
                    Faro.getClients()[i].setCounty(new_info2);
                    cout << "Client was successfully modified!" << endl << endl;
                }

            }
            else {//caso de nao se confirmar a mudança
                cout << "Operation was canceled! " << endl << endl;
                cout << "1. Return to Main Menu. " << endl;
                cout << "2. Return to Clients Management. " << endl;
                menu_int_options(op,1,2);
                return op;
            }
        }
        else if(option == 3){
            cout << "Base: ";
            cin.ignore('\n',1000);
            getline(cin, new_info);
            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, new_info);
            }
            verification_base(new_info);
            base = new_info;
            if (base == "Porto") {
                v = Porto.getClients();
            }
            else if (base == "Lisboa") {
                v = Lisboa.getClients();
            }
            else if (base == "Faro") {
                v = Faro.getClients();
            }

            cout << "Address: ";
            getline(cin, new_info2);
            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, new_info2);
            }
            cout << "County: ";
            getline(cin, new_info3);
            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, new_info3);
            }
            verification_all_letters(new_info3);
            if (confirm_modifications("modify", "client")) {
                try {
                    out_of_area(v, new_info3,base);//caso o cliente nao resida no concelho da base ou nos concelhos fronteira tambem é rejeitado
                }
                catch (OutOfArea &b) {
                    cout << b.getMsg() << endl<<endl;
                    cout << "1. Return to Main Menu. " << endl;
                    cout << "2. Return to Clients Management. " << endl;
                    menu_int_options(op,1,2);
                    return op;
                }
                if (base == "Porto") {
                    Porto.getClients()[i].setBase(new_info);
                    Porto.getClients()[i].setAddress(new_info2);
                    Porto.getClients()[i].setCounty(new_info3);
                    cout << "Client was successfully modified!" << endl << endl;
                }
                else if (base == "Lisboa") {
                    Lisboa.getClients()[i].setBase(new_info);
                    Lisboa.getClients()[i].setAddress(new_info2);
                    Lisboa.getClients()[i].setCounty(new_info3);
                    cout << "Client was successfully modified!" << endl << endl;
                }
                else if (base == "Faro") {
                    Faro.getClients()[i].setBase(new_info);
                    Faro.getClients()[i].setAddress(new_info2);
                    Faro.getClients()[i].setCounty(new_info3);
                    cout << "Client was successfully modified!" << endl << endl;
                }
            }
            else {//caso de nao se confirmar a mudança
                cout << "Operation was canceled! " << endl << endl;
            }
        }
    }

    //voltar para o menu
    cout << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Clients Management. " << endl;
    menu_int_options(op,1,2);
    return op;
}


int remove_client(Base &Porto, Base &Lisboa, Base &Faro) {
    vector<Client> v;
    string base, auxiliar;
    int i=0, number,option;

    cout << "-------------- REMOVE CLIENT --------------" << endl;

    cout << "Client's Base:";
    getline(cin, base);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, base);
    }
    verification_base(base);

    if (base == "Porto") {
        v = Porto.getClients();
    }
    else if (base == "Lisboa") {
        v = Lisboa.getClients();
    }
    else if (base == "Faro") {
        v = Faro.getClients();
    }



    cout << "What do you know about this client?\n" << endl;//so vamos ter estas duas opçoes porque sao os atributos nao mutaveis do cliente
    cout << "1: Name\n" << "2: NIF\n"<<"0: Return to the main menu\n";
    menu_int_options(number,1,2);


    if(number == 1){
        cout << "Name:";
        cin.ignore('\n',1000);
        getline(cin, auxiliar);
        while(cin.fail() && cin.eof()){
            cin.clear();
            cout << "Invalid character. Please insert a valid input:";
            getline(cin, auxiliar);
        }
        verification_all_letters(auxiliar);
        i = string_sequential_search_c(v, auxiliar);
    }
    else if(number == 2){
        cout << "NIF:";
        cin.ignore('\n',1000);
        getline(cin, auxiliar);
        while(cin.fail() && cin.eof()){
            cin.clear();
            cout << "Invalid character. Please insert a valid input:";
            getline(cin, auxiliar);
        }
        verification_nif(auxiliar);
        i = int_sequential_search_c(v, stoi(auxiliar));
    }
    else if(number == 0){
        return number;
    }

    if (i == -1) {
        cout << "The client inserted does not exist. Try again:";//dar opçao de tentar outra
        while (i == -1) {
            cout << "What do you know about this client?\n" << endl;//so vamos ter estas duas opçoes porque sao os atributos nao mutaveis do cliente
            cout << "1: Name\n" << "2: NIF\n"<<"0: Return to the main menu\n";
            menu_int_options(number,1,2);
            switch (number) {
                case 0:
                    return number;
                case 1:
                    cout << "Name:";
                    cin.ignore('\n',1000);
                    getline(cin, auxiliar);
                    while(cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input:";
                        getline(cin, auxiliar);
                    }
                    verification_all_letters(auxiliar);
                    i = string_sequential_search_c(v, auxiliar);
                    break;
                case 2:
                    cout << "NIF:";
                    cin.ignore('\n',1000);
                    getline(cin, auxiliar);
                    while(cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input:";
                        getline(cin, auxiliar);
                    }
                    verification_nif(auxiliar);
                    i = int_sequential_search_c(v, stoi(auxiliar));
                    break;
            }
        }
    }
    else {
        cout<< v[i];//mostrar o cliente
        if (confirm_modifications("remove", "client")) {
            if (base == "Porto") {
                Porto.removeClient(i);
            }
            else if (base == "Lisboa") {
                Lisboa.removeClient(i);
            }
            else if (base == "Faro") {
                Faro.removeClient(i);

            }
            cout << "Client was successfully removed!" << endl << endl;
        }
        else {//caso de nao se confirmar a remoçao
            cout << "Operation was canceled! " << endl << endl;
        }
    }
    cout << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Clients Management. " << endl;
    menu_int_options(option,1,2);
    return option;

}
//Funcoes relativas as excecoes

void black_list(const Base &base, int nif) {
    vector<Client> black_list = base.getBlackList();
    if (int_sequential_search_c(black_list, nif) == -1) {
        return ;
    }
    throw (BlackList());

}

void out_of_area(const vector<Client> &v,string county,string b) {
    if(b=="Porto"){
        if(find(nearby_Porto.begin(),nearby_Porto.end(), county) == nearby_Porto.end()){
            throw(OutOfArea());
        }
    }
    else if (b=="Lisboa"){
        if (find(nearby_Lisboa.begin(),nearby_Lisboa.end(), county) == nearby_Lisboa.end()) {
            throw(OutOfArea());
        }
    }
    else if (b=="Faro"){
        if (find(nearby_Faro.begin(),nearby_Faro.end(), county) == nearby_Faro.end()) {
            throw(OutOfArea());
        }
    }
    return;


}


void client_already_exists(string nif, const Base &b){
    vector<Client> clients= b.getClients();
    vector<Client>::const_iterator it = clients.begin();

    while(it != clients.end()){
        if (stoi(nif) == (*it).getNif()){
            throw ClientAlreadyExists(nif);
        }
        advance(it, 1);
    }
    return ;

}

int string_sequential_search_c(const vector<Client> &v, string x) {//retorna o indice do vetor onde se encontra x
    for (unsigned int i = 0; i < v.size(); i++)
        if (v[i].getName() == x)
            return i; // encontrou
    return -1; // não encontrou
}

int int_sequential_search_c(const vector<Client> &v, int x) {//retorna o indice do vetor onde se encontra x
    for (unsigned int i = 0; i < v.size(); i++)
        if (v[i].getNif() == x)
            return i; // encontrou
    return -1; // não encontrou
}
