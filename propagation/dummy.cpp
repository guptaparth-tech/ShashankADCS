#include <iostream> 
#include <cmath>
#include <array>
std::array<double,  2> pos_n(double r , double time ){
  double x = r * cos(time);
  double y = r * sin(time );
  std::array<double,  2> curr = {x,y} ; 
  return curr;
}
int main() {
  double mu = 398600.4418 ; //gravitational constant 
  double radius  = 6378.137 ; //radius of the earth 
  double dt = 0.01;
  double t = 0; 
  for (int i = 0 ; i < 1000 ; i++){
    std::array<double, 2> posistion = pos_n(radius, t);
    std::cout << "the current position is: " << posistion[0] << "," << posistion[1] << "\n" ;
    t = i*dt ; 

  }
 
}
