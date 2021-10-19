#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void print_vector_left_to_right(const vector<T>& v, string s) {
  cout << s << endl;
  for (auto i = v.begin(); i != v.end(); ++i) cout << *i << " ";
  cout << endl;
}
template<typename T>
void insertion_sort(vector<T>& v) {
  for (int j = 1; j < v.size(); j++) {
  auto key = v[j];
  int i = j - 1;
  while (i > 0 && v[i] > key) {
  v[i + 1] = v[i];
  i = i - 1;
  }
  v[i+1] = key;
}}
int main()
{
  vector<int> v_int{ 1,26,15,523,523,3,6 };
  vector<string> v_string{ "A","C","B" };
  print_vector_left_to_right(v_int, "Printing unsorted array with integers");
  print_vector_left_to_right(v_string, "Printing unsorted array with strings");
  insertion_sort(v_int);
  print_vector_left_to_right(v_int, "Printing sorted array with integers");
  insertion_sort(v_string);
  print_vector_left_to_right(v_string, "Printing sorted array with strings");
}
