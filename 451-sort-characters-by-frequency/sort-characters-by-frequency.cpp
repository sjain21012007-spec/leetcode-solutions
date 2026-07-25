class Solution {
public:
    string frequencySort(string s) {
        unordered_map <char,int> a;
        string  ans = "";
        int n = s.length();
        
        for(int i=0;i<n;i++)
        {
           a[s[i]]++;
        }
        vector<vector<char>> buckets(n + 1);
        for (const auto& [letter, number] : a) 
        {
            buckets[number].push_back(letter);
        }
        for(int i =n;i>0;i--)
        {
            for(char letter : buckets[i])
           { 
            ans = ans + string(i,letter);
            }
        }
    
           return ans;
    }
};