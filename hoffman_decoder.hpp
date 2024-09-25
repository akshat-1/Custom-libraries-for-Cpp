#include<bits/stdc++.h>
using namespace std;

class decoder
{   string str;
    map<char, string> key;
    string output;

    public:
    decoder(string str , map<char , string> key)
    {
        this->str = str;
        this->key = key;
    }
    void solver()
    {
        int s=0;
        int e=1;
        int n = this->str.length();
        while(s<n)
        {
            string temp = this->str.substr(s,e);
            for(auto it: this->key)
            {
                if(temp == it.second)
                {
                    this->output.push_back(it.first);
                    s =s +e;
                    e=0;
                    break;

                }   
            }
            e++;
        }
    }

    string get_actual_str()
    {
        return this->output;
    }

};


