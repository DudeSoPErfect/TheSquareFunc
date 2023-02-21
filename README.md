# The_square_func

### The essence of the program
The program calculates the roots of the quadratic equation according to the specified parameters and displays the number of roots and their value on the screen.
The program checks the correctness of its calculations on 5 pre-prepared tests. After that, the input of the coefficients of the equation is separated by a space in the order "A B C".
 

### File Description
* **main.cpp** - The main program file. 
Calls functions from other files, namely those that are responsible for checking the correctness of calculations, for solving the input equation and displaying the answer on the screen.
* **testing.cpp** - Auxiliary program file.
Starts testing the correctness of calculations.
* **testing.h** is the header file of the program.
Contains declarations of structures and functions for "testing.cpp ".
* **square.c** is an auxiliary program file.
Contains advanced algorithms for solving the quadratic equation
* **square.h** is the header file of the program.
Contains function declarations for "square.cpp ".

### How to launch
1. Upload all project files to one directory.
2. Install the g++ compiler and add it to the PATH environment variable.
3. Go to the files directory.
4. Launch the application "cmd.exe " in the current directory.
5. In "cmd.exe " run the command "g++ main.cpp square.cpp testing.cpp "
6. In "cmd.exe " run the command "a.exe "
7. Enjoy
