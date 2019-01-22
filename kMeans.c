​
#include <stdio.h>
#include <math.h>
#include "kMeans.h"


void cluster(int K, int N, int *pClass,struct Data *data,struct Data *newCore)
{
	int i,j;
	float distence[N][K];
	float st_x;
	float dst_x;
	float min;
	for(i=0;i<N;i++)
	{
		for(j=0;j<K;j++)
		{
			st_x = (data+i)->st-(newCore+j)->st;
			dst_x = (data+i)->dst-(newCore+j)->dst;
			distence[i][j]=sqrt(pow(st_x,2)+pow(dst_x,2));
		}
		min = 9999;
		
		for(j=0;j<K;j++)
		{
			if(distence[i][j]<min)
			{
				min= distence[i][j];
				*(pClass+i) = j;
			}
		}
		
	}	
}


// 
void GetNewCenter(int K, int N,int *pClass,struct Data *data,struct Data *newCore)
{
	int i,j;
	int cnt=0;
	struct Data sum={0,0};

	for(j=0;j<K;j++)
	{
		for(i=0;i<N;i++)
		{
			
			if(*(pClass+i)==j)
			{
				sum.st +=  (data+i)->st;
				sum.dst += (data+i)->dst;
				cnt++;
			}			
		}
		(newCore+j)->st= sum.st / cnt;
		(newCore+j)->dst= sum.dst/cnt;
		cnt =0;
		sum.st=0;
		sum.dst=0;
	}

}



//
void kMeans(int K, int N, int *pClass, struct Data *data, struct Data *newCore)
{
	cluster(K,N,pClass, data, newCore);
	GetNewCenter(K,N,pClass, data, newCore);
}



​