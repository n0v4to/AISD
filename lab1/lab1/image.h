#pragma once
#include <random>
#include <time.h>
#include <limits>
using namespace std;

struct image_exception {};

template <typename T>
class Image
{

private:
	int size_x;
	int size_y;
	T** image;
	const double eps = 0.0001;

public:
	Image(int x, int y, bool flag);
	T& operator()(int x, int y);
	bool operator==(Image a);
	Image& operator*(const Image& a);
	Image& operator+(const Image& a);
	Image& operator+(const T a);
	Image& operator*(const T a);
	Image& operator!();
	float image_koefficient() const;



	friend std::ostream& operator<<(std::ostream& os, Image<T>& I)
	{
		for (int i = 0; i < I.size_x; i++) {
			for (int j = 0; j < I.size_y; j++) {
				os << I.image[i][j] << " ";
			}
			os << '\n';
		}
		return os;
	}

};



Image<bool>::Image(int x, int y, bool flag)
{
	image = new bool* [x];
	for (int i = 0; i < x; i++)
	{
		image[i] = new bool[y];
	}
	size_x = x;
	size_y = y;
	if (flag == true)
	{
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				image[i][j] = rand() % 2;
			}
		}
	}
	else {
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				image[i][j] = 0;
			}
		}
	}
}


template <typename T>
Image<T>::Image(int x, int y, bool flag)
{
	image = new T * [x];
	for (int i = 0; i < x; i++)
	{
		image[i] = new T[y];
	}
	size_x = x;
	size_y = y;
	if (flag == true)
	{
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				image[i][j] = rand();
			}
		}
	}
	else {
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				image[i][j] = 0;
			}
		}
	}
}


template <typename T>
T& Image<T>::operator()(int x, int y)
{
	return image[x][y];
}



template <typename T>
Image<T>& Image<T>::operator+(const T a) {
	Image<T> result(size_x, size_y, false);
	for (int i = 0; i < size_x; i++) {
		for (int j = 0; j < size_y; j++) {
			result.image[i][j] = image[i][j] + a;
			if (result.image[i][j] < image[i][j])
				result(i, j) = numeric_limits<T>::max();
			else
				result(i, j) = result.image[i][j];
		}
	}
	return result;
}


template <typename T>
Image<T>& Image<T>::operator*(const T a) {
	Image<T> result(size_x, size_y, false);
	for (int i = 0; i < size_x; i++) {
		for (int j = 0; j < size_y; j++) {
			result.image[i][j] = image[i][j] * a;
			if (result.image[i][j] < image[i][j])
				result(i, j) = numeric_limits<T>::max();
			else
				result(i, j) = result.image[i][j];
		}
	}
	return result;
}


Image<bool>& Image<bool>::operator*(const Image<bool>& a) {
	if (a.size_x != size_x || a.size_y != size_y) {
		throw image_exception();
	}

	Image<bool> result(size_x, size_y, false);
	for (int i = 0; i < size_x; i++) {
		for (int j = 0; j < size_y; j++) {
			result.image[i][j] = (bool)(image[i][j] & a.image[i][j]);
		}
	}
	return result;
}


template <typename T>
Image<T>& Image<T>::operator*(const Image<T>& a) {
	if (a.size_x != size_x || a.size_y != size_y) {
		throw image_exception();
	}

	Image<T> result(size_x, size_y, false);
	for (int i = 0; i < size_x; i++) {
		for (int j = 0; j < size_y; j++) {
			result.image[i][j] = image[i][j] * static_cast<T>(a.image[i][j]);
			if (result.image[i][j] < image[i][j])
				result(i, j) = numeric_limits<T>::max();
			else
				result(i, j) = result.image[i][j];
		}
	}
	return result;
}



Image<bool>& Image<bool>::operator+(const Image<bool>& a) {
	if (a.size_x != size_x || a.size_y != size_y) {
		throw image_exception();
	}

	Image<bool>* result = new Image<bool>(size_x, size_y, false);
	for (int i = 0; i < size_x; i++) {
		for (int j = 0; j < size_y; j++) {
			result->image[i][j] = (bool)(image[i][j] | a.image[i][j]);
		}
	}
	return *result;
}



template <typename T>
Image<T>& Image<T>::operator+(const Image<T>& a) {
	if (a.size_x != size_x || a.size_y != size_y) {
		throw image_exception();
	}

	Image<T> result(size_x, size_y, false);
	for (int i = 0; i < size_x; i++) {
		for (int j = 0; j < size_y; j++) {
			result.image[i][j] = image[i][j] + static_cast<T>(a.image[i][j]);
			if (result.image[i][j] < image[i][j])
				result(i, j) = numeric_limits<T>::max();
			else
				result(i, j) = result.image[i][j];
		}
	}
	return result;
}


template <typename T>
Image<T>& Image<T>::operator!() {
	for (int i = 0; i < size_x; i++) {
		for (int j = 0; j < size_y; j++) {
			image[i][j] = -1 * image[i][j];
		}
	}
	return *this;
}

template <typename T>
float Image<T>::image_koefficient() const {
	float sum = 0.0f;
	float maxVal = numeric_limits<T>::max();


	for (int i = 0; i < size_x; i++)
	{
		for (int j = 0; j < size_y; j++)
		{
			sum += static_cast<T>((image[i][j]) / maxVal);
		}
	}
	float fillKoef = sum / (size_x * size_y);

	return abs(fillKoef);
}




template <typename T>
bool Image<T>::operator==(Image<T> a)
{
	if (a.size_x != size_x || a.size_y != size_y) {
		throw image_exception();
	}

	for (int i = 0; i < size_x; i++) {
		for (int j = 0; j < size_y; j++) {
			if (a.image[i][j] != image[i][j]) {
				return false;
			}
		}
	}
	return true;
}



bool Image<float>::operator==(Image a)
{
	if (a.size_x != size_x || a.size_y != size_y) {
		throw image_exception();
	}

	for (int i = 0; i < size_x; i++) {
		for (int j = 0; j < size_y; j++) {
			if (!(a.image[i][j] - image[i][j] <= eps || image[i][j] - a.image[i][j] <= eps)) {
				return false;
			}
		}
	}
	return true;
}