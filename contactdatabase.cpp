#include "contactdatabase.h"
#include <iostream>
#include <iomanip>

ContactDatabase::ContactDatabase(){
  int result = sqlite3_open("contacts.db", &db);   
}

void ContactDatabase::get_records(ContactService *c){
   //SQL statement
   char * sql = "SELECT * FROM contacts;";
  
   sqlite3_exec(db, sql, callback, c, &error);
   
   std::cerr << error << '\n';
}

void ContactDatabase::insert_record(Contact c){
  string sql_command = "INSERT INTO contacts (last_name, first_name, phone_number, address, city, state, zip_code)";

  std::stringstream vals;
  vals << std::quoted(c.get_last_name()) << ',' << std::quoted(c.get_first_name()) << ','
       << std::quoted(c.get_phone_number()) << ',' << std::quoted(c.get_address()) << ','
       << std::quoted(c.get_city()) << ',' << std::quoted(c.get_state()) << ','
       << std::quoted(c.get_zip_code());
  string sql_data = "VALUES(" + vals.str() + ");";

  string sql = sql_command + sql_data;

  char *error;
  if(sqlite3_exec(db, sql.c_str(), NULL, NULL, &error) != SQLITE_OK){
    std::cerr << "error on insert\n";
    std::cout << error << '\n';
    std::cout << sql << '\n';
  }
}

void ContactDatabase::remove_record(Contact c){
  //TODO
}


int ContactDatabase::callback(void* c, int argc, char **argv, char** error){
  string last_name = argv[0];
  string first_name = argv[1];
  string phone_number = argv[2];
  string address = argv[3];
  string city = argv[4];
  string state = argv[5];
  string zip_code = argv[6];
    
  reinterpret_cast<ContactService*>(c)->add_memory_only(last_name, first_name, phone_number, address,
		  city, state, zip_code);
  std::cerr << "finished callback\n";

  return 0;
}

ContactDatabase::~ContactDatabase()
{
  sqlite3_close(db);
}
