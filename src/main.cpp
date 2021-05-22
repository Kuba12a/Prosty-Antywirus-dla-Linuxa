
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

void interface_scan() {

  cout << "podaj sciezke do pliku" << endl;
  string input;
  cin >> input;
  if (is_file(input))
    scan_hashes(input);
  else
    cout << "bledna sciezka" << endl;
}

void interface_directory() {
  cout << "Podaj sciezke do folderu" << endl;
  string input;
  cin >> input;
  if (!is_file(input)){
  	if(exists(input))
    setup_directory(input);
	else cout << "bledna sciezka" << endl;}
  else
  cout << "bledna sciezka" << endl;
}

void interface() {
  cout << "1-skanuj plik" << endl;
  cout << "2-skanuj folder" << endl;
  cout << "3-wyjscie" << endl;

  string input;
  cin >> input;
  int input_int = 0;
  try {
    input_int = stoi(input);

  } catch (const invalid_argument &e) {

    cerr << e.what();
    cout << endl;
  }

  if (input_int == 1)
    interface_scan();

  if (input_int == 2)
    interface_directory();

  if (input_int == 3)
    exit(3);
}

int main() {
  
  do_mkdir("../kwarantanna", 0000);
  while (1 == 1)
    interface();
  

}
