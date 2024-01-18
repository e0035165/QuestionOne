//
//  main.cpp
//  QuestionOne
//
//  Created by Sart Way on 17/1/24.
//

#include <iostream>
#include <iostream>
#include <string>
#include<algorithm>
#include<functional>
#include<fstream>
#include<vector>
#include <set>
#include <queue>
#include<map>
#include <chrono>
#include <thread>

using namespace std;
string ltrim(const string &str);
vector<string> split(const string& str);
string rtrim(const string &str);

//struct Node{
//    char word;
//    bool* charNext = new bool[26];
//    Node* children;
//    bool endofword = false;
//    Node(char w) {
//        this->word=w;
//        if(int(this->word) >= 49 && int(this->word) <= 57)
//        {
//            this->children=nullptr;
//            this->endofword=true;
//        } else {
//            this->children = new Node[26];
//            for(int i=0;i<26;i++)
//            {
//                this->children[i] = NULL;
//            }
//        }
//    }
//    Node(){}
//    
//};

class Solution
{
    public:
    int* eachNode;
    int MaxSequence(int *arr, int n) {
        int* dp = new int[n+1];
        dp[n]=0;
        int ans = INT_MIN;
        for(int i=n-1;i>=0;--i)
        {
            int A = arr[i];
            int B = arr[i]+dp[i+1];
            if(B>A) {
                dp[i]=B;
            } else {
                dp[i]=A;
            }
            if(dp[i]>ans)
            {
                ans = dp[i];
            }
            //cout << dp[i] << endl;
        }
        
        return ans;
    }
    
    int naiveRecursive(int idx, int arr[], int n)
    {
        if(idx == n)
        {
            return 0;
        }
        
        int A = arr[idx];
        int B = arr[idx]+naiveRecursive(idx+1, arr, n);
        if(A<B)
        {
            eachNode[idx] = B;
        } else {
            eachNode[idx] = A;
        }
        return eachNode[idx];
    }
};


int main(int argc, const char * argv[]) {
    Solution solution;
    fstream finout("File.txt", ios::in | ios::out);
    string numbers;
    getline(finout,numbers);
    vector<string> num_ans = split(rtrim(numbers));
    int n = (int)num_ans.size();
    int* arr = new int[n];
    for(int i=0;i<n;++i)
    {
        arr[i] = stoi(num_ans[i]);
    }
    int ans = solution.MaxSequence(arr, n);
    cout << ans << endl;
    delete[] arr;
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int c) {return !std::isspace(c);}));
    return s;

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int c) {return !std::isspace(c);}));
    return s;

    return s;
}



vector<string> split(const string& str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
