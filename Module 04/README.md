# Module 4: Memory Allocation, "Smart" Pointers, Time

## Homework

#### Programming Project #1 - The Display Box (20 points)

After taking a course in geology, you  become a rock hound and start collecting samples of rocks, minerals,  and gemstones for display. (A mineral is a stone that has been  transformed into a crystalline structure such as quartz, talc, and  calcite. A gemstone is a precious or semiprecious stone or rock, especially one cut, polished, and used in a piece of jewelry.)

After buying a display box with 10 empty  slots, you decide to put your 10 best stones (lettered A, B, C, ... J)  by selecting a slot randomly for each stone until finding an empty  slot. For each stone, record the number of attempts it took to find an  empty slot for that stone.

Step 1: Include the **iostream**, **iomanip**, **memory**, and **ctime** libraries.

Step 2: Create a structure named **Stone** which will hold two variables:

1. the letter of the stone occupying a slot in the display box (A - J)
2. the number of attempts it took to find an available slot for this stone

The **Stone** structure also should have a constructor which sets the initial values for each of the variables above.

Step 3: In **main**, set the seed of the C++ random number generator to create a different  set of numbers each time your program is run. (Code blocks circled in red cannot be cut-and-pasted.)

```c++
srand(time(NULL));
```

Step 4: Create an array of 10 unique pointers to **Stone** objects:

```c++
  unique_ptr<Stone> slots[10]];
```

By using unique pointers, we guarantee that each stone object will be referenced by one and only one slot in the display box.

Step 5: Create a **for** loop which processes a single stone (lettered A, B, C... through J).

Step 6: For that stone, use an inner loop:

Step 6a:  Generate a random number between 0 and 9. Make sure that you track the number of attempts it takes to find an open slot in the display box.

Note: To test if a slot is available, say **slot[index]**, use:

```c++
 if(!slot[index]))...  
```

Step 6b: If the slot at that index is not available, continue the inner loop and try another random number, increasing the number of attempts by 1.

Step 6c: If the slot is available, then create a new **Stone** object for this stone's letter and the number of attempts it took to find an available slot for this stone.

```c++
unique_ptr new_stone(new Stone(stone_letter, attempts));
slots[index] = move(new_stone);
```

Notice the use of the **move** function, instead of using an assignment statement, (Why?)

Exit the inner which loop generates  random numbers, and start the next iteration of the outer loop looking  for a slot for the next stone.

Step 7: When all 10 stones have been placed into a slot in the display, print a report showing:

- The slot number (0 - 9)
- The stone's letter assigned to that slot (**slots[i]->stone_number**)
- The number of attempts it took to find an available slot for that stone (**slots[i]->attempts**)
- A grand total of the number of attempts

Notice that stone **A** (the first stone) should take only one attempt, since all ten slots are available when placing that stone. For stone **B**, the number of attempts should also be very low, since 9 of the 10 slots are still available.

However, as the stone letters get higher, so should the number of attempts. For example when trying to place the last stone (with letter **J**), 9 of the 10 slots are already filled, so it may take several attempts to find the only open slot.

Your report might look like the following (the numbers will be different).

```
  Slot  Stone  Attempts  
  ----  -----  --------
     0     G      4
     1     A      1
     2     H      4
     3     I      9
     4     B      1
     5     E      3
     6     F      1
     7     J      7
     8     C      2
     9     D      1

  Total Attempts:  33
```

Run your program at least twice. Submit your program along with print screens or snips showing the results of both runs.

#### Extra Credit (5 points)

Sort the array of pointers used in the above solution by stone's letter. (Do not create any additional pointers.)

You may have to add a new variable to the **Stone** structure for the *original slot* the stone was in, since the index into the **slots** array will no longer correspond to the slot in the display box in which the stone was initially placed.

Print the report again showing the  results sorted by stone letter. For example, the report using the same  results as the above might look like:

```
  Stone  Slot  Attempts  
  -----  ----  --------
    A      1      1
    B      4      1
    C      8      2
    D      9      1
    E      5      3
    F      6      1
    G      0      4
    H      2      4
    I      3      9
    J      7      7

  Total Attempts:  33
```



## Lab

#### Project Detail

1. At the top of the program, include the **ctime** library.
2. In **main**, create string arrays for:

- weeks of the day (Sunday=0, Monday=1, Tuesday=2...)
- months of the year (January=0, February=1, March=2...)

3. Create a **time_t** variable and set to the current time (don't forget to include **ctime** at the top of your program). (Code blocks circled in **red** cannot be cut-and-pasted.)

```
  time_ttnoww==time(NULL));; 
```

4. Establish a **tm** structure and reference with a pointer. Assign to the current time:

```
  tmm*locall==localtime(&now));; 
```

5. Using the values in the structure, print today's date using the following formats:

```
  1/1/20 (m/d/yy)
  January 1, 2020  
    1-Jan-2020
```

6. Print the current time in the following format. (Make sure that if  the number of minutes is less than 10, than you provide a leading zero,  such as 5:05pm.)

```
  17:30
  5:30pm / 12:00am  
```

7. Create a **tm** structure for your birthday and time, assigning all variables appropriately:

```c++
tm birthday;

birthday.tm_year = ??? - 1900;
birthday.tm_mon = ??;
birhtday.tm_mday = ??;
birthday.tm_hour = ??;
birthday.tm_min = ??;
birthday.tm_sec = ??;
birthday.tm_isdst = ??;
```

8. Determine how many seconds after epoch you were born, then use the **ctime** function to print the date and time, and finally determine how old you  are in seconds. (You can use any other big moment in your life, such as  receiving your high school diploma, proposing to your significant other, driving your first car, opening your first paycheck, or a important  moment in history.)

```c++
time_t time_of_birthday = mktime(&birthday);
cout << ctime(&time_of_birthday) << endl
     << "I was born " << time_of_birthday
     << " seconds after epoch!" << endl;
```

9. Determine the number of seconds that occur in one week. (Multiply  the number of days in a week by the number of hours in a day, by the  number of minutes in an hour, by the number of seconds in a minute). *Use the computer to calculate this number, don't do the math yourself.*

10. Subtract the number of seconds in a week from the **time_t** variable created just above.

11. Print the date and time occurring exactly one week before the big moment in your life using the **ctime** function.