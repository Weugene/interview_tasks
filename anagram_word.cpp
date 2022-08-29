#include <iostream>
#include <string>

int main(int argc, char *argv[]){
	std::string s1, s2;
	std::cin >> s1;
	std::cin >> s2;
	if (s1.size() != s2.size()){
    	std::cout << 0;
        return 0;
    }
	int N = s1.size();
    int j;
	for (int i = 0, j = N - 1; i < N; i++){
        if (s1[i] != s2[j] ){
            std::cout << 0;
            return 0;
        }
    	j--;
    }
 	std::cout << 1;
}
