#include <string>
#include <fstream>
#include <iostream>

void changelog_writer(std::string stringone, std::string stringtwo)//writes whatever updates to the text file, stringone contains the change, stringtwo contains what actually updated
{
  std::fstream file_opener;//how the file will be accessed

  file_opener.open("Changelog.txt", std::fstream::app);//accessing the file and std::fstream::app appends to the text file, not overwriting it

  stringone = stringone  + ": ";//added separator for strings

  file_opener << stringone;//write the change to the file

  file_opener << stringtwo;//write the actual update to the file

  file_opener << "\n";

}

void changelog_reader()
{
  std::fstream file_opener;//how the file will be accessed

  file_opener.open("Changelog.txt");//accesses the changelog

  std::string file_line;//string to hold the lines

  while(std::getline(file_opener,file_line))//while the string has a line from the text file
  {
    std::cout << file_line << std::endl;//output it to the terminal
  }
}
