/**
 * Hash Function for integer
 *
 * @author Malgorzata Sklarek
 */

#ifndef MOVIERECOMMENDER_INTHASHKEY_H
#define MOVIERECOMMENDER_INTHASHKEY_H

#include <cstddef>

template<size_t tableSize>
/**
 * Hash function for int. The hash value is calculated by int i mode tableSize
 * @tparam tableSize the size of the hashtable
 */
struct LongHashKey {
    unsigned long operator()(const long &k) const {
        return k % tableSize;
    }
};

#endif //MOVIERECOMMENDER_INTHASHKEY_H
