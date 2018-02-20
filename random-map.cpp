// constructing maps
#include <ctime>
#include <iostream>
#include <map>

#include "random-map.hpp"

int RandomElementSelector::get_random_element(const AssociativeArray& map) {
  auto mapi = map.begin();
  std::advance(mapi, rand() % map.size());
  auto prob= (*mapi).second;
  std::cout << "probability: " << prob << std::endl;
  return (*mapi).first;
}

int main ()
{
  srand(time(NULL));
  AssociativeArray *mymap= new AssociativeArray();

  // performance measurement

  std::clock_t start;
  start = std::clock();

  // create random probabilities

  for (int i= 0; i < DICTIONARY_SIZE; i++) {
    int random_index= rand() % DICTIONARY_SIZE;
    
    (*mymap)[random_index]= (float) rand() / RAND_MAX;
  }

  // input associative array

  for(AssociativeArray::iterator iter = mymap->begin(); iter != mymap->end(); ++iter) {
    std::cout << "key= " << iter->first << ", value= " << iter->second << std::endl;
  }

  std::cout << "Time to build set of " << DICTIONARY_SIZE
            << " elements: "
            << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000)
            << " ms" << std::endl;

  for (int i= 0; i < TEST_SIZE; i++) {
    
    std::clock_t start;
    start = std::clock();

    std::cout << RandomElementSelector::get_random_element(*mymap) << std::endl;

    std::cout << "Time to retrieve index: "
              << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000)
              << " ms" << std::endl;
  }

  // reclaim space

  delete mymap;

  return 0;
}
