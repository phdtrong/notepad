// TODO: main should start the program and hold the menu
#include "changelog.cpp"
#include "notes.cpp"
#include <iostream>
#include <string>
#include <vector>


int main()
{
  std::string selection;
  std::vector<Entry> notepad;

  std::cout << "Notepad Program\n(type in a number to select an option)\n";

  // this loop keeps the menu up until the user exits the program
  do
  {
    std::cout << "1: Make a new entry\n"
              << "2: View notepad\n"
              << "3: Save notepad\n"
              << "4: Import notepad file\n"
              << "0: Close program\n";

    std::cin >> selection;
  } while (selection != "0");

  return 0;
}
