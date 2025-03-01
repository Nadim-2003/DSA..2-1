// #include <iostream>
// using namespace std;

// void Combination(char c[], int index, int n)
// {
//     if(index==n)
//     {
//         for(int i=0; i<n; i++)
//         {
//             cout << c[i] << " ";
//         }
//         cout << endl;
//         return;
//     }

//     c[index] = 'a';
//     Combination(c, index+1, n);
//     c[index] = 'b';
//     Combination(c, index+1, n);
//     c[index] = 'c';
//     Combination(c, index+1, n);
// }

// int main()
// {
//     int n;
//     cin >> n;
//     char c[n];
//     Combination(c, 0, n);
//     return 0;
// }


#include <iostream>
#include <vector>
using namespace std;
//Print all possible combinations of k digits from (0-n) in descending order.

// Recursive function to generate combinations
void generateCombinations(int n, int k, int start, int shesh, int combination[]) {
    // If the current combination has the required size k
    if (shesh == k) {
        for (int i = 0; i < k; i++) {
            cout << combination[i];
        }
        cout << endl;
        return;
    }

    // Generate next elements
    for (int i = start; i >= 0; i--) {
        combination[shesh] = i; // Set the current depth to the number
        generateCombinations(n, k, i - 1, shesh + 1, combination);
    }
}

int main() {
    int n, k;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;

    int combination[k]; // Array to hold the current combination

    // Generate combinations starting from n
    generateCombinations(n, k, n-1, 0, combination);

    return 0;
}

// #include <iostream>
// using namespace std;

// void permutation(char arr[], int start, int stop)
// {
//     if(start == stop)
//     {
//         for(int i=0; i<=stop; i++)
//         {
//             cout << arr[i];
//         }
//         cout << endl;
//         return;
//     }

//     for(int i=start; i<=stop; i++)
//     {
//         swap(arr[start], arr[i]);
//         permutation(arr, start+1, stop);
//         swap(arr[start], arr[i]);
//     }
// }

// int main()
// {
//     char arr[] = {'a', 'b', 'c'};
//     permutation(arr, 0, 2);
//     return 0;
// }

// #include <iostream>

// using namespace std;

// int K;

// // Function to generate words recursively
// void generate(string word, int countA) {
//     if (word.length() == K) {
//         if (countA > 4) cout << word << endl;
//         return;
//     }

//     generate(word + 'A', countA + 1); // Add 'A'
//     generate(word + 'B', countA);     // Add 'B'
//     generate(word + 'C', countA);     // Add 'C'
// }

// int main() {
//     cout << "Enter K (must be > 5): ";
//     cin >> K;

//     if (K <= 5) {
//         cout << "K must be greater than 5.\n";
//         return 1;
//     }

//     generate("", 0);
//     return 0;
// }

/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 void f(int n,int arr[],int idx){
  if(idx==n){
    for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
    }
    cout<<endl;
    return;
  }
  for(int i=0;i<5;i++){
    if(i%2!=idx%2) continue;
    arr[idx]=i;
    f(n,arr,idx+1);
  }
 }
int main(){
    int n;
    cin>>n;
    int arr[n];
    f(n,arr,0);
    return 0;
}*/

/*#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void subset(int n, int arr[], vector<int> &ans, int idx)
{
  if (idx >= n)
  {
    for (auto it : ans)
      cout << it;
    cout << endl;
    return;
  }
  subset(n, arr, ans, idx + 1);
  ans.push_back(arr[idx]);
  subset(n, arr, ans, idx + 1);
  ans.pop_back();
}
int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  vector<int> ans;
  subset(n, arr, ans, 0);
  return 0;
}*/
