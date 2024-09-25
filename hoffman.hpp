#include<bits/stdc++.h>
using namespace std;

class encoder
{   string str;
    map<char,string> key;
    string encoded;

string gen_encoding(map<char,string> m , string str)
{   string ans;
    for(long long unsigned  i=0 ; i<str.length(); i++)
    {
        ans+= m[str[i]];
    }

    return ans;
}
void traverse(string& str , map< pair<int, string> , vector<pair<pair<int,string>,int>>>& m , pair<int ,string> top, map<char,string>& ans, map<pair<int,string> , bool>& vis)
{   if(m[top].empty())
{
    
    ans[top.second[0]] =str;
}
vis[top] = true;

   
    for( auto it: m[top])
    {   if(!vis[it.first])
    {
        str += to_string(it.second);
        traverse(str , m,it.first,ans, vis);
        str.pop_back();
    }

    }
}

public:
encoder(string str)
{
    this->str = str;
}

void solver()
{
   string str = this->str;
     
    

    priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>>> pq;
    vector<int> freq(126,0);
    map< pair<int, string> , vector<pair<pair<int,string>,int>>>adj;
    map<char, string> ans;

    map<pair<int,string> , bool> vis;
    for(auto i:str)
    {   
        
        freq[int(i)]++;
    }

    
    for(unsigned long long int i=0 ; i< freq.size(); i++)
    {   
        if(freq[i] !=0)
        {   
             string temp;
            temp.push_back(char(i));
            pq.push(make_pair(freq[i], temp));
        }
    }
   
    
    while(!pq.empty())
    {
        auto fir = pq.top();
        pq.pop();

        vis[fir] = false;
        if(!pq.empty())
        {
        auto sec = pq.top();
        pq.pop();
        vis[sec] = false;
        

        pair<int ,string> temp;
        temp = make_pair(fir.first + sec.first , fir.second + sec.second);
        pq.push(temp);

        adj[temp].push_back(make_pair(fir,0));
        adj[temp].push_back(make_pair(sec,1));
        }
        else{
            pq.push(fir);
            break;
        }

    }
    auto temp = pq.top();
    string str2;

    
    
   traverse(str2,adj, temp ,ans, vis);
  
    this->key = ans;

   string encoded = gen_encoding(ans, str); 
   this->encoded = encoded;
   
}

map<char ,string> get_key()
{
    return this->key;
}
string get_str()
{
    return this->encoded;
}

        
};