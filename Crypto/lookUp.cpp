#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

// A simple HashTable class
class HashTable {
private:
    // The size of the hash table
    static const int tableSize = 10;

    // Array of lists to handle collisions (chaining method)
    vector<list<pair<string, int>>> table;

    // Simple hash function to map strings to table indices
    int hashFunction(const string& key) {
        int hashValue = 0;
        for (char ch : key) {
            hashValue += ch;
        }
        return hashValue % tableSize;
    }

public:
    // Constructor to initialize the hash table with empty lists
    HashTable() : table(tableSize) {}

    // Function to insert a key-value pair into the hash table
    void insert(const string& key, int value) {
        int index = hashFunction(key);
        table[index].push_back({key, value});
    }

    // Function to retrieve a value based on a key
    int get(const string& key) {
        int index = hashFunction(key);

        // Search the list at this index for the key
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                return pair.second; // Return the value if the key matches
            }
        }

        // If the key is not found
        cout << "Key not found!" << endl;
        return -1; // Indicate that the key is not found
    }

    // Function to display the contents of the hash table
    void display() {
        for (int i = 0; i < tableSize; i++) {
            cout << "Index " << i << ": ";
            for (const auto& pair : table[i]) {
                cout << "[" << pair.first << ": " << pair.second << "] -> ";
            }
            cout << "NULL" << endl;
        }
    }
};

// Main function to demonstrate the hash table
int main() {
    // Create a hash table
    HashTable hashTable;

    // Insert some key-value pairs
    hashTable.insert("apple", 100);
    hashTable.insert("banana", 200);
    hashTable.insert("grape", 300);
    hashTable.insert("pear", 400);
    hashTable.insert("rpea", 4000);
    hashTable.insert("Orange", 500);
    hashTable.insert("orange", 600);

    // Display the contents of the hash table
    cout << "Hash Table Contents:" << endl;
    hashTable.display();
    cout << endl;

    // Retrieve some values based on keys
    cout << "Value for 'apple': " << hashTable.get("apple") << endl;
    cout << "Value for 'banana': " << hashTable.get("banana") << endl;
    cout << "Value for 'grape': " << hashTable.get("grape") << endl;
    cout << "Value for 'pear': " << hashTable.get("pear") << endl;
    cout << "Value for 'rpea': " << hashTable.get("rpea") << endl;
    cout << "Value for 'orange': " << hashTable.get("orange") << endl; // Non-existent key

    return 0;
}
