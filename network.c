


void initialize_weights(double lower_bound, double upper_bound)
{
	flush_network();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (C[i][j] == 1)
				W[i][j] = random_double(lower_bound, upper_bound);
		}
		b[i] =random_double(lower_bound, upper_bound) ;
	}
	
}

void install_connections()
{
	int j = 0;
	L = 0;
	while (neurons_in_layer[j] > 0)
	{
		++L;
		++j;
	}
	N = 0;
	for (int l = 0; l < L; l++)
	{
		for (int i = 0; i < neurons_in_layer[l]; i++)
		{
			d[N] = l;
			++N;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (d[i] - d[j] == 1)
				C[i][j] = 1;
			else
				C[i][j] = 0;
		}
	}
}

void flush_network()
{
	for (int i = 0; i < N; i++)
	{
		z[i] = 0;delta[i]= 0;a[i] = 0;b[i] = 0;da[i]=0;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			dW[i][j] = 0;
		}
	}
}
void backpropagate(double error)
{
	double s = 0;
	delta[N - 1] = error ;//* da[N - 1];

	for (int from = N - 2; from > -1; from--)
	{
		delta[from] = 0;
		for (int to = from + 1; to < N; to++)
			delta[from] += C[to][from] * W[to][from] * da[to] * delta[to];
	}


	for (int i = neurons_in_layer[0]; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			dW[i][j] += C[i][j] * delta[i] * a[j] * da[i];
		}
		db[i] += delta[i] * da[i];//*copysign(1.0,b[i]);
	}

}

void process_epoch()
{
	real x = 0, error = 0, error_sum = 0;
	for (int i = 0; i < data_points; i++)
	{
		x = data[i][0];
		error = f(x) - F(F_code,x);
		error_sum += fabs(error);
		backpropagate(error);
	}
	mean_error = error_sum/data_points;
}

void update_parameters()
{
	double old;
	for (int to = neurons_in_layer[0]; to < N; to++)
	{
		for (int from = 0; from < to; from++)
		{

			old = W[to][from];
			W[to][from] -= rate * dW[to][from]/batch_size;
			if (fabs(W[to][from]) > WEIGHT_LIMIT) W[to][from] = old;
			dW[to][from] = 0;
		}
		b[to] -= rate * db[to]/batch_size;
		db[to] = 0;
	}
}

void set_up_network()
{
	flush_network();
	install_connections();
	initialize_weights(-.7,.7);
	install_structure(structure_W,structure_H);
	
}

void load_new_data()
{
	real x = 0, yy = 0;
	for (int i = 0; i < data_points; i++)
	{
		x = random_double(left, right);
		data[i][0] = x;
		//yy = F(F_code, x) + random_double(-noise, noise);
		yy = F(F_code, x) + random_normal(0,noise);
		if (fabs(yy) < max_f) data[i][1] = yy; else data[i][1]= max_f*copysign(1.0, yy);
		

	}
}
		
		
		
