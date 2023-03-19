// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        ++count;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int i = 0;
  int j = len-1;
  while (j > i) {
    if (arr[i] + arr[j] > value) {
      --j;
    }
    if (arr[i] + arr[j] == value) {
      ++count;
      --j;
    }
    if (arr[i] + arr[j] < value) {
      if (arr[i] == arr[i + 1]) {
        j = len - 1;
      }
      ++i;
    }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  int i = 0;
  int j = len - 1;
  int mid;
  int k = 0;
  while (k <= j) {
    mid = (k + j) / 2;
    if (arr[i] + arr[mid] == value) {
      ++count;
      int k1 = mid + 1;
      int k2 = mid - 1;
      while (arr[mid] == arr[k1]) {
        ++count;
        ++k1;
      }
      while (arr[mid] == arr[k2]) {
        ++count;
        --k2;
      }
      ++i;
      k = i;
    }
    else {
      if (arr[i] + arr[mid] > value) {
        j = mid - 1;
      }
      else {
        k = mid + 1;
      }
    }
  }
  return count;
}
