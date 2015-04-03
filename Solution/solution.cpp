#include "solution.h"


Solution::Solution()
{

}

Solution::~Solution()
{

}

std::vector<std::string> Solution::findRepeatedDnaSequences(std::string s)
{
    std::vector<std::string> result;
    std::unordered_map<int,int> hashmap;

    int size=s.size();

    if(size>10)
    {
        for(int i =0;i<size-9;i++)
        {
            int V=0;

            for(int j=i;j<i+10;j++)
            {
                V <<= 3;
                V|=s[j]&7;
            }            

            if(hashmap[V]++==1)
            {
                result.push_back(s.substr(i,10));
            }
        }
    }

    return result;
}

std::vector<std::vector<int>> Solution::generate(int numRows)
{
    std::vector<std::vector<int>> result;
    if(numRows>=1)
    {
        for(int i=1;i<=numRows;i++)
        {
            std::vector<int> tempRow;
            for(int j=1;j<=i;j++)
            {
                if(j==1||j==i)
                {
                    tempRow.push_back(1);
                }
                else
                {
                    tempRow.push_back(result[i-2][j-2]+result[i-2][j-1]);
                }
            }
            result.push_back(tempRow);
        }
        return result;
    }
    else
    {
        return result;
    }
}

int Solution::compareVersion(std::string version1, std::string version2)
{

    std::vector<std::string> strs1;
    for(int i=0,j=0;i<version1.size();i++)
    {
        if(version1[i]=='.')
        {
            strs1.push_back(version1.substr(j,i-j));
            j=i+1;
        }
        else if(i==version1.size()-1)
        {
            strs1.push_back(version1.substr(j,version1.size()-j));
        }
    }

    std::vector<std::string> strs2;
    for(int i=0,j=0;i<version2.size();i++)
    {
        if(version2[i]=='.')
        {
            strs2.push_back(version2.substr(j,i-j));
            j=i+1;
        }
        else if(i==version2.size()-1)
        {
            strs2.push_back(version2.substr(j,version2.size()-j));
        }
    }

    std::vector<int> number1;
    for(std::vector<std::string>::iterator it=strs1.begin();it!=strs1.end();it++)
    {
        number1.push_back((std::stoi(*it)));
    }

    std::vector<int> number2;
    for(std::vector<std::string>::iterator it=strs2.begin();it!=strs2.end();it++)
    {
        number2.push_back((std::stoi(*it)));
    }

    if(number1.size()<number2.size())
    {
        int diff=number2.size()-number1.size();
        for(int i=0;i<diff;i++)
        {
            number1.push_back(0);
        }
    }
    else if(number1.size()>number2.size())
    {
        int diff=number1.size()-number2.size();
        for(int i=0;i<diff;i++)
        {
            number2.push_back(0);
        }
    }

    for(int i=0;i<number1.size();i++)
    {
        if(number1[i]>number2[i])
        {
            return 1;
        }
        else if(number1[i]<number2[i])
        {
            return -1;
        }
        else
        {
            if(i==number1.size()-1)
            {
                return 0;
            }
            else
            {
                continue;
            }
        }
    }

    return 1;
}

ListNode* Solution::getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *HeadA=new ListNode(2);

    ListNode *iterator=HeadA;

    for(int i=1;i<=6;i++)
    {
        while(iterator->next!=NULL)
        {
            iterator=iterator->next;
        }
        iterator->next=new ListNode(i);
    }

    ListNode HeadB=2;

    iterator=&HeadB;

    for(int i=4;i<=10;i++)
    {
        while(iterator->next!=NULL)
        {
            iterator=iterator->next;
        }
        iterator->next=new ListNode(i);
    }
}


bool Solution::isPalindrome(std::string s)
{
    std::vector<int> NumberList;
    for(std::string::iterator it=s.begin();it!=s.end();it++)
    {
        //int v=*it;
        if(*it>=65&&*it<=90)
        {
            NumberList.insert(NumberList.end(),*it);
        }
        else if(*it>=97&&*it<=122)
        {
            NumberList.insert(NumberList.end(),*it-32);
        }
        else if(*it>=48&&*it<=57)
        {
            NumberList.insert(NumberList.end(),*it);
        }
    }

    int length=NumberList.size();
    int midpoint=length/2;
    for(int i=0;i<midpoint;i++)
    {
        if(NumberList[i]!=NumberList[length-i-1])
        {
            return false;
        }
    }

    return true;
}

