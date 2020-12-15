# 15. Polymorphism and Virtual Functions

# 15.1 Type Compatibility in Inheritance Hierarchies

Objects of a derived class can be used whenever objects of a base class are expected.

----------
## Hierarchies of Inheritance

A derived class can itself serve as a base class for other classes, resulting in an inheritance hierarchy

## Type Compatibility in Inheritance

Because objects in an inheritance hierarchy are commonly accesses through pointers, these rules are in terms of pointers:

1. A derived class pointer can always be assigned to a base class pointer
    - A derived class object can be assigned to a base class pointer
    
    ```c++
    // Raw pointers
    Base *raw_bp1 = new Derived();
    // Smart pointers
    shared_ptr<Base> bp1 = make_shared<Derived>();
    ```
    
    
    
2. A type cast is required to perform the opposite assignment of a base class pointer to a derived class pointer

    - An error may result at run time if the base class pointer does not actually point to a derived class object

Assuming the **base pointers were previously pointing to derived class objects**, these assignments will leave `pd1` and `raw_pd1` pointing to derived class objects

```c++
// Raw pointers
Derived *raw_dp1 = static_cast<Derived*>(raw_bp1)
// Smart pointers
shared_ptr<Derived> dp1 = static_pointer_cast<Derived><bp1>;
```

Using those pointers to access derived class members:

```c++
cout << ptr->d << endl;
```

Assuming the **base pointer were previously pointing to a base class object**, these assignments compile, however, during runtime causes an error because `Base` class object does not have the member `d`

```c++
raw_pd = static_cast<Derived*>(raw_pb);
pd = static_pointer_cast<Derived>(pb);
```

These type compatibility rules apply to other cases:

- A function parameter that is declared as a pointer to a base class will accept a pointer to a derived class object
- A function that declares a return type of a pointer to class C may return a pointer to an object of derived class

## Type Casting of Base Class Pointers

In general, a pointer to a base class that actually points to a derived class object must be appropriate cast


```c++
shared_ptr<Person> pPerson = make_shared<Faculty>("Donald Knuth", Discipline::COMPUTER_SCIENCE);
```
- Even though the assignment is legal, the `pPerson` pointer is not aware of `Faculty` class members other than those inherited from `Person`

The type cast informs the compiler that `pPerson` is actually pointing to a `Faculty` object

```c++
static_pointer_cast<Faculty>(pPerson)->setDepartment(Discipline::BIOLOGY);
```

Alternatively, first cast `pPerson` to a pointer to `Faculty` stored in `pFaculty` and then use that to access `Faculty`-specific members:

```c++
shared_ptr<Faculty> pFaculty = static_pointer_cast<Faculty>(pPerson);
pFaculty->setDepartment(Discipline::BIOLOGY);
```


When a pointer to a base class is being used to access a member function that has been overridden by the derived class, the default C++ behavior is to use the version of the function that is defined in the class of the pointer

```c++
shared_ptr<Person> pP = make_shared<TFaculty>("Indiana Jones", Discipline::ARCHEOLOGY, "Dr.");
cout << pP->getName();
```
- The compiler is not aware that the actual class type of the object is `TFaculty`. The compiler sees the class type of the pointer and assumes that the class type is the same as the pointer. Therefore, calls the version of `getName()` defined in the `Person` class.



# 15.2 Polymorphism and Virtual Member Functions

Virtual functions allow the most specific version of a member function in an inheritance hierarchy to be selected for execution. Virtual functions make polymorphism possible.

----------

A piece of code is polymorphic if executing the code with different types of data produces different behavior

When a base class pointer is pointing to a derived class object, the default C++ behavior is to use the class type of the pointer rather than that of the object to determine which version of an overridden function to call.

To have the compiler select the more specialized version of a function in the derived class, declare the function to be a virtual function in the base class

- Virtual functions are used in C++ to support polymorphic behavior

```c++
class B {
public:
  virtual void mfun() {
    cout << "Base class version";
  }
};
```

The virtual characteristic is inherited:

​	If a member function of a derived class overrides a virtual function in the base class, then that member function is automatically virtual itself

​	Although it is not necessary, can tag all virtual functions with the keyword `virtual` to make it easier to identify

## Dynamic and Static Binding

The compiler binds the name to a function definition when the function is called

**Static binding** happens at compile time and binds the name to a fixed function definition, which is then executed each time the name is invoked

​		The compiler uses type information available at compile time

​		If the code is operating on objects of different classes within an inheritance hierarchy, the only type information available to the compiler will be the base class pointer type used to access all the objects

​		Static binding will always use the base class version of member functions

**Dynamic binding** occurs at run time. Only works if the compiler can determine at run time the exact class that a subclass object belongs to.

​		The compiler uses run-time type information to call the version of the function defined in its class

​		To make dynamic binding possible, the compiler stores run-time type information in every object of a class with a virtual function

​		Dynamic binding always uses the version of the member function in the actual class of the object, regardless of the class of the pointer used to access the object


## C++11’s `override` and `final` Keywords

C++11 introduces the `override` keyword to help prevent subtle errors when overriding virtual functions

To make sure that a member function in a derived class overrides a virtual member function in a base class, place the `override` keyword just after the derived class’s function prototype or header:

```c++
virtual void functionA(int arg) const override {
  cout << "This is Derived::functionA" << endl;
}
```

The `override` keyword tells the compiler that the function is supposed to override a function in the base class.

- It will cause a compile error if the function does not actually override any fuctions

## Preventing a Member Function from Being Overridden

In a derived class, when a virtual member function is declared with the `final` keyword, it cannot be overridden further down in the hierarchy

```c++
virtual void message() const final;
```

If a derived class attempts to override a `final` member function, the compiler outputs an error

# 15.3 Abstract Base Classes and Pure Virtual Functions

Abstract classes and pure virtual functions can be used to define an interface that must be implemented by derived classes.

----------

C++ permits the declaration of **pure virtual functions**, a member function for which the class provides no implementation

To declare a pure virtual function, set it equal to zero `= 0` instead of the class body:

```c++
void draw() = 0;
```

A pure virtual function is sometimes called an **abstract function**, and a class with at least one pure virtual function is called an **abstract class**.

The C++ compiler will not allow you to instantiate an abstract class

​		Abstract classes can only be bases classes derived from

A class derived from an abstract class inherits all functions in the base class and will itself be an abstract class unless it overrides all the abstract functions it inherits

​		Abstract classes define an interface that will have to be supported by all derived classes

# 15.4 Composition versus Inheritance

Inheritance should model an “is-a” relation, rather than a “has-a” relation, between the derived and base classes

----------

**Class inheritance** in an object-oriented language should be viewed as: the derived class is a special case of the base class

​		A class can be considered to be the *set* of all objects that can be created from it

​		Because the derived class is a special case of the base class, the set of objects that correspond to the derived class will be a *subset* of the of the set of objects that correspond to the base class

​		Each derived class object *is a* base class object

**Class composition** occurs whenever a class contains an object of another class as one of its member variables

​		Because a derived class inherits all the members of its base class, a derived class effectively contains an object of its base class

​		Good design practice to prefer composition to inheritance whenever possible

​			One reason is that inheritance breaks the encapsulation of the base class by exposing its protected members to the members of the derived class

The **uses implementation of** relation occurs when one class calls a member function of an object of the second class

