#include "Order_functions.h"

int searchByRestaurant(Base base, string name, Restaurant& restaurant)  {
    bool isValid;

    do{
        try {
            restaurant = base.searchRestaurant(name);
            isValid = true;
        }
        catch (RestaurantNotFound &msg){
            cout << endl << endl << "ATENTION: Restaurant '" << msg.getName() << "' does not exist." << endl << endl;
            isValid = false;
            cout << "Try again. Restaurant's name: ";
            getline(cin, name);

            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, name);
            }
            formatting_string(name);
        }
    } while(!isValid);

    int size = restaurant.getProducts().size();
    for(int i = 0; i < size; i++){
        cout << "Product " << i+1 <<  ": " << restaurant.getProducts()[i] << endl;
    }

    int option;
    cout << endl << "Do you want to order a product? Choose the number of the product (insert 0 to return to the main menu): ";
    product_menu(option, 0, size);
    cin.ignore(1000, '\n');

    return (option-1);
}

int searchByArea(Base b, string base, string county, Restaurant& restaurant){

    bool isValid;
    int option;

    do{
        try {
            restaurant.setCounty(county, base);
            isValid = true;
        }
        catch (RestaurantOutOfArea &msg){
            cout << endl << endl << "ATENTION: " << msg.getCounty() << " does not belong to the base area." << endl << endl;
            isValid = false;
            cout << "Try again. Restaurant's county: ";
            getline(cin, county);

            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, county);
            }
            verification_all_letters(county);
        }

    } while(!isValid);

    int size = b.getRestaurants().size();
    int counter = 0;
    vector<int> index;

    cout << endl;
    for(int i = 0; i < size; i++){
        if(b.getRestaurants()[i].getCounty() == county){
            index.push_back(i);
            counter++;
            cout << "--> Restaurant " << counter << endl << b.getRestaurants()[i] << endl;
        }
    }

    if(counter == 0){
        cout << endl << "There are no restaurants in this county!" << endl;
        return -1;
    }

    cout << "0. Return to Main Menu" << endl;
    cout << "Now choose the restaurant: " ;
    product_menu(option, 0, counter);

    if(option == 0) return -1;

    restaurant = b.getRestaurants()[index[option]];
    size = restaurant.getProducts().size();

    cout << endl << endl;
    cout << "You chose the restaurant with the following products: ";

    for(int i = 0; i < size; i++){
        cout << "Product " << i+1 <<  ": " << restaurant.getProducts()[i] << endl;
    }

    cout << endl << "Do you want to order a product? Choose the number of the product (insert 0 to return to the main menu): ";
    product_menu(option, 0, size);
    cin.ignore(1000, '\n');

    return (option-1);

}

int searchByPrice(Base base, float pmax, Restaurant& restaurant){

    vector<pair<Restaurant, int>> products;
    int size1 = base.getRestaurants().size(), size2;

    for(int i = 0; i < size1; i++){
        size2 = base.getRestaurants()[i].getProducts().size();
        for(int j = 0; j < size2; j++){
            if(base.getRestaurants()[i].getProducts()[j].getPrice() <= pmax){
                products.push_back(make_pair(base.getRestaurants()[i], j));
            }
        }
    }

    if(products.empty()){
        cout << endl << "There are no products in this price range." << endl;
        return -1;
    }

    int size = products.size();
    for(int i = 0; i<size; i++){
        cout << "Product " << i+1 << ": " << products[i].first.getProducts()[products[i].second] << " --> " << products[i].first.getName() << ", " << products[i].first.getCounty() << endl;
    }

    int option;
    cout << "0. Return to Main Menu" << endl;
    cout << endl << "Do you want to order a product? Choose the number of the product (insert 0 to return to the main menu): ";
    product_menu(option, 0, size);
    cin.ignore(1000, '\n');

    return (option-1);

}

int searchByTypeOfFood(Base base, string type_of_food, Restaurant& restaurant){
    vector<pair<Restaurant, int>> products;
    int size1 = base.getRestaurants().size(), size2;

    for(int i = 0; i < size1; i++){
        size2 = base.getRestaurants()[i].getProducts().size();
        for(int j = 0; j < size2; j++){
            if(base.getRestaurants()[i].getProducts()[j].getType_of_food() == type_of_food){
                products.push_back(make_pair(base.getRestaurants()[i], j));
            }
        }
    }

    if(products.empty()){
        cout << endl << "There are no products with this type of food." << endl;
        return -1;
    }

    int size = products.size();
    for(int i = 0; i<size; i++){
        cout << "Product " << i+1 << ": " << products[i].first.getProducts()[products[i].second] << " --> " << products[i].first.getName() << ", " << products[i].first.getCounty() << endl;
    }

    int option;
   // restaurant = products[option-1];
    cout << "0. Return to Main Menu" << endl;
    cout << endl << "Do you want to order a product? Choose the number of the product (insert 0 to return to the main menu): ";
    product_menu(option, 0, size);
    cin.ignore(1000, '\n');

    return (option-1);
}

