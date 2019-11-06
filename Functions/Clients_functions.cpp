#include "Clients_functions.h"
#include "utils.cpp"

int create_client(Base &Porto, Base &Lisboa , Base &Faro) {
    string aux;
    vector<Client> v;
    Client new_client;
    Base base;


    cout << "-------------- CREATE CLIENT --------------" << endl;

    cout << "Base: ";
    getline(cin, aux);
    //verificar base
    new_client.setBase(aux);

    switch (base) {
        case "porto":
            v = Porto.getClients();
            base = Porto;
            break;

        case "lisboa":
            v = Lisboa.getClients();
            base = Lisboa;
            break;

        case "faro":
            v = Faro.getClients();
            base = Faro;
            break;
    }


    cout << "Name:";
    getline(cin, aux);
    //verificar que sao so letras
    new_client.setName(aux);

    cout << "NIF: ";
    getline(cin, aux);
    //verificar NIF
    new_client.setNif(stoi(aux));

    cout << "Address: ";//nao ha verificaçao porque pode ter tanto letras como numeros
    getline(cin, aux);
    new_client.setAddress(aux);

    cout << "County: ";
    getline(cin, aux);
    //verificar que é so letras
    new_client.setCounty(aux);


    if (confirmed_client()) {
        try {
            Black_List(base, nif);//se o cliente estiver na black_list é rejeitado
        }
        catch (Black_list &e) {
            cout << e.getMsg() << endl;
            return -1;
        }
        try {
            out_of_area(v, new_client.getCounty());//caso o cliente nao resida no concelho da base ou nos concelhos fronteira tambem é rejeitado
        }
        catch (OutOfArea &b) {
            cout << b.getMsg() << endl;
            return -1;
        }

        switch (new_client.getBase()) {//acrescentar o novo cliente ao vetor dos Clientes
            case "porto":
                Porto.getClients().push_back(new_client);
                cout << "Client was successfully created!" << endl << endl;
                break;

            case "lisboa":
                Lisboa.getClients().push_back(new_client);
                cout << "Client successfully was created!" << endl << endl;
                break;

            case "faro":
                Faro.getClients().push_back(new_client);
                cout << "Client successfully was created!" << endl << endl;
                break;
        }
    }
    else {
        //caso de nao se confirmar a criaçao
        return 1;//end of the function call
    }

    //voltar para o menu

    return 0;

}

