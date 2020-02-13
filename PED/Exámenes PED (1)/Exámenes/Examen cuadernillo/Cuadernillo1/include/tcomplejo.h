#ifndef _TComplejo_
#define _TComplejo_

#include <iostream>
#include <vector>
#include <cstdlib>
#include <math.h>

using namespace std;

class TComplejo
{

	friend ostream &operator<<(ostream &os, const TComplejo &t);
	friend TComplejo operator+ (double , const TComplejo&);
	friend TComplejo operator- (double , const TComplejo&);
	friend TComplejo operator* (double , const TComplejo&);

	private:
		double re, im;
	public:
		TComplejo();
		TComplejo(double re);
		TComplejo(double re, double im);
		TComplejo(const TComplejo &t);
		~TComplejo();

		double Re() const {return re;}
		double Im() const {return im;}
		void Re(double re) {this->re = re;}
		void Im(double im) {this->im = im;}
		double Arg(void ) const;
		double Mod(void ) const;

		bool operator== (const TComplejo &) const;
		bool operator!= (const TComplejo &) const;
		TComplejo& operator= (const TComplejo &);
		TComplejo operator+ (TComplejo &) const;
		TComplejo operator- (TComplejo &) const;
		TComplejo operator* (TComplejo &) const;
		TComplejo operator+ (double) const;
		TComplejo operator- (double) const;
		TComplejo operator* (double) const;
		bool operator<(const TComplejo &) const;
		bool operator>(const TComplejo &) const;
};

#endif