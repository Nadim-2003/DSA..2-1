#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
void enqueue(int x) {
        s.push(x);
    }

    int dequeue() {
        if (s.empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int x = s.top();
        s.pop();

        if (s.empty()) return x;
        int item = dequeue();
        s.push(x);

        return item;
    }

int main() {
    
    enqueue(1);
    enqueue(2);
    enqueue(3);
    
    cout << dequeue() << endl; // 1
    cout << dequeue() << endl; // 2
    cout << dequeue() << endl; // 3
    
    return 0;
}

/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int precedence(char c){
  if(c=='^') return 3;
  if(c=='*' || c=='/') return 2;
  return 1;
}
string intopost(string s){
  stack<char>st;
  string ans;
  for(auto c:s){
    if((c>='A' && c<='Z') || (c>='a' && c<='z')){
      ans+=c;
    }else if(c=='('){
      st.push(c);
    }else if(c==')'){
      while(!st.empty() && st.top()!='('){
        ans+=st.top();
        st.pop();
      }
      st.pop();
    }else{
      while(!st.empty() && precedence(st.top())>=precedence(c)){
        ans+=st.top();
        st.pop();
      }
      st.push(c);
    }

  }
  while(!st.empty()){
    ans+=st.top();
    st.pop();
  }
  return ans;
}
int main(){
   string s;
   cin>>s;
   cout<<intopost(s)<<endl;
    return 0;
}*/

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//   string s;
//   cin >> s;
//   stack<int> st;
//   int n = s.length();
//   for (int i = 0; i < n; i++) {
//     if (isdigit(s[i]))
//       st.push(s[i] - '0');
//     else if (s[i] != '#' and s[i] != '$') {
//       int x = st.top();
//       st.pop();
//       int y = st.top();
//       st.pop();
//       if (s[i] == '+') {
//         st.push(x + y);
//       } else if (s[i] == '-') {
//         st.push(y - x);
//       } else if (s[i] == '*') {
//         st.push(x * y);
//       } else if (s[i] == '/') {
//         if (x == 0)
//           x = 2;
//         st.push(y / x);
//       }
//     } else {
//       int x = st.top();
//       st.pop();
//       if (s[i] == '#')
//         x += 1;
//       else
//         x -= 1;
//       st.push(x);
//     }
//   }
//   cout << st.top() << '\n';
// }
