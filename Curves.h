#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include <math.h>

using namespace std;

const double PI_4 = 0.7853982;

class Curve
{
protected:
	double x_coord, y_coord;
	string curve_type;
public:
	Curve(double x, double y, string type);
	string GetType();
	virtual std::vector<double> GetPointByParam(double param);
	virtual std::vector<double> GetDerivativeByParam(double param);
};

class Circle : public Curve
{
public:
	Circle(double x, double y, double radii);
	double GetRadius();
	std::vector<double> GetPointByParam(double param) override;
	std::vector<double> GetDerivativeByParam(double param) override;
private:
	double radius;
};

class Ellipse : public Curve
{
public:
	Ellipse(double x, double y, double a_radii, double b_radii);
	std::vector<double> GetPointByParam(double param) override;
	std::vector<double> GetDerivativeByParam(double param) override;
private:
	double a_radius, b_radius;
};

class Helix : public Curve
{
public:
	Helix(double x, double y, double step, double radius);
	std::vector<double> GetPointByParam(double param) override;
	std::vector<double> GetDerivativeByParam(double param) override;
private:
	double step, radius;
};