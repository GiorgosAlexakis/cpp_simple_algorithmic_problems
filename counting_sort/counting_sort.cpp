#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm> 
using namespace std;

void print_vector_left_to_right(const vector<int>& v, string s=" ") {
  cout << s << endl;
  for (auto i = v.begin(); i != v.end(); ++i) cout << *i << " ";
  cout << endl;
}

void counting_sort(vector<int>& A,vector<int>& B,int k) {
  vector<int> C;
  for(int i = 0;i<k;i++) C.push_back(0);
  for(int j = 0;j<A.size();j++)C[A[j]]=C[A[j]]+1;
  //C[i] now contains the number of elements is equal to i
  for (int i = 1; i < k; i++) {
    C[i] = C[i] + C[i-1];
  }
  //C[i] now contains the number of elements less than or equal to i
  for (int j = A.size() - 1; j >= 0; j--) {
    B[C[A[j]]-1] = A[j];
    C[A[j]] = C[A[j]] - 1;
  }
  
  //B now is the sorted array
}

int main() {
  vector<int> v{2,5,3,0,2,3,0,3};
  int k = *max_element(v.begin(), v.end())+1;
  vector<int> B;
  for(int i = 0;i<v.size();i++) B.push_back(0);
  counting_sort(v,B,k);
  print_vector_left_to_right(B);
}