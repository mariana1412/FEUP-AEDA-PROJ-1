#include "Order_functions.h"
#include <ctime>

bool comparePrice(const pair<Restaurant, int> &p1, const pair<Restaurant, int> &p2){
    if(p1.first.getProducts()[p1.second].getPrice() < p2.first.getProducts()[p2.second].getPrice()) return true;
    return false;
}

vector<int> searchByRestaurant(Base base, string name, Restaurant& restaurant)  {
    bool isValid;
    vector<int> result;
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
    if (option == 0)
        return {};
    result.push_back(option-1);

    cout << endl;
    while (option != 0) {
        cout << " --> " << restaurant.getName() << ", " << restaurant.getCounty() << endl;
        for(int i = 0; i < size; i++){
            cout << "Product " << i+1 <<  ": " << restaurant.getProducts()[i] << endl;
        }
        cout << endl << "Do you want to order another product? Insert 0 to complete the order: ";
        product_menu(option, 0, size);
        cin.ignore(1000, '\n');
        if (option != 0)
            result.push_back(option-1);
    }
    return result;
}

vector<int> searchByArea(Base b, string base, string county, Restaurant& restaurant){

    bool isValid;
    int option;
    vector<int> result;

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
        return {};
    }

    cout << "0. Return to Main Menu" << endl;
    cout << "Now choose the restaurant: " ;
    product_menu(option, 0, counter);

    if(option == 0) return {};

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
    if (option == 0)
        return {};

    result.push_back(option-1);

    cout << endl;
    while (option != 0) {
        cout << " --> " << restaurant.getName() << ", " << restaurant.getCounty() << endl;
        for(int i = 0; i < size; i++){
            cout << "Product " << i+1 <<  ": " << restaurant.getProducts()[i] << endl;
        }
        cout << endl << "Do you want to order another product from the same restaurant? Insert 0 to complete the order: ";
        product_menu(option, 0, size);
        cin.ignore(1000, '\n');
        if (option != 0)
            result.push_back(option-1);
    }
    return result;

}

vector<int> searchByPrice(Base base, float pmax, Restaurant& restaurant){

    vector<pair<Restaurant, int>> products;
    int size1 = base.getRestaurants().size(), size2;
    vector<int> result;

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
        return {};
    }

    sort(products.begin(), products.end(), comparePrice);
    cout << endl;
    int size = products.size();
    for(int i = 0; i<size; i++){
        cout << "Product " << i+1 << ": " << products[i].first.getProducts()[products[i].second] << " --> " << products[i].first.getName() << ", " << products[i].first.getCounty() << endl;
    }

    int option;
    cout << endl << "Do you want to order a product? Choose the number of the product (insert 0 to return to the main menu): ";
    product_menu(option, 0, size);
    cin.ignore(1000, '\n');

    if (option == 0)
        return {};

    result.push_back(products[option-1].second);
    restaurant = products[option-1].first;

    vector<int> index;

    cout << endl;
    while (option != 0) {
        size = products.size();
        cout << " --> " << restaurant.getName() << ", " << restaurant.getCounty() << endl;
        for(int i = 0; i<size; i++){
            if(products[i].first == restaurant){
                index.push_back(products[i].second);
                cout << "Product " << index.size() << ": " << restaurant.getProducts()[products[i].second]  << endl;
            }
        }
        cout << endl << "Do you want to order another product from the same restaurant? Insert 0 to complete the order: ";
        product_menu(option, 0, index.size());
        cin.ignore(1000, '\n');
        if (option != 0)
            result.push_back(index[option - 1]);

    }
    return result;
}

vector<int> searchByTypeOfFood(Base base, string type_of_food, Restaurant& restaurant){
    vector<pair<Restaurant, int>> products;
    int size1 = base.getRestaurants().size(), size2;
    vector<int> result;

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
        return {};
    }

    cout << endl;
    int size = products.size();
    for(int i = 0; i<size; i++){
        cout << "Product " << i+1 << ": " << products[i].first.getProducts()[products[i].second] << " --> " << products[i].first.getName() << ", " << products[i].first.getCounty() << endl;
    }

    int option;
    cout << endl << "Do you want to order a product? Choose the number of the product (insert 0 to return to the main menu): ";
    product_menu(option, 0, size);
    cin.ignore(1000, '\n');

    if (option == 0)
        return {};

    result.push_back(products[option-1].second);
    restaurant = products[option-1].first;

    vector<int> index;

    cout << endl;
    while (option != 0) {
        size = products.size();
        cout << " --> " << restaurant.getName() << ", " << restaurant.getCounty() << endl;
        for(int i = 0; i<size; i++){
            if(products[i].first == restaurant){
                index.push_back(products[i].second);
                cout << "Product " << index.size() << ": " << restaurant.getProducts()[products[i].second]  << endl;
            }
        }
        cout << endl << "Do you want to order another product from the same restaurant? Insert 0 to complete the order: ";
        product_menu(option, 0, index.size());
        cin.ignore(1000, '\n');
        if (option != 0)
            result.push_back(index[option - 1]);

    }

    return result;
}

