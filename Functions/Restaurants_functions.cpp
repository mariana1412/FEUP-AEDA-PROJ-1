#include "Restaurants_functions.h"

int create_restaurant(Base &Porto, Base &Lisboa, Base &Faro){
    Restaurant new_restaurant;
    string aux;
    string b;
    Base base;
    vector<Restaurant> restaurants;
    bool isValid;

    cout << endl << endl << "-------------- CREATE RESTAURANT --------------" << endl << endl;

    cout << "Base: ";
    getline(cin, b);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout <<  "Invalid base. Please insert a valid input: ";
        getline(cin, b);
    }

    verification_base(b);

    if (b == "Porto") base = Porto;
    else if (b == "Lisboa") base = Lisboa;
    else if(b == "Faro") base = Faro;

    restaurants = base.getRestaurants();

    cout << endl << endl << "Name: ";
    getline(cin, aux);

    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, aux);
    }
    verification_all_letters(aux);

    do{
        try {
            new_restaurant.setName(aux, base);
            isValid = true;
        }
        catch (RestaurantAlreadyExists &msg){
            cout << endl << endl << "ATENTION: Restaurant '" << msg.getName() << "' already exists." << endl << endl;
            isValid = false;
            cout << "Try again. Name: ";
            getline(cin, aux);

            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, aux);
            }
            verification_all_letters(aux);
        }
    } while(!isValid);


    cout << endl << endl << "County: ";
    getline(cin, aux);

    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, aux);
    }

    verification_all_letters(aux);

    do{
        try {
            new_restaurant.setCounty(aux, b);
            isValid = true;
        }
        catch (RestaurantOutOfArea &msg){
            cout << endl << endl << "ATENTION: " << msg.getCounty() << " does not belong to the base area." << endl << endl;
            isValid = false;
            cout << "Try again. County: ";
            getline(cin, aux);

            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, aux);
            }
            verification_all_letters(aux);
        }
    } while(!isValid);


    cout << endl << "Address: ";
    getline(cin, aux);

    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, aux);
    }

    formatting_string(aux);
    new_restaurant.setAddress(aux);

    int n, i = 0;

    cout << endl << endl << "How many products does the restaurant have? Please insert an integer number: ";
    cin >> n;

    while(cin.fail() && cin.eof() && n == 0){
        cin.clear();
        cout << "Invalid number. Please insert a valid input: ";
        cin >> n;
    }

    Product product;
    while (n != i){
        cout << i <<  ". Product name: ";
        getline(cin, aux);

        while (cin.fail() && cin.eof()){
            cin.clear();
            cout << "Invalid character. Please insert a valid input: ";
            getline(cin, aux);
        }
        verification_all_letters(aux);
        product.setName(aux);

        cout << endl  << "Type of food: ";
        getline(cin, aux);
        while (cin.fail() && cin.eof()){
            cin.clear();
            cout << "Invalid character. Please insert a valid input: ";
            getline(cin, aux);
        }
        verification_all_letters(aux);
        product.setType_of_food(aux);
        new_restaurant.addType_of_food(aux);

        cout << endl << "Price: ";
        getline(cin, aux);
        while (cin.fail() && cin.eof()){
            cin.clear();
            cout << "Invalid character. Please insert a valid input: ";
            getline(cin, aux);
        }
        verification_float(aux);
        product.setprice(stof(aux));

        try{
            new_restaurant.addProduct(aux);
        }
        catch (ProductAlreadyExists &msg){
            cout << endl << endl << "ATENTION: " << msg.getName() << " already exists." << endl;
            cout << "Try again! " << endl;
            i--;
        }

        i++;
    }

    new_restaurant.setRevenue(0.0);
    if(confirm_modifications("create", "restaurant")){
        if (b == "Porto") Porto.addRestaurant(new_restaurant);
        else if (b == "Lisboa") Lisboa.addRestaurant(new_restaurant);
        else if(b == "Faro") Faro.addRestaurant(new_restaurant);

        cout << "Restaurant was successfully created!" << endl << endl;
    }

    else {
        cout << "Operation was canceled!" << endl << endl;
    }

    return 0;
}

