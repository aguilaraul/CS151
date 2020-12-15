# 13. Advanced File and I/O Operations

# 13.1 Input and Output Streams

`ifstream` objects are used for file input, `ofstream` objects are used for file output, and `fstream` objects are used for both input and  output.

----------


- An input stream is a sequence from which data can be read
  * Keyboard is the standard example of an input stream
- An output stream is a sequence to which data can be written
  - Monitor screen is standard example of an output stream
- An input-output stream is a sequence of data that allows both reading and writing



C++ provides various classes for working with streams:

- `istream` and `ostream` for standard input and output
    - `cin` is a predefined object of `istream` to read from keyboard
    - `cout` is a predefined object of `ostream` to write to screen
- `ifstream`, `ofstream`, and `fstream` for file IO
- `istringstream` and `ostringstream` for reading and writing strings

The `fstream` class allows a file to be used for both input and output

## The File Stream Classes

The `ifstream`, `ofstream`, and `fstream` classes are very similar

Each has a default constructor:

```c++
ifstream();
ofstream();
fstream();
```

By default:

- `ifstream` objects open files for input
- `ofstream` objects open files for output
- `fstream` objects open files for both input and output

The `fstream` class combines in itself the capabilities of both `ifstream` and `ofstream`. Therefore, `fstream` has every member function and operator possessed by those two classes


## Using Constructors to Open Files

Each has initialization constructors that take two parameters:

1. The name of a file to be opened
    - Given by a C-string
2. An open mode
    - A setting that determines how the file will be used
    - Setting is optional, otherwise defaults
    

```cpp
ifstream(const char* filename, ios::openmode mode = ios::in);
ofstream(const char* filename, ios::openmode mode = ios::out);
fstream(const char* filename, ios::openmode mode = ios::in | ios::out);

// C++11, can used a string object
ifstream(const string& filename, ios::openmode mode = ios::in);
ofstream(const string& filename, ios::openmode mode = ios::out);
fstream(const string& filename, ios::openmode mode = ios::in | ios::out);
```



All three file stream classes have member functions that can be used to open files:

```c++
void open(const char* filename, ios::openmode mode = ios::in | ios::out);
void open(const string& filename, ios::openmode mode = ios::in | ios::out);
```

Create stream object and open file:

```c++
fstream outFile("inout.txt", ios::in | ios::out);
```


## File Open Modes

A file open mode is a setting that determines how the file can be used. The type `openmode` is defined in a stream-related class called `ios`. Values of this type are static constant members of the `ios` class

The binary or operator `|` can be used to combine the effect of two or more flags:

```c++
ios::in | ios::out | ios::ate
```


| **File Mode Flag** | **Meaning**                                                                                                           |
| ------------------ | --------------------------------------------------------------------------------------------------------------------- |
| `ios::app`         | Append: Output will always take place at the end of the file                                                          |
| `ios::ate`         | At end: Output will initially take place at the end of the file                                                       |
| `ios::binary`      | Binary: Data read or written to the file is in binary form                                                            |
| `ios::in`          | Input: The file will allow input operations. If the file does not exist, the open will fail                           |
| `ios::out`         | Output: The file will allow output operations. If the file does not exist, an empty file of the given name is created |
| `ios::trunc`       | Truncate: If the file being opened exists, its contents are discarded and its size is truncated to zero               |



**NOTE**

> When used by itself, the `ios::out` flag causes the contents of an existing file to be deleted, the assumption being that the programmer wants to overwrite the file.
>
> If `ios::out` is combined with `ios::app`, the contents of the existing file are preserved, and all the data is appended to the end of the file 

----------

**Program 13-1**
Opens the file, reads and prints its contents, and then writes the word “Hello” at the end of the file

```c++
// Demonstrates reading and writing a file through an fstream object
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  fstream inOutFile;
  string word;
  
  // Open the file
  inOutFile.open("inout.txt");
  if(inOutFile.fail()) {
    cout << "The file was not found." << endl;
    return 1;
  }

  // Read and print every word already in the file
  while(inOutFile >> word) {
    cout << word << endl;
  }

  // Clear end of file flag to allow additional file operations
  inOutFile.clear();

  // Write a word to the file and close the file
  inOutFile << "Hello" << endl;
  
  inOutFile.close();
  return 0;
}
```
----------
## Error Flags

File stream objects set a number of error flags whenever an input or output operation fails

Once an error flag is set, the stream will not allow further operations to be performed on it until the error flags have been cleared:

```c++
// Clears error flags
inOutFile.clear();
```


## Output Formatting and I/O Manipulators

I/O manipulators can be used on output stream objects, such as `fstream`, `ofstream`, and `ostringstream`:

**Example: Formatting**
Function takes in a `double` and formats it to two decimal places with dollar sign in front:

