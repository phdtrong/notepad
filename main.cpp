// TODO: main should start the program and hold the menu
#include "changelog.cpp"
#include "notes.cpp"
#include <iostream>
#include <string>
#include <vector>


int main()
{
  Entry* written_entry;
  unsigned selection;
  std::vector<Entry*> notepad;


  std::cout << "Notepad Program\n";

  // this loop keeps the menu up until the user exits the program
  do
  {
    std::cout << "\nMain menu:\n(type in a number to select an option)\n"
              << "1: Make a new entry\n"
              << "2: View notepad\n"
              << "3: Save notepad\n"
              << "4: Import notepad file\n"
              << "5: View changelog\n"
              << "0: Close program\n";

    std::cin >> selection;
    // this instruction allows user inputs to work properly
    std::cin.ignore();

    switch (selection)
    {
      case 0:
        break;
      case 1:
        written_entry = new_entry();
        notepad.push_back(written_entry);
        break;
      case 2:
        notepad_view(notepad);
        break;
      default:
        std::cout << "\n";
    }
  } while (selection != 0);

  return 0;
}
