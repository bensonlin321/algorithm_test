#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <string>
std::string _parseString(std::string a){
	//char *p = &a[a.length()-1];
	// record all < and remove the specific character
	int arrow_cnt = 0;
	int total_len = a.length() - 1;
	for (int i = total_len ; i >= 0; i--){
		if (a.at(i) == '<'){
			a.erase(i);
			arrow_cnt++;
			//*p = ' ';
			//p--;
		}
		else{
			if (arrow_cnt > 0){
				arrow_cnt--;
				// remove the specific character
				a.erase(i);
				//*p = ' ';
				//p--;
			}
		}
	}
	//printf("\n\n===\n\n%s\n\n", temp.c_str());
	printf("\n%s\n", a.c_str());
	return a;
}
bool isEqual(std::string a, std::string b){
	if (!a.compare(b)){
		return true;
	}
	else{
		return false;
	}
}
void alg_func1(){
	printf("Given a string with \"a~z\" and \"<\" that represent you type the keyboard (\"<\" means backspace).\
		   		\nFor example, \"abc<<dd<<\" represents \"a\", and \"zzz<<<\" represents \"\".");
}
int main(int argc, char* argv[])
{
	// ========== alg_func1 ==========
	alg_func1();
	std::string a = "abc<<dd<<";
	std::string out1 = _parseString(a);
	std::string b = "azzzz<<<<";
	std::string out2 = _parseString(b);
	bool eq = isEqual(out1, out2);
	printf("\n====== Result ======\n");
	printf("str1: %s, str2: %s\n", out1.c_str(), out2.c_str());
	printf("equal? %s\n", eq ? "yes" : "no");
	// ===============================
	system("pause");
	return 0;
}