int modify_client(Base &Porto, Base &Lisboa, Base &Faro) {

    vector<string> v;
    string base;
    int number;
    int i, auxiliar;

    cout << "-------------- MODIFY CLIENT --------------" << endl;

    cout << "Client's Base: ";
    getline(cin, base);
    //verificar base

    switch (base) {
        case "porto":
            v = Clients_porto;
            break;
        case "lisboa":
            v = Clients_lisboa;
            break;
        case "faro":
            v = Clients_faro;
            break;
    }


    cout << "What do you know about this client?\n" << endl;//so vamos ter estas duas opçoes porque sao os atributos nao mutaveis do cliente
    cout << "1: Name\n" << "2: NIF\n";
    cin << getline(cin, number);//verificar se o input é diferente das opçoes possiveis

    switch (number) {
        case 1:
            cout << "Name: ";
            cin >> getline(cin, auxiliar);//verificar a string
            i=string_sequential_search(&v, auxiliar);
        case 2:
            cout << "NIF: ";
            cin >> getline(cin, auxiliar);//verificar o nif
            i = int_sequential_search(&v, stoi(auxiliar));
    }

    if (i == -1) {
        cout << "The client inserted does not exist";//dar opçao de tentar outra vez ou sair da funcao?
    }
    else {
        string new_info, new_info2,new_info3;
        cout << "What do you wish to change?\n";
        cout << "1: Base\n" << "2: Address\n" << "3: Both";
        cin >> getline(cin, auxiliar);//verificar se o input é diferente das opçoes possiveis

        switch (auxiliar) {
            case 1:
                cout << "Base: ";
                cin >> getline(cin, new_info);
                //verificar base
                base = new_info;
                switch (base) {
                    case "porto":
                        v = Clients_porto;
                        break;
                    case "lisboa":
                        v = Clients_lisboa;
                        break;
                    case "faro":
                        v = Clients_faro;
                        break;
                }
                if (confirmed_client()) {
                    if (base == "porto"{
                        Porto.getClients()[i].setBase(new_info);
                    }
                            else if (base == "lisboa"{
                        Lisboa.getClients()[i].setBase(new_info);
                    }
                            else if (base == "faro"{
                        Faro.getClients()[i].setBase(new_info);
                    }
                    cout << "Client successfully was modified!" << endl << endl;
                    break;
                }
                else {//caso de nao se confirmar a mudança
                    return 1; //end of the function call
                }

            case 2:
                cout << "Address: ";
                cin >> getline(cin, new_info);
                cout << "County: ";//verificar string
                cin >> getline(cin, new_info2);
                if (confirmed_client()) {
                    try {
                        out_of_area(v, new_client.getCounty());//caso o cliente nao resida no concelho da base ou nos concelhos fronteira tambem é rejeitado
                    }
                    catch (OutOfArea &b) {
                        cout << b.getMsg() << endl;
                        return -1;
                    }
                    if (base == "porto") {
                        Porto.getClients()[i].setAddress(new_info);
                        Porto.getClients()[i].setCounty(new_info2);
                        cout << "Client successfully was modified!" << endl << endl;
                    }
                    else if (base == "lisboa") {
                        Lisboa.getClients()[i].setAddress(new_info);
                        Lisboa.getClients()[i].setCounty(new_info2);
                        cout << "Client successfully was modified!" << endl << endl;
                    }
                    else if (base == "faro") {
                        Faro.getClients()[i].setAddress(new_info);
                        Faro.getClients()[i].setCounty(new_info2);
                        cout << "Client successfully was modified!" << endl << endl;
                    }

                }
                else {//caso de nao se confirmar a mudança
                    return 1; //end of the function call
                }
                break;
            case 3:
                cout << "Base: ";
                cin >> getline(cin, new_info);
                //verificar a base
                base = new_info;
                switch (base) {
                    case "porto":
                        v = Clients_porto;
                        break;
                    case "lisboa":
                        v = Clients_lisboa;
                        break;
                    case "faro":
                        v = Clients_faro;
                        break;
                }
                cout << "Address: ";
                cin >> getline(cin, new_info2);
                cout << "County: ";
                cin >> getline(cin, new_info3);
                //verificar se é tudo letras
                if (confirmed_client()) {
                    try {
                        out_of_area(v, new_client.getCounty());//caso o cliente nao resida no concelho da base ou nos concelhos fronteira tambem é rejeitado
                    }
                    catch (OutOfArea &b) {
                        cout << b.getMsg() << endl;
                        return -1;
                    }
                    if (base == "porto") {
                        Porto.getClients()[i].setBase(new_info);
                        Porto.getClients()[i].setAddress(new_info2);
                        Porto.getClients()[i].setCounty(new_info3);
                        cout << "Client successfully was modified!" << endl << endl;
                    }
                    else if (base == "lisboa") {
                        Lisboa.getClients()[i].setBase(new_info);
                        Lisboa.getClients()[i].setAddress(new_info2);
                        Lisboa.getClients()[i].setCounty(new_info3);
                        cout << "Client successfully was modified!" << endl << endl;
                    }
                    else if (base == "faro") {
                        Faro.getClients()[i].setBase(new_info);
                        Faro.getClients()[i].setAddress(new_info2);
                        Faro.getClients()[i].setCounty(new_info3);
                        cout << "Client successfully was modified!" << endl << endl;
                    }
                    break;
                }
                else {//caso de nao se confirmar a mudança
                    return 1; //end of the function call
                }
        }
    }

    //voltar para o menu
    return 0;
}


int remove_client(Base &Porto, Base &Lisboa, Base &Faro) {
    vector<strings> v;
    string base;
    cout << "-------------- REMOVE CLIENT --------------" << endl;

    cout << "Client's Base: ";
    getline(cin, base);
    //verificar base
    switch (base) {
        case "porto":
            v = Clients_porto;
            break;
        case "lisboa":
            v = Clients_lisboa;
            break;
        case "faro":
            v = Clients_faro;
            break;
    }

    int number;
    cout << "What do you know about this client?\n" << endl;//so vamos ter estas duas opçoes porque sao os atributos nao mutaveis do cliente
    cout << "1: Name\n" << "2: NIF\n";
    cin << getline(cin, number);//verificar se o input é diferente das opçoes possiveis

    int i, auxiliar;
    switch (number) {
        case 1:
            cout << "Name: ";
            cin >> getline(cin, auxiliar);//verificar a string
            i = string_sequential_search(&v, auxiliar);
        case 2:
            cout << "NIF: ";
            cin >> getline(cin, auxiliar);//verificar o nif
            i = int_sequential_search(&v, stoi(auxiliar));
    }

    if (i == -1) {
        cout << "The client inserted does not exist";//dar opçao de tentar outra vez ou sair da funcao?
    }
    else {
        if (confirmed_client()){
            if (base == "porto") {
                Clients_porto.erase(Clients_porto.begin() + i);
            }
            else if (base == "lisboa") {
                Clients_lisboa.erase(Clients_lisboa.begin() + i);
            }
            else if (base == "faro") {
                Clients_faro.erase(Clients_faro.begin() + i);

            }
            cout << "Client successfully was removed!" << endl << endl;
        }
        else {//caso de nao se confirmar a remoçao
            return 1;
        }
    }
    return 0;
}