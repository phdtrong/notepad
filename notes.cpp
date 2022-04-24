/* Program name: "Notepad"
This program is used to create, view, save, and sort notepads.
Copyright (C) 2022 John Dinh, Triet Le, Ares Hamilton

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

File name: notes.cpp
This file contains all functions and classes pertaining to notepads and their
respective entries.
Last modified by: Ares Hamilton
*/

#include "changelog.cpp"
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


// this function handles the partitioning for the quick sort algorithm
unsigned partition(std::vector<Entry*>& notepad, unsigned low, unsigned high)
{
  unsigned j = low;
  Entry* swap = new Entry();
  std::string pivot = notepad[high]->get_header();
  for (int i = low; i < high; i++)
  {
    if (notepad[i]->get_header() <= pivot)
    {
      swap = notepad[i];
      notepad[i] = notepad[j];
      notepad[j] = swap;
      j++;
    }
  }
  swap = notepad[high];
  notepad[high] = notepad[j];
  notepad[j] = swap;
  return j;
}



// this function will use a quick sort algorithm to reorder the entries
void quick_sort(std::vector<Entry*>& notepad, unsigned low, unsigned high)
{

  // return once the sorting is done
  if (low >= high)
  {
    return;
  }
  unsigned j = partition(notepad, low, high);
  quick_sort(notepad, low, j - 1);
  quick_sort(notepad, j + 1, high);
}


// this function returns a newly written entry
Entry* new_entry()
{
  std::string header_input, body_input;

  // user inputs a header and a body for the entry
  std::cout << "\nheader: ";
  getline(std::cin, header_input);
  std::cout << "body: ";
  getline(std::cin, body_input);

  // Entry object is created and returned
  Entry* entry = new Entry(header_input, body_input);
  return entry;
}


// this function displays a single entry and its options
void entry_view(std::vector<Entry*>& notepad, unsigned entry_spot)
{
  unsigned selection;
  std::string edit;


  // from here, the user can edit the entry, delete it, or return to main menu
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
    std::cin.ignore();

    switch (selection)
    {
      case 0:
        break;
      case 1:
        // user edits header
        std::cout << "new header: ";
        getline(std::cin, edit);
        changelog_writer("Entry edit", "changed header of " +
                          notepad[entry_spot - 1]->get_header());
        notepad[entry_spot -1]->set_header(edit);
        break;
      case 2:
        // user edits body
        std::cout << "new body: ";
        getline(std::cin, edit);
        changelog_writer("Entry edit", "changed body of " +
                          notepad[entry_spot - 1]->get_header());
        notepad[entry_spot -1]->set_body(edit);
        break;
      case 3:
        // user deletes entry
        changelog_writer("Entry deletion",
                          notepad[entry_spot - 1]->get_header() + " deleted");
        notepad.erase(notepad.begin() + entry_spot - 1);
        return;
      default:
        std::cout << "\n";
    }
  } while (selection != 0);
  return;
}

// this function displays the list of entries in the notepad
void notepad_view(std::vector<Entry*>& notepad)
{
  int selection;

  do
  {
    std::cout << "\nNotepad Entries:\n"
              << "(type in a number to selection an option)\n";

    for (unsigned i = 0; i < notepad.size(); i++)
    {
      std::cout <<  i + 1 << ": "<< notepad[i]->get_header() << "\n";
    }
    std::cout << "-1: sort notepad\n";
    std::cout << "0: Return to main menu\n";

    // the user can select a specific entry to view
    std::cin >> selection;
    if (selection == -1)
    {
      // the user can sort the notepad in alphabetical order
      quick_sort(notepad, 0, notepad.size() - 1);
      //selection_sort(notepad);
    } else if (selection >= 1 && selection <= notepad.size())
    {
      entry_view(notepad, selection);
    } else if (selection > notepad.size() || selection < -1)
    {
      std::cout << "\n";
    }

  } while (selection != 0);
  return;
}

// this function saves a notepad onto a local file
void save_notepad(std::string file, std::vector<Entry*>& notepad)
{
  std::ofstream save;
  save.open(file);

  // notepad is transferred line by line to the file
  for (int i = 0; i < notepad.size(); i++)
  {
    save << notepad[i]->get_header() << "\n";
    save << notepad[i]->get_body() << "\n\n";
  }

  save.close();

  // this only needs to be printed if the user is manually saving
  if (file != "autosave")
  {
    std::cout << "\nNotepad saved to " << file << "\n";
  }
}


// this function imports a notepad from a local file
void import_notepad(std::vector<Entry*>& notepad)
{
  std::ifstream import;
  std::string file, imported_header, imported_body, empty_space;

  // user gives a file name to import
  std::cout << "\nName of file: ";
  std::cin >> file;
  import.open(file);

  // the file's contents are imported line by line
  while (true)
  {
    std::getline(import, imported_header);
    std::getline(import, imported_body);
    std::getline(import, empty_space);

    // stops adding entries when it reaches the end of the file
    if (import.eof()) break;

    Entry* imported_entry = new Entry(imported_header, imported_body);
    notepad.push_back(imported_entry);
  }

  import.close();
  std::cout << "\nNotepad imported from " << file << "\n";
  changelog_writer("Notepad import", "File named " + file + " imported");
}
