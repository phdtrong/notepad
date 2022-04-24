#include "notes.cpp"
#include <iostream>
#include <string>
#include <vector>


int main()
{
  Entry* written_entry;
  unsigned selection;
  std::string file;
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
        // user adds an entry
        written_entry = new_entry();
        notepad.push_back(written_entry);
        changelog_writer("Entry addition",
                          written_entry->get_header() + "added");
        break;
      case 2:
        // user views notepad
        notepad_view(notepad);
        break;
      case 3:
        // user saves notepad to file
        std::cout << "\nName of file: ";
        std::cin >> file;
        changelog_writer("Notepad save", "File named " + file + " saved");
        save_notepad(file, notepad);
        break;
      case 4:
        // user imports notepad from file
        import_notepad(notepad);
        break;
      default:
        std::cout << "\n";
    }
  } while (selection != 0);


  // notepad is autosaved, even if the user did not save
  save_notepad("autosave", notepad);
  changelog_writer("autosave", "autosave file updated ");
  return 0;
}
