#include "contact.h"
using std::string;

Contact::Contact(){
  //Default to empty entries
  set_first_name("");
  set_last_name("");
  set_phone_number("");
  set_address("");
  set_city("");
  set_state("");
  set_zip_code("");
}
Contact::Contact(string fName, string lName, string pNumber,
		 string add, string city, string state, string zip){
  //While probably safe to directly set these values, future changes
  //may call for a more complicated process

  set_first_name(fName);
  set_last_name(lName);
  set_phone_number(pNumber);
  set_address(add);
  set_city(city);
  set_state(state);
  set_zip_code(zip);
}

void Contact::set_first_name(string fName){
  first_name = fName;
}

void Contact::set_last_name(string lName){
  last_name = lName;
}

void Contact::set_phone_number(string pNumber){
  phone_number = pNumber;
}

void Contact::set_address(string add){
  address = add;
}

void Contact::set_city(string city){
  this->city = city;
}

void Contact::set_state(string st){
  state = st;
}

void Contact::set_zip_code(string zip){
  zip_code = zip;
}

string Contact::get_first_name(){
  return first_name;
}

string Contact::get_last_name(){
  return last_name;
}

string Contact::get_phone_number(){
  return phone_number;
}

string Contact::get_address(){
  return address;
}

string Contact::get_city(){
  return city;
}

string Contact::get_state(){
  return state;
}

string Contact::get_zip_code(){
  return zip_code;
}

string Contact::to_string(){
  return last_name + ',' + first_name + ',' + phone_number + ',' + address + ',' +
    city + ',' + state + ',' + zip_code;
}
