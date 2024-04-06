#ifndef Matrix_hpp
#define Matrix_hpp

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <fstream>

class Matrix{
public:
    Matrix();
    
    Matrix(const std::string &path);
    
    Matrix(const std::vector<std::vector<int>> &matrix, bool t, std::vector<float> p);
    
    bool empty() const;
    
    size_t rows() const;
    
    size_t colums() const;
    
    std::pair<size_t, size_t> size() const;
    
    void print() const;
    
    bool matType() const;
    
    float probability(size_t i) const;
    
    bool probExist() const;
    
    std::vector<int>::iterator colBegin(size_t i);
    
    std::vector<int>::iterator colEnd(size_t i);
    
    friend Matrix winMatrix(const Matrix &);
    
    friend Matrix loseMatrix(const Matrix &);
    

private:
    bool type;
    std::vector<float> prob;
    size_t c;
    size_t r;
    std::vector<std::vector<int>> arr;
};


Matrix winMatrix(const Matrix &);

Matrix loseMatrix(const Matrix &);

#endif /* Matrix_hpp */
