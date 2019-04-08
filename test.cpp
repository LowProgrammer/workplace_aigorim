#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <string>
#include "aigorithm.cpp"

using namespace std;

void quick_sort(int arr[], int low, int heigh);
void print_arr(int a[], int size_arr);
int partition(int arr[], int low, int heigh);
string removePar(string s, int x);
/**
 * leecode 771
**/
int numJewelsInStones(string J, string S)
{
    int num = 0;
    int jell[60] = {0};
    int len1 = J.length();
    int len2 = S.length();
    if (!len1 || !len2)
        return 0;
    for (int i = 0; i < len1; i++)
    {
        if (jell[(int)J[i] - 65] == 0)
            jell[(int)J[i] - 65] = 1;
    }

    for (int i = 0; i < len2; i++)
    {
        if (jell[((int)S[i]) - 65] == 1)
            num++;
    }
    return num;
}
/**
 * leecode 709
**/
string toLowerCase(string str)
{
    int len = str.length();
    string result = "";
    for (int i = 0; i < len; i++)
    {
        if ((int)str[i] <= 90 && (int)str[i] >= 65)
        {
            //result+=(char)((int)str[i]+32);
            str[i] = (char)((int)str[i] + 32);
        }
        // else
        // {
        //     result+=str[i];
        // }

        /* code */
    }
    return str;
}
/**
 * leecode 804
 * 
 * */
int uniqueMorseRepresentations(vector<string> &words)
{
    string ch[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    vector<string> result;
    set<string> result_set;
    int len = words.size();
    cout << len << (int)'a' << "123" << endl;
    int num = 0, index1 = 97;

    for (int i = 0; i < len; i++)
    {
        string str = "";
        string demoS = words[i];
        for (int j = 0; j < demoS.length(); j++)
        {
            str += ch[(int)(demoS[j]) - 97];
        }
        result.push_back(str);
        result_set.insert(str);
        //cout<<num++<<str<<endl;
    }
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    for (int k = 0; k < result.size(); k++)
    {
        cout << result[k] << endl;
    }
    num = result.size();
    return result_set.size();
}

/**
 * leecode 929 
 * 
 * */
int numUniqueEmails(vector<string> &emails)
{
    int len = emails.size();
    set<string> result;
    stack<char> str;
    for (int i = 0; i < len; i++)
    {
        string name = "";
        cout << emails[i] << endl;
        //bool is_name=false;
        int pos = emails[i].find('@');
        //cout<<"pos:"<<pos<<endl;
        int len2 = emails[i].length();

        for (int j = 0; j < pos; j++)
        {

            if (emails[i][j] == '.')
                continue;
            if (emails[i][j] == '+')
            {
                break;
            }
            name += emails[i][j];
            //str.push(emails[i][j]);
        }
        for (int j = pos; j < len2; j++)
        {
            //str.push(emails[i][j]);
            name += emails[i][j];
        }
        // while(!str.empty()){
        //     name=str.top()+name;
        //     str.pop();
        // }
        cout << name << endl;
        result.insert(name);
    }
    return result.size();
}

/**
 * leecode 961
 * 
 * */

int repeatedNTimes(vector<int> &A)
{
    int len = A.size();
    int num = 1, id;
    id = A[0];
    cout << "id-->" << id << endl;
    int ind = 0;
    for (int i = 1; i < len; i++)
    {

        if (A[i] == id)
        {
            num++;
        }
        else
        {
            num--;
            if (num < 0)
            {
                for (int j = 0; j < len; j++)
                {
                    if (A[j] == A[i])
                        ind++;
                }
                if (ind >= len / 2)
                {
                    id = A[i];
                    break;
                }
                else
                {
                    id = A[i + 1];
                    i++;
                    num = 1;
                }
            }
        }
        cout << "id-->" << id << endl;
    }
    cout << "id: " << id << endl;
    return id;
}

/**
 * leecode 977
 * 
 * */
vector<int> sortedSquares(vector<int> &A)
{
    vector<int> reuslt;
    int len = A.size();
    int num[10000];
    //cout<<len<<endl;
    for (int i = 0; i < len; i++)
    {
        num[i] = A[i] * A[i];
        //  cout<<num[i]<<endl;
    }
    quick_sort(num, 0, len - 1);
    for (int i = 0; i < len; i++)
    {
        reuslt.push_back(num[i]);
    }
    print_arr(num, len);
    return reuslt;
}
/**
 * leecode 905
 * 
 * */
vector<int> sortArrayByParity(vector<int> &A)
{
    // int arr[5000];
    // vector<int> result;
    int len = A.size();
    int index_l = 0, index_r = 0;
    // for(int i = 0; i < len; i++)
    // {
    //     if(A[i]%2==0){
    //         result.push_back(A[i]);
    //     }else
    //     {
    //         arr[index++]=A[i];
    //     }

    // }
    // index--;
    // while(index>=0){
    //     result.push_back(arr[index--]);
    // }
    // for(int i = 0; i < result.size(); i++)
    // {
    //     cout<<result[i]<<endl;
    // }
    /**
         * 第二种
         **/
    vector<int> re(len);
    for (int i = 0; i < len; i++)
    {
        if (A[i] % 2 == 0)
        {
            re[index_l++] = A[i];
        }
        else
        {
            re[len - 1 - (index_r++)] = A[i];
        }
    }
    for (int i = 0; i < re.size(); i++)
    {
        cout << re[i] << endl;
    }
    return re;
}
/**
 *leecode  832
 * 
 **/
vector<vector<int> > flipAndInvertImage(vector<vector<int> > &A)
{
    //vector<vector<int>> result;
    int tmp;
    int len = A.size(), len_in = (tmp = A[0].size()) % 2 ? (tmp + 1) / 2 : tmp / 2;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len_in; j++)
        {
            int te = A[i][j];
            A[i][j] = !A[i][tmp - j - 1];
            A[i][tmp - j - 1] = !te;
        }
    }

    return A;
}

