#include "../include/VirusScanner.h"
#include "../include/FileHandler.h"
#include "../include/HashCalculator.h"

#include <dirent.h>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <sys/stat.h>
#include <sys/vfs.h>

using namespace std;

static int wiruses;
static int scanned_files;
static int safe_files;
static int kwarantanna;

int check_file(string path) {

  struct statfs statfs_struct;

  int status = statfs(path.c_str(), &statfs_struct);
  if (status != 0) {
    perror("check failed");
    return -1;
  }

  if (statfs_struct.f_type == 61267) {
    return 1;
  } else {
    return 0;
  }
}

void directory(string folder) {
  struct dirent *dir_entry;
  folder += "/";
  DIR *dir = opendir(folder.c_str());

  if (dir == NULL) // opendir returns NULL if couldn't open directory
  {
    cout << "Could not open the directory" << endl << errno << endl;
    return;
  }

  while ((dir_entry = readdir(dir)) != NULL) {
    string fileName = dir_entry->d_name;
    if (fileName == "." || fileName == "..") {
      continue;
    }

    if (dir_entry->d_type == DT_DIR) {

      directory(folder + fileName);
    }

    if (dir_entry->d_type == DT_REG) {

      if (check_file(folder + fileName) == 1) {
        scanned_files++;
        cout << "         " << folder << fileName << endl;
        if (scan_hashes(folder + fileName))
          wiruses++;
        else
          safe_files++;
      } else
        safe_files++;
    }
  }

  closedir(dir);
}

void setup_directory(string folder) {
  kwarantanna = 0;
  wiruses = 0;
  scanned_files = 0;
  safe_files = 0;
  directory(folder);
  cout << "przeskanowane" << endl;
  cout << scanned_files << endl;
  cout << "wirusy" << endl;
  cout << wiruses << endl;
  cout << "bezpieczne" << endl;
  cout << safe_files << endl;
  cout << "pliki w kwarantannie" << endl;
  cout << kwarantanna << endl;
}

bool scan_hashes(string path) {


  string hash_to_compare = get_hash(path);
  ifstream myfile;
  myfile.open("../Hashes/hashes.txt");
  string temp;
  string folder = SplitFilename(path);
  while (getline(myfile, temp)) {
    if (temp == hash_to_compare) {
      if(folder!="kwarantanna"){
      cout << "wirus" << endl;
      move_to_quarantine2(path);
      myfile.close();
      return true;}
  
    }
  }
  myfile.close();
  return false;
}
