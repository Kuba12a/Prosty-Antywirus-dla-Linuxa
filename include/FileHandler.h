#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <fstream>
#include <dirent.h>
#include <sys/stat.h>

using namespace std;

string get_filename(string path);

bool exists (const string& name);

int move_to_quarantine2(string path);

string SplitFilename(string& str);

bool is_file(string);

void create_file();

int do_mkdir(const char *path, mode_t mode);

void save_to_db(string hash);

void move_to_quarantine(string path);

#endif
