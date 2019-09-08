
#include <Rcpp.h>

//' @title Class Random_walk
//' @name Random_walk
//' @description drifted random walk class
//' @export Random_walk
class Random_walk
{
  // Access specifier
private:
  // membres
  double sigma ;


public:

  // constructeur
  Random_walk(  double sigma_){
    sigma = sigma_;
  }

  // setter
  void set_sigma(double sigma_){
    sigma = sigma_;
  }
  //getter
  double get_sigma(){
    return sigma ;
  }

  double compute_next_pos(double x0, double delta){
    return x0 + Rcpp::rnorm(1, 0, 1)[0] * sigma * pow(delta, .5);
  }
  Rcpp::NumericVector simulate(Rcpp::NumericVector times, double x0){
    int n = times.size();
    Rcpp::NumericVector out(n);
    out[0] = x0;
    for(int i = 0; i < n - 1 ; ++i ){
      out[i+1] =  compute_next_pos(out[i], times[i+1]-times[i]);
    }
    return out;
  }

};

RCPP_MODULE(rw_Module) {
  using namespace Rcpp;
  //  .constructor()
  class_<Random_walk>("Random_walk")
    .constructor< double>()
    .property( "sigma_R", &Random_walk::get_sigma, &Random_walk::set_sigma )
    .method( "simulate_R", &Random_walk::simulate )
  ;
}
