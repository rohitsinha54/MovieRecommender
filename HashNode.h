/**
 * Represents a node in the HashMap.
 *
 * @author Malgorzata Sklarek
 */

#ifndef MOVIERECOMMENDER_HASHNODE_H
#define MOVIERECOMMENDER_HASHNODE_H

#include <cstddef>

template<typename K, typename V>

/**
 * HashNode class represents a node in the HashMap. It contains the key and value with with a pointer next which links
 * to another HashNode. This is used to do collision resolution for which we use separate chaining. The next points to
 * the next node in the chain.
 *
 * @tparam K the key
 * @tparam V the value
 */
class HashNode {
public:

    /**
     * Constructs a HashNode. next is set to NULL by default.
     * @param k the key
     * @param v the value
     */
    HashNode(const K &k, const V &v) : key(k), value(v), next(NULL) {
        // constructor with initialization list. This will do initialization of fields too.
    }

    /**
     * @return the key
     */
    K getKey() const {
        return key;
    }

    /**
     * @return the value
     */
    V getValue() const {
        return value;
    }

    /**
     * Sets the value
     * @param v the value to set
     */
    void setValue(V v) {
        value = v;
    }

    /**
     * @return The next HashNode
     */
    HashNode *getNext() const {
        return next;
    }

    /**
     * Sets the next to the given HashNode
     * @param n pointer to the HashNode to set to
     */
    void setNext(HashNode *n) {
        next = n;
    }

private:
    K key; // the key
    V value; // the value
    HashNode *next; // next hashnode in the chain i.e. which ended up in the same hash bucket

    // we don't allow copying and assignment for HashNode so we have this empty methods for that
    HashNode(const HashNode &);

    HashNode &operator=(const HashNode &);
};

#endif //MOVIERECOMMENDER_HASHNODE_H
