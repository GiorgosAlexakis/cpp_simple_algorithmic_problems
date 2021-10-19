#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm> 
using namespace std;
//Practicing divide and conquer
//There is a much faster solution for this problem
int find_max_crossing_subarray(vector<int>& v, int low, int mid, int high) {
  int left_sum = INT_MIN, right_sum = INT_MIN,sum = 0;
  for (int i = mid; i >= low; i--) {
    sum += v[i];
    if (sum > left_sum) {
      left_sum = sum;
    }
  }
  sum = 0;
  for (int i = mid+1; i <= high; i++) {
    sum += v[i];
    if (sum > right_sum) {
      right_sum = sum;
    }
  }
  return left_sum + right_sum;
}

int find_maximum_subarray(vector<int>& v, int low, int high) {
  if(high==low) return v[low];
  else {
    int mid = (low + high)/2;
    int left_sum = find_maximum_subarray(v,low,mid);
    int right_sum = find_maximum_subarray(v,mid+1,high);
    int cross_sum = find_max_crossing_subarray(v,low,mid,high);
    if(left_sum>=right_sum && left_sum>=cross_sum) return left_sum;
    else if(right_sum>=left_sum && right_sum>=cross_sum) return right_sum;
    else return cross_sum;
  }
}

int main() {
  vector<int> v{-1,-1,-2,-2};
  int low = 0;
  int high = v.size()-1;
  return find_maximum_subarray(v, low, high);
}