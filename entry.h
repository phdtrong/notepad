#pragma once
#ifndef __ENTRY_H__
#define __ENTRY_H__
#include <string>
#include <iostream>

// this class pertains to each entry a user would create in the notepad
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
  Entry();
  // parameterized constructor
  Entry(std::string header, std::string body);
};
#include "entry.cpp"
#endif