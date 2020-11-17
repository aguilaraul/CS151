# Module 1: Course Introduction

## Project 1 - Use a vector to sort numbers (10 points)

The purpose of this project is to generate thirty random whole numbers between 1 and 10, insert them into a vector in *descending* order, then and print the numbers in *ascendin*g order:

Use the following plan of attack:

1. Create an empty vector of **int** elements.
2. Use the **srand** function to change the "seed" for generating random numbers so that the **rand** function will generate a *different* set of random numbers every time your program is run.
3. Use the **rand** function to generate a random number whole number between 0 and **RAND_MAX** (using Dev-C++, **RAND_MAX** is 32,767).
4. Convert this number into a number between 1 and 10.
   - *hint:* use the **%** operator.
5. Use a loop to **scan** the vector until you find the position of an element containing a  number that is less than the random number just generated above.
6. Use an iterator to *insert* the random number into the vector at that position.
7. Go back to step 3 and perform again until the vector contains 30 random numbers
8. After all 30 numbers have been generated and inserted into the vector, they should appear in *descending* order in the vector.
9. Use the **pop_back** function in a loop to print the numbers in *ascending* order on the console until the vector is empty.

## Project 2 - Use a vector to sort countries by area (15 points)

Below is a list of the 14 countries in South America, including their population and area:

|       Name       | Population (in 1,000's) | Area (sq. miles) |
| :--------------: | :---------------------: | :--------------: |
|    Argentina     |         45,258          |    1,073,234     |
|     Bolivia      |         11,696          |     424,052      |
|      Brazil      |         212,845         |    3,287,086     |
|      Chile       |         19,206          |     291,855      |
|     Columbia     |         51,115          |     440,715      |
|     Ecuador      |         17,705          |     106,851      |
| Falkland Islands |            3            |      4,700       |
|  French Guiana   |           290           |      32,253      |
|      Guyana      |           787           |      82,978      |
|     Paraguay     |          7,145          |     157,056      |
|       Peru       |         33,108          |     496,093      |
|     Suriname     |           586           |      63,252      |
|     Uruguay      |          3,475          |      68,037      |
|    Venezuela     |         28,102          |     353,748      |

 

Create a class called **Country**.

- The properties (variables) of each country will be its name, population, and area.
- Put the definitions of those properties and prototypes of functions in a header file with a guard.
- Put the function definitions in a .cpp file.
  - Functions should include a constructor and "getters" for each property of the class.

Then, similar to what you did in project 1:

1. Create an empty vector of **Country** elements (make this a global variable).
2. In main, in alphabetic order, create a **Country** object for each of the countries in South America.
   - as each is created insert it into the vector in *ascending* order based on the country's area.
   - consider writing a function which takes a **Country** object and inserts it into the vector in the appropriate spot in the vector.
3. Once the vector is filled, print a report showing each country.
   - At the top of the report, put headings at the top of each column.
   - Do *not* use **pop_back**.  Instead, simply use a loop to access and print the values of each country in the vector, starting with element #0.
4. Inside the loop, use the **cout** object to align columns:
   - The name of the country should be left-aligned (padded to the right)
   - The population and area should be right-aligned (padded to the left)
5. The first part of your report might look like the following:

```
       Country      Population     Area
  ----------------  ----------  ----------  
  Falkland Islands           3        4700
  French Guiana            290       32253
  Suriname                 586       63252
  Uruguay                 3475       68037
  Guyana                   787       82978
  Ecuador                17705      106851
               . . . . . . . .
```

6. After all countries have been printed, show totals for the population and area columns.