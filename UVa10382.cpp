#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int n,best_i,check_i,need_c;
long double l,w,x_tmp,r_tmp,ans_tmp,now_x;
vector<long double>c_l,c_r;

int main(){
	while (cin>>n>>l>>w){
		c_l.clear();
		c_r.clear();
		for (int i=0;i<n;i++){
			cin >> x_tmp >> r_tmp;
			
			//important
			if (r_tmp*2>w){
				ans_tmp=pow((r_tmp*r_tmp)-((w*w)/4),0.5);
				c_l.push_back(x_tmp-ans_tmp);
				c_r.push_back(x_tmp+ans_tmp);
			}
		}
		
		/*for (int i=0;i<c_l.size();i++){
			cout << c_l[i] << " " << c_r[i] << endl;
		}*/
		
		need_c=0;
		now_x=0;
		c_l.push_back(-100000);
		c_r.push_back(-100000);
		best_i=c_l.size()-1;
		
		while (now_x<l){
			check_i=best_i;
			for (int i=0;i<c_l.size();i++){
				if (c_l[i]<=now_x&&c_r[i]>=c_r[best_i]){
					best_i=i;
				}
			}
			if (check_i==best_i){
				need_c=-1;
				break;
			}
			else{
				need_c++;
				now_x=c_r[best_i];
			}
		}
		
		cout << need_c << endl;
	}
	
	return 0;
} 
