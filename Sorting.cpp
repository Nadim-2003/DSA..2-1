/*#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void selection(int arr[], int n)
{

  for (int i = 0; i < n - 1; i++)
  {
    int min = i;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[min] >= arr[j])
      {
        min = j;
      }
    }
    swap(arr[i], arr[min]);
  }
}

void bubble(int arr[], int n)
{

  for (int i = n - 1; i > 0; i--)
  {

    for (int j = 0; j < i; j++)
    {
      if (arr[j] >= arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

void insection(int arr[], int n)
{

  for (int i = 0; i < n-1; i++)
  {

    for (int j = i + 1; j > 0; j--)
    {
      if (arr[j - 1] >= arr[j])
      {
        swap(arr[j], arr[j - 1]);
      }
    }
  }
}

void merge(int arr[], int low, int mid, int high)
{
  vector<int> temp;
  int l = low;
  int n = mid + 1;
  while (l <= mid && n <= high)
  {
    if (arr[l] <= arr[n])
    {
      temp.push_back(arr[l]);
      l++;
    }
    else
    {
      temp.push_back(arr[n]);
      n++;
    }
  }
  while (l <= mid)
  {
    temp.push_back(arr[l]);
    l++;
  }
  while (n <= high)
  {
    temp.push_back(arr[n]);
    n++;
  }
  for (int i = low; i <= high; i++)
  {
    arr[i] = temp[i - low];
  }
}

void sort(int arr[], int low, int high)
{
  if (low >= high)
    return;
  int mid = (low + high) / 2;
  sort(arr, low, mid);
  sort(arr, mid + 1, high);
  merge(arr, low, mid, high);
}

void count(int arr[], int n, int pos)
{
  //    int m=INT_MIN;
  //   for(int i=0;i<n;i++){
  //      m=max(arr[i],m);
  //   }
  //    vector<int> v(m+1,0);
  //   for(int i=0;i<n;i++){
  //      v[arr[i]]++;
  //   }
  //    for(int i=1;i<=m;i++){
  //     v[i]+=v[i-1];
  //    }
  //    int ans[n];
  //    for(int i=0;i<n;i++){
  //       ans[--v[arr[i]]]=arr[i];
  //    }
  //     for(int i=0;i<n;i++){
  //       cout<<ans[i]<<" ";
  //    }
  vector<int> v(10, 0);
  for (int i = 0; i < n; i++)
  {
    v[(arr[i] / pos) % 10]++;
  }
  for (int i = 1; i < 10; i++)
  {
    v[i] += v[i - 1];
  }
  int ans[n];
  for (int i = 0; i < n; i++)
  {
    ans[--v[((arr[i] / pos) % 10)]] = arr[i];
  }
  for (int i = 0; i < n; i++)
  {
    arr[i] = ans[i];
  }
}
void radix(int arr[], int n)
{
  int m = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    m = max(arr[i], m);
  }
  for (int i = 1; m / i > 0; i *= 10)
  {
    count(arr, n, i);
  }
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
  //insection(arr, n);
  // radix(arr,n);
    sort(arr,0,n-1);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }

  return 0;
}*/

// ####### Merge sort for a link list

//  #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// struct node
// {
//   int n;
//   node *next;
//   node(int a)
//   {
//     n = a;
//     next = nullptr;
//   }
// };
// node *head = NULL;
// node *tail = NULL;

// void travarse(int n)
// {
//   if (head == nullptr)
//   {
//     head = new node(n);
//     tail = head;
//   }
//   else
//   {
//     node *temp = new node(n);
//     tail->next = temp;
//     tail = temp;
//   }
// }
// node *merge(node *l, node *r)
// {
//   node *dummy = new node(-1);
//   node *temp = dummy;
//   while (l && r)
//   {
//     if (l->n <= r->n)
//     {
//       temp->next = l;
//       l = l->next;
//     }
//     else
//     {
//       temp->next = r;
//       r = r->next;
//     }
//     temp = temp->next;
//   }
//   if (l)
//     temp->next = l;
//   if (r)
//     temp->next = r;

//   return dummy->next;
// }
// node *sort(node *head)
// {

//   if (head == NULL || head->next == NULL)
//     return head;

//   node *slow = head;
//   node *ans = nullptr;
//   node *fast = head;
//   while (fast && fast->next)
//   {
//     ans = slow;
//     slow = slow->next;
//     fast = fast->next->next;
//   }

//   if (ans)
//     ans->next = nullptr;
//   node *l1 = sort(head);
//   node *l2 = sort(slow);
//   return merge(l1, l2);
// }

// void display(node *temp)
// {
//   while (temp)
//   {
//     cout << temp->n << " ";
//     temp = temp->next;
//   }
// }
// int main()
// {

//   int n;
//   cin >> n;
//   while (n--)
//   {
//     int x;
//     cin >> x;
//     travarse(x);
//   }

//   node *ok = sort(head);
//   display(ok);
//   return 0;
// }


