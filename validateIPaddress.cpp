/*
 Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.

IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;

Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.

IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).

However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.

Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.

Note: You may assume there is no extra space or special characters in the input string.

Example 1:

Input: "172.16.254.1"

Output: "IPv4"

Explanation: This is a valid IPv4 address, return "IPv4".

Example 2:

Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"

Output: "IPv6"

Explanation: This is a valid IPv6 address, return "IPv6".

Example 3:

Input: "256.256.256.256"

Output: "Neither"

Explanation: This is neither a IPv4 address nor a IPv6 address.
*/

// code:


using namespace std;
class Solution {
public:
    
bool isNumber( std::string token )
{

    for (int i=0; i < token.length(); i++){
        if ((token[0] == '0') && (token.length() > 1)){
            return false;
        }
        switch(token[i]) {
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '0':           
                break;
            default:
                return false;

        }
    }
    return true;
}
    
bool isHex(std::string token )
{   
    for (int i=0; i < token.length(); i++){
        switch(token[i]) {
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '0':           
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
            case 'A':
            case 'B':
            case 'C':
            case 'E':
            case 'F':                
                break;
            default:
                return false;

        }
    }
    return true;
}

string validIPAddress(string IP) {
    
        bool ip4 = false;
        bool ip6 = false;    
    
        bool precedingzero = false;
        bool emptygroup = false;

        


// Check if the input is in hex or dec and if leading zeroes and empty groups are present
        if (IP[0] == ':' || IP[IP.size() - 1] == ':' ){

            return("Neither");
        }
        if (IP[0] == '.' || IP[IP.size() - 1] == '.' ){

            return("Neither");
        }        

        for (int i = 0; i < IP.size(); i++){
            if (IP[i] == ':'){
                ip6 = true;
                if (IP[i-1] == ':'){
                    emptygroup = true;              
                }                
            }
             if (IP[i] == '.'){
                 ip4 = true;
            //     if (IP[i+1] == '0'){
            //         precedingzero = true;                    
            //     }
             }
        }
        
        
        if (ip4 && ip6){

            return ("Neither");
        }
        
//        if (precedingzero || emptygroup){
        if (emptygroup){

            return("Neither");
        }
        
// Checking for ip4        

        if (ip4){
            string str = IP;
            std::replace(str.begin(), str.end(), '.', ' ');  // replace '.' by ' '
            vector<string> array;
            stringstream ss(str);
            string temp;
            while (ss >> temp){
                try{
                    if ((stoi(temp,nullptr,10) < 0) || (stoi(temp,nullptr,10) > 255)){

                        return("Neither");
                    }
                    if (!isNumber(temp)){

                        return("Neither");
                    }                    
                }
                catch(...){

                    return("Neither");
                }
                array.push_back(temp);
            }
            if (array.size() != 4){

                return("Neither");                                        
            }
            return ("IPv4");
        }

// Checking for ip6
        
        if (ip6){
            string str = IP;
            std::replace(str.begin(), str.end(), ':', ' ');  // replace ':' by ' '
            vector<string> array;
            stringstream ss(str);
            string temp;
            while (ss >> temp){
                try{
// (str_hex,nullptr,16);                    
                    if ((stoi(temp,nullptr,16) < 0) || (stoi(temp,nullptr,16) >  65535) || (temp.size() > 4)){
                        return("Neither");
                    }
                    if (!isHex(temp)){
                        return("Neither");
                    }                                        
                }
                catch(...){
                    return("Neither");
                }
                array.push_back(temp);
            }
            if (array.size() != 8){
                return("Neither");
            }   
            return ("IPv6");
        }
        

        return("Neither");
        
    }
};