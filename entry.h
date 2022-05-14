#include "changelog.cpp"
class Entry
{

private:
  std::string _header, _body;

public:

  // getters and setters for each attribute
  std::string get_header();

  std::string get_body();

  void set_header(std::string new_header);

  void set_body(std::string new_body);


  //default constructor
  Entry() : _header(""), _body("") {};
  // parameterized constructor
  Entry(std::string header, std::string body);
};