int create_order(Base &Porto, Base &Lisboa, Base &Faro){
    Client cliente;
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
        cout << "The inserted client does not exist. You have to create an account to order a product." << endl
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
            if(base == "Porto"){
                index = int_sequential_search_c(Porto.getClients(), stoi(aux));
                cliente = Porto.getClients().at(index);
            }
            else if(base == "Lisboa"){
                index = int_sequential_search_c(Lisboa.getClients(), stoi(aux));
                cliente = Lisboa.getClients().at(index);
            }
            else if(base == "Faro"){
                index = int_sequential_search_c(Faro.getClients(), stoi(aux));
                cliente = Faro.getClients().at(index);
            }
        }

        else {
            return 1;
        }
    }
    int nif = stoi(aux);
    cout << "Which search method do you want?" << endl;
    cout << "1. Restaurant" << endl;
    cout << "2. Area" << endl;
    cout << "3. Price" << endl;
    cout << "4. Type of culinary" << endl;
    cout << "0. Return to Main Menu" << endl;

    menu_int_options(option, 0, 4);
    cin.ignore(1000, '\n');

    vector<int> indprod;
    Restaurant restaurant;
    string auxiliar;

    if(option == 0){
        return 1;
    }

    else if(option == 1){
        cout << endl << endl;
        cout << "Restaurant's name: ";
        getline(cin, auxiliar);
        while (cin.fail() && cin.eof()) {
            cin.clear();
            cout << "Invalid character. Please insert a valid input:";
            getline(cin, auxiliar);
        }
        formatting_string(auxiliar);
        if(base == "Porto") indprod = searchByRestaurant(Porto, auxiliar, restaurant);
        else if(base == "Lisboa") indprod = searchByRestaurant(Lisboa, auxiliar, restaurant);
        else if(base == "Faro") indprod = searchByRestaurant(Faro, auxiliar, restaurant);
    }

    else if(option == 2){
        cout << endl << endl << "Restaurant's county: ";
        getline(cin, auxiliar);

        while(cin.fail() && cin.eof()){
            cin.clear();
            cout << "Invalid character. Please insert a valid input: ";
            getline(cin, auxiliar);
        }
        verification_all_letters(auxiliar);

        if(base == "Porto") indprod = searchByArea(Porto, base, auxiliar, restaurant);
        else if(base == "Lisboa") indprod = searchByArea(Lisboa, base, auxiliar, restaurant);
        else if(base == "Faro") indprod = searchByArea(Faro, base, auxiliar, restaurant);
    }

    else if(option == 3){
        cout << endl << endl << "Maximum price: ";
        getline(cin, auxiliar);

        while(cin.fail() && cin.eof()){
            cin.clear();
            cout << "Invalid character. Please insert a valid input: ";
            getline(cin, auxiliar);
        }
        verification_float(auxiliar);

        if(base == "Porto") indprod = searchByPrice(Porto, stof(auxiliar), restaurant);
        else if(base == "Lisboa") indprod = searchByPrice(Lisboa, stof(auxiliar), restaurant);
        else if(base == "Faro") indprod = searchByPrice(Faro, stof(auxiliar), restaurant);
    }
    else if(option == 4){
        cout << endl << endl << "Type of food: ";
        getline(cin, auxiliar);

        while(cin.fail() && cin.eof()){
            cin.clear();
            cout << "Invalid character. Please insert a valid input: ";
            getline(cin, auxiliar);
        }
        verification_all_letters(auxiliar);

        if(base == "Porto") indprod = searchByTypeOfFood(Porto, auxiliar, restaurant);
        else if(base == "Lisboa") indprod = searchByTypeOfFood(Lisboa, auxiliar, restaurant);
        else if(base == "Faro") indprod = searchByTypeOfFood(Faro, auxiliar, restaurant);
    }
    if(indprod.size() == 0){
        cout << endl << "Operation was canceled." << endl;
        return 1;
    }
    time_t now = time(0);
    tm* gmtm = gmtime(&now);
    Time order_time((*gmtm).tm_hour,(*gmtm).tm_min,(*gmtm).tm_mday,(*gmtm).tm_mon+1,(*gmtm).tm_year+1900);
    vector<Product> products;
    for (int i: indprod){
        products.push_back(restaurant.getProducts().at(i));
    }
    float tax;
    if (cliente.getCounty() != restaurant.getCounty())
        tax = 5;
    else
        tax = 3;
    string answer;
    Delivery delivery(restaurant, order_time, products, nif, tax);
    if (base == "Porto"){
        Porto.addDelivery(delivery);
        Porto.addDeliveryToDeliverer(delivery);
    }
    else if (base == "Lisboa") {
        Lisboa.addDelivery(delivery);
        Lisboa.addDeliveryToDeliverer(delivery);
    }
    else if (base == "Faro") {
        Faro.addDelivery(delivery);
        Faro.addDeliveryToDeliverer(delivery);
    }

    cout << "==================== Delivery Form ====================" << endl;


    return 1;
}