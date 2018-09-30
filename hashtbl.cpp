
/*
hashtbl.cpp
Slave file for hashtbl.h
Implementing the MaxBucketSize and Analysis methods for HashTable<K,D,H>
Amir Yousef
9-16-2014
Project1
COP4531 
*/

#include <hashtbl.h>
template <typename K, typename D, class H>
size_t HashTable<K,D,H>::MaxBucketSize () const
{
  size_t i = 0;
  size_t max = 0;
  for(i = 0; i < numBuckets_; i++)
    {
      if(max < bucketVector_[i].Size())
	{
	  max = bucketVector_[i].Size();
	}
    } 
  return max;
}

template <typename K, typename D, class H>
void HashTable<K,D,H>::Analysis (std::ostream& os) const
{
  size_t i = 0;
  size_t size = 0;
  size_t item = 0;
  size_t element = 0;
  float check = 0;
  Vector <int> bucket(1);
  bucket[0] = 0;
  for(i = 0; i < numBuckets_; i++)
    {
      if(bucket.Size()-1 < bucketVector_[i].Size())
	{
	  if(bucket.Size()+1 >= bucket.Capacity())
	    {
	      bucket.SetCapacity(bucketVector_[i].Size()*2);
	    }
	  bucket.SetSize(bucketVector_[i].Size()+ 1, 0);
	}
      size = bucketVector_[i].Size();
      bucket[size]++;
      element += size;
      if(size > 0)
	{
	  item++;
	}
    }
  os << "\ntable size: " << element << "\nnumber of buckets: " << numBuckets_ << "\nnonempty buckets: " << item << "\nmax bucket size: " << MaxBucketSize() << "\nexpected search time: " << (float)(1 + (element * 1.0)/(numBuckets_ * 1.0)) << "\nactual search time: " << (float)(1 + (element * 1.0)/(item * 1.0)) << '\n';
  os << "\nbucket size distributions\n-------------------------\nsize \tactual \ttheory (uniform random distribution) \n----\t------\t------\n";
  check = numBuckets_ * pow((numBuckets_*1.0 - 1)/ (numBuckets_*1.0), element);
  i = 0;
  while(check > 0.1 || i < bucket .Size())
    {
      os << i << '\t';
      if(i < bucket.Size())
	{
	  os << bucket [i] << '\t' << check << '\n';
	}
      else
	{
	  os << "\t" << check << '\n';
	}
      i++;
      check = ((element - (i) + 1.0)/(i)) * (1.0 / (numBuckets_ - 1.0)) * check;
    }
}
