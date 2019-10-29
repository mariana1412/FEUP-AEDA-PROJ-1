#include "Restaurant.h"


Restaurant::Restaurant(string address, vector<string> types_of_food, vector<Product> products, float revenue){
 this-> address=address;
 this-> types_of_food=types_of_food;
 this-> products=products;
 this-> revenue=revenue;

}
string Restaurant::getAddress() const{
    return address;
}
vector<string> Restaurant::getTypes_of_food() const{
    return types_of_food;
}
vector<Product> Restaurant:: getProducts() const{
    return products;
}
float Restaurant::getRevenue() const{
    return revenue;
}