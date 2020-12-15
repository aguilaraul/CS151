# 16 Exceptions and Templates

# **16.1 Exceptions**

Exceptions are used to signal errors or unexpected events that occur while a program is running.

----------
## **Throwing an Exception**

One way of handling complex error conditions is with *exceptions*

- An exception is a value or an object that signals an error

Exception is thrown if attempting to divide by zero:

```c++
double divide(double num, double den) {
  if(den == 0) {
    throw string("Error: Cannot divide by zero.\n");
  } else {
    return num / den;
  }
}
```

The `throw` keyword is followed by an argument, which can be any value.

- The type of argument is used to determine the nature of the error

The line containing a throw statement is known as the **throw point**.
When an error occurs, control is passed to the **exception handler**, the part of the program that catches and handles that type of error

## **Handling an Exception**

To handle an exception, a program must have a try/catch construct

```c++
try {
  quotient = divide(num1, num2);
  cout << "The quotient is " << quotient << endl;
} catch(string exceptionString) {
  cout << exceptionString;
}
```

The first part of the construct is the try block

- This starts with the keyword `try` and is followed by a block of code executing any statements that might directly or indirectly cause an exception to be thrown

The try block is immediately followed by one or more catch blocks, which are exception handlers

- A catch block starts with the keyword `catch`, followed by a set of parentheses containing the declaration of an exception parameter.
## **What If an Exception Is Not Caught?**

There are two possible ways for an thrown exception not to be caught:

1. The program does not contain a catch block with an exception handler of the correct type
2. The exception was thrown from outside a try block

In either case, the exception will cause the entire program to abort execution

## **Object-Oriented Exception Handling with Classes**

The `IntRange` class:

```c++
#ifndef INTRANGE_H
#define INTRANGE_H

#include <iostream>
using namespace std;

class IntRange
{
    private:
    int input;
    int lower;
    int upper;
    public:
    // Exception class
    class OutOfRange
    {}; // Empty class declaration
    // Member functions
    IntRange(int low, int high)
    {
        lower = low;
        higher = high;
    }
    int getInt()
    {
        cin >> input;
        if(input < lower || input > upper)
        {
            throw OutOfRange();
        }
        return input;
    }
};
#endif
```

Instead of throwing a string or primative type value, `getInt()` throws an **exception class** 

```cpp
class OutOfRange
{}; // Empty class declartation
```

The only important part of this class is its name, which will be used by the exception-handling code
        The `throw` statement's argument, `OutOfRange()`, causes an instance of the `OutOfRange` class to be created and thrown as an exception

```cpp
if(input < lower || input > upper) {
    throw OutOfRange();
}
```

A try-catch block to handle the exception:

```cpp
try {
    userValue = range.getInput();
    cout << "You entered " << userValue << endl;
} catch (IntRange::OutOfRange) {
    cout << "That value is out of range.\n";
}
```
## **Multiple Exceptions**

C++ allows multiple throw and catch exceptions as long as each exception is of a different type
Expand the `IntRange` class to throw two exceptions: one if the input is too low, and one if the input is too high:

```cpp
// Exception classes
class TooLow
{};
class TooHigh
{};
int getInput()
{
    cin >> input;
    if(input < lower) {
        throw TooLow();
    } else if (input > upper) {
        throw TooHigh();
    }
    return input;
}
```

Write multiple catch blocks to match the exceptions:

```cpp
try {
    userValue = range.getInput();
    cout << "You entered " << userValue << endl;
} catch (IntRange::TooLow) {
    cout << "That value is too low.\n";
} catch (IntRange::TooHigh) {
    cout << "That value is too high.\n";
}
```
## **Extracting Information from the Exception Class**

An exception can not only signal when an invalid value has been entered, but also pass the value back
        This can be done by giving the exception class members in which the information can be stored

```c++
// Exception class
class OutOfRange
{
    public:
    int value;
    OutOfRange(int i) {
        value = i;
    }
};
```

When the exception is thrown, pass the value entered by the user to the `OutOfRange` constructor:

```c++
throw OutOfRange(input);
```

The class instance carries this member variable to the catch block that intercepts the exception:

```c++
catch(IntRange::OutOfRange ex) {
    cout << "That value " << ex.value
        << " is out of range.\n";
}
```
## **Handling the** `**bad_alloc**` **Exception Thrown by** `**new**`

The `new` operator throws a system-defined exception of type `bad_alloc` if it is unable to allocate the requested storage

```c++
- Must include `<new>` header file
// This program demonstrates the use of `bad_alloc`
int main() {
    int *p;
    try {
        p = new int[2];
        p[0] = 10;
        p[1] = 20;
    } catch(bad_alloc) {
        cout << "Memory cannot be allocated.";
        exit(1);
    }
    cout << p[0] << " " << p[1];
    return 0;
}
```

The program attempts to allocate an array of two integers using the `new` operator. If the allocation fails, the resulting `bad_alloc` exception is caught and terminates the program with an error message. Otherwise, success means the numbers in array are printed.

## **Unwinding the Stack**

If an exception is thrown in a try block that has a catch block capable of handling the exception, control transfers from the throw point to the catch block