int modify_restaurant(Base &Porto, Base &Lisboa, Base &Faro) {

    string base, aux;
    bool isValid;
    int res;
    Restaurant restaurant;

    cout << endl << endl << "-------------- MODIFY RESTAURANT --------------" << endl << endl;

    cout << "Base: ";
    getline(cin, base);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout <<  "Invalid base. Please insert a valid input: ";
        getline(cin, base);
    }

    verification_base(base);

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
            if (base == "Porto") restaurant = Porto.searchRestaurant(aux);
            else if (base == "Lisboa") restaurant = Lisboa.searchRestaurant(aux);
            else if(base == "Faro") restaurant = Faro.searchRestaurant(aux);
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

    if (base == "Porto") res = Porto.getIndexrestaurant(restaurant);
    else if (base == "Lisboa") res = Lisboa.getIndexrestaurant(restaurant);
    else if(base == "Faro") res = Faro.getIndexrestaurant(restaurant);

    int choice = 0;
    int option = 0;
    cout << endl << endl << "What do you want to change? "<< endl;
    cout << "1. Address" << endl;
    cout << "2. Products" << endl;
    cout << "3. Everything" << endl;

    menu_int_options(option, 1, 3);
    string change;
    Product product;
    int c = 0, prod;

    switch(option){
        case 1:
            cout << "The current county is " << restaurant.getCounty() << ". Do you want to change it? ";
            cout << "Insert 'yes' to change. " << endl << "Insert 'no' to continue. " << endl << "Answer: ";
            cin >> change;

            while (cin.fail()) {
                if (cin.eof()) {
                    cin.clear();
                    cout << "Invalid operation, please insert a valid one: ";
                    cin >> change;
                }
            }

            formatting_string(change);

            while (cin.fail() || (change != "Yes" && change != "No")) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid operation, please insert a valid one: ";
                cin >> change;
                while (cin.fail()) {
                    if (cin.eof()) {
                        cin.clear();
                        cout << "Invalid operation, please insert a valid one: ";
                        cin >> change;
                    }
                }

                formatting_string(change);
            }


            if(change == "Yes"){
                cout << endl << endl << "County: ";
                getline(cin, aux);

                while(cin.fail() && cin.eof()){
                    cin.clear();
                    cout << "Invalid character. Please insert a valid input: ";
                    getline(cin, aux);
                }

                verification_all_letters(aux);

                do{
                    try {
                        restaurant.setCounty(aux, base);
                        isValid = true;
                    }
                    catch (RestaurantOutOfArea &msg){
                        cout << endl << endl << "ATENTION: " << msg.getCounty() << "does not belong to the base area." << endl << endl;
                        isValid = false;
                        cout << "Try again. County: ";
                        getline(cin, aux);

                        while(cin.fail() && cin.eof()){
                            cin.clear();
                            cout << "Invalid character. Please insert a valid input: ";
                            getline(cin, aux);
                        }
                        verification_all_letters(aux);
                    }
                } while(!isValid);

            }

            cout << endl << "Address: ";
            getline(cin, aux);

            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, aux);
            }

            formatting_string(aux);
            restaurant.setAddress(aux);

            break;
        case 2:
            cout << "Do you want to: "<< endl;
            cout << "1. Add a new product" << endl;
            cout << "2. Modify a product" << endl;
            cout << "3. Remove a product" << endl;

            menu_int_options(choice, 1, 3);

            if(choice == 1){
                do{
                    cout << endl << "Product name: ";
                    getline(cin, aux);

                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_all_letters(aux);
                    product.setName(aux);

                    cout << endl  << "Type of food: ";
                    getline(cin, aux);
                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_all_letters(aux);
                    product.setType_of_food(aux);
                    restaurant.addType_of_food(aux);

                    cout << endl << "Price: ";
                    getline(cin, aux);
                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_float(aux);
                    product.setprice(stof(aux));

                    try{
                        restaurant.addProduct(aux);
                        isValid = true;
                    }
                    catch (ProductAlreadyExists &msg){
                        isValid = false;
                        cout << endl << endl << "ATENTION: " << msg.getName() << " already exists." << endl;
                        cout << "Try again! " << endl;
                    }
                } while( !isValid);
            }

            else if(choice == 2){

                cout << "Insert the name of the product you want to modify: ";
                getline(cin, aux);

                while(cin.fail() && cin.eof()){
                    cin.clear();
                    cout << "Invalid character. Please insert a valid input: ";
                    getline(cin, aux);
                }
                formatting_string(aux);

                do{
                    try {
                        product = restaurant.searchProduct(aux);
                        isValid = true;
                    }
                    catch (ProductNotFound &msg){
                        cout << endl << endl << "ATENTION: Product '" << msg.getName() << "' does not exist." << endl << endl;
                        isValid = false;
                        cout << "Try again. Insert the name of the product you want to modify: ";
                        getline(cin, aux);

                        while(cin.fail() && cin.eof()){
                            cin.clear();
                            cout << "Invalid character. Please insert a valid input: ";
                            getline(cin, aux);
                        }
                        formatting_string(aux);
                    }
                } while(!isValid);

                prod = restaurant.getIndexProduct(product);

                cout << endl << endl << endl << "What do you want to modify: "<< endl;
                cout << "1. Name" << endl;
                cout << "2. Type of food" << endl;
                cout << "3. Price" << endl;
                cout << "4. Everything" << endl;
                menu_int_options(c, 1, 4);

                if(c == 1){
                    cout << endl << "Product name: ";
                    getline(cin, aux);

                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_all_letters(aux);
                    product.setName(aux);
                }

                else if (c == 2){
                    cout << endl  << "Type of food: ";
                    getline(cin, aux);
                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_all_letters(aux);
                    product.setType_of_food(aux);
                }

                else if( c == 3){
                    cout << endl << "Price: ";
                    getline(cin, aux);
                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_float(aux);
                    product.setprice(stof(aux));
                }

                else if (c == 4){
                    cout << endl << "Product name: ";
                    getline(cin, aux);

                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_all_letters(aux);
                    product.setName(aux);


                    cout << endl  << "Type of food: ";
                    getline(cin, aux);
                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_all_letters(aux);
                    product.setType_of_food(aux);

                    cout << endl << "Price: ";
                    getline(cin, aux);
                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_float(aux);
                    product.setprice(stof(aux));
                }

                if(confirm_modifications("modify", "product")){
                    if(c == 2 || c == 4) restaurant.addType_of_food(aux);
                    restaurant.getProducts()[prod] = product;
                }
                else {
                    cout << "Operation was canceled!" << endl << endl;
                    return 0;
                }
            }

            else if(choice == 3){
                if (confirm_modifications("remove", "product")){
                    restaurant.getProducts().erase(restaurant.getProducts().begin() + prod);
                }
                else {
                    cout << "Operation was canceled!" << endl << endl;
                    return 0;
                }
            }
            break;
        case 3:

            cout << "The current county is " << restaurant.getCounty() << ". Do you want to change it? ";
            cout << "Insert 'yes' to change. " << endl << "Insert 'no' to continue. " << endl << "Answer: ";
            cin >> change;

            while (cin.fail()) {
                if (cin.eof()) {
                    cin.clear();
                    cout << "Invalid operation, please insert a valid one: ";
                    cin >> change;
                }
            }

            formatting_string(change);

            while (cin.fail() || (change != "Yes" && change != "No")) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid operation, please insert a valid one: ";
                cin >> change;
                while (cin.fail()) {
                    if (cin.eof()) {
                        cin.clear();
                        cout << "Invalid operation, please insert a valid one: ";
                        cin >> change;
                    }
                }

                formatting_string(change);
            }


            if(change == "Yes"){
                cout << endl << endl << "County: ";
                getline(cin, aux);

                while(cin.fail() && cin.eof()){
                    cin.clear();
                    cout << "Invalid character. Please insert a valid input: ";
                    getline(cin, aux);
                }

                verification_all_letters(aux);

                do{
                    try {
                        restaurant.setCounty(aux, base);
                        isValid = true;
                    }
                    catch (RestaurantOutOfArea &msg){
                        cout << endl << endl << "ATENTION: " << msg.getCounty() << "does not belong to the base area." << endl << endl;
                        isValid = false;
                        cout << "Try again. County: ";
                        getline(cin, aux);

                        while(cin.fail() && cin.eof()){
                            cin.clear();
                            cout << "Invalid character. Please insert a valid input: ";
                            getline(cin, aux);
                        }
                        verification_all_letters(aux);
                    }
                } while(!isValid);

            }

            cout << endl << "Address: ";
            getline(cin, aux);

            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, aux);
            }

            formatting_string(aux);
            restaurant.setAddress(aux);

            cout << "Do you want to: "<< endl;
            cout << "1. Add a new product" << endl;
            cout << "2. Modify a product" << endl;
            cout << "3. Remove a product" << endl;

            menu_int_options(choice, 1, 3);

            if(choice == 1){
                do{
                    cout << endl << "Product name: ";
                    getline(cin, aux);

                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_all_letters(aux);
                    product.setName(aux);

                    cout << endl  << "Type of food: ";
                    getline(cin, aux);
                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_all_letters(aux);
                    product.setType_of_food(aux);
                    restaurant.addType_of_food(aux);

                    cout << endl << "Price: ";
                    getline(cin, aux);
                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_float(aux);
                    product.setprice(stof(aux));

                    try{
                        restaurant.addProduct(aux);
                        isValid = true;
                    }
                    catch (ProductAlreadyExists &msg){
                        isValid = false;
                        cout << endl << endl << "ATENTION: " << msg.getName() << " already exists." << endl;
                        cout << "Try again! " << endl;
                    }
                } while( !isValid);
            }

            else if(choice == 2){

                cout << "Insert the name of the product you want to modify: ";
                getline(cin, aux);

                while(cin.fail() && cin.eof()){
                    cin.clear();
                    cout << "Invalid character. Please insert a valid input: ";
                    getline(cin, aux);
                }
                formatting_string(aux);

                do{
                    try {
                        product = restaurant.searchProduct(aux);
                        isValid = true;
                    }
                    catch (ProductNotFound &msg){
                        cout << endl << endl << "ATENTION: Product '" << msg.getName() << "' does not exist." << endl << endl;
                        isValid = false;
                        cout << "Try again. Insert the name of the product you want to modify: ";
                        getline(cin, aux);

                        while(cin.fail() && cin.eof()){
                            cin.clear();
                            cout << "Invalid character. Please insert a valid input: ";
                            getline(cin, aux);
                        }
                        formatting_string(aux);
                    }
                } while(!isValid);

                prod = restaurant.getIndexProduct(product);

                cout << endl << endl << endl << "What do you want to modify: "<< endl;
                cout << "1. Name" << endl;
                cout << "2. Type of food" << endl;
                cout << "3. Price" << endl;
                cout << "4. Everything" << endl;
                menu_int_options(c, 1, 4);

                if(c == 1){
                    cout << endl << "Product name: ";
                    getline(cin, aux);

                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_all_letters(aux);
                    product.setName(aux);
                }

                else if (c == 2){
                    cout << endl  << "Type of food: ";
                    getline(cin, aux);
                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_all_letters(aux);
                    product.setType_of_food(aux);
                }

                else if( c == 3){
                    cout << endl << "Price: ";
                    getline(cin, aux);
                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_float(aux);
                    product.setprice(stof(aux));
                }

                else if (c == 4){
                    cout << endl << "Product name: ";
                    getline(cin, aux);

                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_all_letters(aux);
                    product.setName(aux);


                    cout << endl  << "Type of food: ";
                    getline(cin, aux);
                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_all_letters(aux);
                    product.setType_of_food(aux);

                    cout << endl << "Price: ";
                    getline(cin, aux);
                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_float(aux);
                    product.setprice(stof(aux));
                }

                if(confirm_modifications("modify", "product")){
                    if(c == 2 || c == 4) restaurant.addType_of_food(aux);
                    restaurant.getProducts()[prod] = product;
                }
                else {
                    cout << "Operation was canceled!" << endl << endl;
                    return 0;
                }
            }

            else if(choice == 3){
                if (confirm_modifications("remove", "product")){
                    restaurant.getProducts().erase(restaurant.getProducts().begin() + prod);
                }
                else {
                    cout << "Operation was canceled!" << endl << endl;
                    return 0;
                }
            }
            break;
    }

    if(confirm_modifications("modify", "restaurant")){
        if (base == "Porto") Porto.getRestaurants()[res] = restaurant;
        else if (base == "Lisboa") Lisboa.getRestaurants()[res] = restaurant;
        else if(base == "Faro") Faro.getRestaurants()[res] = restaurant;
        cout << "Restaurant was successfully modified!" << endl << endl;
    }

    else {
        cout << "Operation was canceled!" << endl << endl;
    }



}

