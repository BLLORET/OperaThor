#include <stdio.h>
#include <stdlib.h>

/*struct Complex
{
	float real;
	float img;
}*/

float mysqrt(float n);

float mysqrt(float n)
{
	float x = n;
	while(x>n/x)
	{
		x = (x+n/x)/2;
	}
	return x;
	
}

/*struct Complex *add_comp(struct Complex a, struct Complex b)
{
	struct Complex *res = malloc(sizeof(struct Complex));
	res -> img = a -> img + b->img;
	res->real = a->real+b->real;
	printf("%fi+%f +%fi+%f = %fi+%f",a->img,a->real,b->img,b->real);	
}

struct Complex *mult_comp(struct Complex a, struct Complex b)
{
	struct Complex *res = malloc(sizeof(struct Complex));
	res -> real = a->real*b->real-a->img*b->img;
	res ->img = a->real*b->img+b->real*a->img;
	return res;
}*/

void main()
{
printf("%f", mysqrt(4));	
}
