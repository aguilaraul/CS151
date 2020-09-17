# CS151
MCC CS 151

## Module 1 - Course Introduction

## Module 2 - Number systems, algorithms, pointers

## Module 3 - Pointers, dynamic memory allocation

### Programming Challenge 1
Write a program that dynamically allocates an array large enough to hold a
user-defined number of test scores. Once all of the scores are entered, the
array should be passed to a function that sorts them in ascending order.
Another function should be called that calculates the average score. The
program should then display the sorted list of scores and the average with
appropriate headings. 

_Use pointer notation rather than array notation whenever possible._

When finished with the array, use the delete operator to de-allocate the array.

__Input Validation: Do not accept negative test scores.__ Demonstrate this
validation in your sample output.

### Programming Challenge 2
Modify the program above to allow the user to enter name-score pairs (use a
class). For each student taking the test, the user should enter a string
representing name of the student, followed by an integer representing the
student's score. Modify both the sorting and average-calculating functions so
they take arrays of _objects_, with each object containing the name and score
of a single student.

_In traversing the arrays, use pointers rather than array indices._

When finished with the array, use the __delete__ operator to de-allocate the array.

Include a class definition for a student, including a constructor, getters and
setters for the name and score, and a destructor.

### Programming Challenge 3
In statistics, the _mode_ of a set of values is the value that occurs most
often. Write a program that determines how many pieces of pie most people eat
in a year. Set up a dynamically-allocated integer array that can hold responses
from 30 people. For each person, enter the number of pieces they say they eat
in a year. Then write a function that finds the mode of those 30 values (this
will be the number of pie slices eaten by the most people). The function that
finds and returns the mode should accept two arguments, an array of integers,
and a value indicating how many elements are in the array.

## Module 4 - Memory allocation, "smart" pointers, Time

### Lab - Using Time
In this lab you will manipulate a time variable and corresponding structure,
print today's date and time in various formats, and determine how to adjust the
internal form of other dates.