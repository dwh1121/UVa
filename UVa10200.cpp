#include<iostream>
#include<iomanip>

using namespace std;

bool com[100010042]={0};
//10001
//100020001
//100010041

long long unsigned int euler(long long unsigned int x){
	return x*x+x+41;
}

int main(){
    long long unsigned int a,b,save;
    
    for (long long unsigned int i=2;i<=10001;i++){
    	if (com[i]==0){
    		for (long long unsigned int j=2;i*j<=100010042;j++){
    			com[i*j]=1;
    		}
    	}
    }
    
    while(cin >> a >> b){
    	save=0;
    	for (int i=a;i<=b;i++){
    		if (com[euler(i)]==0) save++;
    	}
    	
    	cout << fixed << setprecision(2) << static_cast<float>(save)/static_cast<float>(b-a+1)*100 + 1e-9 << endl;
    }
    
    return 0;
}

