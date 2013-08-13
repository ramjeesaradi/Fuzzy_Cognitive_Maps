#pragma once

#include "error.h"
#include "fcm.h"

array<double, 100> pso(double lower_bound ,double upper_bound ,double epsilon, double omega, double phyp, double phyg , int horizon ,int concept_nos);