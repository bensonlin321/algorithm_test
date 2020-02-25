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
            arrow_cnt++;
            a.erase(i);
        }
        else{
            // remove the specific character
            if (arrow_cnt > 0){
                a.erase(i);
            }
            arrow_cnt--;
        }
    }
    //printf("\n\n===\n\n%s\n\n", temp.c_str());
    printf("\n%s\n", a.c_str());
    return a;
}

bool isEqual(std::string a, std::string b){
    if (!_parseString(a).compare(_parseString(b))){
        return true;
    }
    else{
        return false;
    }
}

bool isEqualVer2(char *a, int a_len, char* b, int b_len){
    char *ap;
    char *bp;
    int rec_a = 0, rec_b = 0;
    int a_arrow_cnt = 0, b_arrow_cnt = 0;
    int total_len = a_len > b_len ? a_len - 1 : b_len - 1;

    ap = &a[a_len - 1];
    bp = &b[b_len - 1];

    for (int i = total_len; i >= 0; i--){
        // a string
        if (i >= 0 && i < a_len){
            if (a[i] == '<'){
                a_arrow_cnt++;
            }
            else{
                if (a_arrow_cnt == 0){
                    rec_a = i;
                    ap = &a[i];
                }
                a_arrow_cnt--;
            }
        }

        // b string
        if (i >= 0 && i < b_len){
            if (b[i] == '<'){
                b_arrow_cnt++;
            }
            else{
                if (b_arrow_cnt == 0){
                    rec_b = i;
                    bp = &b[i];
                }
                b_arrow_cnt--;
            }
        }
    }

    if (rec_a != rec_b){
        return false;
    }
    // rec_a == rec_b
    for (int i = 0; i <= rec_a; i++){
        if (ap[0] != bp[0]){
            return false;
        }
        ap--;
        bp--;
    }
    return true;
}


void alg_func1(){
    printf("Given a string with \"a~z\" and \"<\" that represent you type the keyboard (\"<\" means backspace).\
		   		\nFor example, \"abc<<dd<<\" represents \"a\", and \"zzz<<<\" represents \"\".");
}

int main(int argc, char* argv[])
{
    // ========== alg_func1 ==========
    alg_func1();
    std::string a = "ab<c<<dd<";
    std::string b = "azzzz<<<<";
    bool eq = isEqual(a, b);
    printf("\n====== Result ======\n");
    printf("equal? %s\n", eq ? "yes" : "no");
    // ===============================

    // Can you avoid using extra O(n) space and avoid modifying the input string?
    char test_a[] = "aab<c<<dd<";
    char test_b[] = "bazzb<zz<<<<";
    eq = isEqualVer2(test_a, strlen(test_a), test_b, strlen(test_b));
    printf("\n====== Result ======\n");
    printf("equal? %s\n", eq ? "yes" : "no");
    system("pause");
    return 0;
}

