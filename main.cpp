#include "Criteria.hpp"

int main(int argc, const char * argv[]) {
    try{
        
        if (argc < 2){
            throw std::string("empty path to matrix file");
        }
        
        Matrix mat(argv[1]);
        
        std::map<size_t, int> m;
        size_t strategy;
        
        mat.print();
        
        Bayes bayes(mat);
        strategy = bayes.fix();
        m[strategy] += 1;
        
        Valde valde(mat);
        strategy = valde.fix();
        m[strategy] += 1;
        
        Sevidge sevidge(mat);
        strategy = sevidge.fix();
        m[strategy] += 1;
        
        Gurvice gurvice(mat, 0.5);
        strategy = gurvice.fix();
        m[strategy] += 1;
        
        auto res = std::max_element(m.begin(), m.end(),[] (const std::pair<char,int>& a, const std::pair<char,int>& b){
            return a.second < b.second;
        });
        
        std::cout << "The best strategy: A" << res->first + 1 << std::endl;
        
    }
    catch (std::string error)
    {
       std::cout << error << std::endl;
    }
    
    return 0;
}
