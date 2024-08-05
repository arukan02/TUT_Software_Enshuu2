#ifndef BMI_HPP
#define BMI_HPP

class BMI {
public:
    BMI(double weight, double height);
    double calculate() const;

private:
    double weight;
    double height;
};

#endif // BMI_HPP
