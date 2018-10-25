#include <iostream>
using namespace std;


int main(){
	
	int i,j,n,a[50],frame[10],pf,k,avail,count=0;
    cout << "Enter the number of pages: ";
	cin >> n;
	cout << "Enter the page number: ";
    for(i=0;i<n;i++)
    cin >> a[i];
    cout << "Enter the number of frames: ";
    cin >> pf;
	
	for(int i=0;i<pf;i++)
        frame[i]= -1;
    
	j=0;
	cout << "\tRef string\t Page Frames\n";
    for(int i=0;i<n;i++) {
        
		cout << a[i] <<"\t\t";
        avail=0;
    	for(int k=0;k<pf;k++)
			if(frame[k]==a[i])
                avail=1;
        
		if (avail==0){
            frame[j]=a[i];
            j=(j+1)%pf;
            count++;
            for(int k=0;k<pf;k++)
            cout << frame[k] << "\t";
		}
        cout << endl;
	}
    cout << "Page Fault Is  " << count;
    return 0;
}

