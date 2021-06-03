real F(int F_code, real x)
{
	real g = 0,h = 0,b=0;
	switch(F_code)
	{
		case 0: g = sin(x);break;
		case 1: g = fmod(x,2)-.5;break;
		case 2: g = .5*x*x-1.5;break;
		case 3: g = 2*exp(-x*x)-.5;break;
		case 4: g = exp(0.2*sin(x*x*x))*sin(x);break;
		case 5: g = fabs(x)-2;break;
		case 6: g = cbrt(x);break;
		case 7: g = floor(x-.2) - 0.50; break;
		case 8: g = 1.5 + sqrt(x)-x;break;
		case 9: g = fmod(x,2); break;
		case 10: if (x > 0) g = 1+exp(-x); else g= .5*x;break;
		case 11: g = 0.2*x*x*x;break;
		case 12: if (fabs(x) > 1) g = -1.5; else g = 1.5;break;
		case 13: g = 0.75 - (abs(floor(x))%2); break;
		case 14: g = 2*sin(4*x);break;
		case 15: g = fabs(1.5*sin(8*x)) - fmod(x,1);break;
		case 16: g = 2-8*fmod(fabs(x),.5);break;
		case 17: g = fmod(fabs(x),1.0);break;
		case 18: g = fmod(fmod(x,2),1);break;
		case 19: h = fmod(fabs(x),1);g =  ((h >0.5)?1-h:h)-.25;break;
		case 20: h = fmod(fabs(4*x),2);g = (h >1)?2-h:h;break;
		case 21: h = fmod(fabs(x),2);g = ((h >1)?2-h:h)-.5;break;
		case 22: b = 4;h = fmod(fabs(x),b); g = ((h>.5*b)?b-h:h)-.25*b;break;
		default: g = 0;break;
			
	}
	if (fabs(g) < max_f) return g; else return max_f*copysign(1.0, g);
	
}

double f(double x)
{
	double s = 0,p=10,h=0;
	double shift = 3;
	z[0] = x;
	for (int i = 1; i < neurons_in_layer[0]; i++) z[i] = pow(x/PI, i + 1);
	for (int i = 0; i < N; i++)
	{
		s = 0;
		if (i > neurons_in_layer[0] - 1)
		{
			for (int j = 0; j < i; j++)
			{
				if (C[i][j] == 1)
					s += W[i][j] * a[j];
			}
			z[i] = b[i] + s;
		}
		switch (layer_transfer[d[i]])
		{
		case 0:
			a[i] = z[i];
			da[i] = 1;
			break;
		case 1:
			a[i] = tanh(z[i]);
			da[i] = 1 - a[i] * a[i];
			break;
		case 2:
			a[i] = (z[i] > 0) * z[i];
			da[i] = (z[i] > 0);
			break;
		case 3:
			a[i] = z[i]/(1+exp(-z[i]));
			da[i] = a[i] + (1-a[i])/(1+exp(-z[i]));
			break;
		case 4:
			a[i] = sin(z[i]);
			da[i] = cos(z[i]);
			break;
		case 5:
			h = fmod(fabs(z[i]),p);a[i] = ((h>0.5*p)?p-h:h)-0.25*p;
			da[i] = (h > 0.5*p)?-1:1;
			break;
		}
	}
	a[N - 1] *= amplify;
	da[N - 1] *= amplify;
	if (fabs(a[N-1]) < max_f)	return a[N - 1]; else return max_f*copysign(1.0,a[N-1]);
}

