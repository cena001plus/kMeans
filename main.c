​
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "kMeans.h"



void main()
{
    // k-Means
    #define N 24
    #define K 2

	//train data
    struct Data data[N]={{6,0.89},{5,0.6},{2,0.8},{6.3,2.1},\
	    		{2.89,0.8},{4.66,1.3},{3.98,1.26},{6.3,2.1},\
		    	{3.3,0.8},{3.8,1.44},{4,1.39},{4.99,1.24},\
		    	{5.9,1.1},{6.8,0.9},{6,0.8},{6.8,1.2},\
		    	{7.4,2},{6,1.5},{8.2,2.3},{7.7,2.1},\
		    	{9.5,3.2},{7.6,2.5},{6.2,1.2},{8.5,1.7}};
    
    int iClass[N]={0};
    struct Data newCore[2]={{4.66,1.3},{7.7,2.1}};
    int iIters=0;
    int count=0;
    float distence[2]={0};
	
	//test data struct
    struct Test{
        float para1;
        float para2;
    }testdata[4]={{6,1.6},\
               {8,2.2},\
                 {10,1},\
                 {3,1.1}};

	//calc new center
	while(iIters<10)
	{
		iIters++;
		kMeans(K,N,iClass,data,newCore);
		for(count=0;count<K;count++)
		{
			printf("newCore[%d]=(%f,%f)\n",count,newCore[count].para1, newCore[count].para2);
		}
		for(count=0;count<N;count++)
		{
			printf("iClass[%d]=%d\n",count, iClass[count]);
		}	
	}	

	//just test it
    for(count=0;count<4;count++)
    {
        for(iIters=0;iIters<K; iIters++)
        {
            distence[iIters] = sqrt(pow((testdata+count)->para1 - newCore[iIters].para1,2)+\
                            pow((testdata+count)->para2-newCore[iIters].para2,2));
        }
        if(distence[0]>distence[1])
        {
            printf("test result: 0 \n");
        }
        else
        {
            printf("test result: 1 \n");
        }
    }

}

​