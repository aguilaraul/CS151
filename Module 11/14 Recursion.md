# 14. Recursion

# 14.1 Introduction to Recursion

A recursive function is one that calls itself

----------

To be useful, a recursive function must have a way of controlling the number of recursive calls

    - The recursive calls stop when it reaches a base case

Recursive functions work by breaking a complex problem down into subproblems of the same type

The more times a function is called, the more the depth of recursion increases

Consider the use of recursion when there is a way to express the solution of a problem in terms of solutions of simpler, or smaller, problems of the same type

## Direct and Indirect Recursion

Direct recursion are recursive functions that directly call themselves

Indirect recursion occurs when function A calls function B, which then calls function A

# 14.2 Recursive Factorial Function

In mathematics, the notation `n!` represents the factorial of the number:

    6! = 1 * 2 * 3 * 4 * 5 * 6

Recursive factorial function:

    int factorial(int num) {
      if(num == 0) {
        return 1;
      } else {
        return num * factorial(num-1);
    }
# 14.3 Recursive gcd Function

Calculate the greatest common divisor, or gcd, of two numbers

Using Euclid’s algorithm, the gcd of two positive integers, x and y, is:

    // if y divides x with no remainder
    gcd(x, y) = y
    // otherwise, gcd is gcd(y, x%y);
    gcd(y, x%y) = gcd

Recursive gcd function:

    int gcd(int x, int y) {
      if(x%y == 0) {
        return y;
      } else {
        return gcd(y, x%y);
      }
    }
# 14.4 Solving Recursively Defined Problems

Fibonacci sequence:

    int fib(int n) {
      if(n <= 0) {
        return 0;
      } else if (n == 1) {
        return 1;
      } else {
        return fib(n-1) + fib(n-2);
      }
    }
# 14.5 Binary Search Function
    int binarySearch(const int array[], int first, int last, int value)
    {
      int middle;
      if(first > last) {
        return -1;
      }
      middle = (first+last)/2;
      if(array[middle] == value) {
        return middle;
      }
      if(array[middle] < value) {
        return binarySearch(array, middle+1, last, value);
      } else {
        return binarySearch(array, first, middle-1, value);
      }
    }
# 14.6 QuickSort Algorithm
    void quickSort(int arr[], int start, int end) {
      if(start < end) {
        // Partition the array and get the pivot point
        int p = partition(arr, start, end);
        
        // Sort the portion before the pivot point
        quickSort(arr, start, p-1);
    
        // Sort the portion after the pivot point
        quickSort(arr, p+1, end);
      }
    }
    
    int partition(int arr[], int start, int end) {
      // The pivot element is taken to be the element at
      // the start of the subrange to be partitiond
      int pivotValue = arr[start];
      int pivotPosition = start;
    
      // Rearrange the rest of the array elements to
      // partition the subrange from start to end
      for(int pos = start+1; pos <= end; pos++) {
        if(arr[pos] < pivotValue) {
          // arr[scan] is the 'current' item
          // Swap the current item with the item to the
          // right of the pivot element
          swap(arr[pivotPosition+1], arr[pos]);
          // Swap the current item with the pivot element
          swap(arr[pivotPosition], arr[pivotPosition+1]);
          // Adjust the pivot position so it stays with the
          // pivot element
          pivotPosition++;
        }
      }
      return pivotPosition;
    }
# 14.7 The Towers of Hanoi
# 14.8 Exhaustive and Enumeration Algorithms

An enumeration algorithm is one that generates all possible combinations of items

An exhaustive algorithm is one that searches through such a set of combinations to find the best

# 14.9 Recursion versus Iteration

Recursion and iteration are equivalent in expressive power.

----------

In general, programs that use recursion incur more overhead than equivalent programs that use iteration

    - This is because recursion involves making multiple function calls that add to the stack

There are some recursive algorithms (like the Fibonacci sequence) that in the course of solving a problem recompute solutions to the same subproblems over and over again

    - Such algorithms are inefficient over iteration

In general, recursion should be used whenever the problem has a natural recursive solution that does not unnecessarily recompute solutions to subproblems