/**
 *  leecode 657 
 * 
 **/
bool judgeCircle(string moves)
{
    int pos_x = 0, pos_y = 0; //U D L R
    int len = moves.length();
    for (int i = 0; i < len; i++)
    {
        if (moves[i] == 'U')
            pos_y++;
        if (moves[i] == 'D')
            pos_y--;
        if (moves[i] == 'L')
            pos_x--;
        if (moves[i] == 'R')
            pos_x++;
    }
    return (pos_x == 0 && pos_y == 0) ? true : false;
}
/**
 * leecode 1021
 * 这个题可以可以改成递归求字符串
 * */
string removeOuterParentheses(string S)
{
    //if(S.compare("()"))return "()";
    //stack<char> str;
    int len = S.length();
    string result;
    int index = 0, str_l = 0, str_r;
    for (int i = 0; i < len; i++)
    {
        if (S[i] == '(')
            index++;
        if (S[i] == ')')
            index--;
        if (index == 0)
        {
            int tmp = str_l;
            str_l = i;
            int len_son = i - tmp;
            //cout << result << " ->" << tmp << " len =" << len_son << endl;
            
            if (tmp == 0)
            {
                //cout<<S.substr(tmp, len_son + 1)<<endl;
                result += removePar(S.substr(tmp, len_son + 1), len_son + 1);
            }    
            else
            {
                //cout<<S.substr(tmp+1, len_son )<<endl;
                result += removePar(S.substr(tmp+1, len_son), len_son);
            }
        }
    }
    //cout<<result<<endl;
    return result;
}
string removePar(string S, int size)
{
    if (S == "()")
        return "";
    else
    {
        return S.substr(1, size - 2);
    }
}
int main()
{
    // char test[]="1234";
    // cout<<test[1]<<strlen(test);
    // cout<<"qwe"<<(int)'A'<<"   "<<(int)'z'<<(int)'a'<<(int)'Z'<<endl;
    // cout<<numJewelsInStones("aAZz","aaaasadhkjhffahdjakaaaZZZfslkahZfGSHGDJGBMCKHUIZZZZZZFFzA");
    // cout<<endl;
    // cout<<toLowerCase("HEshdkhHJSHDBCOIWYEHCKAJSDK");

    // string ss[]={"gin", "zen", "gig", "msg"};
    // vector<string> s(ss,ss+4);
    // cout<<uniqueMorseRepresentations(s);

    //string ss[]={"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
    // string ss[] = {"test.email+alex@leetcode.com", "test.email@leetcode.com"};
    // vector<string> emails(ss, ss + 2);
    // cout << numUniqueEmails(emails);

    // int nu[] = {1,6,6,9};
    // vector<int> num(nu, nu +  4);
    // cout << repeatedNTimes(num);

    // int nu[] = {-8,-6,-4,-2,0,1,3,5,7};
    // vector<int> num(nu, nu +  9);
    // sortedSquares(num);

    // int nu[] = {3,1,2,4};
    // vector<int> num(nu, nu +  4);

    // vector<int> s=sortArrayByParity(num);
    // int tmp,s=(tmp=4)%2?(tmp+1)/2:tmp/2;
    // cout<<(!0)<<"   "<<s;

    // cout<<judgeCircle("LLLLRRUDDRR");
    
    // cout << removeOuterParentheses("()()") << endl;
    // string s = "asdfg";
    // cout << s.substr(1, 3);
    return 0;
}
