int findPos(int *a,int low,int high)
{
  int val = a[low];
  while(low<high)
  {
    while(a[high]>=val && low<high)
      --high;
    a[low] = a[high];
    while(a[low]<=val && low<high)
      ++low;
    a[high] = a[low];
  }
  a[low] = val;
  return low;
}