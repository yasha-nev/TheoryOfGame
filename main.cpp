#include "Criteria.hpp"

int main(int argc, const char * argv[]) {
    try{
        
        if (argc < 2){
            throw std::string("empty path to matrix file");
        }
        
        Matrix mat(argv[1]);
        
        std::map<size_t, int> m;
        
        mat.print();
        
        Bayes bayes(mat);
        m[bayes.fix()] += 1;
        
        Valde valde(mat);
        m[valde.fix()] += 1;
        
        Sevidge sevidge(mat);
        m[sevidge.fix()] += 1;
        
        float h;
        std::cout << "add h parametr: ";
        std::cin >> h;
        
        if (std::cin.fail()){
            throw std::string("Wrong parametr");
        }
        
        Gurvice gurvice(mat, h);
        m[gurvice.fix()] += 1;
        
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
