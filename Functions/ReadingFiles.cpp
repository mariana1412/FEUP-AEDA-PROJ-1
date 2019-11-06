#include "ReadingFiles.h"

void extract_Bases() {
    string line, location, manager, blacklist;
    ifstream basefile;
    basefile.open("Base.txt");
    if (basefile.is_open()) {
        while (!basefile.eof()) {
            getline(basefile, line);    //Porto
            getline(basefile, location);
            Location l; //alterar
            getline(basefile, manager);
            getline(basefile, blacklist);
            vector<Client> bl; //alterar
            Base baseP(l, manager, {}, bl, {}); //Construtor Base Porto

            getline(basefile, line);    //separator
            getline(basefile, line);    //Lisboa
            getline(basefile, location);
            Location l1; //alterar
            getline(basefile, manager);
            Base baseL(l, manager, {}, {}, {}); //Construtor Base Lisboa

            getline(basefile, line);    //separator
            getline(basefile, line);    //Faro
            getline(basefile, location);
            Location l2; //alterar
            getline(basefile, manager);
            Base baseF(l2, manager, {}, {}, {});    //Construtor Base Faro
        }
    }
    else
        cerr << "File could not be opened" << endl;
    basefile.close();

}

void extract_Clients(){
    string line, name, nif, location;
    bool black;
    ifstream clientfile;
    clientfile.open("Cliente.txt");
    if (clientfile.is_open()) {
        while (!clientfile.eof()) {
            getline(clientfile, line);

            if (line == "Porto"){
                getline(clientfile, name);
                getline(clientfile, nif);
                getline(clientfile, location);
                Location l; //alterar
                getline(clientfile, line);
                if (line == "true")
                    black = true;
                if (line == "false")
                    black = false;
                getline(clientfile, line); //separator
                Client* c= new Client("Porto", name, stoi(nif), l.getAddress(), black, l.getCounty());
                baseP.addClient(*c);
                delete c;
                continue;
            }

            if (line == "Lisboa"){
                getline(clientfile, name);
                getline(clientfile, nif);
                getline(clientfile, location);
                Location l1; //alterar
                getline(clientfile, line);
                if (line == "true")
                    black = true;
                if (line == "false")
                    black = false;
                getline(clientfile, line); //separator
                Client* c= new Client("Lisboa", name, stoi(nif), l1.getAddress(), black, l1.getCounty());
                baseL.addClient(*c);
                delete c;
                continue;
            }

            if (line == "Faro"){
                getline(clientfile, name);
                getline(clientfile, nif);
                getline(clientfile, location);
                Location l2; //alterar
                getline(clientfile, line);
                if (line == "true")
                    black = true;
                if (line == "false")
                    black = false;
                getline(clientfile, line); //separator
                Client* c= new Client("Faro", name, stoi(nif), l2.getAddress(), black, l2.getCounty());
                baseF.addClient(*c);
                delete c;
                continue;
            }
        }
    }
    else
        cerr << "File could not be opened" << endl;
    clientfile.close();


}

void extract_Restaurants(){
    string line, location, types_of_food, products, revenue;
    ifstream restaurantfile;
    restaurantfile.open("Restaurants.txt");
    Restaurant r;
    if (restaurantfile.is_open()) {
        while (!restaurantfile.eof()) {
            getline(restaurantfile, line);
            if (line == "Porto") {
                getline(restaurantfile, location);
                getline(restaurantfile, types_of_food);
                vector<string> tof; //alterar
                getline(restaurantfile, products);
                vector<Product> product; // alterar
                getline(restaurantfile, revenue);
                getline(restaurantfile, line); //separator
                Restaurant* r = new Restaurant(location, tof, product, stof(revenue));
                baseP.addRestaurant(*r);
                delete r;
                continue;
            }

            if (line == "Lisboa") {
                getline(restaurantfile, location);
                getline(restaurantfile, types_of_food);
                vector<string> tof; //alterar
                getline(restaurantfile, products);
                vector<Product> product; // alterar
                getline(restaurantfile, revenue);
                getline(restaurantfile, line); //separator
                Restaurant* r = new Restaurant(location, tof, product, stof(revenue));
                baseL.addRestaurant(*r);
                delete r;
                continue;
            }

            if (line == "Faro") {
                getline(restaurantfile, location);
                getline(restaurantfile, types_of_food);
                vector<string> tof; //alterar
                getline(restaurantfile, products);
                vector<Product> product; // alterar
                getline(restaurantfile, revenue);
                getline(restaurantfile, line); //separator
                Restaurant* r = new Restaurant(location, tof, product, stof(revenue));
                baseF.addRestaurant(*r);
                delete r;
                continue;
            }
        }
    }
    else
        cerr << "File could not be opened" << endl;
    restaurantfile.close();
}

