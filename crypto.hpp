#pragma once
#ifndef __CDQ_CRYPTO__
#define __CDQ_CRYPTO__
#endif

/***
Crypto Tools
- by CDQ
LOG
- crack Caesar : 2019/12/30~2019/12/30
- crack Substitution : 2019/12/30~2019/12/30
***/

#include<string>
#include<vector>
#include<queue>
#include<utility>
#include<map>

namespace crypto{
	using uint = unsigned int;
	
	/**
	Crack Caesar cryptogram
	- Shift all alphabets 26 times.
	**/
	std::vector<std::string> crackCaesar(std::string str){
		#define isAlpha(x) ('a'<=((x)|32)&&((x)|32)<='z')
		#define cti(x) (((x)|32)-'a')
		#define isSmall(x) (((x)&32)?1:0)
		std::vector<std::string> res;
		const uint ss=str.size();
		for(uint i=0;i<26;i++){
			for(uint j=0;j<ss;j++){
				if(isAlpha(str[j])){
					uint c=cti(str[j]);
					str[j]=(char)((c+1)%26+'A'+(isSmall(str[j])<<5));
				}
			}
			res.push_back(str);
		}
		#undef isAlpha
		#undef cti
		#undef isSmall
		
		return res;
	}
	
	/**
	Crack Substitution cryptogram
	- Count alphabet & use frequency table
	- Low Accuracy
	**/
	std::vector<int> countFreq(std::string s){
		#define isAlpha(x) ('a'<=((x)|32)&&((x)|32)<='z')
		#define cti(x) (((x)|32)-'a')
		std::vector<int> v(26,0);
		for(int i:s)++v[cti(i)];
		#undef cti
		#undef isAlpha
		
		return v;
	}
	std::string guessSubs(std::string s){
		#define isAlpha(x) ('a'<=((x)|32)&&((x)|32)<='z')
		#define isSmall(x) (((x)&32)?1:0)
		std::vector<int> v(countFreq(s));
		const std::string freqord = "etaoinsrhdlucmfywgpbvkxqjz";
		std::priority_queue<std::pair<int,char>> pq;
		for(int i=0;i<26;i++){
			pq.push(std::pair<int,char>(v[i],'a'+i));
		}
		std::map<char,char> tp;
		for(int i=0;i<26;i++){
			tp[pq.top().second]=freqord[i];
			pq.pop();
		}
		for(int i=0;i<s.size();i++){
			if(isAlpha(s[i])){
				if(isSmall(s[i])){
					s[i]=tp[s[i]];
				}
				else{
					s[i]=tp[s[i]|32];
					s[i]&=~32;
				}
			}
		}
		#undef isAlpha
		#undef isSmall
		
		return s;
	}
}
