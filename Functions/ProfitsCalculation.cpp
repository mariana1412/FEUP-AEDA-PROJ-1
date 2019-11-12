#include "ProfitsCalculation.h"

int ProfitsByBase(Base p, Base l, Base f){
    float profit=0;
    int option,op;
    Base b;
    vector<Delivery> v;
    cout << "From which base do you want to know the profit?"<<endl;
    cout << "\t 1.Porto \t 2.Lisboa \t 3.Faro "<<endl;
    menu_int_options(op, 1,3);
    switch (op){
        case 1:
            for(int i = 0; i < p.getDeliveries().size(); i++){
                profit += p.getDeliveries()[i].getFinalPrice();
            }
            break;
        case 2:
            for(int i = 0; i < l.getDeliveries().size(); i++){
                profit += l.getDeliveries()[i].getFinalPrice();
            }
            break;
        case 3:
            for(int i = 0; i < f.getDeliveries().size(); i++){
                profit += f.getDeliveries()[i].getFinalPrice();
            }
            break;
    }

    cout << "The profit of this base is "<< profit<<" euros." <<endl;

    cout << endl << "1. Return to Main Menu. " << endl;
    cout << "2. Return to  Profit Calculation. " << endl;
    menu_int_options(option,1,2);
    return option;
}

int ProfitsByRestaurant(Base p, Base l , Base f){
    int option,op;
    string base,aux;
    Restaurant restaurant;
    bool isValid;
    float profit;
    Base b;

    cout << "From which base is the restaurant you want to know the profit?"<<endl;
    cout << "\t 1.Porto \t 2.Lisboa \t 3.Faro "<<endl;
    menu_int_options(op, 1,3);
    cin.ignore(1000,'\n');
    switch (op) {
        case 1:
            base = "Porto";
            break;
        case 2:
            base = "Lisboa";
            break;
        case 3:
            base = "Faro";
            break;
    }

    cout << "Insert the name of the restaurant you want to modify: ";
    getline(cin, aux);

    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, aux);
    }
    formatting_string(aux);
    do{
        try {
            if (base == "Porto") restaurant = p.searchRestaurant(aux);
            else if (base == "Lisboa") restaurant = l.searchRestaurant(aux);
            else if(base == "Faro") restaurant = f.searchRestaurant(aux);
            isValid = true;
        }
        catch (RestaurantNotFound &msg){
            cout << endl << endl << "ATENTION: Restaurant '" << msg.getName() << "' does not exist." << endl << endl;
            isValid = false;
            cout << "Try again. Insert the name of the restaurant you want to modify: ";
            getline(cin, aux);

            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, aux);
            }
            formatting_string(aux);
        }
    } while(!isValid);

    profit = restaurant.getRevenue();
    cout << "The profit of this base is "<< profit<<" euros."<<endl;


    cout << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Profit Calculation. " << endl;
    menu_int_options(option,1,2);
    return option;
}
int ProfitsByClient(Base p, Base l, Base f){
    int op,option,i;
    Base b;
    string aux;
    float profit;

    cout << "From which base is the client you want to know the outlay?"<<endl;
    cout << "\t1.Porto \t 2.Lisboa \t 3.Faro "<<endl;
    menu_int_options(op, 1,3);
    cin.ignore (1000, '\n');
    switch (op){
        case 1:
            b= p;
            break;
        case 2:
            b=l;
            break;
        case 3:
            b=f;
            break;
    }
    cout << "What is the name of the client you want to know the outlay? ";
    getline(cin, aux);
    while (cin.fail() && cin.eof()) {
        cin.clear();
        cout << "Invalid character. Please insert a valid input:";
        getline(cin, aux);
    }
    verification_all_letters(aux);
    i = string_sequential_search_aux(b.getClients(), aux);
    if (i == -1) {
        cout << "The client inserted does not exist. Try again:"<<endl;//dar opçao de tentar outra
        while (i == -1) {
            cout << "What is the name of the client you want to know the outlay? ";
            getline(cin, aux);
            while (cin.fail() && cin.eof()) {
                cin.clear();
                cout << "Invalid character. Please insert a valid input:";
                getline(cin, aux);
            }
            verification_all_letters(aux);
            i = string_sequential_search_aux(b.getClients(), aux);
        }
    }
    int nif = b.getClients()[i].getNif();
    vector<Delivery>:: const_iterator it_d = b.getDeliveries().begin();
    for (it_d; it_d != b.getDeliveries().end(); it_d){
        if((*it_d).getNif()==nif){
            profit += (*it_d).getFinalPrice();
        }

    }


    cout << "The profit of this base is "<< profit<<" euros."<<endl;

    cout << endl << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Profit Calculation. " << endl;
    menu_int_options(option,1,2);
    return option;
}
int ProfitByTimeInterval(Base p, Base l , Base f){
    int option;




    cout << "1. Return to Main Menu. " << endl;
    cout << "2. Return to  Profit Calculation. " << endl;
    menu_int_options(option,1,2);
    return option;
}





int string_sequential_search_aux(const vector<Client> &v, string x) {//retorna o indice do vetor onde se encontra x
    for (unsigned int i = 0; i < v.size(); i++)
        if (v[i].getName() == x)
            return i; // encontrou
    return -1; // não encontrou
}