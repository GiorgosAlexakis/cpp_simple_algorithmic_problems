#include <iostream>
#include <vector>
#include<iterator>
using namespace std;

void print_vector_left_to_right(const vector<int>& v, string s=" ") {
  cout << s << endl;
  for (auto i = v.begin(); i != v.end(); ++i) cout << *i << " ";
  cout << endl;
}
void merge(vector<int>::iterator left, vector<int>::iterator mid,vector<int>::iterator right) {
  
  vector<int> left_array(left, mid);
  vector<int> right_array(mid, right);
  auto left_size = left_array.size();
  auto right_size = right_array.size();
  int i=0,j=0;
  auto k=left;
  while (i < left_size && j < right_size) {
    if (left_array.at(i) < right_array.at(j)) { 
      *k=left_array.at(i);
      i++;
      k++;
}
    else { 
      *k = right_array.at(j);
      j++;
      k++;
    }
}
  while (i < left_size) {
    *k = left_array.at(i);
    i++;
    k++;
  }
  while (j < right_size){ *k = right_array.at(j);j++;k++;}
}
void merge_sort(vector<int>::iterator left,vector<int>::iterator right) {
  auto size = (right - left);
  if(size <= 1) return;
  auto mid = next(left,size/2);
  merge_sort(left,mid);
  merge_sort(mid,right);

}
int main()
{
  vector<int> v{12341,1325,15,60,20};
  auto left = v.begin();
  auto right = v.end();
  merge_sort(left,right);
  print_vector_left_to_right(v);
}
