#include<iostream>
#include<vector>

using namespace std;

int main(){
	int n,m,l_tmp,r_tmp,max_r,now_x,best_i,check_i;
	bool t_f;
	vector<int>l_save,r_save,needs_save;
	
	cin >> n;
	
	while (n--){
		cin >> m;
		
		l_save.clear();
		r_save.clear();
		
		while (cin>>l_tmp>>r_tmp){
			l_save.push_back(l_tmp);
			r_save.push_back(r_tmp);
			
			if (l_tmp==0&&r_tmp==0) break;
		}
		
		max_r=-60000;
		now_x=0;
		needs_save.clear();
		best_i=l_save.size()-1;
		t_f=1;
		while (max_r<m){
			check_i=best_i;
			
			for (int i=0;i<l_save.size()-1;i++){
				if (l_save[i]<=now_x&&r_save[i]>max_r){
					max_r=r_save[i];
					best_i=i;
				}
				else if (r_save[i]==max_r&&l_save[i]<l_save[best_i]){
					max_r=r_save[i];
					best_i=i;
				}
			}
			
			if (check_i==best_i){
				t_f=0;
				break;
			}
			else{
				needs_save.push_back(best_i);
				now_x=max_r;
			}
		}
		
		if (t_f==1){
			cout << needs_save.size() << endl;
			
			for (int i=0;i<needs_save.size();i++){
				cout << l_save[needs_save[i]] << " " << r_save[needs_save[i]] << endl;
			}
			
			if (n!=0){
				cout << endl;
			}
		}
		else {
			cout << 0 << endl << endl;
		}
	}
	
	return 0;
} 
