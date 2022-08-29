#include<iostream>
#include <bitset>
#include <stack>

template<std::size_t Size>
class A
{

 public:
    int m_i;
    int m_N;
    std::bitset<Size> m_bitset;
    A(int i, int N) : m_i(i-1), m_N(N), m_bitset(std::bitset<Size>(i-1)) {
    }
    bool check_good(){
        std::stack<bool> mystack;
        if (m_bitset.count() != m_N/2)
            return false;
        for (int i = 0; i < m_N; i++){
            // std::cout << "m_bitset[" << i << "]:" << m_bitset[i] << std::endl;
            if (m_bitset[i])
                mystack.push(m_bitset[i]);
            else if (mystack.size() > 0)
                mystack.pop();
            else
                return false;
        }
        if (mystack.empty())
            return true;
        else
            return false;

    }
    // needs body 
    friend std::ostream & operator<<( std::ostream & Out , int)
    {
        return Out;
    }
};

char parenthesis(char in) {return (in == '0') ? '(' : ')'; }
template<std::size_t Size>
std::ostream& operator<<(std::ostream& out, const A<Size>& a) // overload for xyz not int
{
    std::string binary = std::bitset<Size>(a.m_i).to_string().substr(Size - a.m_N, Size);
    for (auto c : binary){
        out << parenthesis(c);
    }
    // out<< " => " << binary; // use out not cout
    return out;  // and don't forget to return out as well
}
int main(){
	int N;
	std::cin >> N;
    N *=2;
	for (int i = 0; i < 2 << (N-1); i++){
		A<23> a(i, N);
        if (a.check_good() ) std::cout << a << std::endl;
    }
}
