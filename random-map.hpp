#ifndef RANDOMMAP_HPP
#define RANDOMMAP_HPP

typedef std::map<int, float> AssociativeArray;

#define DICTIONARY_SIZE     100L
#define TEST_SIZE           50

class RandomElementSelector {

public:

  /* method: get_random_element
   * parameter: reference to AssociativeArray
   * returns: Retrieve the index of a random element in the supplied associative array
   *
   */

  static int get_random_element(const AssociativeArray& map);

};


#endif