int create_order(Base &Porto, Base &Lisboa, Base &Faro){

    string base;
    int option;
    cout << endl << endl << "-------------- CREATE ORDER --------------" << endl << endl;

    cout << "What's your base? ";
    getline(cin, base);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout <<  "Invalid base. Please insert a valid input: ";
        getline(cin, base);
    }

    verification_base(base);

    string aux;
    int index;
    bool black;

    cout << "What's your nif? " << endl;
    getline(cin, aux);
    while (cin.fail() && cin.eof()) {
        cin.clear();
        cout << "Invalid character. Please insert a valid input:";
        getline(cin, aux);
    }
    verification_nif(aux);
    if(base == "Porto") {
        index = int_sequential_search_c(Porto.getClients(), stoi(aux));
        if(index != -1){
            black = Porto.getClients()[index].getBlack();
        }
    }
    else if(base == "Lisboa"){
        index = int_sequential_search_c(Lisboa.getClients(), stoi(aux));
        if(index != -1){
            black = Lisboa.getClients()[index].getBlack();
        }
    }
    else if(base == "Faro"){
        index = int_sequential_search_c(Faro.getClients(), stoi(aux));
        if(index != -1){
            black = Faro.getClients()[index].getBlack();
        }
    }

    if(black){
        cout << "You are in the blacklist! Blacklisted clients cannot order!" << endl;
        return 1;
    }

    while(index == -1){
        cout << "The client inserted does not exist. You have to create an account to order a product." << endl
        << "Do you want to: " << endl << "1. Try again" << endl << "2. Return to Main Menu" << endl;

        menu_int_options(option, 1, 2);
        cin.ignore(1000, '\n');

        if(option == 1){
            cout << "What's your nif? ";
            getline(cin, aux);
            while (cin.fail() && cin.eof()) {
                cin.clear();
                cout << "Invalid character. Please insert a valid input:";
                getline(cin, aux);
            }
            verification_nif(aux);
            if(base == "Porto") index = int_sequential_search_c(Porto.getClients(), stoi(aux));
            else if(base == "Lisboa") index = int_sequential_search_c(Lisboa.getClients(), stoi(aux));
            else if(base == "Faro") index = int_sequential_search_c(Faro.getClients(), stoi(aux));
        }

        else {
            return 1;
        }
    }
    while (true) {
        cout << "Which search method do you want?" << endl;
        cout << "1. Restaurant" << endl;
        cout << "2. Area" << endl;
        cout << "3. Price" << endl;
        cout << "4. Type of culinary" << endl;
        cout << "0. Return to Main Menu" << endl;

        menu_int_options(option, 0, 4);
        cin.ignore(1000, '\n');

        int indprod;
        Restaurant restaurant;
        string auxiliar;

        if (option == 0) {
            return 1;
        } else if (option == 1) {
            cout << endl << endl;
            cout << "Restaurant's name: ";
            getline(cin, auxiliar);
            while (cin.fail() && cin.eof()) {
                cin.clear();
                cout << "Invalid character. Please insert a valid input:";
                getline(cin, auxiliar);
            }
            formatting_string(auxiliar);
            if (base == "Porto") indprod = searchByRestaurant(Porto, auxiliar, restaurant);
            else if (base == "Lisboa") indprod = searchByRestaurant(Lisboa, auxiliar, restaurant);
            else if (base == "Faro") indprod = searchByRestaurant(Faro, auxiliar, restaurant);
        } else if (option == 2) {
            cout << endl << endl << "Restaurant's county: ";
            getline(cin, auxiliar);

            while (cin.fail() && cin.eof()) {
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, auxiliar);
            }
            verification_all_letters(auxiliar);

            if (base == "Porto") indprod = searchByArea(Porto, base, auxiliar, restaurant);
            else if (base == "Lisboa") indprod = searchByArea(Lisboa, base, auxiliar, restaurant);
            else if (base == "Faro") indprod = searchByArea(Faro, base, auxiliar, restaurant);
        } else if (option == 3) {
            cout << endl << endl << "Maximum price: ";
            getline(cin, auxiliar);

            while (cin.fail() && cin.eof()) {
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, auxiliar);
            }
            verification_float(auxiliar);

            if (base == "Porto") indprod = searchByPrice(Porto, stof(auxiliar), restaurant);
            else if (base == "Lisboa") indprod = searchByPrice(Lisboa, stof(auxiliar), restaurant);
            else if (base == "Faro") indprod = searchByPrice(Faro, stof(auxiliar), restaurant);
        } else if (option == 4) {
            cout << endl << endl << "Type of food: ";
            getline(cin, auxiliar);

            while (cin.fail() && cin.eof()) {
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, auxiliar);
            }
            verification_all_letters(auxiliar);

            if (base == "Porto") indprod = searchByTypeOfFood(Porto, auxiliar, restaurant);
            else if (base == "Lisboa") indprod = searchByTypeOfFood(Lisboa, auxiliar, restaurant);
            else if (base == "Faro") indprod = searchByTypeOfFood(Faro, auxiliar, restaurant);
        }
        cout << endl;
        cout << "1. Return to Main Menu" << endl;
        cout << "2. Add another product to the order" << endl;
        menu_int_options(option, 1, 2);
        if (option == 1)
            return option;
        else if (option == 2)
            continue;
    }
}



