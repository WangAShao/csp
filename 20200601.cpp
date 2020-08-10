 #include <iostream>
 using namespace std;
 const int N = 1e3 + 10;
 struct Point{
   int x;
   int y;
};
 Point a[N];
 Point b[N];
 int ans[25] = {0};
 int main()
{
   int n, m,i=0,j=0, ns=0;
   cin>>n>>m;
   for(int k=0; k<n; k++)
  {
     int x1,y1;
     char t;
     scanf("%d %d %c", &x1, &y1, &t);
     if(t == 'A')
     {
         a[i].x = x1;
         a[i].y = y1;
         i++;
     }
     else
     {
         b[j].x = x1;
         b[j].y = y1;
         j++;
     }
  }
  for(int k=0; k<m; k++)
   {
      int p0,px,py;
      scanf("%d %d %d", &p0, &px, &py);
      int flag1=1, flag2=1;
      int t1=0, t2=0;
      for(int t=0; t<i; t++)
     {
         if(!t) {
         t1 = p0 + a[t].x * px + a[t].y * py;
         if(t1 < 0) t1 = -1;
         else t1 = 1;
         continue; 
        } 
     int temp = p0 + a[t].x * px + a[t].y * py;
     if(temp * t1 < 0){
          flag1 = 0;
          break;
       }
    }
      if(!flag1) 
    {    
        ans[ns++] = 0;
        continue;
  }
      for(int t=0; t<j; t++)
    {
        if(!t) {
           t2 = p0 + b[t].x * px + b[t].y * py;
           if(t2 < 0) t2 = -1;
           else t2 = 1;
           continue; 
          }
       int temp = p0 + b[t].x * px + b[t].y * py;
       if(temp * t2 < 0){
          flag2 = 0;
          break;
        }
      }
      if(!flag2)
     {
        ans[ns++] = 0;
        continue;
     }
     if(t1 * t2 < 0)
    {
       ans[ns++] = 1;
       continue;
    }
     else
        ans[ns++] = 0;
  }
  for(int t=0; t<ns; t++)
    {
        if(ans[t]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
 
 return 0;
}