/*
Question:

Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.
 

Follow up:
Could you solve it using only O(1) extra space?
 

Example 1:

Input:
["a","a","b","b","c","c","c"]

Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Explanation:
"aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".

 

Example 2:

Input:
["a"]

Output:
Return 1, and the first 1 characters of the input array should be: ["a"]

Explanation:
Nothing is replaced.

 

Example 3:

Input:
["a","b","b","b","b","b","b","b","b","b","b","b","b"]

Output:
Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].

Explanation:
Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
Notice each digit has it's own entry in the array.

 

Note:

    All characters have an ASCII value in [35, 126].
    1 <= len(chars) <= 1000.
*/

// Answer:

using namespace std;
class Solution {
public:
    void displayElements(vector<char>& chars1){
        for (int i = 0; i < chars1.size(); i++ ){
            cout << chars1[i] << "  ,";
        }
        cout << endl;
    }
    int compress(vector<char>& chars) 
    {
        vector<char>::iterator iter = chars.begin();
//        cout << *(iter) << endl ;
        int tempcount = 1;
        char tempchar;

        while(iter != (chars.end() - 1)){
//            displayElements(chars);                    
            
            if (*(iter) == *(iter + 1))
            {

                tempcount++;
                tempchar = *(iter);
                if (tempcount > 2)
                {
//                    cout << "erasing happens for character " << tempchar << endl;
                    chars.erase(iter - 1);
                    iter = iter - 1;
                }
            }
            else{ 
                if (tempcount > 1) {
                    *(iter - 1) = tempchar;
                    string finalappendage = to_string(tempcount);
                    for (int j = 0; j < finalappendage.length(); j++)
                    {
                        if (j == 0)
                        {
                         *(iter) =  finalappendage[0];
                          continue;                    
                        }

                        chars.insert(++iter, finalappendage[j]);
                    }                    

                
                tempcount = 1;
            
                }
            }
            iter++;
            
        }
// write required for the last sequence if it exists
        if (tempcount > 1)
        {
            *(iter - 1) = tempchar;
            string finalappendage = to_string(tempcount);
            for (int j = 0; j < finalappendage.length(); j++)
            {
                if (j == 0)
                {
                 *(iter) =  finalappendage[0];
                  continue;                    
                }
                
                chars.push_back(finalappendage[j]);
            }
        }
        return(chars.size());
    }


    
    };

