// TODO: implement classes and methods for notes (ability to write notes, delete notes, sort them, etc.)
#include <iostream>
#include <string>
#include <vector>

// this class pertains to each entry a user would create in the notepad
class Entry
{

private:
  std::string _header, _body;

public:

  // getters and setters for each attribute
  std::string get_header()
  {
    return _header;
  }

  std::string get_body()
  {
    return _body;
  }

  void set_header(std::string new_header)
  {
    _header = new_header;
  }

  void set_body(std::string new_body){
    _body = new_body;
  }


  //default constructor
  Entry() : _header(""), _body("") {};
  // parameterized constructor
  Entry(std::string header, std::string body) : _header(header), _body(body) {};
};



// this function returns a newly written entry
Entry* new_entry()
{
  std::string header_input, body_input;

  std::cout << "\nheader: ";
  getline(std::cin, header_input);
  std::cout << "body: ";
  getline(std::cin, body_input);

  Entry* entry = new Entry(header_input, body_input);
  return entry;
}

// this function displays a single entry and its options
void entry_view(std::vector<Entry*>& notepad, unsigned entry_spot)
{
  unsigned selection;
  std::string edit;

  do
  {
    std::cout << "\nEntry " << entry_spot << ":\n"
              << notepad[entry_spot - 1]->get_header() << "\n"
              << notepad[entry_spot - 1]->get_body() << "\n"
              << "\n(type in a number to selection an option)\n"
              << "1. Edit header\n"
              << "2. Edit body\n"
              << "3. Delete entry\n"
              << "0. Return to notepad\n";
    std::cin >> selection;

    switch (selection)
    {
      case 0:
        break;
      case 1:
        std::cout << "new header: ";
        std::cin >> edit;
        notepad[entry_spot -1]->set_header(edit);
        break;
      case 2:
        std::cout << "new body: ";
        std::cin >> edit;
        notepad[entry_spot -1]->set_body(edit);
        break;
      case 3:
        notepad.erase(notepad.begin() + entry_spot - 1);
        return;
      default:
        std::cout << "\n";
    }
  } while (selection !=0);
  return;
}

// this function displays the list of entries in the notepad
void notepad_view(std::vector<Entry*>& notepad)
{
  unsigned selection;

  do
  {
    std::cout << "\nNotepad Entries:\n"
              << "(type in a number to selection an option)\n";

    for (unsigned i = 0; i < notepad.size(); i++)
    {
      std::cout <<  "1: " << notepad[i]->get_header() << "\n";
    }

    std::cout << "0: Return to main menu\n";
    std::cin >> selection;

    if (selection >= 1 && selection <= notepad.size())
    {
      entry_view(notepad, selection);
    } else if (selection > notepad.size() || selection < 0)
    {
      std::cout << "\n";
    }

  } while (selection != 0);
  return;
}
