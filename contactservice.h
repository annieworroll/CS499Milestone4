#ifndef CONTACT_SERVICE
#define CONTACT_SERVICE

#include <string>
using std::string;
#include <vector>
#include <utility>

#include "contact.h"
#include "contactdatabase.h"

class ContactDatabase;

class ContactService{
  
  std::vector<Contact> contact_list;
  
  //stores the index of the current record
  int current_record;
  ContactDatabase *db;
  
 public:
  ContactService(ContactDatabase *db);
  void add_entry(string f_name, string l_name, string phone_number,
		 string address, string city, string state,
		 string zip);
  void add_memory_only(string f_name, string l_name, string phone_number,
		 string address, string city, string state,
		 string zip);
  Contact get_current_entry();
  Contact get_next_entry();
  Contact remove_entry();

  void update_last_name(string new_last_name);
  void update_first_name(string new_first_name);
  void update_phone_number(string new_phone_number);
  void update_address(string new_address);
  
  

};
  
#endif
