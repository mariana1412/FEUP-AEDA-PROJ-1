#include "Order_functions.h"

Restaurant searchByRestaurant(Base base, string name)  {
    Restaurant restaurant;
    bool isValid = true;

    do{
        try {
            restaurant = base.searchRestaurant(name);
            isValid = true;
        }
        catch (RestaurantNotFound &msg){
            cout << endl << endl << "ATENTION: Restaurant '" << msg.getName() << "' does not exist." << endl << endl;
            isValid = false;
            cout << "Try again. Insert the name of the restaurant you want to modify: ";
            getline(cin, name);

            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, name);
            }
            formatting_string(name);
        }
    } while(!isValid);

    return restaurant;
}


int create_order(Base &Porto, Base &Lisboa, Base &Faro){

    string b;
    cout << endl << endl << "-------------- CREATE ORDER --------------" << endl << endl;

    cout << "Base: ";
    getline(cin, b);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout <<  "Invalid base. Please insert a valid input: ";
        getline(cin, b);
    }

    verification_base(b);






    return 0;
}



