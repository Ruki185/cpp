#include "utils.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

double* resize(double* array, int *n);

/* todo:
 *      * read doubles from cin and put them into an array until something that
 *        is not a number is entered. (std::cin.fail() is true)
 *      * increase the array's size if necessary
 *      * reset cin (see clear() and ignore())
 *      * read in the same amount of integers
 *      * implement functions in utils.cpp
 *      * test given input with isPermutation() and isSorted()
 *      * clean up all dynamically allocated memory
 */
int main(int, char**) {
  int elem_count = 0;
  int size = 4;

  double *data = new double[size];
  cout << "Type the numbers you want to add." << '\n';

  while (!cin.fail()) {
    cin >> data[elem_count];
    data = resize(data, &size);

    if (cin.fail())
      break;

    elem_count++;
  }

  cin.clear();
  cin.ignore();

  cout << "Type the indicies for the permutation." << '\n';
  cout << elem_count;

  int *perms = new int[elem_count];
  cout << "Type the numbers you want to add." << '\n';

  int i = 0;
  while (i < elem_count) {
    if (cin.fail()) {
      continue;
    }
    cin >> perms[i++];
  }

  cin.clear();
  cin.ignore();

  if (isPermutation(perms, elem_count)) {
    cout << "Valid Permutation: true" << '\n';
    if (isSorted(data, elem_count, perms))
      cout << "Sorted: true" << '\n';
    else
      cout << "Sorted: false" << '\n';
  }
  else
    cout << "Valid Permutation: false" << '\n';

  delete[] data;
  delete[] perms;
  return 0;
}

//tut halt irgendwie Magie, hoffentlich
double* resize(double *array, int* size)  {
  *size += 1;
  double *array2 = new double[*size]();
  for (int i = 0; i< *size - 1; i++) {
    array2[i] = array[i];
  }
  delete[] array;
  return array2;
}
