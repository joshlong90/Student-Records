# Student-Records #
### Project Description ###
The aim of the student records project was to provide a program for reading, processing and maintaining a collection of student records.

----
### Demo ###
To demo the project simply run the following commands:

To compile the program use:

`$ make` 

To run the program \
To simply add a certain number of records use:

`$ ./main <number_of_records_to_add>` 

or 

To initiate the dynamic version of the program with the following options 
* A - Add student record
* F - Find student record
* G - Get statistics
* H - Help
* P - Print all records
* Q - Quit

Use the following:

`$ ./main` 

or 

To run the program with the supplied input file use:

`$ ./main < input.txt`

----
### Output ###
Provided below is an example interaction:

```
./main
Enter command (a,f,g,p,q, h for Help)> a
Enter student ID: 1111111
Enter credit points: 15
Enter WAM: 77
Student record added.
Enter command (a,f,g,p,q, h for Help)> f
Enter student ID: 333333
Not valid. Enter a valid value: 3333333
No record found.
Enter command (a,f,g,p,q, h for Help)> a
Enter student ID: 3333333
Enter credit points: 12
Enter WAM: 85
Student record added.
Enter command (a,f,g,p,q, h for Help)> p
————————
Student zID: z1111111
Credits: 15
Level of performance: DN
————————
————————
Student zID: z3333333
Credits: 12
Level of performance: HD
————————
Enter command (a,f,g,p,q, h for Help)> f
Enter student ID: 3333333
————————
Student zID: z3333333
Credits: 12
Level of performance: HD
————————
Enter command (a,f,g,p,q, h for Help)> a
Enter student ID: 3333333
Enter credit points: 12
Enter WAM: 85
Student record updated.
Enter command (a,f,g,p,q, h for Help)> g
Number of records: 2
Average WAM: 81.000
Average weighted WAM: 80.556
Enter command (a,f,g,p,q, h for Help)> q
Bye.
```
