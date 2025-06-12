#include<bits/stdc++.h>
using namespace std;
int n;
vector<char> s(21);
void pre(int node)
{
    if (node>n) return;
    cout<<s[node]<<" ";
    pre(2*node);
    pre(2*node+1);
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>s[i];
    }
    pre(1);
} // PROB E 이진트리의 전위순회 


#include<bits/stdc++.h>
using namespace std;
int n;
vector<char> s(21);
void in(int node)
{
    if (node>n) return;
    in(2*node);
    cout<<s[node]<<" ";
    in(2*node+1);
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>s[i];
    }
    in(1);
} // PROB F 이진트리의 중위순회 


#include<bits/stdc++.h>
using namespace std;
int n;
vector<char> s(21);
void post(int node)
{
    if (node>n) return;
    post(2*node);
    post(2*node+1);
    cout<<s[node]<<" ";
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>s[i];
    }
    post(1);
} // PROB G 이진트리의 후위순회 
