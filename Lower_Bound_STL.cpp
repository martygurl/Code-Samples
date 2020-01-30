/*********************************************************************************************************************************************************************
 * You are given N integers in sorted order. Also, you are given Q queries. In each query, you will be given an integer and you have to tell 
 * whether that integer is present in the array. If so, you have to tell at which index it is present and if it is not present, you have to 
 * tell the index at which the smallest integer that is just greater than the given number is present.
 * 
 * Input Format:
 * The first line of the input contains the number of integers N. The next line contains N integers in sorted order. 
 * The next line contains Q, the number of queries. Then Q lines follow each containing a single integer Y. 
 * Note that if the same number is present multiple times, you have to print the first index at which it occurs. 
 * Also, the input is such that you always have an answer for each query.
 * 
 * Constraints:
 * 1 <= N <= 10^5
 * 1 <= X(i) <= 10^9, where X(i) is the i-th element in the array
 * 1 <= Q <= 10^5
 * 1 <= Y <= 10^9
 * 
 * Output Format:
 * For each query you have to print "Yes" (without the quotes) if the number is present and at which index(1-based) it is present separated by a space.
 * If the number is not present you have to print "No" (without the quotes) followed by the index of the next smallest number just greater than that number.
 * You have to output each query in a new line.
 * 
 * Example Input:
 * 8
 * 1 1 2 2 6 9 9 15
 * 4
 * 1
 * 4
 * 9
 * 15
 * 
 * Example Output:
 * Yes 1
 * No 5
 * Yes 6
 * Yes 8
 * ******************************************************************************************************************************************************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
   int length, num;
   cin >> length;
   vector<int> numbers;

   for (int i = 0; i < length; i++)
   {
       cin >> num;
       numbers.push_back(num);
   }

   int queries, find;
   cin >> queries;
   for (int i = 0; i < queries; i++)
   {
       cin >> find;
       vector<int>::iterator low = lower_bound(numbers.begin(), numbers.end(), find);
       if (numbers[low - numbers.begin()] == find)
       {
           cout << "Yes " << (low - numbers.begin()+1) << endl;
       }
       else
       {
           cout << "No " << (low - numbers.begin()+1) << endl;
       }
   }
   return 0;
}