/* 
Introduction  to C++ for Financial Engineers: An Object Oriented Approach
Chapter 1: Introduction to C++ and Quantiative Finance
*/

// 1.3

#include <iostream> // For input/output operations
#include <cmath>    // For mathematical functions

// Normal distribution CDF approximation
double N(double x) {
    return 0.5 * (1.0 + erf(x / sqrt(2.0)));
}

class VanillaOptionsPricer {
    public:
        double S; // Stock price
        double r; // Risk Free Interest rate
        double sig; // Volatility
        double K; // Strike price
        double T; // Time to expiration
        double b; // Cost of carry
        
        // Constructor
        VanillaOptionsPricer(double stock_price, double risk_free_rate, double volatility, 
            double strike_price, double time_to_expiry, double cost_of_carry): S(stock_price), r(risk_free_rate), sig(volatility), 
            K(strike_price), T(time_to_expiry), b(cost_of_carry) {}

    double CallPrice(){
        double tmp = sig * sqrt(T);
        double d1 = ( log(S/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;
        double d2 = d1 - tmp;
        return (S * exp((b-r)*T) * N(d1)) - (K * exp(-r * T)* N(d2));
    }

    double PutPrice()
    {
        double tmp = sig * sqrt(T);
        double d1 = ( log(S/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;
        double d2 = d1 - tmp;
        return (K * exp(-r * T)* N(-d2)) - (S * exp((b-r)*T) * N(-d1));
    }
    
};
