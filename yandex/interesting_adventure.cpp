//use C++20
#include<iostream>
#include <vector>
#include <queue> // FIFO queue
#include <set>
struct C{
    int m_x, m_y;
    C(int x, int y): m_x(x), m_y(y){}
    std::ostream& operator<<(std::ostream& os){
        os << m_x << " " << m_y << "\n";
        return os;
    }
    int length(const C& other)const{
        return abs(other.m_x - m_x) + abs(other.m_y - m_y);
    }
};
std::ostream& operator<<(std::ostream& os, const C& a)
{
     os << a.m_x << " " << a.m_y << "\n";
    return os;
}

struct NW{
    int n;
    int w;
    NW(int n_, int w_): n(n_), w(w_){}
};

int bfs(const int s, const int finish, const std::vector<std::vector<NW>>& adj){
    int N = adj.size();
    std::set<int> visited;
    std::queue<std::pair<int, int>> queue;
    queue.push({s,0});
    while(!queue.empty()){
        auto& [v, count] = queue.front();
        queue.pop();
        if (v == finish) {
            return count;
        }
        // here we run looking up from a vertex v
        for (auto& nw : adj[v]){
            // If a vertex is visited?
            if (!visited.contains(nw.n) ){
                // std::cout << nw.n << " " << v << std::endl;
                // add to the queue
                queue.push({nw.n, count + 1});
            }
        }
    }

    return -1;
}

int taxicabLength(const int i, const int j, const std::vector<C>& coord){
    return coord[i].length(coord[i]);
}

int main(){
	int N;
	std::cin >> N;
    std::vector<C> coord;
    coord.reserve(N);
    int x, y;
	for (int i = 0; i < N; i++){
        std::cin >> x >> y; // (2≤n≤1000)
		coord.emplace_back(x, y);
        // std::cout << coord[i];
    }
    int k;
    std::cin >> k; // k < 2*10^9
    int A, B;
    std::cin >> A >> B;
    A--; B--;

    std::vector<std::vector<NW>> adj;
    adj.resize(N);
    for (int i = 0; i < N; i++){
        // std::cout << "i=" << i << ": [";
        for (int j = 0; j < N; j++){
            int w = coord[i].length(coord[j]);
            if ((i != j) && w <= k){
                adj[i].emplace_back(j, w);
                // std::cout << " " << j;
            }
        }
        // std::cout << " ]" << std::endl;
    }
    auto cost = bfs(A, B, adj);
    std::cout << cost;
}
