

// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string bool_cast(vector<bool> b) {
    string s="";
    for(bool i:b){
        i==1?s+="1":s+="0";
    }
    return s;
}



using namespace std;
int toInt(string s) {
    unsigned long long value = std::stoull(s, 0, 2);

    return value;
}
int main() {
    // Write C++ code here
    
    vector<bool> t = {1,1,1,1};
    string s= bool_cast(t);
    
    
    cout<<toInt(s);
    return 0;
}
