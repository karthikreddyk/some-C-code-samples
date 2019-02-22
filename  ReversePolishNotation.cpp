/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:

    Division between two integers should truncate toward zero.
    The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.

Example 1:

Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Example 2:

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

Example 3:

Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/
// code:

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<string>::iterator iter;
        while(tokens.size() > 1){
            iter = tokens.begin();            
            for ( int j = 0; iter != tokens.end(); iter++){
                   if (*iter == "+"){
                        if (j >=2)
                        {
                            int temp = stoi(*(iter -2)) + stoi(*(iter -1));
                            tokens.erase(iter);
                            iter--;
                            tokens.erase(iter);
                            iter--;
                            *iter = to_string(temp);
                            j = 1;
                        }
                       else{
                           j = 0;
                           iter = iter - 3;
                       }
                   }
                    else if (*iter == "-"){                    
                        if (j >=2)
                        {
                            int temp = stoi(*(iter -2)) - stoi(*(iter -1));
                            tokens.erase(iter);
                            iter--;
                            tokens.erase(iter);
                            iter--;
                            *iter = to_string(temp);
                            j = 1;
                        }
                       else{
                           j = 0;
                           iter = iter - 3;                           
                       }                        
                    }
                    else if (*iter == "*"){                                    
                        if (j >=2)
                        {
                            int temp = stoi(*(iter -2)) * stoi(*(iter -1));
                            tokens.erase(iter);
                            iter--;
                            tokens.erase(iter);
                            iter--;
                            *iter = to_string(temp);
                            j = 1;
                        }
                       else{
                           j = 0;
                           iter = iter - 3;                           
                       }                        
                    }
                    else if (*iter == "/"){
                        if (j >=2)
                        {
                            int temp = stoi(*(iter -2)) / stoi(*(iter -1));
                            tokens.erase(iter);
                            iter--;
                            tokens.erase(iter);
                            iter--;
                            *iter = to_string((int)floor(temp));
                            j = 1;
                        }
                       else{
                           j = 0;
                           iter = iter - 3;                           
                       }                        
                    }
                
                    else{
                        j++;
                    }
//                cout << "Result at the end of current iteration is:" << *(iter) << endl;
                }
//            cout <<"Result after for loop execution is "<< tokens[0] <<endl ;
        }

        return (stoi(tokens[0]));

    }
};