​	Assuming that the catch block executes to completion without throwing futher exceptions, returning from the function, or terminating the program, execution will continue at the first statement after the sequence of catch blocks attached to the try block

If the function does not contain an appropriate catch block, control passes out of the function, and the exception is automatically rethrown at the point of the call in the calling function

​	By this process, an exception can unwind the stack as it propagates backwards along the chain of function calls until the exception is thrown out of a try block that has an appropriate catch block

​	If no such catch block is found, the exception will eventually be thrown out of the main function, causing the program to be terminated

## Rethrowing an Exception

It is possible for try blocks to be nested:

    void main()
    {
      try {
        doSomething();
      } catch (exception1) {
        // Exception handle code
      } catch (exception2) {
        // Exception handle code
      }
    }

With nested try blocks, it is sometimes necessary for the inner exception handler to pass an exception to an outer exception handler. Or both an inner and an outer catch block must perform operations when a particular exception is thrown.

​	These situations require that the inner catch block rethrow the exception so the outer block can catch it

A catch block can rethrow an exception with the `throw;` statement with no parameter

```c++
void doSomething() {
  try {
    // Code that can throw Exception 1 and 3
  } catch(exception1) {
    throw; // Rethrow the exception
  } catch(exception3) {
    // Code to handle exception 3
  }
}
```

When the first catch block catches `exception1`, the `throw;` statement simply throws the exception again. The catch block in the outer try/catch construct, will then handle the exception

# 16.2 Function Template

A function template is a “generic” function that can work with different data types. The grammar writes the specifications of the function but substitutes parameters for data types. When the compiler encounters a call to the function, it generates code to handle the specific data type(s) used in the call.

----------

With overloaded function, each of the functions must still be written individually

```c++
int square(int number) { return number*number; }
double square(double number) { return number * number; }
```

In situations like this, it is more convenient to write a function template than an overloaded function

​	Function templates allow a single function definition that works with many different data types

​	A function template is not an actual function, but a “mold” the compiler used to generate one or more functions

​	When writing a function template, do not have to specify actual types instead use a type parameter to specify a generic data type that the compiler uses to generate code of the appropriate type based on context


    template <class T> T square(number) {
      return number * number;
    }
1. `template` The beginning of a function template is marked by a template prefix, which begins with the keyword `template`

2. `<class T>` A set of angled brackets that contain one or more generic data types. A generic data type starts with the `class` keyword followed by the name of the data type. There are more, they would be separated by commas

3. `T square(T number)` The header defines `square` as a function that returns a type `T` and uses a parameter, `number`, that is also type `T`

  

**NOTE**

> All type parameters defined in a function template must appear at least once in the function parameter list.

The compiler must already know the template’s content before it encounters a call to the function template. Templates, therefore, should be placed near the top of the program or in a header file

**NOTE**

> A function template is only the specification of a function an by itself does not consume memory. An actual instance of the function is created in memory when the compiler encounters a call to the template function |

## The `swap` Function Template
```c++
template<class T> void swap(T &a, T&b) {
  T temp = a;
  a = b;
  b = temp;
}
```

The function is declared in the `algorithm` header file

## Using Operators in Function Templates

Templates will only work with types that support the operations used in the template.

```c++
template<class T> T square(T number) {
  return number * number;
}
```

The `square` template will work correctly as long as the type parameter supports the `*` operator

Templates will work with any user-defined class type that overloads the operators
Errors will result if the template is used with types not supported


## Function Templates with Multiple Types

More than one generic type may be used in a function template

**NOTE**

> Each type parameter declared in the template prefix must be used somewhere in the template definition.

## Overloading with Function Templates

Function templates may be overloaded. As with regular functions, function templates are overloaded by having different parameter lists

## Defining Template Functions
Beginning with C++11, you may use the keyword `typename` in place of `class` in the `template` prefix.

So the `template` prefix can be written as `template <typename T>`

# 16.3 Class Templates

Templates may also be used to create generic classes and abstract data types

----------

Class templates can be used whenever several classes are needed that only differ in the types of some of their data members or in the types of the parameters of their member functions

This calls template `SimpleVector` will store elements of type `T` in a dynamically generated array:

```c++
template <class T>
class SimpleVector {
  unique_ptr<T []> aptr;
  int arraySize;
public:
  SimpleVector(int);  // Constructor
  SimpleVector(const SimpleVector&);  // Copy constructor
  int size() const { return arraySize; }
  T &operator\[\](int);  // Overloaded [] operator
  void print() const;  // Output the array elements
};
```

Defining a `SimpleVector` object by using the convert constructor:

```c++
SimpleVector<double> dTable(10);
```

* This statement uses the convert constructor to create an array of 10 elements of type `double`

To define a member function outside the class:

```c++
template <class T>
T &SimpleVector<T>::operator\[\](int sub)
{
  if(sub < 0 || sub >= arraySize) {
    throw IndexOutOfRangeException(sub);
  return aptr[sub];
}
```

The list, and the angled brackets that enclose it, can be omitted whenever the name of the class is within the scope of the template class

# 16.4 Class Templates and Inheritance

Inheritance can be applied to class templates.

