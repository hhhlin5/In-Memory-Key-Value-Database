# In-Memory-Key-Value-Database

## Overview
Transactions are an important part of relational databases. Transactions allow “all or nothing” updates to databases to prevent dirty writes. This is especially important while dealing with things like money. In this assignment I will build an in-memory database with transaction support. 

## Instructions
Build an in-memory key-value database that supports the following functions:
1. **begin_transaction()** starts a new transaction.
2. **put(key, value)** will create a new key with the provided value if a key doesn’t exist. Otherwise it will update the value of an existing key. If put(key, val) is called when a transaction is not in progress throw an exception.
3. **get(key)** will return the value associated with the key or null if the key doesn’t exist. It can be called anytime even when a transaction is not in progress.
4. **commit()** applies changes made within the transaction to the main state. Allowing any future gets() to “see” the changes made within the transaction
5. **rollback()** should abort all the changes made within the transaction and everything should go back to the way it was before.
6. Within a transaction you can make as many changes to as many keys as you like. However, they should not be “visible” to get(), until the transaction is committed.
7. At a time only a single transaction may exist. A transaction ends when either commit() or rollback() is called.

## Running the Code

To run the code, you will need a C++ compiler installed on your system. Follow these steps:

1. Clone the repository to your local machine.
2. Navigate to the directory containing the source files (`main.cpp` and `key_value_database.h`).
3. Compile the code using a C++ compiler. For example, if using g++, run the following command:
   `g++ -o key_value_database main.cpp key_value_database.cpp`
5. Execute the compiled binary to run the program:
   `./key_value_database`


## Assignment Modification for Official Use

To modify this assignment for official use, consider the following changes:

1. **Clarifications to Instructions**: Provide more detailed explanations for each function and operation in the assignment description. This will help students understand the requirements more clearly.
2. **Additional Methods**: Introduce additional methods or functionalities to expand the scope of the assignment. For example, you could add a method to delete keys from the database or implement a feature to support nested transactions.
3. **Grading Criteria**: Define specific grading criteria for each aspect of the assignment, including correctness, efficiency, code quality, and adherence to best practices. This will ensure consistency in grading and provide students with clear expectations.
4. **Feedback Mechanism**: Implement a feedback mechanism where students can submit their solutions for evaluation and receive feedback from instructors or peers. This will promote learning and improvement by providing constructive criticism and guidance.
5. **Integration with Learning Resources**: Integrate the assignment with relevant learning resources, such as readings, lectures, or online tutorials, to reinforce key concepts and provide additional context for students.

By incorporating these modifications, the assignment can be enhanced to provide a more comprehensive learning experience for students and better prepare them for real-world programming challenges.


## Resources
https://www.dbvis.com/thetable/database-transactions-101-the-essential-guide/

https://medium.com/@mithoonkumar/design-an-in-memory-nosql-database-ood-428d48b68dfa

https://www.geeksforgeeks.org/java-util-hashmap-in-java-with-examples/

https://www.geeksforgeeks.org/python-dictionary/ 
