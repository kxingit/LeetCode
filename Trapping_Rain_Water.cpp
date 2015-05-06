int max(int a, int b){
  if (a > b) return a;
  else return b;
}

int trap(int* height, int heightSize) {
  int secHeight = 0;
  int left = 0;
  int right = heightSize - 1;
  int trap = 0;
  while(left < right){
    if(height[left] < height[right]){
      secHeight = max(height[left], secHeight);
      trap += (secHeight - height[left]);
      left++;
    }else{
      secHeight = max(height[right], secHeight);
      trap += (secHeight - height[right]);
      right--;
    }
  }
  return trap;
}
