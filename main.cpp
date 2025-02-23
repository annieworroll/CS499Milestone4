/* Contact Manager
   Application using ContactService class to manage
   a list of contacts, serving as a digital rolodex
*/

#include <iostream>
#include <string>
#include "contactservice.h"
#include "sqlite3.h"

//Will be used by all functions
ContactService contacts;

void print_menu()
{
  std::cout << "(A)dd Entry (D)elete Entry (C)urrent Entry (N)ext Entry (E)xit\n";
}

void add_entry()
{
  std::cout << "Enter first name : \n";
  string f_name = "";
  std::cin >> f_name;

  std::cout << "Enter last name : \n";
  string l_name = "";
  std::cin >> l_name;
  
  std::cout << "Enter phone number : \n";
  string p_number = "";
  std::cin >> p_number;
  
  std::cout << "Enter address : \n";
  string address = "";
  //cin seperates tokens on whitespace, getline() on newline specifically
  std::getline(std::cin, address);
  
  contacts.add_entry(f_name, l_name, p_number, address);
}

void delete_entry()
{
  contacts.remove_entry();
}

Contact get_current_entry()
{
  return contacts.get_current_entry();
}

Contact get_next_entry()
{
  return contacts.get_next_entry();
}

void print_record()
{
  std::cout << get_current_entry().get_first_name() << '\n';
  std::cout << get_current_entry().get_last_name() << '\n';
  std::cout << get_current_entry().get_phone_number() << '\n';
  std::cout << get_current_entry().get_address() << '\n';
}


int main()
{
  //Initialize sqlite
  sqlite3_initialize();
  char command = ' ';

  while((command != 'e') && (command != 'E')){
    print_menu();
    std::cin >> command;
    //Ensure any garbage is dispensed with
    std::cin.clear();
    switch(command){
      //Using fallthrough for case insensitivity
    case 'a': case 'A':
      add_entry();
      break;
    case 'd': case 'D':
      delete_entry();
      break;
    case 'c': case 'C':
      get_current_entry();
      print_record();
      break;
    case 'n': case 'N':
      get_next_entry();
      print_record();
      break;
    case 'e': case 'E':
      //This is handled in the loop condition
      break;
    default:
      std::cout << "Invalid menu option. Please try again.\n";
    }
    
  }

  return 0;
}
