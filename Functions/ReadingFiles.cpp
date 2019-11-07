#include "ReadingFiles.h"

void extract_Clients(Base& baseP, Base& baseL, Base& baseF){
    string line, name, nif;
    ifstream clientfile;
    clientfile.open("C:\\Users\\Diogo Almeida\\Desktop\\Projeto AEDA\\Clientes.txt");
    if (clientfile.is_open()) {
        bool black = false;
        while (!clientfile.eof()) {
            getline(clientfile, line);

            if (line == "Porto"){
                getline(clientfile, name);
                getline(clientfile, nif);
                getline(clientfile, line);
                Location location(line);
                getline(clientfile, line);
                if (line == "true")
                    black = true;
                getline(clientfile, line); //separator
                baseP.addClient(Client("Porto", name, stoi(nif), location.getAddress(), black, location.getCounty()));
                continue;
            }

            if (line == "Lisboa"){
                getline(clientfile, name);
                getline(clientfile, nif);
                getline(clientfile, line);
                Location location(line);
                getline(clientfile, line);
                if (line == "true")
                    black = true;
                getline(clientfile, line); //separator
                baseL.addClient(Client("Lisboa", name, stoi(nif), location.getAddress(), black, location.getCounty()));
                continue;
            }

            if (line == "Faro"){
                getline(clientfile, name);
                getline(clientfile, nif);
                getline(clientfile, line);
                Location location(line);
                getline(clientfile, line);
                if (line == "true")
                    black = true;
                getline(clientfile, line); //separator
                baseF.addClient(Client("Faro", name, stoi(nif), location.getAddress(), black, location.getCounty()));
                continue;
            }
        }
    }
    else
        cerr << "File could not be opened" << endl;
    clientfile.close();

}

void extract_Restaurants(Base& baseP, Base& baseL, Base& baseF){
    string line, name, location, revenue;
    vector<string> types_of_food;
    vector<Product> products;
    ifstream restaurantfile;
    restaurantfile.open("C:\\Users\\Diogo Almeida\\Desktop\\Projeto AEDA\\Restaurants.txt");
    if (restaurantfile.is_open()) {
        while (!restaurantfile.eof()) {
            getline(restaurantfile, line);
            if (line == "Porto") {
                getline(restaurantfile, name);
                getline(restaurantfile, location);
                getline(restaurantfile, line);
                types_of_food = stringToStringVector(line);
                getline(restaurantfile, line);
                products = stringToProductVector(line);
                getline(restaurantfile, revenue);
                getline(restaurantfile, line); //separator
                baseP.addRestaurant(Restaurant(name, location, types_of_food, products, stof(revenue)));
                continue;
            }

            if (line == "Lisboa") {
                getline(restaurantfile, name);
                getline(restaurantfile, location);
                getline(restaurantfile, line);
                types_of_food = stringToStringVector(line);
                getline(restaurantfile, line);
                products = stringToProductVector(line);
                getline(restaurantfile, revenue);
                getline(restaurantfile, line); //separator
                baseL.addRestaurant(Restaurant(name, location, types_of_food, products, stof(revenue)));
                continue;
            }

            if (line == "Faro") {
                getline(restaurantfile, name);
                getline(restaurantfile, location);
                getline(restaurantfile, line);
                types_of_food = stringToStringVector(line);
                getline(restaurantfile, line);
                products = stringToProductVector(line);
                getline(restaurantfile, revenue);
                getline(restaurantfile, line); //separator
                baseF.addRestaurant(Restaurant(name, location, types_of_food, products, stof(revenue)));
                continue;
            }
        }
    }
    else
        cerr << "File could not be opened" << endl;
    restaurantfile.close();
}

