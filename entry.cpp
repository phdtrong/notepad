#pragma once
#ifndef __ENTRY_CPP__
#define __ENTRY_CPP__
#include "entry.h"
  // getters and setters for each 
std::string Entry::get_header()
{
    return _header;
}

  std::string Entry::get_body()
  {
    return _body;
  }

  void Entry::set_header(std::string new_header)
  {
    _header = new_header;
  }

  void Entry::set_body(std::string new_body){
    _body = new_body;
  }


  //default constructor
  Entry::Entry() : _header(""), _body("") {};
  // parameterized constructor
  Entry::Entry(std::string header, std::string body) : _header(header), _body(body) {};
#endif