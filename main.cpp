#include <iostream>
#include "key_value_database.h"

int main() {
    KeyValueDatabase db;

    // should return null, because key 1 doesn’t exist in the DB yet
    std::cout << "Value of key 1: " << db.get("A") << std::endl;

    try {
        // should throw an error because a transaction is not in progress
        db.put("A", 5);
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Start a transaction
    db.begin_transaction();
    db.put("key1", 10);
    db.put("key2", 20);

    // Display values before committing
    std::cout << "Before commit - key1: " << db.get("key1") << std::endl;  // Output: 10
    std::cout << "Before commit - key2: " << db.get("key2") << std::endl;  // Output: 20

    // Commit the transaction
    db.commit();

    // Display values after committing
    std::cout << "After commit - key1: " << db.get("key1") << std::endl;  // Output: 10
    std::cout << "After commit - key2: " << db.get("key2") << std::endl;  // Output: 20

    // Start a new transaction
    db.begin_transaction();
    db.put("key1", 30);

    // Display value within the transaction
    std::cout << "Within transaction - key1: " << db.get("key1") << std::endl;  // Output: 30

    // Rollback the transaction
    db.rollback();

    // Display value after rollback
    std::cout << "After rollback - key1: " << db.get("key1") << std::endl;  // Output: 10

    return 0;
}
