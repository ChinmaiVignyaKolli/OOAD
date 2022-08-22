float cordic(angle)
{
int width = 16;
float x[16]={0};
float y[16]={0};
float z[16]={0};
float A=1;
x[0] = R;
y[0] = 0;
z[0] = angle;
int z_sign=0;
for(i=0;i<width;i++)
{
z_sign = dectobin(z,i);
x[i+1] = z_sign ? x[i] - y[i]/(2^i) : x[i] - y[i]/(2^i) ;
y[i+1] = z_sign ? y[i] + x[i]/(2^i) : y[i] + x[i]/(2^i) ;  
z[i+1] = z_sign ? z[i] - atan_table[i] : z[i] + atan_table[i]; 
A = A * 1/sqrt(1+2^(-2*i);
}

float cosangle = x[width-1] * A; 
float sinangle = y[width-1] * A;
}

return sinangle;
}

int dectobin(int z[],int x)
{
	int i=0,bin[10]={0};
	while(z[x]!=0)
	{
	bin[i] = z[x]%2;
	z[x] = z[x]/10;
	i++;
	}
	return bin[0];
}
