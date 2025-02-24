#ifndef CONTACT_DATABASE
#define CONTACT_DATABASE

#include "contact.h"
#include "contactservice.h"
#include "sqlite3.h"

class ContactService;

class ContactDatabase{
 public:
  //Sets up database
  ContactDatabase();
  //gets records and puts them into contact service object
  void get_records(ContactService *c);
  void insert_record(Contact c);
  void remove_record(Contact c);
  ~ContactDatabase();

 private:
  static int callback(void*, int, char **, char **);
  sqlite3 *db;
  const char* data = "Callback called";
  char* error = 0;
};

#endif
