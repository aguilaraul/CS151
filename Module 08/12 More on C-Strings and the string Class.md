# 12. More on C-Strings and the `string` Class

# 12.1 Character Testing

The C++ library provides several functions for testing characters. To use these functions you must include the `<cctype>` header file

----------

These functions test a single `char` argument and return either `true` or `false`

    - The return value is nonzero to indicate `true` or zero to indicate `false`

**Character-Testing Functions**

| **Character Function** | **Description**                               |
| ---------------------- | --------------------------------------------- |
| `isalpha()`            | Check if character is alphabetic              |
| `isalnum()`            | Check if character is alphanumeric            |
| `isdigit()`            | Check if character is decimal digit           |
| `islower()`            | Check if character is lower case              |
| `isprint()`            | Check if character is printable               |
| `ispunct()`            | Check if character is a punctuation character |
| `isupper()`            | Check if character is upper case              |
| `isspace()`            | Check if character is a white-space           |

# 12.2 Character Case Conversion

The C++ library offers functions for converting a character to uppercase or lowercase

----------

Two functions `toupper` and `tolower` for converting the case of a character


- They return the equivalent without changing original argument
| **Function** | **Description**                       |
| ------------ | ------------------------------------- |
| `toupper`    | Convert string to uppercase lettering |
| `tolower`    | Convert string to lowercase lettering |

# 12.3 C-Strings

A C-string is a sequence of character stored in consecutive memory locations and terminated by a null character

----------

C++ provides two different data types for working with strings:

1. C-strings
2. the `string` class
    - Has useful, string-related functions and safeguards not present in C-strings

The `string` class is built on top of C-strings

A C-string is a sequence of character stored in consecutive memory locations and terminated by a null character:

    - A null character is the character whose ASCII code is 0
    char ch1, ch2, ch3;
    ch1 = '\0';
    ch2 = 0;
    ch3 = NULL;

A C-string is really a null-terminated array of characters and is represented in the program by a pointer to the first character in the array:

    char *

The type of a C-string is *pointer to char*

C-strings can appear in a program as:

- “Hard-coded” string literals
    - The array is allocated implicitly by the compiler
- Programmer-defined arrays of characters
    - The array is explicitly allocated by the programmer
- Pointers to characters
## String Literals

String literal, or string constants, are written directly into the program as a sequence of characters enclosed in double quotes:

    "I'm still in love with you"

String literals can only hold C-strings that are hard-coded into the program


