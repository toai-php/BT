/* Su dung source code cua Thay trong thu muc prufercode */
#include<bits/stdc++.h>

using namespace std;

#define MAX 100000
int main()
{
  int va;
  cin >> va;
  ofstream cout("data.in");
  int n2 = va - 2; //n-2 phan tu
  int prufer[MAX] = {0};
  int prufer0[MAX]={0};
  bool elements[MAX] = {0};

  
  srand (time(NULL));  

  prufer[n2] = 0;

  for (int i = 0; i < n2; i++)
    {

      prufer[i] = rand() % (n2 + 2) ;

    }

  
  for (int i = 0; i < n2+1; i++) elements[prufer[i]] = true;    


  for (int i = 0; i < n2+1; i++)
    {

      int j = 0; while (elements[j]) j++;  //tim phan tu nho nhat
      elements[j] = true;
      prufer0[i] = j;

      elements[prufer[i]] = false;        // Prufer[i] co the dung cho phan tu tiep theo
      for (int k = i+1; k < n2+1; k++ )   // tru khi prufer[i] co khong mat o phia sau 
	if (prufer[i] == prufer[k])
	  {
	    elements[prufer[i]] = true;
	    break;
	  }
    }

  cout<< n2+1 <<endl;
  for (int i = 0; i < n2 + 1; i++) 
    cout<<prufer0[i]<<" "<<prufer[i]<<endl;
  
  
  return 0;
}