int remove_restaurant(Base &Porto, Base &Lisboa, Base &Faro){

    string aux, base;
    vector<Restaurant> restaurants;
    bool isValid, confirm;

    cout << endl << endl << "-------------- REMOVE RESTAURANT --------------" << endl << endl;

    cout << "Base: ";
    getline(cin, base);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout <<  "Invalid base. Please insert a valid input: ";
        getline(cin, base);
    }

    verification_base(base);


    cout << endl << endl << "Insert the name of the restaurant you want to remove: ";
    getline(cin, aux);

    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, aux);
    }

    formatting_string(aux);

    do{
        try {
            if (base == "Porto") confirm = Porto.removeRestaurant(aux);
            else if (base == "Lisboa") confirm  = Lisboa.removeRestaurant(aux);
            else if(base == "Faro") confirm = Faro.removeRestaurant(aux);
            isValid = true;
        }
        catch (RestaurantNotFound &msg){
            cout << endl << endl << "ATENTION: Restaurant '" << msg.getName() << "' does not exist." << endl << endl;
            isValid = false;
            cout << "Try again. Insert the name of the restaurant you want to remove: ";
            getline(cin, aux);

            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, aux);
            }
            formatting_string(aux);
        }
    } while(!isValid);

    if (confirm) cout << endl << endl << "Restaurant was successfully removed!" << endl << endl;
    else cout << endl << endl << "Operation was canceled!" << endl << endl;

    return 0;

}