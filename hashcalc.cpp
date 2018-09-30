/*
    hashcalc.cpp
    08/27/11
    Chris Lacher

    hash function calculator

    Copyright 2011, R. C. Lacher
*/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <xstring.cpp>
#include <string>
#include <hashfunctions.cpp>

int main()
{
  fsu::String s;
  //  std::string s;
  unsigned int d;
  std::cout << "Enter divisor for hash value          D: ";
  std::cin >> d;
  std::cout << "\nEnter string to be hashed ('}' to quit): ";
  std::cin >> s;

  while (s[0] != '}')
  {
    std::cout << "                        Simple(k):       " 
	      << hashfunction::Simple(s) << '\n'
	      << "                        Simple(k) mod D: "
	      << hashfunction::Simple(s) % d << '\n'
              << "                        MM(k):           " 
	      << hashfunction::MM(s) << '\n'
	      << "                        MM(k) mod D:     "
	      << hashfunction::MM(s) % d << '\n'
              << "                        KISS(k):         " 
	      << hashfunction::KISS(s) << '\n'
	      << "                        KISS(k) mod D:   "
	      << hashfunction::KISS(s) % d << '\n'
	      << "\nEnter string to be hashed ('}' to quit): ";
    std::cin >> s;
  }
  return 0;
} // main()
