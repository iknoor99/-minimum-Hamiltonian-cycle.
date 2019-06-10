#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

template <class loop>

bool permute(loop start, loop end) {
    
	if (start == end) {
	  return false;
	}

    
    loop p = end;
	p=p-1;


    if (start == p){

	 return false;
	}

    while (true) {

        loop q = p;
	p=p-1;

        while (*p < *q) {

            loop l = end-1;

            for (;*p >= *l;l--);
            
			    
	    iter_swap(p, l);
	    for(loop s1=q,e1=end-1;s1<e1;s1++,e1--) iter_swap(s1,e1);           
	    return true;
	
        }

	if (p == start) {

            for(loop s1=q,e1=end-1;s1<e1;s1++,e1--) iter_swap(s1,e1);
            return false;
        }

    }
}


int factorial(int V){
	int fact=1;

	if(V==1){
	return fact;
	}	
	
	while(V>1){

	fact=fact*V;
	V--;
	}

}

int main(int argc, char *argv[])
{
	
	int filedata;
   	ifstream inputfile; 
	ofstream outfile;
	int V=0,E=0,p=0,q=0,r=0;
	
   	inputfile.open(argv[1]);

	if(!inputfile){
	cout<<"Issue with opening the file";
	return(-1);		
	}

	outfile.open(argv[2]);

	if(!outfile){
	cout<<"Issue with opening the file";
	return(-1);		
	}

	inputfile>>filedata;
	

	for(int i=0;i<filedata;i++){

   		inputfile>>V;

		int hamilgraph[V][V];
    
    		for (int i = 0; i < V; i++){	
			for (int j=0; j<V; j++){
			hamilgraph[i][j]=0;
			}
    		} 
 
		inputfile>>E;
		
		for(int j=0;j<E;j++){
			
			inputfile>>p;
			inputfile>>q;
			inputfile>>r;
			hamilgraph[p][q]=r;
			hamilgraph[q][p]=r;
		}
		
				

		int dummyarray[V];

		for(int i=0;i<V;i++){
			dummyarray[i]=i;
		}

		int totalpermutations=factorial(V);
		int minarray[totalpermutations];
		int loopindex=-1;

    		do {
			int weight=0;
			loopindex++;

			for(int i=0;i<V-1;i++){

				weight=weight+hamilgraph[dummyarray[i]][dummyarray[i+1]];
		
			}

			weight=weight+hamilgraph[dummyarray[V-1]][dummyarray[0]];

			minarray[loopindex]=weight;

		

		}//do 

    
    		while(permute(dummyarray,dummyarray+V));
		int min=minarray[0];
		for(int i=0;i<totalpermutations;i++){
			if(minarray[i]<min){
				min=minarray[i];

			}

		}
		
		cout<<"MIN WEIGHT IS :"<<min<<endl;	
		outfile<<min<<endl;
		
		
	
}//for loop
inputfile.close();
outfile.close();
return 0;
}//main