void extract_Employees() {
    string line, name, nif, birthdate, income, task, vehicle, background, history;
    ifstream employeefile;
    employeefile.open("Employees.txt");
    if (employeefile.is_open()) {
        while (!employeefile.eof()) {
            getline(employeefile, line);
            if (line == "Porto") {
                getline(employeefile, line);
                if (line == "Admin") {
                    getline(employeefile, name);
                    getline(employeefile, nif);
                    getline(employeefile, birthdate);
                    Time bd;    //alterar
                    getline(employeefile, income);
                    getline(employeefile, task);
                    getline(employeefile, line);
                    Admin *a = new Admin("Porto", name, stoi(nif), bd, stof(income), task);
                    baseP.addAdmin(*a);
                    delete a;
                }
                if (line == "Deliverer") {
                    getline(employeefile, name);
                    getline(employeefile, nif);
                    getline(employeefile, birthdate);
                    Time bd;    //alterar
                    getline(employeefile, income);
                    getline(employeefile, vehicle);
                    Vehicle vehi;           //alterar
                    getline(employeefile, history);
                    vector<Deliver> deliver;    //alterar
                    Deliverer *d = new Deliverer("Porto", name, stoi(nif), bd, stof(income), vehi, deliver);
                    baseP.addDeliverer(*d);
                    delete d;
                }
                continue;
            }

            if (line == "Lisboa") {
                getline(employeefile, line);
                if (line == "Admin") {
                    getline(employeefile, name);
                    getline(employeefile, nif);
                    getline(employeefile, birthdate);
                    Time bd;    //alterar
                    getline(employeefile, income);
                    getline(employeefile, task);
                    getline(employeefile, line);
                    Admin *a = new Admin("Lisboa", name, stoi(nif), bd, stof(income), task);
                    baseL.addAdmin(*a);
                    delete a;
                }
                if (line == "Deliverer") {
                    getline(employeefile, name);
                    getline(employeefile, nif);
                    getline(employeefile, birthdate);
                    Time bd;    //alterar
                    getline(employeefile, income);
                    getline(employeefile, vehicle);
                    Vehicle vehi;           //alterar
                    getline(employeefile, history);
                    vector<Deliver> deliver;    //alterar
                    Deliverer *d = new Deliverer("Lisboa", name, stoi(nif), bd, stof(income), vehi, deliver);
                    baseL.addDeliverer(*d);
                    delete d;
                }
                continue;
            }

            if (line == "Faro") {
                getline(employeefile, line);
                if (line == "Admin") {
                    getline(employeefile, name);
                    getline(employeefile, nif);
                    getline(employeefile, birthdate);
                    Time bd;    //alterar
                    getline(employeefile, income);
                    getline(employeefile, task);
                    getline(employeefile, line);
                    Admin *a = new Admin("Faro", name, stoi(nif), bd, stof(income), task);
                    baseF.addAdmin(*a);
                    delete a;
                }
                if (line == "Deliverer") {
                    getline(employeefile, name);
                    getline(employeefile, nif);
                    getline(employeefile, birthdate);
                    Time bd;    //alterar
                    getline(employeefile, income);
                    getline(employeefile, vehicle);
                    Vehicle vehi;           //alterar
                    getline(employeefile, history);
                    vector<Deliver> deliver;    //alterar
                    Deliverer *d = new Deliverer("Faro", name, stoi(nif), bd, stof(income), vehi, deliver);
                    baseF.addDeliverer(*d);
                    delete d;
                }
                continue;
            } else
                cerr << "File could not be opened" << endl;
            employeefile.close();
        }
    }
}


