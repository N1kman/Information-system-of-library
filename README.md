# Information-system-of-library

When developing the information system of the library, the basic principles of the C++ programming language were studied and used. 
The basic properties of object-oriented programming were also observed: inheritance, polymorphism, encapsulation.
The developed information system of the library facilitates the work of the administrator. 
Namely, the system allows administrators to control the issuance and acceptance of books, 
and all possible changes, additions, deletions, search, sorting and other actions with users and books are available to administrators. 
A user-friendly interface has been developed for the user. 
The following actions are available: viewing the history of requests, taking and returning books, viewing debts, and others.

!!!System restrictions:
The program can be compiled with any Windows-compatible compiler and run on any computer running Microsoft Windows.

!!!Software restrictions:
The first restriction applies to administrators, the administrator cannot register himself, 
this can only be done by the main administrator, 
whose name, surname and password are specified in the program code by the constants nam, fam and pass, respectively. 
Also, administrators must specify the actual time of entry, so that users have a valid time to take or return books.
First name, last name, title and other character strings have a constant length length_12, and only Russian is supported for input. 
The password must contain only numbers and English letters and be 8 characters long.
All filenames for storing information are given by constants.
The number of undoable actions for technical work is set by the standard_MAX constant.

developed by Gill Nikita from VMSIS
