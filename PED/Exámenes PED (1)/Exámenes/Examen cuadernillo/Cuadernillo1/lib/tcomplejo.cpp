#include "tcomplejo.h"

TComplejo::TComplejo()
{
	re = 0;
	im = 0;
}

TComplejo::TComplejo(double re)
{
	this->re = re;
	im = 0;
}


TComplejo::TComplejo(double re, double im)
{
	this->re = re;
	this->im = im;
}


TComplejo::TComplejo(const TComplejo &t)
{
	re = t.re;
	im = t.im;
}


TComplejo::~TComplejo()
{
	re = im = 0;
}

double TComplejo::Arg(void) const
{
	double rad;
	if(re == 0 && im == 0)
		rad = 0;
	else
		rad = atan2(im, re);
	return rad;
}


double TComplejo::Mod(void) const
{
	double modulo=sqrt(pow(re,2.0) + pow(im,2.0));
	return modulo;
}


bool TComplejo::operator== (const TComplejo &t) const
{
	bool temp;
	temp = (re == t.re && im == t.im)? true : false;
	return temp;
}


bool TComplejo::operator!= (const TComplejo &t) const
{
	return !(*this == t);
}

TComplejo& TComplejo::operator= (const TComplejo &t)
{
	re = t.re;
	im = t.im;
	return *this;
}

TComplejo TComplejo::operator+ (TComplejo &t) const
{
	TComplejo temp;

	temp.re = re + t.re;
	temp.im = im + t.im;

	return temp;
}


TComplejo TComplejo::operator- (TComplejo &t) const
{
	TComplejo temp;

	temp.re = re - t.re;
	temp.im = im - t.im;

	return temp;
}


TComplejo TComplejo::operator* (TComplejo &t) const
{
	TComplejo temp;

	temp.re = (re * t.re) - (im * t.im);
	temp.im = (re * t.im) + (im * t.re);

	return temp;
}


TComplejo TComplejo::operator+ (double d) const
{
	TComplejo temp;
	temp.re = re + d;
	temp.im = im;
	return temp;
}


TComplejo TComplejo::operator- (double d) const
{
	TComplejo temp;
	temp.re = re - d;
	temp.im = im;
	return temp;
}


TComplejo TComplejo::operator* (double d) const
{
	TComplejo temp;
	temp.re = re * d;
	temp.im = im * d;
	return temp;
}



ostream &operator<<(ostream &os, const TComplejo &t)
{
	os << "(" << t.re << " " << t.im << ")";
	return os;
}


TComplejo operator+ (double d, const TComplejo &t)
{
	TComplejo temp;
	temp.re = t.re + d;
	temp.im = t.im;
	return temp;
}


TComplejo operator- (double d, const TComplejo &t)
{
	TComplejo temp;
	temp.re = d - t.re;
	temp.im = -t.im;
	return temp;
}

bool TComplejo::operator>(const TComplejo &m) const{
	return Mod() > m.Mod() || 
	Mod() == m.Mod() && Re() > m.Re() || 
	Mod() == m.Mod() && Re() == m.Re() && Im() > m.Im();
}

bool TComplejo::operator<(const TComplejo &m) const{
	return *this != m && !(*this > m);
}

TComplejo operator* (double d, const TComplejo &t)
{
	TComplejo temp;
	temp.re = t.re * d;
	temp.im = t.im * d;
	return temp;
}
