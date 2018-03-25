#include <iostream>
#include <vector> 
using namespace std; 

int lengthOfLongestSubstring(string word); 
int findLongest(const int& startIndex, const string& word); 

int main()
{

	cout << lengthOfLongestSubstring("dvdf") << endl;
	return 0; 
}


int lengthOfLongestSubstring(string word)
{
	if (word.length() == 0)
        {
            return 0; 
        }
        int result = 1;
        int count = 0; 
        for (int k = 0; k < word.length() - 1; k++)
        { 
            count = findLongest(k, word); 
            result = max(result, count);
        }
        return result;
}

int findLongest(const int& startIndex, const string& word)
{
	int result = 1; 
        int count = 0; 
        vector<bool> list(128, false);
        for (int i = startIndex; i < word.length(); i++)
        {
            int temp = word[i];
            if (list[temp])
            {   
                result = max(count, result);
                for (int j = 0; j < 128; j++)
                {
                    if (list[j])
                    {
                        list[j] = false;
                    }
                }
                count = 1;     
            }
            else
            {
                count++;
            }
            list[temp] = true;
        }
        result = max(count, result); 
        return result; 
}