```c++
string dollarFormat(double amount) {
  // Create ostringstream object
  ostringstream outStr;

  // Set up format information and write to outStr
  outStr << showpoint << fixed << setprecision(2);
  outStr << '$' << amount;

  // Extract and return the string inside outStr
  return outStr.str();
}
```


----------

**I/O Manipulators**

| **Manipulator**   | **Description**                                              |
| ----------------- | ------------------------------------------------------------ |
| `dec`             | Displays subsequent numbers in decimal format                |
| `endl`            | Writes new line and flushes output stream                    |
| `fixed`           | Uses fixed notation for floating-point numbers               |
| `flush`           | Flushes output stream                                        |
| `hex`             | Input or outputs in hexadecimal                              |
| `left`            | Left justifies ouput                                         |
| `oct`             | Inputs or outputs in octal                                   |
| `right`           | Right justifies output                                       |
| `scientific`      | Uses scientific notation for floating-point numbers          |
| `setfill(ch)`     | Makes `ch` the fill character                                |
| `setprecision(n)` | Sets floating-point precision to `n`                         |
| `setw(n)`         | Set width of output field to `n`                             |
| `showbase`        | Shows the base when printing numbers                         |
| `noshowbase`      | Doe not show the base when printing numbers                  |
| `showpoint`       | Forces decimal point and trailing zeros to be displayed      |
| `noshowpoint`     | Prints no trailing zeros and drops decimal point if possible |
| `showpos`         | Prints a `+` with nonnegative numbers                        |
| `noshowpos`       | Does not print `+` with nonnegative numbers                  |

----------
## Closing Files

Open files use resources in the operating system, so it is important to close files as soon as they are done being used

Each class has a `close` member function:

```c++
void close();
```


## Flushing the Buffer

Data written to file stream objects are buffered within the operating system and is not immediately written to disk:

- When the file is closed, the operating system writes this data to the disk in a process known as flushing the buffer.
    - Closing the file will ensure that buffered data is not lost in the case that the program terminates abnormally.
- When the buffer is full, the operating system also flushes the buffer

The `endl` and `flush` manipulators allow the programmer to flush the buffer at any time

```c++
outFile << flush;
```


# 13.2 More Detailed Error Testing

All stream objects have error state bits that indicate the condition of the stream

----------
## Files Condition Bit Flags

These flags indicate the current state of the stream

| **Bit**         | **Description**                                                                     |
| --------------- | ----------------------------------------------------------------------------------- |
| `ios::eofbit`   | Set when the end of an input stream is encountered                                  |
| `ios::failbit`  | Set when an attempted operation has failed                                          |
| `ios::hardfail` | Set when an unrecoverable error has occurred                                        |
| `ios::badbit`   | Set when an invalid operation has been attempted                                    |
| `ios::goodbit`  | Set when all the flags above are not set. Indicates the stream is in good condition |

----------
## Member Functions That Report on the Bit Flags

The bit flags can be tested by the stream member functions

| Function  | Description                                                                                                              |
| --------- | ------------------------------------------------------------------------------------------------------------------------ |
| `eof()`   | Returns true (nonzero) if the `eofbit` flag is set; otherwise return false                                               |
| `fail()`  | Returns true (nonzero) if the `failbit` or `hardfail` flags are set; otherwise returns false                             |
| `bad()`   | Returns true (nonzero) of the `badbit` flag is set; otherwise returns false                                              |
| `good()`  | Returns true (nonzero) of the `goodbit` flag is set; otherwise returns false                                             |
| `clear()` | When called with no arguments, clears all the flags listed above. Can also be called with a specific flag as an arugment |

----------

**Example: File Status**
Function accepts a file stream reference and shows the state of the file:

```c++
void showState(fstream &file) {
  cout << "File Status:\n";
  cout << " eofbit: " << file.eof() << endl;
  cout << " fail bit: " << file.fail() << endl;
  cout << " bad bit: " << file.bad() << endl;
  cout << " good bit: " << file.good() << endl;
  file.clear();
}
```

For purpose of error testing, a stream object behaves as a Boolean expression that is `true` when no error flags are set and is `false` otherwise.

```c++
if(!dataFile) {
  cout << "Failure!";
} else {
  cout << "Success!";
}
```



# 13.3 Member Functions for Reading and Writing Files

File stream objects have member functions for more specialized file reading and writing.

----------

If whitespace characters are part of the information in a file, a problem arises when the file is read by the `>>` operator, since the operator considers whitespace characters as delimiters.


## The `getline` function

One way to get around the problem is to use a function that reads an entire line of text

```c++
istream& getline(istream& is, string& str, char delim = '\n');
```

