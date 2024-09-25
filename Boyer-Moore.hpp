#include <bits/stdc++.h>
using namespace std;

class boyer_Moore
{

    string text;
    string find;
    unordered_map<char, int> last_ocr;
    vector<int> ans;
    int n_comp;

    void find()
    {
        for (int i = 0; i < find.length(); i++)
        {
            this->n_comp++;
            this->last_ocr[this->find[i]] = i;
        }
        int n = this->text.length();
        int m = this->find.length();

        for (int i = m - 1; i < n;)
        {
            int j = m - 1;
            int k = i;
            while (this->text[k] == this->find[j] && j >= 0)
            {
                k--;
                j--;
            }
            if (j < 0)
            {
                this->ans.push_back(i);
                i++;
            }
            else
            {
                if (this->last_ocr.count(this->text[k]))
                {

                    i += (m - 1 - this->last_ocr[this->text[k]]) - (i - k);
                }
                else
                {

                    i += m - 1 - (i - k);
                }
            }
        }
    }

public:
    boyer_Moore(string text, string find)
    {
        this->text = text;
        this->find = find;
        this->n_comp = 0;
    }

    int n_rep()
    {
        return this->ans.size();
    }
    vector<int> last_ind()
    {
        return this->ans;
    }
    int n_comp()
    {
        return this->n_comp;
    }
};