![](https://paper-attachments.dropbox.com/s_59ED17D11EE8E15CE1B5414E7588EF753B1D33CF3220AE4BF88DC6B4122B0B29_1604639599315_image.png)


The compiler treats the address of the first character of the array as the value of the string literal

    // This program demonstrates that string literal are pointers to char
    #include <iostream>
    using namespace std;
    
    int main() {
      const char * p = nullptr, *q = nullptr;
      p = "Hello ";
      q = "Bailey";
    
      // Print the pointers as C-strings
      cout << p << q << endl;
    
      // Print C-string addresses
      cout << int(p) << endl;
      cout << int(q) << endl;
    
      // A string literal can be treated as a pointer
      cout << int("literal") << endl;
      
      return 0;
    }


## Programmer-Defined Arrays of Character

To have a C-string read from a file or keyboard, must first explicitly define a char array

    - The size should hold the characters of the string + 1 for the terminating null character
    const int SIZE == 20;
    char company[SIZE];

A C-string defined as an array can be given its value by initializing it with a string literal, by reading characters into it from the keyboard or file, or by copying characters into it:

    const int SIZE = 20;
    char company[SIZE] = "Robotic Systems, inc.";
    char corporation[] = "C. K. Graphics";

A C-string stored as a programmer-defined array can be processed using subscript notation


## Pointers to `char`

Use a pointer to `char` to point to a C-string whose storage has already been allocated by one of the other two methods:

    char name[] = "John Q. Public";
    char *p;
    p = name;
    cout << p << endl;
    p = "Jane Doe";
    cout << p << endl;
- A major advantage in using a pointer variable to represent a C-string is the ability to make the pointer point to different C-strings

Another way, define the pointer and then set it to point to dynamically allocated storage returned by the `new` operator

    const int NAME_LENGTH = 50;
    char *pName = nullptr;
    // Allocate the array
    pName = new char[NAME_LENGTH];
    
    // Read a string
    cout << "Enter your name: ";
    cin.getline(pName, NAME_LENGTH);
    
    // Display the string
    cout << "Hello " << pName;
    
    // Release the memory
    delete[] pName;


# 12.4 Library Functions for Working with C-Strings

The C++ library provides many functions for working with C-strings

----------

Must include `<cstring>`


## The `strlen` Function

The `strlen` function is passed a C-string as its argument and returns the length of the string

    - The number of characters up to but not including the null terminator
    char str[] = "Hello";
    int length = strlen(str);

The length of string should not be confused with the size of the array holding it

## Passing C-String arguments

The C-string can be passed to the a function in the form of:

    - A string literal
    - The name of an array that stores the C-string
    - A pointer variable hold the address of the C-string


## The `strcat` Function

The `strcat` function takes two strings as parameters and concatenates them, returning a single string:

    const int SIZE = 13;
    char string1[SIZE] = "Hello ";
    char string2[] = "World!";
    strcat(string1, string2);
    cout << string1 << endl;

The function copies the contents of `string2` to the end of `string1`

    - The programmer’s responsibility to make sure the array holding `string1` is large enough to hold `string1` and `string2` plus a null terminator

Program to test an array’s size before `strcat` is called:

    if(sizeof(string1) >= (strlen(string1) + strlen(string2) + 1)) {
      strcat(string1, string2);
    } else {
      cout << "String1 is not large enough to concatenate." << endl;
    }
| If the array holding the first string is not large enough to hold both strings, `strcat` will overflow the boundries of the array |

![](https://paper-attachments.dropbox.com/s_59ED17D11EE8E15CE1B5414E7588EF753B1D33CF3220AE4BF88DC6B4122B0B29_1605039253705_image.png)

## The `strcpy` Function

The `strcpy` function can be used to copy one C-string to another

    const int SIZE = 20;
    char name[SIZE];
    strcpy(name, "Albert Einstein");

The second C-string is copied to the address specified by the first C-string argument
If anything is already stored in the location, then it is overwritten

    char string1[] = "Hello";
    cout << string1 << endl;
    strcpy(string1, "World");
    cout << string1 << endl;

Output:

    Hello
    World!
| `strcpy` performs no bounds checking. The first argument will be overflowed if it is not large enough to hold the string specified by the second argument |

## Comparing C-Strings

Just as the assignment operator **cannot** be used to assign to C-strings, the relational operators **cannot** be used to compare C-strings

    <=, <, >, >=, !=, ==

When used, these operator compare the addresses at which the C-strings are stored instead of the actual contents

## The `strcmp` Function

To properly compare C-strings, use the `strcmp` function

Takes two C-strings as parameters and returns an integer:

    int strcmp(char* string1, char* string2);

The value of the result is set to:

- `strcmp() == 0` the two strings are equivalent
- `strcmp() < 0` means `string1` comes before `string2` in alphabetical order
- `strcmp() > 0` means `string1` comes after `string2` in alphabetical order


    if(strcmp(string1, string2) == 0) {
      cout << "The strings are equal";
    } else {
      cout << "The strings are not equal";
    }

The function `strcmp` is case sensitive when it compares strings

## Using `!` with `strcmp`

Since `0` is considered logically `false`, the `!` operator converts the value to `true`

The expression `!strcmp(string1, string2)` will return `true` when both strings are the same

    if(!strcmp(string1, string2)) {
      cout << "equal;
    }


# 12.5 Conversions Between Numbers and Strings

The C++ libraries provide functions and classes the can be used to convert a string to numeric form and vice versa

----------

The string of `2679` is a sequence of ASCII codes of the characters that make up the number
Compiler will not allow arithmetic operations

In C++, when a number is read from the keyboard via the stream extraction operator `>>` it performs conversions from string to numeric value before storing the variable
During the output using the stream insertion operator `<<`, the reverse conversion is performed

## Using String Stream Objects for Numeric Conversion

C++ has two classes, `ostringstream` and `istringstream`, that can be used to perform string/numeric conversions for in-memory values

Must include `<sstream>` to use these classes

| **Member Function**       | **Description**                                                                            |
| ------------------------- | ------------------------------------------------------------------------------------------ |
| `istringstream(string s)` | Constructor for `istringstream` sets the initial value of the input stream for the object  |
| `ostringstream(string s)` | Constructor for `ostringstream` sets the initial value of the output stream for the object |
| `string str()`            | Returns the string contained in either object                                              |
| `void str(string &str)`   | Sets the string that serves as the input or output stream for the object                   |


The class `ostringstream` is a subclass of `ostream` and uses the stream insertion operator `<<` to convert numeric values to string

    `ostringstream` writes its data to a string object contained inside it. Each time `<<` is used on the object, it performs any numeric-to-string conversions and appends the result to the end of its string

The class `istringstream` class derives from `istream` and uses the stream extraction operator `>>` to read from the enclosed string and converts from string to numeric value

    `istringstream` reads data from its string object contained inside. The input stream can be set by the constructor or by calling the `str(string s)` function after the object has been created

They do have a disadvantage in that they force you to create `sstream` objects to use their conversion operators

## Numeric Conversion Functions

C++11 provides several `to_string(T value)` functions to convert a numeric value of type `T` to string form

    int a = 5;
    string str = to_string(a*a);
    cout << "The square of 5 is " << str << endl;

The `to_string()` functions cannot handle conversion of integers to bases other than 10

    - An `ostringstream` object should do the conversion

The string-to-numeric conversions are performed by the family of `stoX()` functions

These family members perform string conversions to `int`, `long`, `float`, and `double`

    int stoi(const string&, size_t* pos = 0, int base = 10)
    long stol(const string& str, size_t* pos = 0, int base = 10)
    float stof(...)
    double stod(...)
    - The `pos` and `base` are optional
        - If `pos` is omitted, the index of the stopping character is not stored
        - If `base` is omitted, it is assumed to be 10

For example, an attempt to convert the string `-34is even` will succeed and return the integer `-34` and set the position of the first character that could not be converted to 3

If the string `str` has an invlaid value, such as `"``is -34 even?``"`, then no conversion can be performed and the function throws an `invalid_argument` exception

# 12.6 Writing Your Own C-String Handling Functions

You can design your own specialized functions for manipulating strings

----------

By being able to pass arrays as arguments, functions processing C-strings can be written


## Using Pointers to Pass C-String Arguments

Pointers are useful for writing functions that process C-string:

    If the starting address of the string is passed, then it can be assumed that all the characters, from the start address to the null terminator, are part of the string (not necessary to know length of the string)
# 12.7 More about the C++ `string` Class

The `string` class has several built-in member functions and overloaded operators that simplify tasks over using C-strings

Must include `<string>`

String Constructors

| **Function**              | **Description**                                                  |
| ------------------------- | ---------------------------------------------------------------- |
| `string()`                | Default constructor: creates an empty string                     |
| `string(const char* s)`   | Convert constructor: creates a string object from a C-string s   |
| `string(const string &s)` | Copy constructor: creates a new string from an existing string s |

String class overloads

| **Overload Operator**                           | **Description**                                                                                                                                   |
| ----------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------- |
| `>>`                                            | Extracts characters from stream and inserts them into the string. Characters are copied until a whitespace or the end of the input is encountered |
| `<<`                                            | Inserts the string into a stream                                                                                                                  |
| `=`                                             | Assigns the string on the right to the string on the left                                                                                         |
| `+=`                                            | Appends a copy of the string on the right to the string object on the left                                                                        |
| `+`                                             | Returns a string that is the concatenation of the two strings                                                                                     |
| `[]`                                            | Implements array-substring notation                                                                                                               |
| Relational operators<br> `<, >, <=, >=, ==, !=` | Each relational operator is implemented                                                                                                           |


