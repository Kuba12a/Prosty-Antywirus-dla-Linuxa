#include "../include/HashCalculator.h"
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
using namespace std;

string exec(string command) {
  char buffer[128];
  string result = "";

  // Open pipe to file

  FILE *pipe = popen(command.c_str(), "r");
  if (pipe == NULL) {
    perror("Error opening file");
    return "popen failed!";
  }

  // read till end of process:
  while (!feof(pipe)) {

    if (fgets(buffer, 128, pipe) != NULL)
      result += buffer;
  }

  fclose(pipe);
  return result;
}

string get_hash(string path) {
  string ls = exec("sha512sum \"" + path + "\" |cut  -d \' \' -f 1 ");
  ls = ls.substr(0, ls.size() - 1);
  return ls;
}
