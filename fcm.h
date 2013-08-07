#pragma once

#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <array>

using std::cout;
using std::endl;
using std::array;
using std::ifstream;
using std::ofstream;
using std::isnan;
using std::abs;

long double fcm(array<long double, 100> concept, array<long double, 100> dmns, int array_size, int horizone);