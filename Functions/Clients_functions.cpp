#include "Clients_functions.h"
#include "utils.cpp"

int create_client(Base &Porto, Base &Lisboa, Base &Faro) {
    string aux;
    vector<Client> v;
    Client new_client;
    Base base;

    cout << "-------------- CREATE CLIENT --------------" << endl;

    cout << "Base: ";
    getline(cin, aux);
    //verificar base
    new_client.setBase(aux);

    if (aux == "porto") {
        v = Porto.getClients();
        base = Porto;
    }
    else if (aux == "lisboa") {
        v = Lisboa.getClients();
        base = Lisboa;
    }
    else if(aux == "faro"){
        v = Faro.getClients();
    base = Faro;
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
        Black_List(base, new_client.getNif());//se o cliente estiver na black_list é rejeitado
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

    if (new_client.getBase() == "porto") {
    Porto.getClients().push_back(new_client);
    cout << "Client was successfully created!" << endl << endl;
    }
    else if (new_client.getBase() == "lisboa") {
    Lisboa.getClients().push_back(new_client);
    cout << "Client successfully was created!" << endl << endl;
    }
    else if(new_client.getBase() == "faro"){
    Faro.getClients().push_back(new_client);
    cout << "Client successfully was created!" << endl << endl;
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

    vector<Client> v;
    string base;
    int i;
    string auxiliar, number;

    cout << "-------------- MODIFY CLIENT --------------" << endl;

    cout << "Client's Base: ";
    getline(cin, base);
    /*verificar base*/

    if (base == "porto") {
        v = Porto.getClients();
    }
    else if (base == "lisboa") {
        v = Lisboa.getClients();
    }
    else if (base == "faro") {
        v = Faro.getClients();
    }

    cout << "What do you know about this client?\n" << endl;//so vamos ter estas duas opçoes porque sao os atributos nao mutaveis do cliente
    cout << "1: Name\n" << "2: NIF\n";
    getline(cin, number);//verificar se o input é diferente das opçoes possiveis

    switch (number) {
        case 1:
            cout << "Name: ";
            getline(cin, auxiliar);//verificar a string
            i = string_sequential_search(v, auxiliar);
        case 2:
            cout << "NIF: ";
            getline(cin, auxiliar);//verificar o nif
            i = int_sequential_search(v, stoi(auxiliar));
    }

    if (i == -1) {
        cout << "The client inserted does not exist";//dar opçao de tentar outra vez ou sair da funcao?
    }
    else {
        string new_info, new_info2, new_info3;
        cout << "What do you wish to change?\n";
        cout << "1: Base\n" << "2: Address\n" << "3: Both";
        getline(cin, auxiliar);//verificar se o input é diferente das opçoes possiveis

        if (auxiliar == "1") {
            cout << "Base: ";
            getline(cin, new_info);
            //verificar base
            base = new_info;
            if (base == "porto") {
                v = Porto.getClients();
            }
            else if (base == "lisboa") {
                v = Lisboa.getClients();
            }
            else if (base == "faro") {
                v = Faro.getClients();
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
            }
            else {//caso de nao se confirmar a mudança
                return 1; //end of the function call
            }
        }
        else if (auxiliar == "2") {
            cout << "Address: ";
            getline(cin, new_info);
            cout << "County: ";//verificar string
            getline(cin, new_info2);
            if (confirm_client("create")) {
                try {
                    out_of_area(v, new_info2);//caso o cliente nao resida no concelho da base ou nos concelhos fronteira tambem é rejeitado
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
        }
        else if(auxiliar=="3"){
            cout << "Base: ";
            getline(cin, new_info);
            //verificar a base
            base = new_info;
            if (base == "porto") {
                v = Porto.getClients();
            }
            else if (base == "lisboa") {
                v = Lisboa.getClients();
            }
            else if (base == "faro") {
                v = Faro.getClients();
            }

            cout << "Address: ";
            getline(cin, new_info2);
            cout << "County: ";
            getline(cin, new_info3);
            //verificar se é tudo letras
            if (confirm_client("modify")) {
                try {
                    out_of_area(v, new_info3);//caso o cliente nao resida no concelho da base ou nos concelhos fronteira tambem é rejeitado
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
    vector<Client> v;
    string base,number, auxiliar;
    int i;

    cout << "-------------- REMOVE CLIENT --------------" << endl;

    cout << "Client's Base: ";
    getline(cin, base);
    //verificar base
    if (base == "porto") {
        v = Porto.getClients();
    }
    else if (base == "lisboa") {
        v = Lisboa.getClients();
    }
    else if (base == "faro") {
        v = Faro.getClients();
    }



    cout << "What do you know about this client?\n" << endl;//so vamos ter estas duas opçoes porque sao os atributos nao mutaveis do cliente
    cout << "1: Name\n" << "2: NIF\n";
    getline(cin, number);//verificar se o input é diferente das opçoes possiveis


    if(number=="1"){
        cout << "Name: ";
        getline(cin, auxiliar);//verificar a string
        i = string_sequential_search(v, auxiliar);
    }
    else if(number=="2"){
        cout << "NIF: ";
        getline(cin, auxiliar);//verificar o nif
        i = int_sequential_search(v, stoi(auxiliar));
    }

    if (i == -1) {
        cout << "The client inserted does not exist";//dar opçao de tentar outra vez ou sair da funcao?
    }
    else {
        if (confirm_client("remove")) {
            if (base == "porto") {
                Porto.getClients().erase(Porto.getClients().begin() + i);
            }
            else if (base == "lisboa") {
                Lisboa.getClients().erase(Lisboa.getClients().begin() + i);
            }
            else if (base == "faro") {
                Faro.getClients().erase(Faro.getClients().begin() + i);

            }
            cout << "Client successfully was removed!" << endl << endl;
        }
        else {//caso de nao se confirmar a remoçao
            return 1;
        }
    }
    return 0;
}