#include <stdio.h>
 
int main() {
    int n;
    while(1){
        scanf("%d",&n);
        if(n==0)break;
        else{
            int a[n][n];
            for (int i = 0; i < n/2+n%2; i++)
            {
                for (int j = i; j < n-i; j++)a[n-i-1][j]=a[j][n-i-1]=a[j][i]=a[i][j]=i+1;
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)printf("%d ",a[i][j]);
                printf("\n");
            }

        }
    }
    return 0;
}