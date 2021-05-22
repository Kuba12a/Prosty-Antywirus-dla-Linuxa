#ifndef VIRUSSCANNER_H
#define VIRUSSCANNER_H

#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <fstream>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/vfs.h>

using namespace std;

void stats();

int check_file();

void setup_directory(string folder);

void directory(string folder);

bool scan_hashes(string path);

#endif
