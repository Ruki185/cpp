#include "utils.hpp"

bool isPermutation(int* perm, int count) {
  int *chkPerm = new int[count]();
  for (int i = 0; i<count; i++) {
    if (perm[i] < 0 || perm[i] >= count) {
      delete[] chkPerm;
      return false;
    }
    chkPerm[perm[i]]++;
    if (chkPerm[perm[i]] > 1) {
      delete[] chkPerm;
      return false;
    }
  }
  delete[] chkPerm;
  return true;
}

bool isSorted(double* data, int dataCount, int* perm) {
  for (int i = 0; i < dataCount-1; i++) {
    if (data[perm[i]] > data[perm[i+1]]) {
      return false;
    }
  }

  return true;
}
