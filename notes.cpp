// TODO: implement classes and methods for notes (ability to write notes, delete notes, sort them, etc.)
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


  // constructor
  Entry(std::string header, std::string body) : _header(header), _body(body) {};
};
