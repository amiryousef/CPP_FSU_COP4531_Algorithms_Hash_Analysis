/*
    hashtbl.cpp

    Slave file for hashtbl.h
    Implementing the MaxBucketSize and Analysis methods for HashTable<K,D,H>

*/

#include <hashtbl.h>

template <typename K, typename D, class H>
size_t HashTable<K,D,H>::MaxBucketSize () const
{
  size_t max = 0;
  return max;
}

template <typename K, typename D, class H>
void HashTable<K,D,H>::Analysis (std::ostream& os) const
{
  os << " ** MaxBucketSize() = " << MaxBucketSize() << '\n';
  os << " ** HashTable<K,D,H>::Analysis not implemented\n";
} // Analysis