- The first parameter must be an object of `istream`, `istringstream`, `ifstream`, or `fstream` that is open for input
- The delimiter is optional; defaults to `\n`
    - The delimiting character is removed from the stream and discarded

The value returned is a reference to the input stream that was read, which allows the return value to be tested


## The `get` Family of Member Functions

When the `get` function is called, it returns the next character available from the input stream and removes that character from the stream.

`get()` reads a character from the file

Each of the input classes has a family of `get` member functions that can be used to read single characters:

```c++
int get();
istream& get(char& c);
```


1. The first version reads a single characters
    1. If successful, it returns an integer code representing the character that was read
    2. If unsuccessful, it sets the error codes on the stream and returns the special value `EOF`


```c++
// Read file one character at a time and echo to screen
ch = file.get();
while(ch != EOF) {
  cout << ch;
  ch = file.get();
}
```


2. The second version `get` takes a reference to a character variable to read into and returns the stream that was read from
- Using this function requires testing the stream to determine whether the operation was successful

```cpp
file.get(ch)
while(!file.fail()) {
  cout << ch;
  file.get(ch);
}
```



## The `peek` Member Function

The `peek` function is called, it returns a copy of the next character available without removing it from the stream.

`peek()` looks at the next character from the file without actually reading it

The `peek` function is useful when determining what kind of data is about to be read to decide the best input method to use.

- If the data is numeric, the stream extraction operator `>>` is best
- If the data is non-numeric, then it should be read using `get` or `getline`


## The `put` Member Function

Each output stream class has a `put` member function that takes the integer code of a character and writes the corresponding character to the stream.

```c++
ostream& put(int c);
```

Prints `AB` on the screen:

```c++
#include <iostream>
using namespace std;
int main() {
  char ch = 'A';
  cout.put(ch);
  cout.put(ch + 1);
}
```


## Rewinding a File

Many times it is useful to open a file, process all the data in it, rewind the file back to the beginning, and process it again in a differ manor.

File stream classes offer a number of different member functions to move around in a file

The `seekg` member function sets the position of the next character to be extracted from the input stream:

```c++
seekg(offset, place);
```

The new location is at an offset of `offset` bytes from the starting point given by `place`

- The offset parameter is a `long` integer
- `place` can be one of three values defined in the `ios` class
    1. `ios::beg` beginning of the file
    2. `ios::cur` current place in the file
    3. `ios::end` end of the file

To move to the beginning of the file; move 0 bytes from the beginning of the file:

```c++
seekg(0L, ios::beg);
```


- If already at the end of the file, must clear the end of file flag before calling this function:

```c++
dataIn.clear();
dataIn.seekg(0L, ios::beg);
```



