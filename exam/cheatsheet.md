# Computer Program and Programmer
- **Computer Program**: Bunch of instruction that can excecuted by computers to perform a specific task
- **Program**: Folks who make computer program, turning solution to a problem to instructions for computers
- **How to make one**
    - Identify the problems, the input and output
    - Find the solution as an algorithm (flowchart / pseudocode)
    - Code the algorithm in a programming lang
    - Debug/Test the program for inefficiency and error/bugs
    - Document for the origin of the problem, description, logic tools, program list (?), debug results, and in-code comments

# Computational Thinking
- **Definition**: A soft-skill and mindset to solve a problem with computational approach
- **Four aspects**:
    - **Decomposition**: Break big problems into smaller problems
    - **Pattern-recognition**: Find a similar pattern to the (smaller) problems
    - **Abstraction**: Find the important infos, throw away the rest
    - **Algorithm**: Implement the solution in a structured way
- **Characteristics**
    1. Use Computational Technologie
    2. Can solve problems in many field (not just computech)
    3. Produce a structured outputs

# C++ Basics
- **Basic Structure**
```cpp
#include<iostream> // Headers, required libraries
using namespace std; // like an identifier/last name, func can have same names. here assume everyone is just std
int main(){ // main function
    return 0; // statements are every commands, ends with ; (semicolon)
}
```
- **Type of Variable and Constant**
```cpp
// Variables (MUST declare data types)
int n=10; // integers, whole numbers
double pi=3.14; // decimals/fraction
char a='A' // SINGLE characters
bool B=true // true(1) or false (0)

// Const
const int n=10 // static, the variable won't be changeable
```
- **Input and Output (I/O~~stream~~)**
```cpp
// cin to the right since its inputting to a var (>>), cout to the left since its outputting to cout (<<)
cin>>x; // input to x
cin>>n>>m; // n then m, sequential
cout<<"Hello World"<<x<<endl; // print Helloworld{value of x} then go newline (endl)
```
- **Arithmetics**
```cpp
int n = 16;
int m = 4;
int h1 = n+m; // 20
int h2 = n-m; // -12
int h3 = n*m; // 64
int h4 = n/m; // 4, kuiosien
int h4 = n%m; // 0, remainder/modulo
```
- **Logic Operations/Relationals**
```cpp
int n = 2;
int m = 5;
(n == m); // false, equal to
(n > m) // false, larger
(n < m) // true, smaller
(n >= m) // false, larger or same
(n <= m) // true, smaller or same
(n != m) // true, not equal to
(n != m) && (n < m) // true & true = true, AND (both statement is true)
(n != m) || (n > m) // true & false = true, OR (either statement is true)
!(n != m) // true = false, NOT (reverse the logics)
```
# Conditional Statements
```cpp
int x = 4;
int y = 3;

// If
// one path with req
if (x % 2 == 0){ // true
    cout<<"okh"; // will execute
}

// If-else
// two path: one with req one !req
if (y % 2 == 0){ // not true
    cout<<"genap" // won't execute
}else{ // therefore
    cout<<"ganjil"; // will execute
}

// If-else-if-else
if (x > 0){ // true
    cout<<"positif" // will execute
}else if (x == 0){ // not true
    cout<<"nol";
}else if (x % 2 == 0){ // true but won't execute since the prev steps is already true
    cout<<"genap";
}else{ // last non req else is optional here
    cout<<"ganjil";
}

// Switch
// CAN NOT USE LOGIC NOR ARITHMETIC as req
// just integer and char, avoid floating point or string (theyre too complicated)
switch(x){
    case 1; cout<<1; break; // false
    case 2; cout<<2; break; // false
    case 4; cout<<4; break; // true
    case default; cout<<"nope!"<< break; // default for everything that isn't in the case
}
```
# Looping
```cpp
int N=5;
// FOR Loop
// Execute commands multiple times according to the desired value
// variable inside for loop will be local only to that for loop
// syntax: for {starting variable; variable limit; variable change}
for (int i = 0; i < N; i++){
    cout<<"Hello there";
} // will print Hello there x5

// While Loop
// Check if condition is true, run statement if condition is true
int i = 0 // i is global unlike in for which is local
while (i < N){
    cout<<"Hello there";
    i++; // don't forget to increment the control var to avoid infinte loop
} // print x5 too

// Do-While Loop
// Run statement, check if condition is true, back to the start
int i = 0
do {
    cout<<"Hello there";
    i++
}while(
    i<N;
) // also will print x5

// Nested Loop (loop inside loop is possible)
for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= n - i; j++) {
        cout << " ";
    }
    for (int j = 1; j <= i; j++) {
        cout << "* ";
    }
    cout << endl;
} // tiny little triangle
//    *
//   * *
//  * * *
// * * * *
//* * * * *
```
## Array & Struct
- **Array**: Collection of variables with same data types and same function, accessed using index (starts from 0)
```cpp
int k[10]; // declare array k of ints with 10 element
int k[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // set all to 0, must else the compiler will do funny things
int k[10] = {0}; // do the same as above
int n = k[4]; // assign the fifth element of k. the size starts from 1 but the index starts from 0
int j[2][2]; // array can have as many dimension
```
- **Structs**: Collection of variables that can have different data types and different functions
```cpp
struct Nilai{
    int nilai_angka;
    char huruf;
};
Nilai x; // declare struct Nilai for x
x.nilai_angka = 90; // access struct