#include <iostream>
#include<vector>
using namespace std;
 bool search( int key, vector<int> &fr)
 {
     for(int i=0;i<fr.size(); i++)
        if(fr[i]== key)
        return true;
        
        return false;
 }
 int predict(int pg[],vector<int> &fr,int  pn, int index ){
     
     	int res = -1, farthest = index; 
	for (int i = 0; i < fr.size(); i++) { 
		int j; 
		for (j = index; j < pn; j++) { 
			if (fr[i] == pg[j]) { 
				if (j > farthest) { 
					farthest = j; 
					res = i; 
				} 
				break; 
			} 
		} 

		// If a page is never referenced in future, 
		// return it. 
		if (j == pn) 
			return i; 
	} 

	// If all of the frames were not in future, 
	// return any of them, we return 0. Otherwise 
	// we return res. 
	return (res == -1) ? 0 : res; 
     
 }
 void  optimalPage( int pg[], int pn, int fn)
 {
    vector<int> fr;
    int hit=0;
    for(int i=0;i<pn;i++)
    {
        if (search(pg[i], fr)) { 
			hit++; 
			continue; 
		} 
		if (fr.size() < fn) 
			fr.push_back(pg[i]); 
		else { 
			int j = predict(pg, fr, pn, i + 1); 
			fr[j] = pg[i]; 
		} 
			
    }
    	cout << "No. of hits = " << hit << endl; 
	cout << "No. of misses = " << pn - hit << endl; 
 }
int main() {
    int pg[]= { 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2 }; 
    int pn= sizeof(pg)/sizeof(pg[0]);
    int fn=4;
    optimalPage(pg, pn, fn); 
return 0;
}
