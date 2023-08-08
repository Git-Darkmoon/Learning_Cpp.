/*Goal: practice arithmetic operations in C++
**Write a program that calculates the volumes of:
**a cube, sphere, cone.
**Cube Volume = side^3
**Sphere Volume = (4/3) * pi * radius^3
**Cone Volume = pi * radius^2 * (height/3)
**Write the values to the console.
*/

#include<iostream>
#include <cmath>

float cubeVolume(float side) {
	
	return pow(side,3);
}

float sphereVolume(float radius) {
	
	return (4/3) * M_PI * pow(radius,3);
	
}

float coneVolume(float radius,float height) {
	
	return M_PI * pow(radius,2) * (height/3);
}


int main()
{
    //Dimension of the cube
    int cubeSide = 5;
    //Dimension of sphere
    float sphereRadius = 2.33;
    //Dimensions of cone
    float coneRadius = 7.65;
    int coneHeight = 14;
    
    std::cout << "The cube volume is: " << cubeVolume(cubeSide) << "\n";
    std::cout << "The sphere volume is: " << sphereVolume(sphereRadius) << "\n";
    std::cout << "The cone volume is: " << coneVolume(coneRadius,coneHeight);
    
    
    return 0;
}
