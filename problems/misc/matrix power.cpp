
struct matrix{
	
	double arr[2][2] = {{0, 0}, {0, 0}};
	
	matrix operator * (const matrix &other){
		
		matrix product;
		
		for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
		for(int k = 0; k < 2; k++)
			product.arr[i][k] += arr[i][j] * other.arr[j][k];
			
		return product;
	}
};

matrix fast_power(matrix a, int p){
	
	matrix product;
	for(int i = 0; i < 2; i++) product.arr[i][i] = 1;
	
	while(p){
		if(p&1) product = product * a;
		a = a * a;
		p /= 2;
	}
	
	return product;
}
