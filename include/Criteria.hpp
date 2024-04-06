#ifndef Criteria_hpp
#define Criteria_hpp

#include <algorithm>
#include <functional>
#include <numeric>
#include <map>
#include "Matrix.hpp"

class AbstractCriterion{
public:
    
    AbstractCriterion(){};
    
    virtual size_t fix() = 0;
protected:
    
    Matrix mat;
};

class Bayes : public AbstractCriterion{
public:
    
    Bayes(const Matrix &mat);
    
    size_t fix() override;
    
private:
    std::vector<float> alpha;
};

class Valde : public AbstractCriterion{
public:
    
    Valde(const Matrix &matrix);
    
    size_t fix() override;

private:
    std::vector<int> alpha;
};

class Sevidge : public AbstractCriterion{
public:
    Sevidge(const Matrix &matrix);
    
    size_t fix() override;

private:
    std::vector<int> alpha;
};

class Gurvice : public AbstractCriterion{
public:
    Gurvice(const Matrix &matrix, float h);
    
    size_t fix() override;

private:
    Matrix mat;
    float H;
    std::vector<float> alpha;
};

#endif /* Criteria_hpp */
