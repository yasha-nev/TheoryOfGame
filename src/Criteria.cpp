#include "Criteria.hpp"

Bayes::Bayes(const Matrix &matrix){
    if (matrix.empty()){
        throw std::string("Matrix is empty");
    }
    mat = matrix;
    alpha.resize(mat.rows());
}

size_t Bayes::fix(){
    size_t strategy;
    
    for (size_t i = 0; i < alpha.size(); i++){
        if (mat.probExist()){
            size_t j = 0;
            
            auto prob_sum = [&](float left, float rigth){
                float res = left + rigth * mat.probability(j);
                j++;
                return res;
            };
            
            alpha[i] = std::accumulate(mat.colBegin(i), mat.colEnd(i), 0, prob_sum);
        }
        else{
            alpha[i] = std::accumulate(mat.colBegin(i), mat.colEnd(i), 0) / static_cast<float>(mat.colums());
        }
    }
    
    if (mat.matType()){
        strategy = std::distance(alpha.begin(), std::min_element(alpha.begin(), alpha.end()));
    }
    else{
        strategy = std::distance(alpha.begin(), std::max_element(alpha.begin(), alpha.end()));
    }
    
    std::cout << "The best strategy by Bayes: A" << strategy + 1 << std::endl;
    
    return strategy;
}

Valde::Valde(const Matrix &matrix){
    if (matrix.empty()){
        throw std::string("Matrix is empty");
    }
    
    mat = matrix;
    alpha.resize(mat.rows());
}

size_t Valde::fix(){
    size_t strategy;
    
    
    if (mat.matType()){
        for (size_t i = 0; i < alpha.size(); i++){
            alpha[i] = *std::max_element(mat.colBegin(i), mat.colEnd(i));
        }
        
        strategy = std::distance(alpha.begin(), std::min_element(alpha.begin(), alpha.end()));
    }
    else{
        for (size_t i = 0; i < alpha.size(); i++){
            alpha[i] = *std::min_element(mat.colBegin(i), mat.colEnd(i));
        }
        
        strategy = std::distance(alpha.begin(), std::max_element(alpha.begin(), alpha.end()));
    }
    
    std::cout << "The best strategy by Valde: A" << strategy + 1 << std::endl;
    
    return strategy;
}

Sevidge::Sevidge(const Matrix &matrix){
    if (matrix.empty()){
        throw std::string("Matrix is empty");
    }
    
    mat = matrix;
    alpha.resize(mat.rows());
}

size_t Sevidge::fix(){
    size_t strategy;
    
    if (mat.matType()){
        Matrix res = winMatrix(mat);
        for (size_t i = 0; i < alpha.size(); i++){
            alpha[i] = *std::max_element(res.colBegin(i), res.colEnd(i));
        }
        
        strategy = std::distance(alpha.begin(), std::min_element(alpha.begin(), alpha.end()));
    }
    else{
        Matrix res = loseMatrix(mat);
        for (size_t i = 0; i < alpha.size(); i++){
            alpha[i] = *std::min_element(res.colBegin(i), res.colEnd(i));
        }
        
        strategy = std::distance(alpha.begin(), std::max_element(alpha.begin(), alpha.end()));
    }
    
    std::cout << "The best strategy by Sevidge: A" << strategy + 1 << std::endl;
    
    return strategy;
}

Gurvice::Gurvice(const Matrix &matrix, float h){
    if (matrix.empty()){
        throw std::string("Matrix is empty");
    }
    H = h;
    alpha.resize(mat.rows());
}

size_t Gurvice::fix(){
    size_t strategy;
    
    if (mat.matType()){
        for (size_t i = 0; i < alpha.size(); i++){
            float min = static_cast<float>(*std::min_element(mat.colBegin(i), mat.colEnd(i)));
            float max = static_cast<float>(*std::max_element(mat.colBegin(i), mat.colEnd(i)));
            
            alpha[i] = H * min + (1 - H) * max;
        }
        
        strategy = std::distance(alpha.begin(), std::max_element(alpha.begin(), alpha.end()));
    }
    else{
        for (size_t i = 0; i < alpha.size(); i++){
            float min = static_cast<float>(*std::min_element(mat.colBegin(i), mat.colEnd(i)));
            float max = static_cast<float>(*std::max_element(mat.colBegin(i), mat.colEnd(i)));
            
            alpha[i] = H * max + (1 - H) * min;
        }
        
        strategy = std::distance(alpha.begin(), std::min_element(alpha.begin(), alpha.end()));
    }
    std::cout << "The best strategy by Gurvice: A" << strategy + 1 << std::endl;
    
    return strategy;
}