[More about `seek` member functions](https://github.com/aguilaraul/CS151/blob/master/Module%2009/13%20Advanced%20File%20and%20IO%20Operations.md#the-seekp-and-seekg-member-functions) 

# 13.4 Binary Files

Values of numeric data types such as `int` and `double` must be formatted for output before being written to text files. No such formatting takes places when numbers are written to binary files.

----------

A short integer number such as 1297 has both a string representation “1297” and a binary numeric representation. Both representations can be viewed as sequences of bytes.

![](https://paper-attachments.dropbox.com/s_30A1447FB3EBF043CE26AE2FE27EDEC9C0013A138E3C84991814A3E1A55495D6_1604195393590_image.png)


The conversion of string representation to numeric is called parsing, while the reverse conversion from numeric to string is called formatting.

When data is written in unformatted form, it is said to be written in binary, and files written in this way are called binary files. In contrast, files that hold formatted data are called text files.

The stream insertion operator `<<` provides automatic formatting of numbers during output. Likewise, the stream extraction operator `>>` provides parsing of numeric input


```c++
ofstream file("num.dat");
short x = 1297;
file << x;
```
- When the number is written, it is stored as the characters `1`, `2`, `9`, and `7`.
- When the number is stored in memory, it is formatted as a binary number
    - Data can be stored in a file in binary format.

Open a file in binary mode:

```c++
file.open("stuff.dat", ios::out | ios::binary);
```
**NOTE**

> By default, files are opened in text mode.



`**write**` **Member Function**
The `write` member function of the `ostream` and `ofstream` classes can be used to write binary data to a file or other output stream. 

    write(char* addressOfBuffer, int numberOfBytes);
    - `addressOfBuffer` specify the address of a buffer containing an array of bytes to be written
    - `numberOfBytes` an integer indicating how many bytes are to be written

The `write` member function does not distinguish between data types in the buffer; it just treats the buffer as an array of bytes.

Because C++ does not support a pointer to a byte, the prototype of `write` specifies that the address of a buffer be a pointer to a `char`.
Using a special form of type casting called `reinterpret_cast` forces the compiler to interpret the bits of one type as if they defined a value of a different type.

```c++
double d = 45.9;
double *pd = &d;
char *pChar;
// Convert pointer to double to pointer to char
pChar = reinterpret_cast<char*>(pd);
```

Using `write` to write a `double` and an array of `double` to file:

```c++
double d1 = 45.9;
double dArray[3] = {12.3, 45.8, 19.0};
ofstream outFile("stuff.dat", ios::binary);
outFile.write(reinterpret_cast<char*>(&d1), sizeof(d1));
outFile.write(reinterpret_cast<char*>(dArray). sizeof(dArray));
```

If the data being written is `char` data, there is no need to use type casting:

```c++
char ch = 'X';
char charArray[5] = "Hello";
outFile.write(&ch, sizeof(ch));
outFile.write(charArray, sizeof(charArray));
```

`**read**` **Member Function**
The `read` member function in the `istream` and `ifstream` classes can be used to read binary data.

```c++
read(char* addressOfBuffer, int numberOfBytes);
```

- `addressOfBuffer` the address of a buffer in which the bytes read are stored
- `numberOfBytes` the number of bytes to read

The address of the buffer must be interpreted as a pointer to `char` using `reinterpret_cast`.

**Array Size**
The `sizeof` operator can be used on variables to determine the number of bytes occupied by the variable.


```c++
int buffer[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int size = sizeof(buffer)/sizeof(buffer[0]);
```
- `sizeof(buffer)` returns the number of bytes allocated to the array
- `sizeof(buffer[0])` returns the number of bytes occupied by a single array entry

- With division, we obtain the number of array entries


# 13.5 Creating Records with Structures

Structures may be used to store fixed-length records to a file

----------

The following structure declaration could be used to create a record containing information about a person:

```c++
const int NAME_SIZE = 51, ADDR_SIZE = 51, PHONE_SIZE = 14;
struct Info {
  char name[NAME_SIZE];
  int age;
  char address1[ADDR_SIZE];
  char address2[ADDR_SIZE];
  char phone[PHONE_SIZE];
};
```

Besides providing an organized structure for information, structures also package information into a single unit.

```c++
Info person;
```

Once the members of `person` are filled, the entire variable may be written to a file using the `write` function:

```c++
file.write(reinterpret_cast<char*>(&person), sizeof(person));
```
**NOTE**

> Since structures can contain a mixture of data types, best to always use the `ios::binary` mode when opening a file to store them.
>
> Structures containing pointers cannot be correctly stored to disk using these techniques. This is because of the structure is read into memory, it cannot be guaranteed that all program variables will be at the same memory locations. Because `string` class objects contain implicit pointers, they cannot be stored



# 13.6 Random-Access Files

Random access means non-sequentially accessing information in a file

----------

All programs created so far in this chapter have performed sequential file access.

The problem with sequential file access is that in order to read a specific byte from the file, all the bytes that precede it must be read first.

C++ allows a program to perform random file access. In random file access, a program may immediately jump to any byte in the file without first reading the preceding bytes.


## The `seekp` and `seekg` Member Functions

File stream objects have two member functions that are used to move the read/write position to any byte in the file.

1. The `seekp` function is used with files opened for output
2. The `seekg` function is used with files opened for input


    file.seekp(20L, ios::beg);
1. The first argument is a `long` integer representing an offset into the file
2. The second argument is called the mode flag, and it designates where to calculate the offset from
    - The offset can be calculated from the beginning, end, or the current position in the file.

**File Positioning Flags**

| **Mode Flag** | **Description**                                         |
| ------------- | ------------------------------------------------------- |
| `ios::beg`    | The offset is calculated from the beginning of the file |
| `ios::end`    | The offset is calculated from the end of the file       |
| `ios::cur`    | The offset is calculated from the current position      |

Negative offsets result in the read or write position moving backward in the file
Positive values offsets result in forward movement


## The `tellp` and `tellg` Member Functions

File stream objects have two member functions that return, as a `long` integer, the current byte number of a file’s read and write position.

1. `tellp` is used to return the write position
2. `tellg` is used to return the read position


    pos = outFile.tellp();
    pos = outFile.tellg();


# 13.7 Opening a File for Both Input and Output

Able to perform input and output on an `fstream` file without closing it and reopening it.

----------

When data stored in a file needs to be updated:

1. Open the file
2. Copy the data into memory
3. Modify it
4. Write the data back to the file
5. Close the file

A file can be opened for both input and output by combining the `ios::in` and `ios::out` flags:

```c++
fstream file("data.dat", ios::in | ios::out);
```

When an `fstream` is opened for both the `ios::in` and `ios::out` flags, the file’s current contents are preserved, and the read/write position is initially placed at the beginning of the file. If the file does not exist, it is created.