void extract_Deliveries(Base& baseP, Base& baseL, Base& baseF){
    string line, reason, id, tax, success;
    bool made = false;
    Restaurant restaurant;
    Time date;
    Time hour;
    vector<Product> products;
    ifstream deliveryfile;
    deliveryfile.open("C:\\Users\\Diogo Almeida\\Desktop\\Projeto AEDA\\Encomendas.txt");
    if (deliveryfile.is_open()) {
        while (!deliveryfile.eof()) {
            getline(deliveryfile, line);
            if (line == "Porto") {
                getline(deliveryfile, id);
                getline(deliveryfile, line);
                restaurant = stringToRestaurantSearch(line, baseP);
                getline(deliveryfile, line);
                date = stringToTime(line);
                getline(deliveryfile, line);
                products = stringToProductVectorSearch(line, baseP);
                getline(deliveryfile, success);
                if (success == "Success")
                    made = true;
                else if (success == "Insuccess")
                    made = false;
                getline(deliveryfile, reason);
                getline(deliveryfile, line);
                hour = stringToHour(line);
                getline(deliveryfile, tax);
                getline(deliveryfile, line); //separator
                baseP.addDelivery(Delivery(restaurant, date, products, stoi(id), made, reason, hour, stof(tax)));
                continue;
            }

            if (line == "Lisboa") {
                getline(deliveryfile, id);
                getline(deliveryfile, line);
                restaurant = stringToRestaurantSearch(line, baseL);
                getline(deliveryfile, line);
                date = stringToTime(line);
                getline(deliveryfile, line);
                products = stringToProductVectorSearch(line, baseL);
                getline(deliveryfile, success);
                if (success == "Success")
                    made = true;
                else if (success == "Insuccess")
                    made = false;
                getline(deliveryfile, reason);
                getline(deliveryfile, line);
                hour = stringToHour(line);
                getline(deliveryfile, tax);
                getline(deliveryfile, line); //separator
                baseL.addDelivery(Delivery(restaurant, date, products, stoi(id), made, reason, hour, stof(tax)));
                continue;
            }

            if (line == "Faro") {
                getline(deliveryfile, id);
                getline(deliveryfile, line);
                restaurant = stringToRestaurantSearch(line, baseF);
                getline(deliveryfile, line);
                date = stringToTime(line);
                getline(deliveryfile, line);
                products = stringToProductVectorSearch(line, baseF);
                getline(deliveryfile, success);
                if (success == "Success")
                    made = true;
                else if (success == "Insuccess")
                    made = false;
                getline(deliveryfile, reason);
                getline(deliveryfile, line);
                hour = stringToHour(line);
                getline(deliveryfile, tax);
                getline(deliveryfile, line); //separator
                baseF.addDelivery(Delivery(restaurant, date, products, stoi(id), made, reason, hour, stof(tax)));
                continue;
            }
        }
    }
    else
        cerr << "File could not be opened" << endl;
    deliveryfile.close();
}


