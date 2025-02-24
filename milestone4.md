---

layout: home

---

While std::vector is a capable data structure, it disappears when the computer
is turned off. This can be a problem for a contact list manager, which should 
retain its data even in the event of power loss. Otherwise, paper address books
or the rolodex would be a better solution.

There are multiple ways to achieve this. We could roll our own serialization
functionality, but that would require a great amount of debugging and complicate
the potential sharing of this data with other applications. Some operating 
systems may offer options to do this automatically, which may work with that 
operating system but would greatly complicate attempts to port the application to
another system.

SQLite is a library which allows applications to use an SQL database without the
installation of a full SQL server application. There are some tradeoffs when it 
comes to large datasets and simultaneous access from multiple systems, but this 
is not particularly relevant to a small contact manager application. SQLite is 
available for all major operating systems, and can also be statically linked to
the application, removing the need to install it seperately. Static linking can 
also lead to faster performance, as compilers can produce more optimal code when
they have more control over the overall end product. 
