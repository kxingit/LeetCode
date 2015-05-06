/*
   Rotate an array of n elements to the right by k steps.

   For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

    Note: Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
 */
void reverse(int n[], int i, int j){ // revserse [i, j]
  int tmp;
  while(i < j){
    tmp = n[i];
    n[i++] = n[j];
    n[j--] = tmp;
  }
}

void rotate(int nums[], int n, int k) {
  k = n - k % n;

  reverse(nums, 0, k - 1);
  reverse(nums, k, n - 1);
  reverse(nums, 0, n - 1);
}


