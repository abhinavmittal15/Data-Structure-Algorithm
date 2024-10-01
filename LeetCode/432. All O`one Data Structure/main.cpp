#include<iostream>
#include<string>
#include<unordered_map>
#include<set>
using namespace std;

class AllOne {
private:
    unordered_map<string, int> keyCount;
    set<pair<int, string>> countKeys;
public:
    AllOne() {

    }

    void inc(string key) {
        if (keyCount.find(key) != keyCount.end()) {
            countKeys.erase({keyCount[key], key});
            keyCount[key]++;
        } else {
            keyCount[key] = 1;
        }
        countKeys.insert({keyCount[key], key});
    }

    void dec(string key) {
        if (keyCount.find(key) != keyCount.end()) {
            countKeys.erase({keyCount[key], key});
            if (keyCount[key] == 1) {
                keyCount.erase(key);
            } else {
                keyCount[key]--;
                countKeys.insert({keyCount[key], key});
            }
        }
    }

    string getMaxKey() {
        if (countKeys.empty()) return "";
        return countKeys.rbegin()->second;
    }

    string getMinKey() {
        if (countKeys.empty()) return "";
        return countKeys.begin()->second;
    }
};

int main() {
    AllOne allOne;

    allOne.inc("hello");
    allOne.inc("hello");
    allOne.inc("world");

    cout << "Max Key: " << allOne.getMaxKey() << endl; // Should print "hello"
    cout << "Min Key: " << allOne.getMinKey() << endl; // Should print "world"

    allOne.dec("hello");

    cout << "Max Key: " << allOne.getMaxKey() << endl; // Should print "hello"
    cout << "Min Key: " << allOne.getMinKey() << endl; // Should print "world"

    allOne.dec("hello");

    cout << "Max Key: " << allOne.getMaxKey() << endl; // Should print "world"
    cout << "Min Key: " << allOne.getMinKey() << endl; // Should print "world"

    return 0;
}