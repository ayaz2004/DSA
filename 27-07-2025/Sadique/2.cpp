/*
Given a string queryIP, return "IPv4" if IP is a valid IPv4 address, "IPv6" if IP is a valid IPv6 address or "Neither" if IP is not a correct IP of any type.
A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <= xi <= 255 and xi cannot contain leading zeros. For example, "192.168.1.1" and "192.168.1.0" are valid IPv4 addresses while "192.168.01.1", "192.168.1.00", and "192.168@1.1" are invalid IPv4 addresses.
A valid IPv6 address is an IP in the form "x1:x2:x3:x4:x5:x6:x7:x8" where:
1 <= xi.length <= 4
xi is a hexadecimal string which may contain digits, lowercase English letter ('a' to 'f') and upper-case English letters ('A' to 'F').
Leading zeros are allowed in xi.
For example, "2001:0db8:85a3:0000:0000:8a2e:0370:7334" and "2001:db8:85a3:0:0:8A2E:0370:7334" are valid IPv6 addresses, while "2001:0db8:85a3::8A2E:037j:7334" and "02001:0db8:85a3:0000:0000:8a2e:0370:7334" are invalid IPv6 addresses.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    bool isIPv4(string s){
       vector<string> parts;
       stringstream ss(s);
       string part;
       while(getline(ss, part, '.')) parts.push_back(part);
       if(parts.size()!=4) return false;
       for(string& it:parts){
        if(it.empty() || it.size() > 3) return false;
            if (it.size() > 1 && it[0]=='0') return false;
            for (char c:it) {
                if (!isdigit(c)) return false;
            }
            int num = stoi(it);
            if (num < 0 || num > 255) return false;
       }
       return s.back()!='.';
    }
    bool isIPv6(string s){
        vector<string> parts;
        stringstream ss(s);
        string part;
        while(getline(ss, part, ':')) parts.push_back(part);
        if(parts.size()!=8) return false;
        for(string& it:parts){
            if(it.empty() || it.size()>4) return false;
            for(char ch:it){
                if(!((ch >= '0' && ch <= '9') ||
                     (ch >= 'a' && ch <= 'f') ||
                     (ch >= 'A' && ch <= 'F')))
                        return false;
            }
        }
        return s.back()!=':';
    }
public:
   string valid_IP_address(string queryIP){
      if(count(queryIP.begin(), queryIP.end(), '.')>0){
        if(isIPv4(queryIP)) return "IPv4";
      }else if(count(queryIP.begin(), queryIP.end(), ':')>0){
        if(isIPv6(queryIP)) return "IPv6";
      }
        return "Neither";
    }
};

int main(){
    Solution sol;
    vector<string> tests = {
        "192.168.1.1",              
        "192.168.01.1",            
        "256.256.256.256",          
        "2001:0db8:85a3:0000:0000:8a2e:0370:7334",
        "2001:db8:85a3::8A2E:0370:7334",          
        "02001:0db8:85a3:0000:0000:8a2e:0370:7334" 
    };
    for (string& it:tests) {
        cout<<sol.valid_IP_address(it)<<endl;
    }
    return 0;
}