#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main(){
	int n;
	double save[1000],average,p_diff,n_diff;
	
	cout << fixed << setprecision(2);
	
	while (cin>>n){
		if (n==0) break;
		
		average=0;
		for (int i=0;i<n;i++){
			cin >> save[i];
			average+=save[i];
		}
		
		average /= n;
		
		//cout << "avg:" << average << endl;
		
		p_diff=0;
		n_diff=0;
		for (int i=0;i<n;i++){
			if (save[i]>average){
				//cout << "test_p:" << save[i] << " " << (-average + save[i])*100 << " " <<floor((-average + save[i])*100) << endl;
				p_diff+=(floor((-average + save[i])*100))/100;
			}
			else if (save[i]<average){
				//cout << "test_n:" << save[i] << " " << (average - save[i])*100 << " " <<floor((average - save[i])*100) << endl;
				n_diff+=(floor((average - save[i])*100))/100;
			}
		}
		
		//cout << "p_diff:" << p_diff << " ";
		//cout << "n_diff:" << n_diff << endl;
		
		if (p_diff>n_diff){
			cout << "$" << p_diff << endl;
		}
		else {
			cout << "$" << n_diff << endl;
		}
	}
	
	return 0;
} 
