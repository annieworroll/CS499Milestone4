/* class to hold a contact record */
#include <string>
using std::string;
class Contact{

 private:
  string firstName;
  string lastName;
  string phoneNumber;
  string address;
  string city;
  string state;
  string zip_code;

 public:
  Contact();
  Contact(string fName, string lName, string pNumber, string add,
	  string city, string state, string zip);
  
  void set_first_name(string);
  void set_last_name(string);
  void set_phone_number(string);
  void set_address(string);
  void set_city(string);
  void set_state(string);
  void set_zip_code(string);
  
  string get_first_name();
  string get_last_name();
  string get_phone_number();
  string get_address();
  string get_city();
  string get_state();
  string get_zip_code();
};
