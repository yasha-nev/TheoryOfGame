#include "Matrix.hpp"

Matrix::Matrix(){
    r = 0;
    c = 0;
    type = 0;
}

Matrix::Matrix(const std::string &path){
    std::fstream file(path, std::ios_base::in);
    
    if (!file.is_open()){
        throw std::string("file is not exist or busy");
    }
    file >> type;
    file >> r;
    file >> c;
    
    arr.resize(r);
    
    for (size_t i = 0; i < r; i++){
        arr[i].resize(c);
        for (size_t j = 0; j < c; j++){
            int num;
            file >> num;
            arr[i][j] = num;
        }
    }
    
    size_t p;
    file >> p;
    
    if (p){
        prob.resize(r);
        for (size_t i = 0; i < r; i++){
            file >> prob[i];
        }
    }
    
}

Matrix::Matrix(const std::vector<std::vector<int>> &matrix, bool t, std::vector<float> p = {}){
    if (matrix.empty()){
        throw std::string("matrix is empty");
    }
    prob = p;
    type = t;
    arr = matrix;
    r = arr.size();
    c = arr[0].size();
}

size_t Matrix::rows() const{
    return r;
}

size_t Matrix::colums() const{
    return c;
}

bool Matrix::empty() const{
    return arr.empty();
}

std::pair<size_t, size_t> Matrix::size() const{
    return {r, c};
}

bool Matrix::matType() const{
    return type;
}

float Matrix::probability(size_t i) const{
    if (i > r){
        throw "i > r";
    }
    return prob[i];
}

bool Matrix::probExist() const{
    return !prob.empty();
}

std::vector<int>::iterator Matrix::colBegin(size_t i){
    if (i > r){
        throw "i > r";
    }
    
    return arr[i].begin();
}

std::vector<int>::iterator Matrix::colEnd(size_t i){
    if (i > r){
        throw "i > r";
    }
    
    return arr[i].end();
}

void Matrix::print() const{
    for (size_t i = 0; i < r; i++){
        for (size_t j = 0; j < c; j++){
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}

Matrix winMatrix(const Matrix &matrix){
    Matrix res = matrix;
    
    for (size_t j = 0; j < res.c; j++){
        int min = res.arr[0][j];
        for (size_t i = 0; i < res.r; i++){
            min = min > res.arr[i][j] ? res.arr[i][j] : min;
        }
        
        for (size_t i = 0; i < res.r; i++){
            res.arr[i][j] = res.arr[i][j] - min;
        }
    }
    
    return res;
}

Matrix loseMatrix(const Matrix &matrix){
    Matrix res = matrix;
    
    for (size_t j = 0; j < res.c; j++){
        int max = res.arr[0][j];
        for (size_t i = 0; i < res.r; i++){
            max = max > res.arr[i][j] ? max : res.arr[i][j];
        }
        
        for (size_t i = 0; i < res.r; i++){
            res.arr[i][j] = max - res.arr[i][j];
        }
    }
    
    return res;
}
