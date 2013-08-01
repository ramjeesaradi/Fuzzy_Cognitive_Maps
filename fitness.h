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

long double fitness(array<long double, 100> dmns);
