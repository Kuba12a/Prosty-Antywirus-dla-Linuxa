#ifndef HASHCALCULATOR_H
#define HASHCALCULATOR_H

#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <fstream>
#include <dirent.h>
#include <sys/stat.h>

using namespace std;

string exec(string command);

string get_hash(string path);




#endif
