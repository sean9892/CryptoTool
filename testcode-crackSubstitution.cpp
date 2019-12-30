#include"crypto.hpp"
#include<stdio.h>
#include<iostream>
#include<vector>

int main(void){
	std::string s;
	std::cout<<"INPUT: ";
	std::cin>>s;
	std::cout<<"Frequency Analyze...\n";
	std::vector<int> freq(crypto::countFreq(s));
	int cnt=0;
	for(int i=0;i<26;i++)cnt+=freq[i];
	for(int i=0;i<26;i++){
		std::cout<<(char)('a'+i)<<"|[";
		for(int j=0;j<freq[i];j++)std::cout<<"=";
		for(int j=0;j<cnt-freq[i];j++)std::cout<<" ";
		std::cout<<"]|\n";
	}
	std::cout<<"Guessed Result: "<<crypto::guessSubs(s);
}
