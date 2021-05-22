#include "../include/FileHandler.h"
#include "../include/HashCalculator.h"
#include "../include/VirusScanner.h"

#include <dirent.h>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

typedef struct stat Stat;

bool exists(const string &name) {
  ifstream f(name.c_str());
  return f.good();
}

string get_filename(string path) {

  string base_filename = path.substr(path.find_last_of("/\\") + 1);
  return base_filename;
}

void create_file() {

  FILE *file;
  int file_exists;
  const char *filename = "../hashes.txt";
  file = fopen(filename, "r");
  if (file == NULL)
    file_exists = 0;
  else {
    file_exists = 1;
    fclose(file);
  }
  if (file_exists == 1) {
  } else {
    printf("file does not exist!\n");
    file = fopen(filename, "w+b");
  }
}

int do_mkdir(const char *path, mode_t mode) {
  Stat st;
  int status = 0;

  if (stat(path, &st) != 0) {
    /* Directory does not exist. EEXIST for race condition */
    if (mkdir(path, mode) != 0 && errno != EEXIST)
      status = -1;
  } else if (!S_ISDIR(st.st_mode)) {
    errno = ENOTDIR;
    status = -1;
  }

  return (status);
}

void save_to_db(string hash) {

  ofstream myfile;
  myfile.open("hashes.txt", std::ios_base::app);
  myfile << hash << endl;
  myfile.close();
}

bool is_file(string path_string) {
  const char *path = path_string.c_str();
  struct stat s;
  if (stat(path, &s) == 0) {

    if (s.st_mode & S_IFREG) {
      return true;
    }
  }
  return false;
}

int move_to_quarantine2(string path) {

  string fileName=get_filename(path);

  int i=1;
  string add = to_string(i);
  while(exists("../kwarantanna/" + add+ fileName)){

  
  
  i++;
  add = to_string(i);
  }
  
  fileName=add+fileName;

  string destination = "../kwarantanna/" + fileName;
  int status = rename(path.c_str(), destination.c_str());

  return status;
}

string SplitFilename(string& str)
{
  size_t found;
  size_t found2;
  string temp = str;
  found=temp.find_last_of("/\\");
  temp=temp.substr(0,found);
  found2=temp.find_last_of("/\\");
  temp=temp.substr(found2+1);

return temp;
  
}


