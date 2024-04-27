#include "key_value_database.h"

KeyValueDatabase::KeyValueDatabase() : inTransaction(false) {}

void KeyValueDatabase::begin_transaction() {
    if (inTransaction) {
        throw std::runtime_error("Transaction already in progress");
    }
    transactionData.clear();
    inTransaction = true;
}

void KeyValueDatabase::put(const std::string& key, int value) {
    if (!inTransaction) {
        throw std::runtime_error("No transaction in progress");
    }
    transactionData[key] = value;
}

int KeyValueDatabase::get(const std::string& key) {
    if (inTransaction && transactionData.find(key) != transactionData.end()) {
        return transactionData[key];
    }
    return data[key];
}

void KeyValueDatabase::commit() {
    if (!inTransaction) {
        throw std::runtime_error("No transaction in progress");
    }
    data.insert(transactionData.begin(), transactionData.end());
    transactionData.clear();
    inTransaction = false;
}

void KeyValueDatabase::rollback() {
    if (!inTransaction) {
        throw std::runtime_error("No transaction in progress");
    }
    transactionData.clear();
    inTransaction = false;
}



