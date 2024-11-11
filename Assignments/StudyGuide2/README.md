1. Like private members, protected members are inaccessible outside of the class. However, they can be accessed by derived classes and friend classes/functions.? - True. 
2. Write a single C++ statement that dynamically allocates a single int and initializes it to 99. - int*ptr = new int(99);
3. Which of the following functions demonstrates function overloading in the code snippet? - Same name but different parameter list 
4. Which of the following functions demonstrates function overriding in the code snippet? - a derived class defines a method with the same name 
5. Class Wizard is _______________ the print method in Character
6. The Print method is _______________ in class Character
7. How can we make a class abstract? - Add a virtual function
8. Which of the following is true about the friend keyword in C++? - It allows a non-member function access private and protected data members
9. Which of the following is a potential drawback of using the friend keyword? - Breaks encapsulation 
10. Which of the following statement is correct with respect to the use of friend keyword inside a class? - A friend function or class can access the private and protected data members 
11. Which of the following keywords is used to control access to a class member? - Private, protected, public 
12. Like private members, protected members are inaccessible outside of the class. However, they can be accessed by? - getters and setters, derived classes and friends classes/functions 
13. What is the purpose of an abstract class in C++? - To create a base class with a basic function and makes derived classes implement their specific methods 
14. Given a class Widget, which of the following choices could access  private data members or private member functions of Widget. - f
15. Which of the following type of data member can be shared by all instances of its class? - static data members 
16. An object is a(n) fillin of a class that resides in fillin and has fillin. - instance, memory, state
17. A constructor is executed when _______________? - An object of the class is created 
18. How many objects can be created from an abstract class? - as many as you want 
19. What does the class definitions in the following code represent?
20. Which of the following can be overloaded?
21. Which of the following means "The use of an object of one class in the definition of another class"? - Composition 
22. Which of the following is the only technical difference between structures and classes in C++? - Structures is always public and classes can hide their data  
23. Which of the following concepts means "determine at runtime" what method to invoke? - Runtime polymorphism (virtual functions)
24. In the code snippet below, we have an example of:
25. In the snippet below, if I wanted to make Character an abstract class, I would have to: Add at least one pure virtual function 
26. Which of the following can be an object: an instance of a class
27. A class that has all of its methods implemented, and can be instantiated is know as a(n): Concrete Class 
28. What is the one thing that is necessary for run time polymorphism? - a virtual function 
29. Runtime Polymorphism requires? - a base class pointer or reference and virtual functions
30. We typically choose Inheritance over Composition? we typically choose composition over inheritance
31. When a derived class inherits from more than one base-class directly, we call this?
32. The concept of determining which methods to invoke while a program is executing is known as: Runtime Polymorphism (or Dynamic Binding).
33. The concept of determining which methods to invoke before a program is executing is known as: Compile-time polymorphism or static binding 
34. Write a single C++ statement that dynamically allocates a single int and initializes it to 7. int* ptr = new int(7)
35. Rewrite the snippet below so that the Kid can access his dad private stash of alcohol. The alcohol attribute must stay private.
36. Finish the Character class so that the print method in Character must be implemented in both sub-classes.
37. Add necessary code to snippet below, to ensure it works without error. You cannot change any code, you must add additional code. Simplest answer gets the most points.
61. When a derived class inherits from more than one superclass directly, we call it?
62. Rewrite the snippet below so that the Kid can access his dad private stash of alcohol. The alcohol attribute must stay private.
63. Rewrite the necessary component of the code snippet below, so that the print method in Character must be implemented in both sub-classes.
64. Like private members, protected members are inaccessible outside of the class. However, they can be accessed by derived classes and friend classes/functions.?
80. Which of the following concepts means "determine at runtime" what method to invoke?
81. In the code snippet below, we have an example of:
82. In the snippet below, if I wanted to make Character an abstract class, I would have to:
83. An interface is a C++ class that:
84. Which of the following is a mechanism of static polymorphism?
85. Rewrite the snippet above so that the Kid can access his dad private stash of alcohol.
86. Rewrite the code snippet from question 17, so that it can properly use run time polymorphism.
87. Like private members, protected members are inaccessible outside of the class. However, they can be accessed by derived classes and friend classes/functions.? True 
88. Which of these is a base class: Vehicle or Minivan? vehicle 
89. Like private members, protected members are inaccessible outside of the class. However, they can be accessed by:
90. The concept portrayed in the previous snippet is known as 
91. What is the output of the previous code snippet?
92. Depending on your previous answer, is there anything you could do to either make it work (if you thought it was broken) or make it print the "other" output without altering main? question Encapsulation v Abstraction: Use the answer sheet to answer. label each question with an A for abstraction or E for encapsulation.
93. Hides certain methods from users of the class by protecting them or making them private.
94. Hides whether an array or linked list is used.
95. Solves problem at implementation level.
96. Wraps code and data together.
97. Is focused mainly on what should be done.
98. Is focused on how it should be done.
99. Helps developers to design projects more easily.
100. Lets a developer use a class without worrying about how it's implemented.
101. Solves problem at design level.
102. Hides the irrelevant details found in the code.
103. A Hides certain methods from users of the class by protecting them or making them private.
104. E Hides whether an array or linked list is used.
105. E Solves problem at implementation level.
106. E Wraps code and data together.
107. A Is focused mainly on what should be done.
108. E Is focused on how it should be done.
109. A Helps developers to design projects more easily.
110. A Lets a developer use a class without worrying about how it's implemented.
111. A Solves problem at design level.
112. E Hides the irrelevant details found in the code. question Definitions: Use the answer sheet to answer. Read the definitions following the list of words below, and choose the proper word for the definition. Place the number for the word to the corresponding letter on the answer sheet. Warning: at least 2 of the statements below have NO answer. They sound correct, but are not. On the answer sheet simply write: ?? (two question marks)
113. This is also known as a function, it just resides within a class.
114. This can be called even if no objects of the class exist.
115. There is only one copy of this which is shared by all objects of the class,
116. This is what you get when you have at least one pure virtual member function defined.
117. This can be done in a class or outside of a class. It happens when you share the same name, but not the same parameter list.
118. This happens when you share the same name, but are in different classes. solutionline[maroon]{??} {Overriding needs more}
119. You define arithmetic operators for your own class. This is an example of: _______________.
120. You have a simple problem where you need to give elevated access to a class, but inheritance is not that answer. So you label this class as _______________
121. This is a term not necessarily from C++, but definitely exists in other OOP languages. Where C++'s version would require a single pure virtual function, other languages assume no data and no implementation at all.
122. This is basically a contract agreeing that at some point, you may redefine some method in a child class.
123. This thing resides in memory and has its own state.
124. The level of access known as _______________ can only be circumvented by another entity by giving that entity the Friend label.
125. What type of inheritance are you seeing in the graphic below?
126. An instance variable is the exact same thing as a _______________ variable unless they are in an abstract base class. solutionline[maroon]{??}{Bad Question}
127. In a somewhat oversimplified view of OOP, _______________ deals with hiding things and _______________ deals with exposing things. solutionline[def]{23,17}{Encapsulation, Abstraction}
128. An abstract method is just a regular method in many instances. When we set an abstract method equal to zero we turn it into a _______________
129. By defining a base abstract method as pure public, you are guaranteeing that any _______________ access level will not cause problems in a derived class. solutionline[maroon]{??}{No Answer}
130. Short Answer. Write a simple example in Python (using class names like A, B, and C) showing:
131. Given the code in snippet 2, write a class called Customer that can access both the account_number AND the account_balance if possible. If not explain why and make any fixes necessary to Account.
132. Short Answer. Explain and write an example in C++ describing the diamond problem and how to fix and/or avoid it.



## Major Topics
### Overloading
### Overriding 
### Composition/inheritance 
### Virtual / Pure virtual 
### Access specifiers 
#### Public remain public when derived/inheritance, Protected stays protected in the derived class, private stays private no matter what. 
