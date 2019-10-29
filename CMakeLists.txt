cmake_minimum_required(VERSION 3.15)
project(projeto)

set(CMAKE_CXX_STANDARD 14)

add_executable(projeto main.cpp Classes/Base.h Classes/Base.cpp Classes/Deliver.h Classes/Deliver.cpp Classes/Location.h Classes/Location.cpp Classes/Order.cpp Classes/Order.h Classes/Person.cpp Classes/Person.h Classes/Product.cpp Classes/Product.h Classes/Restaurant.cpp Classes/Restaurant.h Classes/Time.cpp Classes/Time.h Classes/Vehicle.cpp Classes/Vehicle.h)