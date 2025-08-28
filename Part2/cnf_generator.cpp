#include <bits/stdc++.h>
#define inti int
using namespace std;

int main() {
	vector<vector<inti>> clauses;
	inti n;
	cin>>n;
    inti r1,c1;
	inti r2,c2;
	cin>>r1>>c1;//to be removed
	cin>>r2>>c2;//to be removed
	inti variable=1;
	for(inti row=1;row<=n;row++){
		for(inti column=1;column<=n;column++){
			if(row==r1 && column==c1){
				continue;
			}
			if(row==r2 && column==c2){
				continue;
			}
         vector<vector<inti>> cur;
         inti a=variable++;
		
		 inti b=variable++;
		
		 inti c=variable++;
		
		 inti d=variable++;

         clauses.push_back({a,b,c,d});
		 clauses.push_back({-a,-b});
		 clauses.push_back({-a,-c});
		 clauses.push_back({-a,-d});
		 clauses.push_back({-b,-c});
		 clauses.push_back({-b,-d});
		 clauses.push_back({-c,-d});
		 
			 inti newrow=row;
			 inti newcolumn=column-1;
			 if(newrow<1 || newrow>n || newcolumn<1 || newcolumn>n
			 ||  (newrow==r1 && newcolumn==c1) || (newrow==r2 && newcolumn==c2)){
				 clauses.push_back({-b});
			 }
			 else{
            clauses.push_back({-b,b-5});
			 }

			  newrow=row;
			  newcolumn=column+1;
			 if(newrow<1 || newrow>n || newcolumn<1 || newcolumn>n
			 ||  (newrow==r1 && newcolumn==c1) || (newrow==r2 && newcolumn==c2)){
				 clauses.push_back({-a});
			 }
			 else{
			 clauses.push_back({-a,a+5});
			 }

			  newrow=row+1;
			  newcolumn=column;
			  inti tobeadded=n*4;
			  if(row==r1 && column<c1){
				  tobeadded-=4;
			  }
			  if(row==r2 && column<c2){
				  tobeadded-=4;
			  }
			  if(newrow==r1 && newcolumn>c1){
				  tobeadded-=4;
			  }
			  if(newrow==r2 && newcolumn>c2){
				  tobeadded-=4;
			  }
			  if(newrow<1 || newrow>n || newcolumn<1 || newcolumn>n
			 ||  (newrow==r1 && newcolumn==c1) || (newrow==r2 && newcolumn==c2)){
				 clauses.push_back({-c});
			 }
			  else{
			 clauses.push_back({-c,c+1+tobeadded});
			 }

			  newrow=row-1;
			  newcolumn=column;
			  inti tobesubtracted=n*4;
			  if(row==r1 && column>c1){
				  tobesubtracted-=4;
			  }
			  if(row==r2 && column>c2){
				  tobesubtracted-=4;
			  }
			  if(newrow==r1 && newcolumn<c1){
				  tobesubtracted-=4;
			  }
			  if(newrow==r2 && newcolumn<c2){
				  tobesubtracted-=4;
			  }
			  if(newrow<1 || newrow>n || newcolumn<1 || newcolumn>n
			 ||  (newrow==r1 && newcolumn==c1) || (newrow==r2 && newcolumn==c2)){
				 clauses.push_back({-d});
			 }
			  else{
               clauses.push_back({-d,d-1-tobesubtracted});
			 }
	
		}
	}
	cout<<"p cnf "<<variable-1<<" "<<clauses.size()<<endl;
	for(inti i=0;i<clauses.size();i++){
		inti cursize=clauses[i].size();
		for(inti j=0;j<cursize;j++){
			cout<<clauses[i][j]<<" ";
		}
		cout<<0<<endl;
	}
}
