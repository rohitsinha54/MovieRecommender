#ifndef HEAP_H
#define HEAP_H

#include "Movie.h"
#include <vector>

// VERY IMPORTANT!!!
// This heap file will work once the following are implemented:
// 1. Movies.h
// 2. Movies.h needs to have an accessor file named .getrating() (I use it here for the heapify function)

class heap
{
private:
    std::vector<Movie> a;
public:
    // input: vector of Movies, number of movies
    // output: heap of movies created, with highest rated movie on top
    heap(Movie m[], int n) {
        for (int i = 0; i < m.size(); i++) {
            a[i] = m[i];
        }
        build_heap(a, n);
        heap_sort(a, n);
    }

    // input: vector of movies, number of movies, parent index
    // output: movie vector stored in a heap
    void heapify (Movie a[], int n, int i) {
        while (i <= (n-2)/2) {
            int lc = 2*i + 1;
            if (lc + 1 < n && a[lc+1].getrating() > a[lc].getrating()) {
                lc++;
            }
            if (!a[i].getrating() < a[lc].getrating()) {
                break;
            }
            std::swap(a[i], a[lc]);
            i = lc;
        }
    }

    // input: vector of Movies, number of movies
    // output: will build the heap
    void build_heap(Movie a[], int n) {
        for (int i = (n-2)/2; i >= 0; --i) {
            heapify(a, n, i);
        }
    }

    // input: vector of Movies, number of movies
    // output: will sort the heap, with the movie with the greatest rating on top
    void heap_sort(Movie a[], int n) {
        build_heap(a, n);
        for (int s = n; s > 1; --s) {
            std::swap(a[0], a[s-1]);
            heapify(a, s-1, 0);
        }
    }

    // input: single movie
    // output: add a movie to the collection
    void add(Movie m) {
        a.push_back(m);
        build_heap(a, a.size());
        heap_sort(a, a.size());
    }

    // input: none
    // output: delete a movie from the collection
    void delete_movie() {
        a.pop_back();
        build_heap(a, a.size());
        heap_sort(a, a.size());
    }

    // input: number of movies desired
    // output: will return a vector with the top n movies
    std::vector<Movie> top(int n) {
        std::vector<Movie> topmovies;
        for (int i = 0; i < n; i++) {
            topmovies.push_back(a[i]);
        }
        return topmovies;
    }
};

#endif // HEAP_H
