/**
 * problem:
 * Given a string, write a function to check
 * if it is a permutation of a palindrome.
 * example:
 * input: Tactcoa
 * output: true
 */

/*
 * Solution: palindrome <==> at most one bit in the bitVector is set to 1.
 * bit operation : for each char, flip correspounding bit
 * time : O(n)
 * space : O(1)
 */
#include<iostream>
#include<string>

using namespace std;

int getCharNum(char ch){
	if(ch >= 'A' && ch <= 'Z')
		ch -= 32;
	return ch - 'a';
}

void toggle(int& bitVector, int index){
	int mask = 1 << index;

	if(bitVector & mask) // the bit is 1
		bitVector &= ~mask;
	else  // the bit is 0
		bitVector |= mask;
}

bool isPermutationOfPalindrome(string phase){
	int bitVector = 0;

	for(char ch : phase){
		int index = getCharNum(ch);
		toggle(bitVector, index);
	}
	return !bitVector || !(bitVector&bitVector-1);
}
int main()
{
	string phase = "Tactcoa";
	cout << isPermutationOfPalindrome(phase) << endl;
	phase = "Tactca";
	cout << isPermutationOfPalindrome(phase) << endl;
	phase = "Tactcb";
	cout << isPermutationOfPalindrome(phase) << endl;
	return 0;
}
