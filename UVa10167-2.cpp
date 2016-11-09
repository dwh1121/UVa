#include<iostream>
#include<vector>

using namespace std;

int main(){
	int n,a,b,check_pp,check_pn,check_np,check_nn,to_next,range_min,range_big;
	vector<int>a_save,b_save;
	
	while (cin>>n){
		if (n==0) break;
		
		a_save.clear();
		b_save.clear();
		for (int i=0;i<2*n;i++){
			cin >> a >> b;
			a_save.push_back(a);
			b_save.push_back(b);
		}
		
		to_next=1;
		for (int abs_sum=1;abs_sum<=1000;abs_sum++){
			if (to_next==0) break;
			
			if (abs_sum<=500){
				range_min=0;
				range_big=abs_sum;
			}
			else {
				range_min=abs_sum-500;
				range_big=500;
			}
			
			for (int ix=range_min,iy=range_big;ix<=range_big;ix++,iy--){
				check_pp=0;
				check_pn=0;
				check_np=0;
				check_nn=0;
				for (int j=0;j<2*n;j++){
					if ((a_save[j]*ix + b_save[j]*iy)>0) check_pp++;
					else if ((a_save[j]*ix + b_save[j]*iy)==0) check_pp=-1121;
					
					if ((a_save[j]*ix - b_save[j]*iy)>0) check_pn++;
					else if ((a_save[j]*ix - b_save[j]*iy)==0) check_pn=-1121;
					
					if ((-a_save[j]*ix + b_save[j]*iy)>0) check_np++;
					else if ((-a_save[j]*ix + b_save[j]*iy)==0) check_np=-1121;
					
					if ((-a_save[j]*ix - b_save[j]*iy)>0) check_nn++;
					else if ((-a_save[j]*ix - b_save[j]*iy)==0) check_nn=-1121;
				}
				
				if (check_pp==n){
					cout << ix << " " << iy << endl;
					to_next=0;
					break;
				}
				else if (check_pn==n){
					cout << ix << " " << -iy << endl;
					to_next=0;
					break;
				}
				else if (check_np==n){
					cout << -ix << " " << iy << endl;
					to_next=0;
					break;
				}
				else if (check_nn==n){
					cout << -ix << " " << -iy << endl;
					to_next=0;
					break;
				}
			}
		}
	}
	
	return 0;
} 
