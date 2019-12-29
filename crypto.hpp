#pragma once
#ifndef __CDQ_CRYPTO__
#define __CDQ_CRYPTO__
#endif

/***
Crypto Tools
- by CDQ

LOG
- crack Caesar : 2019/12/30~2019/12/30
***/

#include<string>
#include<vector>

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
}
