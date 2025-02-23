#include "contactservice.h"

#include <exception>
#include <stdexcept>

ContactService::ContactService()
{
  //Set to -1 so that get_next_entry can be simpler for the
  //case of the first entry
  current_record = -1;
}

void ContactService::add_entry(string f_name, string l_name,
			       string phone_number, string address)
{
  Contact new_contact(f_name, l_name, phone_number, address, "", "", "");
  contact_list.push_back(new_contact);
}

Contact ContactService::get_current_entry()
{
  Contact record_to_return;
  //If we have records
  if(current_record != -1){
    record_to_return = contact_list[current_record];
  }
  //if we don't, just a default
  return record_to_return;
}

Contact ContactService::get_next_entry()
{
  current_record++;;
  Contact entry_to_return;

  try{
    entry_to_return = contact_list.at(current_record);
  }catch(std::out_of_range& ex){
    //We've run out of entries at this point, wrap to start
    current_record = 0;
    entry_to_return = contact_list[current_record];
  }

  return entry_to_return;
}

//Removes the current record and returns the previous record, or
//a default record if none left
Contact ContactService::remove_entry(){
  Contact entry_to_return;

  std::vector<Contact>::iterator to_erase = contact_list.begin() + current_record;
  try{
    contact_list.erase(to_erase);
    current_record--;
    //If there are records remaining
    if(current_record != -1){
      entry_to_return = contact_list[current_record];
    }
  }catch(std::exception& ex){
    //We get here if the record does not exist, return a default
    return entry_to_return;
  }
  return entry_to_return;
  
}

void ContactService::update_last_name(string new_last_name){
  contact_list[current_record].set_last_name(new_last_name);
}

void ContactService::update_first_name(string new_first_name){
  contact_list[current_record].set_first_name(new_first_name);
}

void ContactService::update_phone_number(string new_phone_number){
  contact_list[current_record].set_phone_number(new_phone_number);
}

void ContactService::update_address(string new_address){
  contact_list[current_record].set_address(new_address);
}

