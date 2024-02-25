#include "Curves.h"
#include <algorithm>
#include <thread>
#include <omp.h>

bool comp(shared_ptr<Circle> l, shared_ptr<Circle> r)
{
	return l->GetRadius() < r->GetRadius();
};

int main()
{
	const int numberOfCurves = 10;
	int tmp;
	double radii_total_sum=0.;
	vector<double> vector3D(3);
	vector<shared_ptr<Curve>> curves;
	vector<shared_ptr<Circle>> circles;

	srand(time(NULL));

	for (int i = 0;i < numberOfCurves;i++)
	{
		tmp = rand() % 3 + 1;
		switch (tmp)
		{
		case 1:
		{
			curves.emplace_back(make_shared<Circle>(rand() % 100 + 1, rand() % 100 + 1, rand() % 100 + 1));
			break;
		}
		case 2:
		{
			curves.emplace_back(std::make_shared<Ellipse>(rand() % 100 + 1, rand() % 100 + 1, rand() % 100 + 1, rand() % 100 + 1));
			break;
		}
		case 3:
		{
			curves.emplace_back(std::make_shared<Helix>(rand() % 100 + 1, rand() % 100 + 1, rand() % 100 + 1, rand() % 100 + 1));
			break;
		}
		default:
			break;
		}
	}

	for (auto it : curves)
	{
		cout << endl << it->GetType()<<endl;
		vector3D = it->GetPointByParam(PI_4);
		printf("Point in case when t = %f is (%f,%f,%f)\n", PI_4, vector3D[0], vector3D[1], vector3D[2]);

		vector3D = it->GetDerivativeByParam(PI_4);
		printf("Derivative in case when t = %f is (%f,%f,%f)\n", PI_4, vector3D[0], vector3D[1], vector3D[2]);

		if (it->GetType() == "Circle")
		{
			circles.emplace_back(dynamic_pointer_cast<Circle>(it));
		}
	}

	cout << "\n-------Working with circles-------\n";
	
	sort(circles.begin(), circles.end(), comp);

	cout << "\nSorted circles\n";

	for (auto it : circles)
	{
		cout << endl << it->GetRadius();
	}

#pragma omp parallel for num_threads(_Thrd_hardware_concurrency())
	for (int i=0;i<circles.size();i++)
	{
		radii_total_sum += circles[i]->GetRadius();
	}

	cout << "\ntotal radii sum is: "<< radii_total_sum;

	return 0;
}