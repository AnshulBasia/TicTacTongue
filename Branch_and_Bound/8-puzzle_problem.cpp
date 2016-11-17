#include <bits/stc++.h>
using namespace std;
#define N 3

struct node{
	node *parent; //to trace in the end
	int mat[N][N];
	int x,y; //for blank tile
	int bound;
	int level;
	node(int matt[N][N],int a,int b){
		parent = NULL;
		x = a;
		y = b;
		level = 0;
		bount = INT_MAX;
	}
	node(int matt[N][N],int a,int b,char m,int l, node* p){
		parent = p;
		memcpy(mat,matt,sizeof(mat));
		x = a;
		y = b;
		level = l+1;
		if(m == 'l'){
			if(x == N){return;}
			if(x == N-1){
				mat[x][y] = mat[x+1][y];
				x = N;
			}
			if(x = N-2){
				mat[x][y] = mat[x+1][y];
				mat[x+1][y] = mat[x+2][y];
				x = N;
			}
		}

		if(m == 'r'){
			if(x = 1){return;}
			if(x == N-1){
				mat[x][y] = mat[x-1][y];
				x = 1;
			}
			if(x == N){
				mat[x][y] = mat[x-1][y];
				mat[x-1][y] = mat[x-2][y];
				x = 1;
			}
		}

		if(m == 'u'){
			if(y == N){return;}
			if(y == N-1){
				mat[x][y] = mat[x][y+1];
				y = N;
			}
			if(y == N-2){
				mat[x][y] = mat[x][y+1];
				mat[x][y+1] = mat[x][y+2];
				y = N;
			}
		}

		if(m == 'd'){
			if(y == 1){return;}
			if(y == N-1){
				mat[x][y] = mat[x][y-1];
				y = 1;
			}
			if(y == N-2){
				mat[x][y] = mat[x][y-1];
				mat[x][y-1] = mat[x][y-2];
				y = 1;
			}
		}

		//New Node constructed if feasible
	}
};

void print(int mat[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}



