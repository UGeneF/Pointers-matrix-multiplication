struct Matr
{
	double* M; 
	unsigned short int order;
	unsigned short int size;	
};

Matr InitMatr(unsigned short int n, unsigned short int m)
{
	Matr temp;
	temp.size = n * n;
	temp.M = new double[temp.size];
	temp.order = n;
	return temp;
}

void EnterZero(Matr A)
{
	double* end_array = A.M + A.size;
	while (A.M < end_array)
	{
		*A.M = 0.0;
		A.M++;
	}
	A.M -= A.size;
}

Matr multiply(Matr A, Matr B, Matr buffer)
{
	EnterZero(buffer);

	double* end_array_buffer = buffer.M + A.size;
	double* end_row_buffer = buffer.M;
	double* temp_b = B.M;
	double* temp_a = A.M;
	double* start_a = A.M;

	while (buffer.M < end_array_buffer)
	{
		temp_a += A.order;
		end_row_buffer += A.order;
		while (buffer.M < end_row_buffer)
		{
			B.M = temp_b;
			while (A.M < temp_a)
			{
				*buffer.M += *A.M * *B.M;
				B.M += A.order;
				A.M++;
			}
			temp_b++;
			A.M -= A.order;
			buffer.M++;
		}
		temp_b -= A.order;
		A.M += A.order;
	}
	buffer.M -= A.size;
	A.M =start_a;
	return buffer;
}
