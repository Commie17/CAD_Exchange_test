#include "Curves.h"

Curve::Curve(double x, double y, string type) : x_coord{ x }, y_coord{ y }, curve_type{type} {};

std::vector<double> Curve::GetPointByParam(double param) { return { 0,0,0 }; };

std::vector<double> Curve::GetDerivativeByParam(double param) { return { 0,0,0 }; };

string Curve::GetType()
{
	return curve_type;
}


Circle::Circle(double x, double y, double radii) : Curve{ x,y,"Circle"}, radius{abs(radii)} {};

std::vector<double> Circle::GetPointByParam(double param)
{
	std::vector<double> tmp = { 0,0,0 };

	tmp = { x_coord + radius * cos(param), y_coord + radius * sin(param), 0.0 };
	return tmp;

};

std::vector<double> Circle::GetDerivativeByParam(double param)
{
	std::vector<double> tmp = { 0,0,0 };

	tmp = { radius * (-1) * sin(param), radius * cos(param), 0.0 };
	return tmp;
};

double Circle::GetRadius()
{
	return radius;
};


Ellipse::Ellipse(double x, double y, double a_radii, double b_radii) : Curve{ x,y,"Ellipse"}, a_radius{abs(a_radii)}, b_radius{abs(b_radii)} {};

std::vector<double> Ellipse::GetPointByParam(double param)
{
	std::vector<double> tmp = { 0,0,0 };

	tmp = { x_coord + a_radius * cos(param), y_coord + b_radius * sin(param), 0.0 };
	return tmp;
};

std::vector<double> Ellipse::GetDerivativeByParam(double param)
{
	std::vector<double> tmp = { 0,0,0 };

	tmp = { a_radius * (-1) * sin(param), b_radius * cos(param), 0.0 };
	return tmp;
};


Helix::Helix(double x, double y, double step, double radius) : Curve{ x,y,"Helix"}, step{step}, radius{radius} {};

std::vector<double> Helix::GetPointByParam(double param)
{
	std::vector<double> tmp = { 0,0,0 };

	tmp = { x_coord + radius * cos(param), y_coord + radius * sin(param), step * param };
	return tmp;
};

std::vector<double> Helix::GetDerivativeByParam(double param)
{
	std::vector<double> tmp = { 0,0,0 };

	tmp = { radius * (-1) * sin(param), radius * cos(param), step };
	return tmp;
};