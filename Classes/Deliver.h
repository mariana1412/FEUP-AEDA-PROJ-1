//
// Created by ritap on 13/10/2019.
//

#ifndef UGH_EATS_DELIVER_H
#define UGH_EATS_DELIVER_H

#include <string>
#include "Time.h"

using namespace std;

class Deliver{
private:
   bool success;
   string reason_insucess;
   Time deliver_time;
   float price;
public:
    Deliver(bool success, string reason_insucess, Time deliver_time, float price);
    bool getSuccess() const;
    string getReason_insucess() const;
    Time getDeliver_time() const;
    float getPrice() const;
};




#endif //UGH_EATS_DELIVER_H
