#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
struct TrieNode{
	TrieNode* x[2];
	int count[2];
	TrieNode(){
		x[0]=NULL;
		x[1]=NULL;
		count[0]=0;
		count[1]=0;
	}
};
void insert(TrieNode* root,int element){
		for(int i=31;i>=0;i--){
			int bit=(element>>i)&1;
			if(bit){
				//AGAR 1 INSERT KRNA H TO
				root->count[1]++;
				if(root->x[1]==NULL){
					root->x[1]=new TrieNode();
				}
				root=root->x[1];
			}
			else{
				//AGAR 0 INSERT KSRNA H TO
				root->count[0]++;
				if(root->x[0]==NULL){
					root->x[0]=new TrieNode();
				}
				root=root->x[0];
			}
		}
}
int query(TrieNode* root,int element,int k){
	
	//element-->jiska xor kr rhe
	// K-->jisse compare kr rhe
	
    int ans=0;
	for(int i=31;i>=0;i--){
		int kbit=(k>>i)&1;
		int elementbit=(element>>i)&1;

		//BHAIYA WALI 4 CONDITIONS

		//AGAR K KA CURR BIT 1 HAI
		
		if(kbit){
				// AGAR ELEMENT KA BHI CURR BIT 1 HAI
				// ANS ME 1 KE SATH XOR ADD KRO AUR 0 TRF MOVE KRO
			
				if(elementbit){
					ans+=root->count[1];
					if(root->x[0]==NULL) return ans;
					root=root->x[0];
				}
					
				// AGAR ELEMENT KA CURR BIT 0 HAI
				// ANSME O KE SATH XOR KRO AUR 1 KI TRF MOVE KRO
					
				else{
					ans+=root->count[0];
					if(root->x[1]==NULL) return ans;
					root=root->x[1];
				}
		}
		// AGAR K KA CURR BIT 0 HAI

		else{
				// AGAR ELEMENT KA CURR 1 HAI TO 1 KI TRF AAGE BADHO
				if(elementbit){
					if(root->x[1]==NULL) return ans;
					root=root->x[1];
				}
				//AGAR ELEMENT KA CURR 0 HAI TO 0 KI TRF AAGE BADHO 
				else{
					if(root->x[0]==NULL) return ans;
					root=root->x[0];
				}
		}

	}
	return ans;
}

int main() {
	int t;
    cin >> t;
    while(t--){
        int n , k ;
        cin >> n >> k;
        int arr[n];
        for(int i = 0 ; i < n; i++){
            cin >> arr[i];
        }
        TrieNode *root = new TrieNode();
        insert(root , 0);
        int Xor = 0;
        long long res = 0;
        for(int i = 0 ; i < n ; i++){
            Xor ^= arr[i];
            res += query(root , Xor , k);
            insert(root , Xor);
        }
        cout<<res<<"\n";
	}
}
