// TODO: changelog should be able to both read from and write to a text file called "Change Log", that holds every update to the user's notes
//       i.e. writing a new note, deleting a note, etc.
#include <string>
#include <fstream>

void changelog_writer(std::string stringone, std::string stringtwo)//writes whatever updates to the text file, stringone contains the change, stringtwo contains what actually updated
{
  std::fstream file_opener;//how the file will be accessed

  file_opener.open("Changelog.txt", std::fstream::app);//accessing the file and std::fstream::app appends to the text file, not overwriting it

  string1 = stringone  + " ";//added separator for strings

  file_opener << stringone;//write the change to the file

  file_opener << stringtwo;//write the actual update to the file

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
