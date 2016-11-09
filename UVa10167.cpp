#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
	int n,a,b,check,to_next,ok_min,ok_min_i;
	vector<int>a_save,b_save,ok_a_save,ok_b_save;
	
	while (cin>>n){
		if (n==0) break;
		
		a_save.clear();
		b_save.clear();
		for (int i=0;i<2*n;i++){
			cin >> a >> b;
			a_save.push_back(a);
			b_save.push_back(b);
		}
		
		ok_a_save.clear();
		ok_b_save.clear();
		for (int ix=-500;ix<=500;ix++){
			for (int iy=-500;iy<=500;iy++){
				if (ix==0&&iy==0) continue;
				
				check=0;
				for (int j=0;j<2*n;j++){
					if ((a_save[j]*ix + b_save[j]*iy)>0) check++;
					else if ((a_save[j]*ix + b_save[j]*iy)==0) check=-1121;
				}
				
				if (check==n){
					ok_a_save.push_back(ix);
					ok_b_save.push_back(iy);
				}
			}
		}
		
		ok_min=2121;
		for (int i=0;i<ok_a_save.size();i++){
			if ((abs(ok_a_save[i])+abs(ok_b_save[i]))<=ok_min){
				ok_min=abs(ok_a_save[i])+abs(ok_b_save[i]);
				ok_min_i=i;
			}
		}
		
		cout << ok_a_save[ok_min_i] << " " << ok_b_save[ok_min_i] << endl;
	}
	
	return 0;
} 
