#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm> 
using namespace std;
void quicksort(vector<int>& v,int low, int high);
int partition(vector<int>& v,int low,int high);

void print_vector_left_to_right(const vector<int>& v, string s=" ") {
  cout << s << endl;
  for (auto i = v.begin(); i != v.end(); ++i) cout << *i << " ";
  cout << endl;
}

void quicksort(vector<int>& v, int low, int high) {
  if (low < high) {
    int q = partition(v,low,high);
    quicksort(v,low,q-1);
    quicksort(v,q+1,high);
  }
}


int partition(vector<int>& v, int low, int high) {
  int x = v[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (v[j] <= x) {
      i = i + 1;
      swap(v[i],v[j]);
    }
  }
  swap(v[i+1],v[high]);
  return i + 1;
}

int main() {
  vector<int> v{ 1421,12,144,25,124 };
  int low = 0;
  int high = v.size() - 1;
  quicksort(v,low,high);
  print_vector_left_to_right(v);
}