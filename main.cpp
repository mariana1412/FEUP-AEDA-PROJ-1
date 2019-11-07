#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
#include "Classes/Person.h"
#include "Classes/Base.h"
#include "Classes/Restaurant.h"
#include "Classes/Time.h"
#include "Classes/Vehicle.h"
#include "Classes/Product.h"
#include "Classes/Order.h"
#include "Classes/Location.h"
#include "Functions/ReadingFiles.h"
#include "Functions/utils.h"
#include "Functions/Verification_Inputs.h"
#include "Functions/StringConverters.h"

using namespace std;

int main() {
    Base baseP, baseL, baseF;
    extract_Clients(baseP, baseL, baseF);
    extract_Restaurants(baseP, baseL, baseF);
    extract_Deliveries(baseP, baseL, baseF);
    extract_Employees(baseP, baseL, baseF);
    extract_Bases(baseP, baseL, baseF);

    return 0;
}