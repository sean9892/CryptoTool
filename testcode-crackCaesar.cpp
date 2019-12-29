/**crackCaesar Test Code**/
#include<stdio.h>
#include<iostream>
#include<string>
#include"crypto.hpp"

int main(){
	std::string inp;
	std::cout<<"INPUT: ";
	std::cin>>inp;
	int cnt=0;
	for(std::string s:crypto::crackCaesar(inp)){
		std::cout<<++cnt<<" SHIFT: "<<s<<"\n";
	}
}