void extract_Employees(Base& baseP, Base& baseL, Base& baseF) {
    string line, name, nif, income, task;
    Time birthdate;
    Vehicle vehicle;
    vector<Delivery> deliveries;
    ifstream employeefile;
    employeefile.open("C:\\Users\\Diogo Almeida\\Desktop\\Projeto AEDA\\Funcionarios.txt");
    if (employeefile.is_open()) {
        while (!employeefile.eof()) {
            getline(employeefile, line);
            if (line == "Porto") {
                getline(employeefile, line);
                if (line == "Admin") {
                    getline(employeefile, name);
                    getline(employeefile, nif);
                    getline(employeefile, line);
                    birthdate = stringToDate(line);
                    getline(employeefile, income);
                    getline(employeefile, task);
                    getline(employeefile, line);    //separator
                    baseP.addAdmin(Admin("Porto", name, stoi(nif), birthdate, stof(income), task));
                }
                if (line == "Deliverer") {
                    getline(employeefile, name);
                    getline(employeefile, nif);
                    getline(employeefile, line);
                    birthdate = stringToDate(line);
                    getline(employeefile, income);
                    getline(employeefile, line);
                    vehicle = stringToVehicle(line);
                    getline(employeefile, line);
                    deliveries = stringToDeliveryVectorSearch(line, baseP);
                    getline(employeefile, line);    //separator
                    baseP.addDeliverer(Deliverer("Porto", name, stoi(nif), birthdate, stof(income), vehicle, deliveries));
                }
                continue;
            }

            if (line == "Lisboa") {
                getline(employeefile, line);
                if (line == "Admin") {
                    getline(employeefile, name);
                    getline(employeefile, nif);
                    getline(employeefile, line);
                    birthdate = stringToDate(line);
                    getline(employeefile, income);
                    getline(employeefile, task);
                    getline(employeefile, line);    //separator
                    baseL.addAdmin(Admin("Lisboa", name, stoi(nif), birthdate, stof(income), task));
                }
                if (line == "Deliverer") {
                    getline(employeefile, name);
                    getline(employeefile, nif);
                    getline(employeefile, line);
                    birthdate = stringToDate(line);
                    getline(employeefile, income);
                    getline(employeefile, line);
                    vehicle = stringToVehicle(line);
                    getline(employeefile, line);
                    deliveries = stringToDeliveryVectorSearch(line, baseL);
                    getline(employeefile, line);    //separator
                    baseL.addDeliverer(Deliverer("Lisboa", name, stoi(nif), birthdate, stof(income), vehicle, deliveries));
                }
                continue;
            }

            if (line == "Faro") {
                getline(employeefile, line);
                if (line == "Admin") {
                    getline(employeefile, name);
                    getline(employeefile, nif);
                    getline(employeefile, line);
                    birthdate = stringToDate(line);
                    getline(employeefile, income);
                    getline(employeefile, task);
                    getline(employeefile, line);    //separator
                    baseF.addAdmin(Admin("Faro", name, stoi(nif), birthdate, stof(income), task));
                }
                if (line == "Deliverer") {
                    getline(employeefile, name);
                    getline(employeefile, nif);
                    getline(employeefile, line);
                    birthdate = stringToDate(line);
                    getline(employeefile, income);
                    getline(employeefile, line);
                    vehicle = stringToVehicle(line);
                    getline(employeefile, line);
                    deliveries = stringToDeliveryVectorSearch(line, baseF);
                    getline(employeefile, line);    //separator
                    baseF.addDeliverer(Deliverer("Faro", name, stoi(nif), birthdate, stof(income), vehicle, deliveries));
                }
                continue;
            } else
                cerr << "File could not be opened" << endl;
            employeefile.close();
        }
    }
}

void extract_Bases(Base& baseP, Base& baseL, Base& baseF) {
    string line;
    ifstream basefile;
    basefile.open("C:\\Users\\Diogo Almeida\\Desktop\\Projeto AEDA\\Base.txt");
    if (basefile.is_open()) {
        while (!basefile.eof()) {
            getline(basefile, line);    //Porto
            getline(basefile, line);
            Location location(line);
            baseP.setLocation(location);
            getline(basefile, line);
            baseP.setManager(line);
            getline(basefile, line);
            baseP.setBlacklist(stringToClientVectorSearch(line, baseP));

            getline(basefile, line);    //separator
            getline(basefile, line);    //Lisboa
            getline(basefile, line);
            Location location1(line);
            baseL.setLocation(location1);
            getline(basefile, line);
            baseL.setManager(line);
            getline(basefile, line);
            baseL.setBlacklist(stringToClientVectorSearch(line, baseL));

            getline(basefile, line);    //separator
            getline(basefile, line);    //Faro
            getline(basefile, line);
            Location location2(line);
            baseF.setLocation(location2);
            getline(basefile, line);
            baseF.setManager(line);
            getline(basefile, line);
            baseF.setBlacklist(stringToClientVectorSearch(line, baseF));
        }
    }
    else
        cerr << "File could not be opened" << endl;
    basefile.close();

}