bool Solution::isPalindrome_2(std::string s)
{
    int i=0;
    int j=s.size()-1;
    int a=0;
    int b=0;
    while(i<j)
    {
        while(!(s[i]>=48&&s[i]<=57||s[i]>=65&&s[i]<=90||s[i]>=97&&s[i]<=122)&&i<s.size())
        {
            i++;
        }
        if(s[i]>=97&&s[i]<=122)
        {
            a=s[i]-32;
        }
        else
        {
            a=s[i];
        }

        while(!(s[j]>=48&&s[j]<=57||s[j]>=65&&s[j]<=90||s[j]>=97&&s[j]<=122)&&j>=0)
        {
            j--;
        }
        if(s[j]>=97&&s[j]<=122)
        {
            b=s[j]-32;
        }
        else
        {
            b=s[j];
        }

        if(a!=b&&(a>=65&&a<=90||a>=48&&a<=57)&&(b>=65&&b<=90||b>=48&&b<=57))
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

bool Solution::isPalindrome_3(std::string s)
{
    std::string::iterator it=s.begin();
    std::string::reverse_iterator jt=s.rbegin();
    int i=0;
    int j=s.size()-1;
    int a=0;
    int b=0;
    while(i<j)
    {
        while(!(*it>=48&&*it<=57||*it>=65&&*it<=90||*it>=97&&*it<=122)&&it!=s.end())
        {
            it++;
            i++;
        }
        if(*it>=97&&*it<=122)
        {
            a=*it-32;
        }
        else
        {
            a=*it;
        }

        while(!(*jt>=48&&*jt<=57||*jt>=65&&*jt<=90||*jt>=97&&*jt<=122)&&jt!=s.rend())
        {
            jt++;
            j--;
        }
        if(*jt>=97&&*jt<=122)
        {
            b=*jt-32;
        }
        else
        {
            b=*jt;
        }

        if(a!=b&&(a>=65&&a<=90||a>=48&&a<=57)&&(b>=65&&b<=90||b>=48&&b<=57))
        {
            return false;
        }
        it++;
        i++;
        jt++;
        j--;
    }
    return true;
}

long double Solution::combination(int InputA, int InputB)
{
    if(InputB==0)
    {
        return 1;
    }
    else if(InputB==1)
    {
        return InputA;
    }
    else
    {
        long double multi1=1;
        for(int i =InputA-InputB+1;i<=InputA;i++)
        {
            multi1*=i;
        }

        long double multi2=1;
        for(int i =1;i<=InputB;i++)
        {
            multi2*=i;
        }

        return multi1/multi2;
    }
}

std::vector<int> Solution::getRow(int rowIndex)
{
    std::vector<int> result1;

    if(rowIndex==0)
    {
        result1.push_back(1);
        return result1;
    }

    for(int i=0;i<=rowIndex/2;i++)
    {
        if(i==0||i==rowIndex)
        {
            result1.push_back(1);
        }
        else if(i==1||i==rowIndex-1)
        {
            result1.push_back(rowIndex);
        }
        else
        {
            result1.push_back((long double)combination(rowIndex,i));
        }
    }

    std::vector<int> result2;

    if(rowIndex%2==1)
    {
        for(std::vector<int>::reverse_iterator it=result1.rbegin();it!=result1.rend();it++)
        {
            result2.push_back(*it);
        }
    }

    if(rowIndex%2==0)
    {
        for(std::vector<int>::reverse_iterator it=result1.rbegin()+1;it!=result1.rend();it++)
        {
            result2.push_back(*it);
        }
    }

    for(std::vector<int>::iterator it=result2.begin();it!=result2.end();it++)
    {
        result1.push_back(*it);
    }

    return result1;
}

bool Solution::hasPathSum(TreeNode *root, int sum)
{

    static bool found=false;

    if(sum-root->val==0 && root->left==NULL && root->right==NULL)
    {
        found=true;
    }
    else
    {
        if(root->left!=NULL)
        {
            hasPathSum(root->left,sum-root->val);
        }

        if(root->right!=NULL)
        {
            hasPathSum(root->right,sum-root->val);
        }
    }

    return found;
}












