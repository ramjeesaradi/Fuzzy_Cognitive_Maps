#pragma once

#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <array>

using std::cout;
using std::cin;
using std::endl;
using std::array;
using std::ifstream;
using std::ofstream;
using std::isnan;
using std::abs;

double fcm(array<double, 100> concept, array<double, 100> dmns, int array_size, int horizon);