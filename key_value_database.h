#ifndef KEY_VALUE_DATABASE_H
#define KEY_VALUE_DATABASE_H

#include <unordered_map>
#include <string>
#include <stdexcept>

class KeyValueDatabase {
private:
    std::unordered_map<std::string, int> data;
    std::unordered_map<std::string, int> transactionData;
    bool inTransaction;

public:
    KeyValueDatabase();

    void begin_transaction();
    void put(const std::string& key, int value);
    int get(const std::string& key);
    void commit();
    void rollback();
};

#endif // KEY_VALUE_DATABASE_H
