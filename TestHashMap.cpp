/**
 * Test for HashMap
 *
 * @author Malgorzata Sklarek
 */

#include <iostream>
#include <assert.h>
#include "HashMap.h"

using namespace std;

void testWithString();

void testWithInt();

int main() {
    // since our hashmap has templates to support different data types we test with int and string types as values
    testWithString();
    testWithInt();
    cout << "All tested passed." << endl;
}

void testWithString() {
    HashMap<long, string, 10L, LongHashKey<10L> > hmap;
    hmap.put(1, "one"); // with our hash function %10 the hashkey for this will be 1
    hmap.put(2, "two");
    hmap.put(11, "eleven"); // with our hash function %10 the hashkey for this will be 1 and this will
    // cause hash collision

    string value;
    bool result = hmap.get(1, value);
    assert(result);
    assert(value == "one");

    result = hmap.get(2, value);
    assert(result);
    assert(value == "two");

    // check the value of the key which caused hash collision
    result = hmap.get(11, value);
    assert(result);
    assert(value == "eleven");

    hmap.remove(2);
    result = hmap.get(2, value);
    assert(!result);
}

void testWithInt() {
    HashMap<long, int, 10L> hmap; // int this we don't give any hash function so the default one will be used
    hmap.put(1, 1);
    hmap.put(2, 2);

    int value;
    bool result = hmap.get(1, value);
    assert(result);
    assert(value == 1);

    result = hmap.get(2, value);
    assert(result);
    assert(value == 2);

    hmap.remove(2);
    result = hmap.get(2, value);
    assert(!result);
}
