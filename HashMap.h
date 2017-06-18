/**
 * Represents the HashMap data structure. This HashMap uses separate chaining for collision resolution
 *
 * @author Malgorzata Sklarek
 */

#ifndef MOVIERECOMMENDER_HASHMAP_H
#define MOVIERECOMMENDER_HASHMAP_H

#include "HashNode.h"
#include "IntHashKey.h"


// template definition
template<typename K, typename V, size_t tableSize, typename F = IntHashKey<tableSize> >
/**
 * HashMap data structure.
 * @tparam K the key type
 * @tparam V the value type
 * @tparam tableSize the size of the table
 * @tparam F the hash key function which will we uses to generate hashes. This is optional for HashMap where
 * key is int. The default value is a hash function which calculates the hash key by mod with the tableSize
 */
class HashMap {
public:
    /**
     * Default constructor which initializes the hashmap of the given size and the hashing function
     */
    HashMap() :
            table(),
            hashFunc() {
    }

    /**
     * Destructor
     */
    ~HashMap() {
        // iterate through all the nodes and delete them
        for (size_t i = 0; i < tableSize; ++i) {
            HashNode<K, V> *entry = table[i];

            while (entry != NULL) {
                HashNode<K, V> *prev = entry;
                entry = entry->getNext();
                delete prev;
            }

            table[i] = NULL;
        }
    }

    /**
     * Get the value for the given key
     * @param key reference to the key whose value needs to be obtained
     * @param value reference to where the value needs to be stored
     * @return a bool which is true if they given key is found else false
     */
    bool get(const K &key, V &value) {
        // get the hash for the key
        unsigned long hashValue = hashFunc(key);
        // query the hash table with the hash value as index
        HashNode<K, V> *entry = table[hashValue];

        // if found then compare the keys in the linked chain to get to the right key then set the value and return
        // true
        while (entry != NULL) {
            if (entry->getKey() == key) {
                value = entry->getValue();
                return true;
            }

            entry = entry->getNext();
        }

        // return false since the key is not found
        return false;
    }

    /**
     * Puts the given key and its value in the hash map
     * @param key the key which needs to be stored
     * @param value value for the key which needs to be stored
     */
    void put(const K &key, const V &value) {
        // get the hash for the key
        unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *prev = NULL;
        HashNode<K, V> *entry = table[hashValue];

        // if there is an existing node at this hash index then we had a collision and if the key of the entry is not
        // same traverse till the end of the chain and store the node at end
        while (entry != NULL && entry->getKey() != key) {
            prev = entry;
            entry = entry->getNext();
        }

        // if entry is null then there is no collision and the hash node can be stored directly
        if (entry == NULL) {
            entry = new HashNode<K, V>(key, value);

            if (prev == NULL) {
                table[hashValue] = entry;

            } else {
                prev->setNext(entry);
            }

        } else {
            // entry is not null and the key matched so its an update in value so just update the value
            entry->setValue(value);
        }
    }

    /**
     * Remove the given key and its value from the hash map
     * @param key the key which needs to be removed
     */
    void remove(const K &key) {
        // get the hash of the key
        unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *prev = NULL;
        HashNode<K, V> *entry = table[hashValue];

        // if entry is not null and the key doesn't match then traverse the chain to find the right node
        while (entry != NULL && entry->getKey() != key) {
            prev = entry;
            entry = entry->getNext();
        }

        if (entry == NULL) {
            // if entry is null that means the key was not found so just return
            return;

        } else {
            // entry is not null and the key matches so remove this node
            if (prev == NULL) {
                table[hashValue] = entry->getNext();

            } else {
                prev->setNext(entry->getNext());
            }

            delete entry;
        }
    }

private:
    // create an array with the given table size where we will store the HashNode
    HashNode<K, V> *table[tableSize];
    F hashFunc;

    // we don't allow copying and assignment for HashMap so we have this empty methods for that
    HashMap(const HashMap &other);

    const HashMap &operator=(const HashMap &other);
};

#endif //MOVIERECOMMENDER_HASHMAP_H
