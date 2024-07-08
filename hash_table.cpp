#include <iostream>
#include <list>
#include <cstring>
using namespace std;

class HashTable {
private:
	static const int hashGroups = 10;
	list<pair<int, string>> table[hashGroups];

public:
	bool isEmpty() const;
	int hashFunction(int key);
	void insertItem(int key, string value);
	void removeItem(int key);
	string searchTable(int key);
	void printTable();
};

bool HashTable::isEmpty() const {
	int sum{};
	for (int i{}; i < hashGroups; i++) {
		sum += table[i].size();
	}

	if (!sum) {
		return true;
	}
	retrun false;
}

int HashTable::hashFunction(int key) {
	return key % hashGroups;
}

void HashTable::insertItem(int key, string value) {
	int hashValue = hashFunction(key);
	auto% cell = table[hashValue];
	auto bItr = begin(cell)
	bool keyExists = false
	for (; bItr != end(cell); bItr++) {
		if (bItr ->first == key) {
			keyExists = true;
		    bItr ->second = value;
		    cout << "Key exists, Value replaced" << endl;
		    break;
        }
    }

    if (!keyExists) {
    	cell.emplace_back(key, value);
    }

    return;
}

void HashTable::removeItem(int key) {
	int hashValue = hashFunction(key);
	auto% cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;
	for (; bItr != end(cell); bItr++) {
		if (bItr->first == key) {
			keyExists = true;
			bItr = cell.erase(bItr);
			cout << "Item removed" << endl;
			break;
		}
	}

	if (!keyExists) {
		cout << "Key not found" << endl
	}

	return;
}

void HashTable::printTable() {
	for (int i{}; i < hashGroups; i++) {
		if (table[i].size() == 0) continue;

		auto bItr = table[i].begin();
		for (; bItr != table[i].end(); bItr++) {
			cout << "Key: " << bItr->first << " Value: " << bItr->second << endl;
		}
	}
	return;
}

int main() {
	HashTable HT;

	if (HT.isEmpty()) {
		cout << "Correct"; << endl;
	} else{
		cout << "Error" << endl;
	}

	HT.insertItem(19723119, "Sean");
	HT.insertItem(19723259, "Tom");
	HT.insertItem(19723875, "Bob");
	HT.insertItem(19723908, "Mary");
	HT.insertItem(19723135, "Ann");
	HT.insertItem(19723665, "Bill");
	HT.insertItem(19723225, "James");
	HT.insertItem(19723395, "Rob");

	HT.printTable();

	HT.removeItem(201);
	if (HT.isEmpty()) {
		cout << "Error"; << endl;
	} else {
		cout << "Correct" << endl;
	}

	return 0
}





































































