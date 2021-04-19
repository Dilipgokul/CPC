
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void mat(int n)
{
int i=0,j=0,k=0;
int a[(2*n-1)][(2*n-1)];
int t=(2*n-1);
int l=t;
  while(t!=t/2)
      { if(n>=1 && n<=1000)
        {
          for(j=k;j<t;j++)
          {
            a[i][j]=n;
          }  
          for(i=k,j=0;i<t;i++)
          {
            a[i][j]=n;
          } 
        i=t;
           for(j=k;j<t;j++)
           {
            a[i][j]=n;
           }
        j=t;
           for(i=k;i<t;i++)
           {
            a[i][j]=n;
           }
        t--;k++;    
        }
      }
      for(i=0;i<=l;i++)
      {
        for(j=0;j<=l;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
      }        
}
int main() 
{   int n;
   // printf("enter the number\n");
    scanf("%d",&n);
    mat(n);
    return 0;
}

