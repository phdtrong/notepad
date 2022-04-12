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

  std::cout << "header: ";
  getline(std::cin, header_input);
  std::cout << "body: ";
  getline(std::cin, body_input);

  Entry* entry = new Entry(header_input, body_input);
  return entry;
}
